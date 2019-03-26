from ast import literal_eval
import os.path
import platform
import configparser
from clang import cindex

from ctypes.util import find_library



def is_number(s):
    try:
        float(s)
        return True
    except ValueError:
        pass

    try:
        import unicodedata
        unicodedata.numeric(s)
        return True
    except (TypeError, ValueError):
        pass

    return False    


class Config:
    # stores the loaded config for easy access in any other module
    config_path = 'config.ini'
    config = configparser.ConfigParser()
    config.read(config_path)

    @staticmethod
    def view():
        # prints the contents of the current configuration
        pass

    @staticmethod
    def update(key, subkey, value):
        # TODO: Make the input a dictionary of {keys: value}? Would have to loop over items, but only write to ini once
        # TODO: alternatively, add a save parameter that determines whether to write to file or not
        """
        Updates the both the current config parser and the config file.
        :param keys: the list of nested keys that make up the compound key that we
            want to update, e.g. for config['Model']['model_name'], use keys =
            ['Model', 'model_name']. Note that the keys are not case-sensitive.
        :param value: the new value to map to the compound key.
        :param default_value: the value to use if the key to update doesn't exist
        :return: None. Updates the config in-place.
        """
        if key not in Config.config: # section doesn't exist
            Config.config.add_section(key)
        Config.config.set(key, option = subkey, value = value) # mutating the parser values
        with open(Config.config_path, 'w') as configfile:      # writing to file
            Config.config.write(configfile)


    @staticmethod
    def cast_value(value):
        """
        Gets the value in the configuration at (key, subkey), casts it to the
            correct type, and returns it
        :param key: the section in the config
        :param subkey: the key within the section whose value is wanted
        :return: Any type. Depends on the value in the string.
        """
        val = value.strip()

        # integers
        if val.isnumeric():
            return int(val)

        # booleans
        bool_vals = ('True', 'False')
        if val in bool_vals:
            return val == bool_vals[0]

        # fractions
        parts = [i.strip() for i in val.split("/")]
        if len(parts) == 2 and all(i.isdigit() for i in parts):
            return int(parts[0]) / int(parts[1])

        # all other data types
        try: # except strings
            return literal_eval(val)
        except: # strings
            return val

    @staticmethod
    def get_value(key, subkey):
        return Config.cast_value(Config.config[key][subkey])

class PreProcessor:

    def toDocStr(self, file, filters):
        """Returns docstring after desired preprocessing filters are applied in order"""
        contents=open(file, 'r').read()
        for filter in filters:
            contents = filter.apply(contents)

        return contents



class Tokenize:

    #TODO: Make linux-worthy
    # if platform.system() == 'Darwin' and not cindex.Config.loaded:
    #    cindex.Config.set_library_file(Config.config['Clang']['library_file'])


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
    def tokensToText(tokens, ignore_comments = False):
        tokens_to_process = tokens
        if ignore_comments:
            tokens_to_process = list([x for x in tokens if str(x.kind) != "TokenKind.COMMENT"])
        tokenStrings = map(lambda x: Tokenize.trainingRepresentative(x), tokens_to_process)
        return " ".join(tokenStrings)

    @staticmethod
    def trainingRepresentative(token):
        txt = token.spelling
        if txt[0] == "\"" and txt[-1] == "\"":
            return "cidSL"
        elif is_number(txt):
            return "cidNL"
        else:
            return txt


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

    @staticmethod
    def get_tu(fn_str):
        if os.path.isfile("libclang-3.9.so.1"): #fix for Graham
            lib = os.getcwd()+"libclang-3.9.so.1"
            print("Setting library to: "+lib)
            cindex.Config.set_library_file(lib)
        else:
            print("Setting library to: "+find_library('clang'))
            cindex.Config.set_library_file(find_library('clang'))
        idx = cindex.Index.create()
        filename = 'tmp.c'
        return idx.parse(filename, unsaved_files=[(filename, fn_str)],
                         args=['-std=c++11'], options=0)



        

    