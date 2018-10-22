
import FeatureSet
from clang import cindex

class PreProcessor:

    def toDocStr(self, file, filters):
        """Returns docstring after desired preprocessing filters are applied in order"""
        contents=open(file, 'r').read()
        for filter in filters:
            contents = filter.apply(contents)

        return contents

class Filter:
    def apply(self, docStr):
        pass

class Tokenize:
    @staticmethod
    def java(file):
        print("Java not yet implemented")
        return " "

    cindex.Config.set_library_file('C:/Program Files/LLVM/bin/libclang.dll')
    @staticmethod    
    def cpp(file):
        idx = cindex.Index.create()
        tu = idx.parse(file,args=['-std=c++11'],options=0)
        return tu.get_tokens(extent=tu.cursor.extent) 

        

    