package codejam2

import groovy.transform.Canonical;

def input = new File("C:\\Users\\Tom\\Downloads\\A-small-attempt0.in")

def lineNum = 0
def numTestCases
def n
def l
def testCase = 1
def currentFlows

def out = new PrintStream("1.out")
input.eachLine { line ->
	if (!lineNum) {
		numTestCases = line as int
	}
	else if (lineNum == 1) {
		def p = line.split("\\s+")
		n = p[0] as int
		l = p[1] as int
	}
	else if (lineNum == 2) {
		currentFlows = line.split("\\s+") as List
	}
	else if (lineNum == 3) {
		def requiredFlows = line.split("\\s+") as List
		def t = new ChargingChaos(n, l, currentFlows, requiredFlows)
		out.println "Case #${testCase++}: $t.answer"
		lineNum = 0
	}
	lineNum++
}
out.close()
@Canonical
class ChargingChaos {
	int n
	int l
	List<String> currentFlows
	List<String> requiredFlows
	def getAnswer() {
		requiredFlows.sort()
		int answer = Math.min(flip(currentFlows, 0, 0, true), flip(currentFlows, 0, 0, false))
		if (answer < Integer.MAX_VALUE) {
			answer
		}
		else {
			"NOT POSSIBLE"
		}
	}

	int flip(List<String> current, int i, int numFlips, boolean flipNext) {
		def flipped
		if (flipNext) {
			numFlips++
			flipped = []
			for (String c in current) {
				def sb = new StringBuilder(c)
				def curChar = sb.charAt(i) as String
				def newChar = (curChar == "1" ? '0' : '1') as char
				sb.setCharAt(i, newChar)
				flipped << sb.toString()
			}
		}
		else {
			flipped  = current
		}
		i++
		if (i == l) {
			if (new ArrayList<String>(flipped).sort() == requiredFlows) {
				return numFlips
			}
			else {
				return Integer.MAX_VALUE
			}
		}
		Math.min(flip(flipped, i, numFlips, true), flip(flipped, i, numFlips, false))
	}
}
class One1 {


	def getAnswer() {
		"test"
	}
}