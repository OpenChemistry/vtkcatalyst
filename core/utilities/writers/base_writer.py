class BaseWriter:
    def __init__(self):
        pass

    def open_ifndef(self, dtype):
        ret = "#ifndef CONDUIT_USE_"
        ret += dtype.replace(" ", "_").upper()
        return ret


    def close_ifndef(self):
        return "#endif"

    # Note that this does return a newline
    def long_comment_line(self):
        return "/" * 77 + "\n"
