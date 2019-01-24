import os.path
from clang import cindex

class PreProcessor:

    def toDocStr(self, file, filters):
        """Returns docstring after desired preprocessing filters are applied in order"""
        contents=open(file, 'r').read()
        for filter in filters:
            contents = filter.apply(contents)

        return contents



class Tokenize:

    #TODO: Make linux-worthy
    # changed to work for Mac; not tested for linux

    if not cindex.Config.loaded:
       cindex.Config.set_library_file(
            '/usr/local/Cellar/llvm/7.0.1/lib/libclang.dylib')
       


    @staticmethod
    def tokenize(file):
        filename, file_extension = os.path.splitext(file)
        lang = file_extension[1:]
        tokens=""
        if lang=="java":
            tokens = Tokenize.java(file)
        elif lang=="cpp":
            tokens = Tokenize.cpp(file)
        return tokens

    @staticmethod
    def lines(lines):
        fileChanges = dict()
        for lineInfo, line in lines.items():
            fil = lineInfo[1]
            if fil in fileChanges:
                currentfile = fileChanges.get(fil)
            else:
                currentfile = ""        
            fileChanges.update({fil:currentfile+"\n"+line})

        idx = cindex.Index.create()

        fileTokens = dict()
        for item in fileChanges.items():
            tu = idx.parse(item[0] ,unsaved_files=[item],args=['-std=c++11'],options=0)
            fileTokens.update({item[0]: list(tu.get_tokens(extent=tu.cursor.extent))})    
        
        return fileTokens

    @staticmethod
    def fun(lines):
        idx = cindex.Index.create()
        
        filename = None
        changes = ""
        for lineInfo, line in lines.items():
            if filename is None:
                filename = lineInfo[1]
            changes = changes+line+"\n"
        if filename is None:
            pass
        tu = idx.parse(filename,unsaved_files=[(filename,changes)],args=['-std=c++11'],options=0)
        return tu.get_tokens(extent=tu.cursor.extent)    
        
    @staticmethod
    def tokensToText(tokens):
        tokenStrings = map(lambda x: x.spelling, tokens)
        return " ".join(tokenStrings)

    import javalang
    @staticmethod
    def java(file):
        print("Java not yet implemented")
        return " "

    @staticmethod    
    def cpp(file):
        idx = cindex.Index.create()
        tu = idx.parse(file,args=['-std=c++11'],options=0)
        return tu.get_tokens(extent=tu.cursor.extent) 




        

    