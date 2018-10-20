package codejam2

import groovy.transform.Canonical;

def input = new File("C:\\Users\\Tom\\Downloads\\C-small-attempt0 (1).in")

def lineNum = 0
def numTestCases
def n
def integers
def testCase = 1
PrintStream out = new PrintStream("3.out")
input.eachLine { line ->
	if (!lineNum) {
		numTestCases = line as int
	}
	else if (lineNum == 1) {
		n = line as int	
	}
	else if (lineNum == 2) {
		integers = line.split("\\s+")
		def t = new ProperShuffle(n, integers)
		out.println "Case #${testCase++}: $t.answer"
		lineNum = 0
	}
	lineNum++
}
out.close()
@Canonical
class ProperShuffle {
	int n
	String[] integers
	
	def getAnswer() {
		double average = findAverage() 
		int numCloserToAverage = 0
		int numCloserToCurrent = 0
		integers.eachWithIndex { integer, index ->
			double amountAwayFromAverage = Math.abs((integer as double) - average)
			double amountAwayFromIndex = Math.abs((integer as double) - index)
			if (amountAwayFromAverage > amountAwayFromIndex) {
				numCloserToAverage++
				
			}
			else {
				numCloserToCurrent++
			}
		}
		if (numCloserToAverage > numCloserToCurrent) {
			"BAD"	
			
		}
		else {
			"GOOD"
		}
	}
	
	def findAverage() {
		double average = 0
		integers.each {
			average+= (it as double) / n
		}
		average
	}
}