import itertools
from .base_writer import BaseWriter


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

extra_args_with_defaults = """conduit_index_t num_elements = 1,
conduit_index_t offset = 0,
conduit_index_t stride = sizeof({dtype}),
conduit_index_t element_bytes = sizeof({dtype}),
conduit_index_t endianness = 0
"""

implementation_str = """{preprocess_str}conduit_node_set{mod}{dtype}{data_structure}{extra}({args});"""


class SettersWriter(BaseWriter):
    def __init__(
        self,
        conduit_types,
        native_types,
        string_types,
        data_structures,
        mods,
    ):
        super().__init__()
        self.conduit_types = conduit_types
        self.native_types = native_types
        self.string_types = string_types
        self.data_structures = data_structures
        self.mods = mods

    # Returns what goes in the () in the method declaration
    def get_sig_args(self, dtype, data_structure, mod):
        ret = ""

        if "path" in mod:
            ret += "const std::string& path,\n"

        if "external" not in mod:
            ret += "const "

        if data_structure == "vector":
            ret += f"std::vector<{dtype}>& data"

        elif data_structure == "ptr":
            ret += f"{dtype}* data,\n"

            dtype_to_take_size_of = dtype
            if dtype in itertools.chain.from_iterable(
                self.native_types.values()
            ):
                # Need to use the #define wrapping this type when
                # determining the stride and bytes
                dtype_to_take_size_of = (
                    "CONDUIT_NATIVE_" + dtype.replace(" ", "_").upper()
                )
            ret += extra_args_with_defaults.format(dtype=dtype_to_take_size_of)

        else:
            ret += f"{dtype}"
            if dtype in ["std::string", "Node"]:
                ret += "&"
            ret += " data"

        return ret

    # Returns the string that goes in the () in the C API call
    def get_c_call_args(self, dtype, data_structure, mod):
        is_mutable = "external" in mod
        arg_sep = ",\n" if mod == "ptr" else ", "

        # Always include this->c_node as first arg
        ret = "this->c_node" + arg_sep

        if "path" in mod:
            ret += "path.c_str()" + arg_sep

        # We may need to do some special operation on
        # data to pass it into the C API. Make a copy if immutable
        if dtype == "std::string":
            ret += "data.c_str()"

        elif dtype == "Node":
            ret += "data.c_node"

        elif data_structure == "vector":
            if is_mutable:
                ret += "data.data()" + arg_sep
            else:
                ret += f"std::vector<{dtype}>(data).data()" + arg_sep
            ret += "data.size()"

        elif data_structure == "ptr":
            if is_mutable:
                ret += "data"
            else:
                ret += f"({dtype}*)"
                ret += (
                    f"memcpy(data_cpy, data, sizeof({dtype}) * num_elements)"
                )

            ret += arg_sep
            ret += extra_args

        else:
            ret += "data"

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
            dtype="_"
            + dtype_str.replace(" ", "_").replace("conduit_", "").lower()
            if dtype
            else "",
            data_structure="_" + data_structure
            if data_structure
            else data_structure,
            args=arg_str,
        )

    # Fills in the implementation for the method
    def get_imp(
        self,
        dtype,
        data_structure,
        mod,
        dtype_str,
        easy_imp=False,
        overloading=False,
    ):
        if easy_imp:
            return self.get_easy_imp(dtype, data_structure, mod, dtype_str)

        # Else actually provide an implementation block
        preprocess_str = ""
        if data_structure == "ptr" and "external" not in mod:
            preprocess_str = f"{dtype} data_cpy[num_elements];"
            # Also need to add a newline
            preprocess_str += "\n"

        c_call_args = self.get_c_call_args(dtype, data_structure, mod)

        # For the set_{dtype}_vector calls, we need to call
        # the C API's set_{dtype}_ptr fxn
        c_data_structure = data_structure
        if data_structure == "vector":
            c_data_structure = "ptr"

        if dtype_str == "string":
            dtype_str = "char8_str"

        return implementation_str.format(
            preprocess_str=preprocess_str,
            dtype="_"
            + dtype_str.replace(" ", "_").replace("conduit_", "").lower(),
            mod="_" + mod if mod else mod,
            data_structure="_" + c_data_structure if c_data_structure else "",
            extra="_detailed" if data_structure == "ptr" else "",
            args=c_call_args,
        )

    # Returns the method signature + implementation
    def construct_setter(
        self,
        dtype,
        data_structure,
        mod,
        easy_imp=False,
        overloading=False,
        dtype_str=None,
    ):
        if dtype_str is None:
            dtype_str = dtype

        # First get the signature args
        decl_args = self.get_sig_args(dtype, data_structure, mod)

        imp = self.get_imp(
            dtype, data_structure, mod, dtype_str, easy_imp=easy_imp
        )

        return set_decl.format(
            mod="_" + mod if mod else mod,
            dtype="_" + dtype_str.replace("conduit_", "").lower()
            if not overloading
            else "",
            data_structure="_" + data_structure
            if not overloading and data_structure
            else "",
            decl_args=decl_args,
            implementation=imp,
        )

    # Writes both the explicit set_{dtype} method and the
    # overloaded set call.
    def construct_overloaded_and_non_overloaded(
        self,
        dtype,
        data_structure,
        mod,
        dtype_str=None,
    ):
        ret = self.construct_setter(
            dtype, data_structure, mod, dtype_str=dtype_str
        )
        ret += "\n" * 2
        ret += self.construct_setter(
            dtype,
            data_structure,
            mod,
            easy_imp=True,
            overloading=True,
            dtype_str=dtype_str,
        )
        ret += "\n" * 2
        return ret

    def write_setters_for_conduit_types(self, ds, mod):
        ret = ""
        types_to_iterate_over = self.conduit_types

        if "external" in mod and ds == "":
            types_to_iterate_over = ["Node"]

        for dtype in types_to_iterate_over:
            if dtype == "Node" and ds != "":
                continue
            ret += self.construct_overloaded_and_non_overloaded(
                dtype, ds, mod
            )

        return ret

    def write_setters_for_native_types(self, ds, mod):
        ret = ""

        if "external" in mod and ds == "":
            return ret

        for base_t, variants in list(self.native_types.items()):
            if base_t != "char":
                ret += self.open_ifndef(base_t) + "\n"

            for variant in variants:
                if variant == "signed char":
                    ret += self.open_ifndef(base_t) + "\n"

                overloading = (
                    False if variant == "char" and ds == "ptr" else True
                )
                ret += self.construct_setter(
                    variant,
                    ds,
                    mod,
                    overloading=overloading,
                )
                ret += "\n"
            ret += self.close_ifndef() + "\n"
        return ret

    def write_setters_for_string_types(self, ds, mod):
        ret = ""
        types_to_iterate_over = self.string_types

        if ds != "":
            return ret

        if "external" in mod:
            types_to_iterate_over = ["char*"]

        for dtype in types_to_iterate_over:
            dtype_str = "string" if dtype == "std::string" else "char8_str"

            ret += self.construct_setter(
                dtype, ds, mod, dtype_str=dtype_str
            )
            ret += "\n" * 2

            if dtype == "std::string":
                ret += self.construct_setter(
                    dtype,
                    ds,
                    mod,
                    easy_imp=True,
                    overloading=True,
                    dtype_str=dtype_str,
                )
                ret += "\n" * 2

        return ret


    def mark_beginning_of_generated_section(self):
        ret = self.long_comment_line()
        ret += "// The following code was generated by core/utilities/generate_setters.py.\n"
        ret += "// The output of the above script is not formatted. It is recommended\n"
        ret += "// to format the output using an automatic formatting tool,\n"
        ret += "// like clang-format.\n"
        ret += self.long_comment_line()
        ret += "\n"
        return ret

    def mark_end_of_generated_section(self):
        ret = self.long_comment_line()
        ret += "// End generated section.\n"
        ret += self.long_comment_line()
        ret += "\n"
        return ret


    def write(self):
        total_str = self.mark_beginning_of_generated_section()
        for mod, ds in itertools.product(self.mods, self.data_structures):
            total_str += self.write_setters_for_conduit_types(ds, mod)
            total_str += self.write_setters_for_native_types(ds, mod)
            total_str += self.write_setters_for_string_types(ds, mod)

        total_str += self.mark_end_of_generated_section()

        return total_str
