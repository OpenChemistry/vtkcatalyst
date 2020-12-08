from writers.setters import SettersWriter
from writers.operators import OperatorsWriter

wrapped_types = [
    "int8",
    "int16",
    "int32",
    "int64",
    "uint8",
    "uint16",
    "uint32",
    "uint64",
    "float32",
    "float64",
]

native_types = {
    "char": ["char", "signed char", "unsigned char"],
    "short": ["short", "unsigned short"],
    "int": ["int", "unsigned int"],
    "long": ["long", "unsigned long"],
    # "long long": ["unsigned long long"], TODO
}

string_types = [
    "std::string",
    "char*"
]

data_structures = ["", "array", "vector", "ptr"]


mods = ["", "path", "external", "path_external"]


if __name__ == '__main__':
    print(SettersWriter(wrapped_types, native_types, string_types, data_structures, mods).write())
    # print(OperatorsWriter(wrapped_types, native_types, data_structures, mods).write())
