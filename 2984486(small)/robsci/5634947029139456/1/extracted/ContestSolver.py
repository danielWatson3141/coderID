class ContestSolver:

	def __init__(self, solver, splitlines=True, specifycasesize=False, nosinglelists=True):
		self.solver = solver
		self.nosinglelists = nosinglelists
		self.splitlines = splitlines
		self.specifycasesize = specifycasesize

	def readInput(self, filename):
		# get input from filename - stores in self.data
		f = open(filename + ".in", 'r')
		lines = f.readlines()
		f.close()
		self.data = []
		for line in lines:
			if self.splitlines:
				self.data.append(line.split())
			else:
				self.data.append([line.rstrip('\n')])

	def parseInput(self, filename=None):
		# parses self.data to self.input
		# interprets first line as number of cases
		# splits remainder of self.input into a list of cases
		if (filename):
			self.readInput(filename)
		self.numcases = int(self.data[0][0])
		self.input = []
		currindex = 1
		for icase in range(self.numcases):
			case = []
			if self.specifycasesize:
				inputs = int(self.data[currindex][0])
				case.append(self.data[currindex])
				currindex += 1
			else:
				inputs = int((len(self.data) - 1) / self.numcases)
			case += self.data[currindex:currindex + inputs]
			self.input.append(case)
			currindex += inputs

	def integerInputs(self):
		# converts all input values to ints
		for icase, case in enumerate(self.input):
			for iline, line in enumerate(case):
				if (self.nosinglelists and len(line) == 1):
					self.input[icase][iline] = int(line[0])
				else:
					for ipart, part in enumerate(line):
						self.input[icase][iline][ipart] = int(part)
						
	def floatInputs(self):
		# converts all input values to floats
		for icase, case in enumerate(self.input):
			for iline, line in enumerate(case):
				if (self.nosinglelists and len(line) == 1):
					self.input[icase][iline] = float(line[0])
				else:
					for ipart, part in enumerate(line):
						self.input[icase][iline][ipart] = float(part)

	def formatOutput(self):
		# returns a string to be written to a file
		outstring = ""
		for icase, case in enumerate(self.output, start=1):
			outstring += "Case #" + str(icase) + ": "
			for part in case:
				outstring += str(part) + " "
			outstring += "\n"
		#print outstring
		return outstring

	def writeOutput(self, filename):
		f = open(filename + ".out", 'w')
		f.write(self.formatOutput())
		f.close()

	def run(self, filename, ints=False, floats=False, test=False, watch=False):
		self.parseInput(filename)
		if ints:
			self.integerInputs()
		elif floats:
			self.floatInputs()
		self.output = []
		for icase, case in enumerate(self.input, start=1):
			self.output.append(self.solver(case))
			if watch:
				print icase, self.output[-1]
		if test:
			print self.formatOutput()
		self.writeOutput(filename)
