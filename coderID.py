from cmd import Cmd
from ProfileSet import *
import pickle

class MyPrompt(Cmd):

    def do_init(self, args):
        """Initialize profile set. non-existent file will create new  args: filePath"""
        if len(args)==0 :
            print("Must supply a filePath")
        else:
            self.ps=ProfileSet(args[0])

    def do_add(self, args):
        """Add data from a new directory"""
        if len(args)==0 :
            print("Must supply a filePath")
        elif len(args==1):
            print("Adding a directory")
            self.ps.merge(ProfileSet(args[0]))
        else:
            print("Adding all")
            for author in args:
                self.ps.addAuthor(author)

    def do_merge(self, other):
        """Merge another profile set into the current one"""
        if other is None:
            print("Must supply a filePath")
        else:
            print("Merging")
            self.ps.merge(ProfileSet(other))
    
    def do_save(self, file):
        """Saves state, overwriting given file"""
        print("saving...")
        if(file is None):
            file = self.ps.fileSource
        pickler = pickle.Pickler(file, pickle.HIGHEST_PROTOCOL)
        pickler.dump(self.ps)
        print("Saved to "+file)


    def do_quit(self, args):
        """quits the program WITHOUT SAVING"""
        print("Quitting.")
        raise SystemExit


if __name__ == '__main__':
    prompt = MyPrompt()
    prompt.prompt = 'coderID> '
    prompt.cmdloop('Starting prompt...')