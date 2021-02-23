from .base import BaseWriter

# set_path_external_uint8_vector
set_decl = """void set{mod}{dtype}{data_structure}({decl_args})
{{
    {implementation}
}}"""

easy_imp = """this->set{mod}{dtype}{data_structure}({args});"""


extra_args = """num_elements,
offset,
stride,
element_bytes,
endianness
"""

extra_args_with_defaults = """index_t num_elements = 1,
index_t offset = 0,
index_t stride = sizeof(conduit::int16),
index_t element_bytes = sizeof(conduit::int16),
index_t endianness = Endianness::DEFAULT_ID
"""

implementation_str = """{preprocess_str}
conduit_node_set{mod}{dtype}{data_structure}{extra}({args});
"""


class SettersWriter(BaseWriter):
    def __init__(
        self,
        wrapped_types,
        native_types,
        string_types,
        data_structures,
        mods,
        num_mods=999,
        num_ds=999,
        num_dtype=10000,
    ):
        super().__init__()
        self.wrapped_types = wrapped_types
        self.native_types = native_types
        self.string_types = string_types
        self.data_structures = data_structures
        self.mods = mods
        self.num_mods = num_mods
        self.num_ds = num_ds
        self.num_dtype = num_dtype


    # Returns what goes in the () in the method declaration
    def get_decl_args(self, dtype, data_structure, mod):
        ret = ""

        if "path" in mod:
            ret += "const std::string& path,\n"

        if "external" not in mod:
            ret += "const "

        if data_structure == "array":
            ret += dtype.replace(" ", "_")
            ret += "_array& data"

        elif data_structure == "vector":
            ret += f"std::vector<{dtype}>& data"

        elif data_structure == "ptr":
            ret += f"{dtype}* data,\n"
            ret += extra_args_with_defaults

        else:
            ret += f"{dtype} data"

        return ret


    # Returns the string that goes in the () in the C API call
    def get_c_call_args(self, dtype, data_structure, mod):
        is_mutable = "external" in mod

        # Always include this->c_node as first arg
        ret = "this->c_node,\n"

        if "path" in mod:
            ret += "path.c_str(),\n"

        # We may need to do some special operation on
        # data to pass it into the C API. Make a copy if immutable
        if dtype == "std::string":
            ret += "data.c_str()"

        elif data_structure == "array":
            ret += f"({dtype}*)"  # Cast
            if is_mutable:
                ret += "data.data_ptr(),\n"
            # Copy
            else:
                ret += dtype.replace(" ", "_") + "_array(data).data_ptr(),\n"
            ret += "data.number_of_elements()"

        elif data_structure == "vector":
            if is_mutable:
                ret += "data.data(),\n"
            else:
                ret += f"std::vector<{dtype}>(data).data(),\n"
            ret += "data.size()"

        elif data_structure == "ptr":
            if is_mutable:
                ret += "data"
            else:
                ret += f"({dtype}*)"
                ret += f"memcpy(data_cpy, data, sizeof({dtype}) * num_elements)"

        else:
            ret += "data"

        if data_structure == "ptr":
            ret += ",\n"
            ret += extra_args

        return ret


    # If we are writing out an overloaded set() that has a corresponding
    # explicit set_{dtype}(), we can just call set_{dtype} instead of
    # providing a new implementation
    def get_easy_imp(self, dtype, data_structure, mod, dtype_str):
        arg_str = ""
        if "path" in mod:
            arg_str += "path,\n"

        arg_str += "data"

        if data_structure == "ptr":
            arg_str += ",\n"
            arg_str += extra_args

        return easy_imp.format(
            mod="_" + mod if mod else mod,
            dtype="_" + dtype_str.replace(" ", "_") if dtype else "",
            data_structure="_" + data_structure if data_structure else data_structure,
            args=arg_str,
        )


    # Fills in the implementation for the method
    def get_imp(self, dtype, data_structure, mod, dtype_str, easy_imp=False, overloading=False):
        if easy_imp:
            return self.get_easy_imp(dtype, data_structure, mod, dtype_str)

        # Else actually provide an implementation block
        preprocess_str = ""
        if data_structure == "ptr" and "external" not in mod:
            preprocess_str = f"{dtype} data_cpy[num_elements];"

        c_call_args = self.get_c_call_args(dtype, data_structure, mod)

        # For the set_{dtype}_array/vector calls, we need to call
        # the C API's set_{dtype}_ptr fxn
        # Similar for the case where data_structure == vector
        c_data_structure = data_structure
        if data_structure in ["array", "vector"]:
            c_data_structure = "ptr"

        if dtype_str == "string":
            dtype_str = "char8_str"

        return implementation_str.format(
            preprocess_str=preprocess_str,
            dtype="_" + dtype_str.replace(" ", "_"),
            mod="_" + mod if mod else mod,
            data_structure="_" + c_data_structure if c_data_structure else "",
            extra="_detailed" if data_structure == "ptr" else "",
            args=c_call_args,
        )


    # Returns the method declaration + implementation
    def construct_set_decl(
        self, dtype, data_structure, mod, easy_imp=False, overloading=False, dtype_str=None
    ):
        if dtype_str is None:
            dtype_str = dtype

        # First get the declaration args
        decl_args = self.get_decl_args(dtype, data_structure, mod)

        imp = self.get_imp(dtype, data_structure, mod, dtype_str, easy_imp=easy_imp)


        return set_decl.format(
            mod="_" + mod if mod else mod,
            dtype="_" + dtype_str if not overloading else "",
            data_structure="_" + data_structure
            if not overloading and data_structure
            else "",
            decl_args=decl_args,
            implementation=imp,
        )

    def write(self):
        total_str = ""
        for mod in self.mods[:self.num_mods]:
            for data_structure in self.data_structures[:self.num_ds]:
                if "external" in mod and data_structure == "":
                    continue

                for dtype in self.wrapped_types[:self.num_dtype]:
                    total_str += self.construct_set_decl(dtype, data_structure, mod)
                    total_str += "\n" * 2
                    total_str += self.construct_set_decl(
                        dtype, data_structure, mod, easy_imp=True, overloading=True
                    )
                    total_str += "\n" * 2

                for base_t, variants in list(self.native_types.items())[:self.num_dtype]:
                    if base_t != "char":
                        total_str += self.open_ifndef(base_t) + "\n"

                    for variant in variants:
                        if variant == "signed char":
                            total_str += self.open_ifndef(base_t) + "\n"

                        total_str += self.construct_set_decl(
                            variant, data_structure, mod, overloading=True
                        )
                        total_str += "\n"
                    total_str += self.close_ifndef() + "\n"

                if data_structure != "":
                    continue

                for dtype in self.string_types[:self.num_dtype]:
                    if dtype == "std::string" and "external" in mod:
                        continue

                    dtype_str = "string" if dtype == "std::string" else "char8_str"

                    total_str += self.construct_set_decl(dtype, data_structure, mod, dtype_str=dtype_str)
                    total_str += "\n" * 2

                    if dtype == "std::string":
                        total_str += self.construct_set_decl(
                            dtype, data_structure, mod, easy_imp=True, overloading=True, dtype_str=dtype_str
                        )
                        total_str += "\n" * 2
        return total_str
