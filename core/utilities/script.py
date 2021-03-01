from writers.setters_writer import SettersWriter

conduit_types = [
    "Node",
    "conduit_int8",
    "conduit_int16",
    "conduit_int32",
    "conduit_int64",
    "conduit_uint8",
    "conduit_uint16",
    "conduit_uint32",
    "conduit_uint64",
    "conduit_float32",
    "conduit_float64",
]

native_types = {
    "char": ["char", "signed char", "unsigned char"],
    "short": ["short", "unsigned short"],
    "int": ["int", "unsigned int"],
    "long": ["long", "unsigned long"],
}

string_types = [
    "std::string",
    "char*"
]

data_structures = ["", "vector", "ptr"]


mods = ["", "path", "external", "path_external"]


if __name__ == '__main__':
    print(SettersWriter(conduit_types, native_types, string_types, data_structures, mods).write())
