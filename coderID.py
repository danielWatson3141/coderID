from cmd import Cmd
import ProfileSet
#from FeatureSet import FeatureSet
import pickle
import os.path

class MyPrompt(Cmd):

    def do_init(self, args):
        """Initialize profile set. non-existent file will create new  args: filePath"""
        if len(args)==0 :
            print("Must supply a filePath")
        else:
            self.ps=ProfileSet.ProfileSet(args[0])

    def do_addAuthors(self, args):
        """Add data from a new author directory, Duplicate Authors will be merged"""
        if len(args)==0 :
            print("Must supply a filePath")
        else:
            print("Adding...")
            for arg in args:
                if os.path.isdir(arg):
                    self.ps.addAuthorsDir(arg)
                else:
                    print("directoryNotFound")
    
    def addOne(self, args):
        """Add one author from a file"""
        self.ps.addAuthor(args[0])

    def do_merge(self, other):
        """Merge another profile set into the current one"""
        if other is None:
            print("Must supply a filePath")
        else:
            print("Merging")
            self.ps.merge(ProfileSet.ProfileSet(other))
    
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

    def do_featureDetect(self, args):
        """runs feature detection"""
        self.ps.detectFeatures()
        self.featuresDetected = True
    
    def do_getFeatures(self, args):
        if(self.featuresDetected):
            return self.ps.toFeatureMatrix()
        else:
            print("Must run featureDetect first")

    def do_display(self, args):
        print("Features:")
        print(self.ps)
        
        print("Authors:")
        for author in self.ps.authors:
            print(author)
            

        


if __name__ == '__main__':
    prompt = MyPrompt()
    prompt.prompt = 'coderID> '
    prompt.cmdloop('Starting prompt...')