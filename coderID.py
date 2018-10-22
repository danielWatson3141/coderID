from cmd import Cmd
import ProfileSet
#from FeatureSet import FeatureSet
import pickle
import os.path

class MyPrompt(Cmd):

    def do_init(self, filePath):
        """Initialize profile set. non-existent file will create new  args: filePath"""
        if filePath == '':
            filePath =  'c:\swAuthors\default.ps'

        if os.path.isfile(filePath) or not os.path.exists(filePath):
            self.ps=ProfileSet.ProfileSet(filePath)
        else:
            print("Please supply a path to either an existing file or where you want the new file to be")

        self.homeFilePath =filePath

        for file in ProfileSet.ProfileSet.listdir_fullpath(os.path.dirname(self.homeFilePath)):
            if(file[len(file)-1]=='!'):
                self.do_addAuthors(file)

        

    def do_addAuthors(self, filePath):
        """Add data from a new author directory, Duplicate Authors will be merged"""
        if len(filePath)==0 :
            print("Must supply a filePath")
        else:
            print("Adding...")
            if os.path.isdir(filePath):
                self.ps.addAuthorsDir(filePath)
            else:
                print("directoryNotFound")
    
    def addOne(self, authorName):
        """Add one author from a file"""
        self.ps.addAuthor(authorName)

    def do_merge(self, other):
        """Merge another profile set into the current one"""
        if other is None:
            print("Must supply a filePath")
        else:
            print("Merging")
            self.ps.merge(ProfileSet.ProfileSet(other))
    
    def do_save(self, file=None):
        """Saves state, overwriting given file"""
        if file == None:
            self.homeFilePath
        
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
        print("Collecting...")
        self.ps.detectFeatures()
        self.featuresDetected = True
    
    def do_getFeatures(self, args):
        if(self.featuresDetected):
           print(self.ps.toFeatureMatrix())
        else:
            print("Must run featureDetect first")

    def do_displayFeatures(self, args):
        print("Features:")
        print(self.ps)
    def do_displayAuthors(self, args):
        print("Authors:")
        for author in self.ps.authors.values():
            print(author)
            

        


if __name__ == '__main__':
    prompt = MyPrompt()
    prompt.prompt = 'coderID> '
    prompt.cmdloop('Starting prompt...')