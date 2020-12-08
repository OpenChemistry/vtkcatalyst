from .base import BaseWriter

class OperatorsWriter(BaseWriter):
    def __init__(
        self,
        wrapped_types,
        native_types,
        data_structures,
        mods,
        num_mods=999,
        num_ds=999,
        num_dtype=10000,
    ):
        super().__init__()

        self.wrapped_types = wrapped_types
        self.native_types = native_types
        self.data_structures = data_structures
        self.mods = mods
        self.num_mods = num_mods
        self.num_ds = num_ds
        self.num_dtype = num_dtype

    def write(self):
        return ""
