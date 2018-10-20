from getopt          import getopt, GetoptError
from multiprocessing import Pool, Queue, Manager
from os              import getpid
from sys             import argv, stderr
from time            import strftime, time
 
class GCJ:
    """
    Wrapper for a lot of functionality that is useful when trying to solve a 
    Google Code jam question.

    For the case of Problem A of the 2008 Qualification Round, example code
    would be:
    
    def preprocess():
        # Tasks to do before the input data is downloaded.
        
    def parse(inFile):
        N = int(inFile.readline())
        searchEngines = [inFile.readline().strip() for z in xrange(N)]
        Q = int(inFile.readline())
        queries = [inFile.readline().strip() for z in xrange(Q)]
        return [searchEngines, queries]

    def solve([searchEngines, queries]):
        N = len(searchEngines)
        dict = {searchEngines[i]: i for i in xrange(N)}
        qs = [dict[k] for k in queries]
        used = [False] * N
        numberused = 0
        resets = 0
        for k in qs:
            if not used[k]:
               if numberused == N - 1:
                  resets += 1
                  numberused = 0
                  used = [False] * N
               used[k] = True
               numberused += 1
        return str(resets)

    if __name__ == "__main__":
        from GCJ import GCJ
        GCJ('a', solve, parse, preprocess, "c:\\temp").run()

    This would give a script with command line options -t, -s, -l, -r, -v, -m:
      -t (default)
        input file  = "c:\\temp\\a-test-0.in"
        output file = "c:\\temp\\a-test-0.out"
        error file  = "c:\\temp\\a-test-0.err"
        (the directory "c:\\temp" and the character "a" at the start of the
         filenames come from arguments to GCJ in the source code and 0 is the default for
         the --id argument)
      -s
        input file  = "c:\\temp\\a-small-0.in"
        output file = "c:\\temp\\a-small-0.out"
        error file  = "c:\\temp\\a-small-0.err"
      -l
        input file  = "c:\\temp\\a-large-0.in"
        output file = "c:\\temp\\a-large-0.out"
        error file  = "c:\\temp\\a-large-0.err"
      --middle
        input file  = "c:\\temp\\a-middle-0.in"
        output file = "c:\\temp\\a-middle-0.out"
        error file  = "c:\\temp\\a-middle-0.err"
      -r (default for -s and -l)
        read the input file. Read the first line to get the number of cases N
        included in the input. Run parse(infile) N times to get N case objects,
        and then run solve(case object) on each of them. If parse is not given run
        solve(infile) N times.
        Output the strings 
        returned from solve, prepended with "Case #<case #>: ". Put output in 
        output file, overwriting it if it exists.
      -v (default for -t (which is default))
        Do the same as above, but check if the contents of the output file now
        are as they would be otherwise. If it is, say "OK". Otherwise, output all
        differences, and write the output into the error file, overwriting it if
        it exists.
      -m <number>
        Set up a pool of <number> worker threads, and put all of the problems
        (along with their problem numbers) on a queue. Each thread, when finished
        with a problem, will take the next case from the queue.
      -i <number>  
        The id number. Default is 0. 
      -p
        Run preprocess()
        
"""

    def __init__(self,  question, solver, reader=None, pre=None, path="", datatype="test", job="validate"):  #"/Users/phi/Dropbox/CodeJam/Current"):
            
        self.reader = reader
        self.solver = solver
        self.question = question
        print("GCJ Wrapper initiated.", file=stderr)
        print("Reading command line arguments", file=stderr)
        try:
            opts, args = getopt(argv[1:],
                                "vstlm:i:p",
                                ["validate", "small", "test", "large", "middle", "multi=","id","preprocess"])
        except GetoptError as err:
            print(str(err))
            exit(2)
        #datatype = "test"
        idnr = "0"
        self.job = job
        self.multi = 1
        for o,a in opts:
            if o in ("-t", "--test"):
                datatype = "test"
                self.job = "validate"
            elif o in ("-s", "--small"):
                datatype = "small"
                self.job = "run"
            elif o in ("-l", "--large"):
                datatype = "large"
                self.job = "run"
            elif o == "--middle":
                datatype = "middle"
                self.job = "run"
            elif o in ("-v", "--validate"):
                self.job = "validate"
            elif o in ("-m", "--multi"):
                self.multi = int(a)
            elif o in ("-i", "--id"):
                idnr = a
            elif o in ("-p", "-preprocess"):
                if pre:
                    print("Preprocessing ...")
                    pre()
                else:
                    print("No preprocess given.")
                
        filepref = path  + question + "-" + datatype + "-" + idnr
        self.infile = filepref + ".in"
        self.outfile = filepref + ".out"
        self.errfile = filepref + ".err"
        if (self.job == "run"):
            print("Creating " + self.outfile + " from " + self.infile, file=stderr)
        else:
            print("Testing that " + self.infile + " would create " + self.outfile, file=stderr)
            print("Storing output in " + self.errfile + " otherwise", file=stderr)
 
    def run(self):
        starttime = time()
        if (self.multi == 1):
            if self.reader == None:
                answers = self.read_and_process()
            else:
                data = self.read()
                answers = self.process(data)
        else:
            if self.reader == None:
                answers = self.read_and_multiprocess()
            else:
                data = self.read()
                answers = self.multiprocess(data, self.multi)
        text = "".join(["Case #%d: %s\n" % (k + 1, answers[k]) for k in range(len(answers))])
        if False:
            print(text)
        self.output(text, time()-starttime)
 
    def read(self):
        inh = open(self.infile, 'r')
        N = int(inh.readline())
        data = [self.reader(inh) for k in range(N)]
        inh.close()
        return data
        
    def read_and_process(self):
        inh = open(self.infile, 'r')
        N = int(inh.readline())
        answers = [None] * N
        for k in range(N):
            print("%s:Working on Case %d" % (strftime("%X"), k + 1))
            answers[k] = self.solver(inh)
            print("%s:Dealt with Case %d: %s" % (strftime("%X"), k + 1, answers[k]))
        inh.close()
        return answers
        
        
        
        
    def process(self, data):
        N = len(data)
        answers = [None] * N
        for k in range(N):
            print("%s:Working on Case %d" % (strftime("%X"), k + 1))
            answers[k] = self.solver(data[k])
            print("%s:Dealt with Case %d: %s" % (strftime("%X"), k + 1, answers[k]))
        return answers
 
    def multiprocess(self, data, numprocs):
        N = len(data)
        manager = Manager()
        queue = manager.Queue()
        data = [[k + 1, data[k], self.solver, queue] for k in range(N)]
 
        pool = Pool(numprocs)
        pool.map_async(multiCase, data, 1)
 
        answers = [None] * N
        workerPids = []
        workingOn = []
        numTodo = N
        numDoing = 0
        numDone = 0
 
        for k in range(2 * N):
            report = queue.get()
            pid = report[0]
            if pid in workerPids:
                idx = workerPids.index(pid)
            else:
                idx = len(workerPids)
                workerPids += [pid]
                workingOn += [None]
            if report[1] == 0:
                workingOn[idx] = report[2]
                numTodo -= 1
                numDoing += 1
            else:
                workingOn[idx] = None
                answers[report[2] - 1] = report[3]
                numDoing -= 1
                numDone += 1
                print("%s:Dealt with Case %d: %s" % (strftime("%X"), numDone, answers[report[2]-1]))
            
            print("{}: {} done  {} pending  {} todo | {}".format(strftime("%X"), clean(numDone), clean(numDoing), 
                                                                  clean(numTodo), " ".join([clean(z) for z in workingOn])))   
            #print("%s:done %s now %s todo %s | %s" % (strftime("%X"), clean(numDone), clean(numDoing), 
#                                                      clean(numTodo), " ".join([clean(z) for z in workingOn])))
        return answers
 
    def output(self, text, duration):
        if self.job == "run":
            open(self.outfile, 'w').write(text)
        else:
            if duration and duration > 5:
                print("%.1fsec" % duration)
            text2 = open(self.outfile, 'r').read()
            if (text.strip() == text2.strip()):
                print("OK")
            else:
                print("Not OK")
                open(self.errfile, 'w').write(text)
                print("new output written to %s" % self.errfile)
                print("Differences:")
                text = text.strip().split("\n")
                text2 = text2.strip().split("\n")
                for k in range(min(len(text), len(text2))):
                    if text[k] != text2[k]:
                        print("Line %d: '%s' vs '%s'" % (k + 1, text[k], text2[k]))
                if len(text) != len(text2):
                    print("Files have different number of lines: %d vs %d" % (len(text), len(text2)))



    def isset(a, bit): return ((a >> bit) & 1) > 0
    def readint(file): return int(file.readline().strip())
    def readfloat(file): return float(file.readline().strip())
    def readstr(file): return file.readline().strip()
    def readstrs(file): return file.readline().strip().split()
    #def readarray(N, foo): return [foo() for i in range(N)]
    def readints(file): return map(int,file.readline().strip().split())
    def readfloats(file): return map(float,file.readline().strip().split())
    def readlist(foo, file): return list(map(foo, file.readline().strip().split()))
    def readintarray(file): return [int(i) for i in file.readline().strip().split()]
    def readfloatarray(file): return [float(i) for i in file.readline().strip().split()]
    def readarray(foo,file): return [foo(i) for i in file.readline().strip().split()]


def clean(r):
    return "   " if (r == None) else ("%3d" % r)
 
def multiCase(inputList):
    [caseNumber, case, solver, queue] = inputList
    queue.put([getpid(), 0, caseNumber])
    answer = solver(case)
    queue.put([getpid(), 1, caseNumber, answer])
 
