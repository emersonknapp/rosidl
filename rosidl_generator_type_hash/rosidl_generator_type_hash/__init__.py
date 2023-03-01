# Copyright 2023 Open Source Robotics Foundation, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import hashlib
import json
from pathlib import Path
import sys
from typing import List, Tuple

from rosidl_parser import definition
from rosidl_parser.parser import parse_idl_file

# ROS Interface Hashing Standard, per REP-2011
RIHS_VERSION = '01'


def generate_type_hash(generator_arguments_file: str) -> List[str]:
    with open(generator_arguments_file, 'r') as f:
        args = json.load(f)
    package_name = args['package_name']
    output_dir = Path(args['output_dir'])
    idl_tuples = args['idl_tuples']
    include_paths = args.get('include_paths', [])

    # Lookup for directory containing dependency .in.json files
    include_map = {
        package_name: output_dir
    }
    for include_tuple in include_paths:
        include_parts = include_tuple.rsplit(':', 1)
        assert len(include_parts) == 2
        include_package_name, include_base_path = include_parts
        include_map[include_package_name] = Path(include_base_path)

    generated_files = []
    hashers = []

    # First generate all .in.json files (so referenced types can be used in expansion)
    for idl_tuple in idl_tuples:
        idl_parts = idl_tuple.rsplit(':', 1)
        assert len(idl_parts) == 2
        locator = definition.IdlLocator(*idl_parts)
        try:
            idl_file = parse_idl_file(locator)
        except Exception as e:
            print('Error processing idl file: ' +
                  str(locator.get_absolute_path()), file=sys.stderr)
            raise(e)

        idl_rel_path = Path(idl_parts[1])
        generate_to_dir = (output_dir / idl_rel_path).parent
        generate_to_dir.mkdir(parents=True, exist_ok=True)

        hasher = InterfaceHasher.from_idl(idl_file)
        generated_files.extend(
            hasher.write_json_in(output_dir))
        hashers.append(hasher)

    # Expand .in.json and generate .sha256.json hash files
    for hasher in hashers:
        generated_files.extend(
            hasher.write_json_out(output_dir, include_map))
        generated_files.extend(
            hasher.write_hash(output_dir))

    return generated_files


# This mapping must match the constants defined in type_description_interfaces/msgs/FieldType.msg
# NOTE: Nonexplicit integer types are not defined in FieldType (short, long, long long).
# If a ROS IDL uses these, this generator will throw a KeyError.
FIELD_VALUE_TYPE_NAMES = {
    None: 'FIELD_TYPE_NOT_SET',
    'nested_type': 'FIELD_TYPE_NESTED_TYPE',
    'int8': 'FIELD_TYPE_INT8',
    'uint8': 'FIELD_TYPE_UINT8',
    'int16': 'FIELD_TYPE_INT16',
    'uint16': 'FIELD_TYPE_UINT16',
    'int32': 'FIELD_TYPE_INT32',
    'uint32': 'FIELD_TYPE_UINT32',
    'int64': 'FIELD_TYPE_INT64',
    'uint64': 'FIELD_TYPE_UINT64',
    'float': 'FIELD_TYPE_FLOAT',
    'double': 'FIELD_TYPE_DOUBLE',
    'long': 'LONG_DOUBLE',
    'char': 'FIELD_TYPE_CHAR',
    'wchar': 'FIELD_TYPE_WCHAR',
    'boolean': 'FIELD_TYPE_BOOLEAN',
    'octet': 'FIELD_TYPE_BYTE',
    definition.UnboundedString: 'FIELD_TYPE_STRING',
    definition.UnboundedWString: 'FIELD_TYPE_WSTRING',
    # NOTE: rosidl_parser does not define fixed string types
    definition.BoundedString: 'FIELD_TYPE_BOUNDED_STRING',
    definition.BoundedWString: 'FIELD_TYPE_BOUNDED_WSTRING',
}

NESTED_FIELD_TYPE_SUFFIXES = {
    definition.Array: '_ARRAY',
    definition.BoundedSequence: '_BOUNDED_SEQUENCE',
    definition.UnboundedSequence: '_UNBOUNDED_SEQUENCE',
}

# Copied directly from FieldType.msg, with a string replace-all applied
FIELD_TYPE_IDS = {
    'FIELD_TYPE_NOT_SET': 0,

    # Nested type defined in other .msg/.idl files.
    'FIELD_TYPE_NESTED_TYPE': 1,

    # Basic Types
    # Integer Types
    'FIELD_TYPE_INT8': 2,
    'FIELD_TYPE_UINT8': 3,
    'FIELD_TYPE_INT16': 4,
    'FIELD_TYPE_UINT16': 5,
    'FIELD_TYPE_INT32': 6,
    'FIELD_TYPE_UINT32': 7,
    'FIELD_TYPE_INT64': 8,
    'FIELD_TYPE_UINT64': 9,

    # Floating-Point Types
    'FIELD_TYPE_FLOAT': 10,
    'FIELD_TYPE_DOUBLE': 11,
    'FIELD_TYPE_LONG_DOUBLE': 12,

    # Char and WChar Types
    'FIELD_TYPE_CHAR': 13,
    'FIELD_TYPE_WCHAR': 14,

    # Boolean Type
    'FIELD_TYPE_BOOLEAN': 15,

    # Byte/Octet Type
    'FIELD_TYPE_BYTE': 16,

    # String Types
    'FIELD_TYPE_STRING': 17,
    'FIELD_TYPE_WSTRING': 18,

    # Fixed String Types
    'FIELD_TYPE_FIXED_STRING': 19,
    'FIELD_TYPE_FIXED_WSTRING': 20,

    # Bounded String Types
    'FIELD_TYPE_BOUNDED_STRING': 21,
    'FIELD_TYPE_BOUNDED_WSTRING': 22,

    # Fixed Sized Array Types
    'FIELD_TYPE_NESTED_TYPE_ARRAY': 49,
    'FIELD_TYPE_INT8_ARRAY': 50,
    'FIELD_TYPE_UINT8_ARRAY': 51,
    'FIELD_TYPE_INT16_ARRAY': 52,
    'FIELD_TYPE_UINT16_ARRAY': 53,
    'FIELD_TYPE_INT32_ARRAY': 54,
    'FIELD_TYPE_UINT32_ARRAY': 55,
    'FIELD_TYPE_INT64_ARRAY': 56,
    'FIELD_TYPE_UINT64_ARRAY': 57,
    'FIELD_TYPE_FLOAT_ARRAY': 58,
    'FIELD_TYPE_DOUBLE_ARRAY': 59,
    'FIELD_TYPE_LONG_DOUBLE_ARRAY': 60,
    'FIELD_TYPE_CHAR_ARRAY': 61,
    'FIELD_TYPE_WCHAR_ARRAY': 62,
    'FIELD_TYPE_BOOLEAN_ARRAY': 63,
    'FIELD_TYPE_BYTE_ARRAY': 64,
    'FIELD_TYPE_STRING_ARRAY': 65,
    'FIELD_TYPE_WSTRING_ARRAY': 66,
    'FIELD_TYPE_FIXED_STRING_ARRAY': 67,
    'FIELD_TYPE_FIXED_WSTRING_ARRAY': 68,
    'FIELD_TYPE_BOUNDED_STRING_ARRAY': 69,
    'FIELD_TYPE_BOUNDED_WSTRING_ARRAY': 70,

    # Bounded Sequence Types
    'FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE': 97,
    'FIELD_TYPE_INT8_BOUNDED_SEQUENCE': 98,
    'FIELD_TYPE_UINT8_BOUNDED_SEQUENCE': 99,
    'FIELD_TYPE_INT16_BOUNDED_SEQUENCE': 100,
    'FIELD_TYPE_UINT16_BOUNDED_SEQUENCE': 101,
    'FIELD_TYPE_INT32_BOUNDED_SEQUENCE': 102,
    'FIELD_TYPE_UINT32_BOUNDED_SEQUENCE': 103,
    'FIELD_TYPE_INT64_BOUNDED_SEQUENCE': 104,
    'FIELD_TYPE_UINT64_BOUNDED_SEQUENCE': 105,
    'FIELD_TYPE_FLOAT_BOUNDED_SEQUENCE': 106,
    'FIELD_TYPE_DOUBLE_BOUNDED_SEQUENCE': 107,
    'FIELD_TYPE_LONG_DOUBLE_BOUNDED_SEQUENCE': 108,
    'FIELD_TYPE_CHAR_BOUNDED_SEQUENCE': 109,
    'FIELD_TYPE_WCHAR_BOUNDED_SEQUENCE': 110,
    'FIELD_TYPE_BOOLEAN_BOUNDED_SEQUENCE': 111,
    'FIELD_TYPE_BYTE_BOUNDED_SEQUENCE': 112,
    'FIELD_TYPE_STRING_BOUNDED_SEQUENCE': 113,
    'FIELD_TYPE_WSTRING_BOUNDED_SEQUENCE': 114,
    'FIELD_TYPE_FIXED_STRING_BOUNDED_SEQUENCE': 115,
    'FIELD_TYPE_FIXED_WSTRING_BOUNDED_SEQUENCE': 116,
    'FIELD_TYPE_BOUNDED_STRING_BOUNDED_SEQUENCE': 117,
    'FIELD_TYPE_BOUNDED_WSTRING_BOUNDED_SEQUENCE': 118,

    # Unbounded Sequence Types
    'FIELD_TYPE_NESTED_TYPE_UNBOUNDED_SEQUENCE': 145,
    'FIELD_TYPE_INT8_UNBOUNDED_SEQUENCE': 146,
    'FIELD_TYPE_UINT8_UNBOUNDED_SEQUENCE': 147,
    'FIELD_TYPE_INT16_UNBOUNDED_SEQUENCE': 148,
    'FIELD_TYPE_UINT16_UNBOUNDED_SEQUENCE': 149,
    'FIELD_TYPE_INT32_UNBOUNDED_SEQUENCE': 150,
    'FIELD_TYPE_UINT32_UNBOUNDED_SEQUENCE': 151,
    'FIELD_TYPE_INT64_UNBOUNDED_SEQUENCE': 152,
    'FIELD_TYPE_UINT64_UNBOUNDED_SEQUENCE': 153,
    'FIELD_TYPE_FLOAT_UNBOUNDED_SEQUENCE': 154,
    'FIELD_TYPE_DOUBLE_UNBOUNDED_SEQUENCE': 155,
    'FIELD_TYPE_LONG_DOUBLE_UNBOUNDED_SEQUENCE': 156,
    'FIELD_TYPE_CHAR_UNBOUNDED_SEQUENCE': 157,
    'FIELD_TYPE_WCHAR_UNBOUNDED_SEQUENCE': 158,
    'FIELD_TYPE_BOOLEAN_UNBOUNDED_SEQUENCE': 159,
    'FIELD_TYPE_BYTE_UNBOUNDED_SEQUENCE': 160,
    'FIELD_TYPE_STRING_UNBOUNDED_SEQUENCE': 161,
    'FIELD_TYPE_WSTRING_UNBOUNDED_SEQUENCE': 162,
    'FIELD_TYPE_FIXED_STRING_UNBOUNDED_SEQUENCE': 163,
    'FIELD_TYPE_FIXED_WSTRING_UNBOUNDED_SEQUENCE': 164,
    'FIELD_TYPE_BOUNDED_STRING_UNBOUNDED_SEQUENCE': 165,
    'FIELD_TYPE_BOUNDED_WSTRING_UNBOUNDED_SEQUENCE': 166,
}


def field_type_type_name(ftype: definition.AbstractType) -> str:
    value_type = ftype
    name_suffix = ''

    if isinstance(ftype, definition.AbstractNestedType):
        value_type = ftype.value_type
        name_suffix = NESTED_FIELD_TYPE_SUFFIXES[type(ftype)]

    if isinstance(value_type, definition.BasicType):
        value_type_name = FIELD_VALUE_TYPE_NAMES[value_type.typename]
    elif isinstance(value_type, definition.AbstractGenericString):
        value_type_name = FIELD_VALUE_TYPE_NAMES[type(value_type)]
    elif (
        isinstance(value_type, definition.NamespacedType) or
        isinstance(value_type, definition.NamedType)
    ):
        value_type_name = 'FIELD_TYPE_NESTED_TYPE'

    return value_type_name + name_suffix


def field_type_type_id(ftype: definition.AbstractType) -> Tuple[str, int]:
    return FIELD_TYPE_IDS[field_type_type_name(ftype)]


def field_type_length(ftype: definition.AbstractType):
    if isinstance(ftype, definition.AbstractNestedType):
        if ftype.has_maximum_size():
            try:
                return ftype.maximum_size
            except AttributeError:
                return ftype.size
    return 0


def field_type_string_length(ftype: definition.AbstractType):
    value_type = ftype
    if isinstance(ftype, definition.AbstractNestedType):
        value_type = ftype.value_type

    if isinstance(value_type, definition.AbstractGenericString):
        if value_type.has_maximum_size():
            try:
                return value_type.maximum_size
            except AttributeError:
                return value_type.size
    return 0


def field_type_nested_type_name(ftype: definition.AbstractType, joiner='/'):
    value_type = ftype
    if isinstance(ftype, definition.AbstractNestedType):
        value_type = ftype.value_type
    if isinstance(value_type, definition.NamespacedType):
        return joiner.join(value_type.namespaced_name())
    elif isinstance(value_type, definition.NamedType):
        return value_type.name
    return ''


def serialize_field_type(ftype: definition.AbstractType) -> dict:
    return {
        'type_id': field_type_type_id(ftype),
        'length': field_type_length(ftype),
        'string_length': field_type_string_length(ftype),
        'nested_type_name': field_type_nested_type_name(ftype),
    }


def serialize_field(member: definition.Member) -> dict:
    return {
        'name': member.name,
        'type': serialize_field_type(member.type),
        # skipping default_value
    }


def serialize_individual_type_description(
    namespaced_type: definition.NamespacedType, members: List[definition.Member]
) -> dict:
    return {
        'type_name': '/'.join(namespaced_type.namespaced_name()),
        'fields': [serialize_field(member) for member in members]
    }


class InterfaceHasher:
    """Contains context about subinterfaces for a given interface description."""

    @classmethod
    def from_idl(cls, idl: definition.IdlFile):
        for el in idl.content.elements:
            if any(isinstance(el, type_) for type_ in [
                definition.Message, definition.Service, definition.Action
            ]):
                return InterfaceHasher(el)
        raise ValueError('No interface found in IDL')

    def __init__(self, interface):
        self.interface = interface
        self.subinterfaces = {}

        # Determine top level interface, and member fields based on that
        if isinstance(interface, definition.Message):
            self.namespaced_type = interface.structure.namespaced_type
            self.interface_type = 'message'
            self.members = interface.structure.members
        elif isinstance(interface, definition.Service):
            self.namespaced_type = interface.namespaced_type
            self.interface_type = 'service'
            self.subinterfaces = {
                'request_message': InterfaceHasher(interface.request_message),
                'response_message': InterfaceHasher(interface.response_message),
                'event_message': InterfaceHasher(interface.event_message),
            }
            self.members = [
                definition.Member(hasher.namespaced_type, field_name)
                for field_name, hasher in self.subinterfaces.items()
            ]
        elif isinstance(interface, definition.Action):
            self.namespaced_type = interface.namespaced_type
            self.interface_type = 'action'
            self.subinterfaces = {
                'goal': InterfaceHasher(interface.goal),
                'result': InterfaceHasher(interface.result),
                'feedback': InterfaceHasher(interface.feedback),
                'send_goal_service': InterfaceHasher(interface.send_goal_service),
                'get_result_service': InterfaceHasher(interface.get_result_service),
                'feedback_message': InterfaceHasher(interface.feedback_message),
            }
            self.members = [
                definition.Member(hasher.namespaced_type, field_name)
                for field_name, hasher in self.subinterfaces.items()
            ]

        self.individual_type_description = serialize_individual_type_description(
            self.namespaced_type, self.members)

        # Determine needed includes from member fields
        included_types = []
        for member in self.members:
            if isinstance(member.type, definition.NamespacedType):
                included_types.append(member.type)
            elif (
                isinstance(member.type, definition.AbstractNestedType) and
                isinstance(member.type.value_type, definition.NamespacedType)
            ):
                included_types.append(member.type.value_type)

        self.includes = [
            str(Path(*t.namespaced_name()).with_suffix('.in.json'))
            for t in included_types
        ]

        self.rel_path = Path(*self.namespaced_type.namespaced_name()[1:])
        self.include_path = Path(*self.namespaced_type.namespaced_name())

        self.json_in = {
            'type_description': self.individual_type_description,
            'includes': self.includes,
        }

    def write_json_in(self, output_dir) -> List[str]:
        """Return list of written files."""
        generated_files = []
        for key, val in self.subinterfaces.items():
            generated_files += val.write_json_in(output_dir)

        json_path = output_dir / self.rel_path.with_suffix('.in.json')
        json_path.parent.mkdir(parents=True, exist_ok=True)
        with json_path.open('w', encoding='utf-8') as json_file:
            json_file.write(json.dumps(self.json_in, indent=2))
        return generated_files + [str(json_path)]

    def _hashable_repr(self) -> str:
        return json.dumps(
            self.json_out,
            skipkeys=False,
            ensure_ascii=True,
            check_circular=True,
            allow_nan=False,
            indent=None,
            separators=(',', ': '),
            sort_keys=False
        )

    def write_json_out(self, output_dir: Path, includes_map: dict) -> List[str]:
        """Return list of written files."""
        generated_files = []
        for key, val in self.subinterfaces.items():
            generated_files += val.write_json_out(output_dir, includes_map)

        # Recursively load includes from all included type descriptions
        pending_includes = self.includes[:]
        loaded_includes = {}
        while pending_includes:
            process_include = pending_includes.pop()
            if process_include in loaded_includes:
                continue
            p_path = Path(process_include)
            assert(not p_path.is_absolute())
            include_package = p_path.parts[0]
            include_file = includes_map[include_package] / p_path.relative_to(include_package)

            with include_file.open('r') as include_file:
                include_json = json.load(include_file)

            loaded_includes[process_include] = include_json['type_description']
            pending_includes.extend(include_json['includes'])

        # Sort included type descriptions alphabetically by type name
        self.json_out = {
            'type_description': self.json_in['type_description'],
            'referenced_type_descriptions': sorted(
                loaded_includes.values(), key=lambda td: td['type_name'])
        }

        json_path = output_dir / self.rel_path.with_suffix('.json')
        with json_path.open('w', encoding='utf-8') as json_file:
            json_file.write(self._hashable_repr())
        return generated_files + [str(json_path)]

    def _calculate_hash_tree(self) -> dict:
        prefix = f'RIHS{RIHS_VERSION}_'
        sha = hashlib.sha256()
        sha.update(self._hashable_repr().encode('utf-8'))
        type_hash = prefix + sha.hexdigest()

        type_hash_infos = {
            self.interface_type: type_hash,
        }
        for key, val in self.subinterfaces.items():
            type_hash_infos[key] = val._calculate_hash_tree()

        return type_hash_infos

    def write_hash(self, output_dir: Path) -> List[str]:
        """Return list of written files."""
        type_hash = self._calculate_hash_tree()
        hash_path = output_dir / self.rel_path.with_suffix('.sha256.json')
        with hash_path.open('w', encoding='utf-8') as hash_file:
            hash_file.write(json.dumps(type_hash, indent=2))
        return [str(hash_path)]
