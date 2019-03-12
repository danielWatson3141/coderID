import configparser
import pprint
from ast import literal_eval

class Config:
    # stores the loaded config for easy access in any other module
    cfg_file = 'config.ini'
    config = configparser.ConfigParser()
    config.read(cfg_file)

    @staticmethod
    def get_val(value):
        val = value.strip()

        # integers
        if val.isnumeric():
            return int(val)

        # booleans
        bool_vals = ('True', 'False')
        if val in bool_vals:
            return val == bool_vals[0]

        # fractions
        parts = val.split("/")
        if len(parts) == 2 and all(i.isdigit() for i in parts):
            return int(parts[0]) / int(parts[1])

        # all other data types
        try:  # except strings
            return literal_eval(val)
        except:
            return val

for x in Config.config.items('Feature Selection'):
    print(x)