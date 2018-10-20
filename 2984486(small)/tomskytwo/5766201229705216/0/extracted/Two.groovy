package codejam2

import groovy.transform.Canonical;

def input = new File("C:\\Users\\Tom\\Downloads\\B-small-attempt0.in")

def lineNum = 0
def numTestCases
def n
def curNode = 0
def testNum = 1
List<Node> nodes = new ArrayList<Node>()
PrintStream out = new PrintStream("2.out")
input.eachLine { line ->
	if (!lineNum) {
		numTestCases = line as int
	}
	else if (lineNum == 1) {
		n = line as int
		nodes = new ArrayList<Node>(n)
		
		n.times {
			nodes << new Node(it + 1)
		}
	}
	else if (curNode < n){
		def pieces = line.split("\\s+")
		def node1 = pieces[0] as int
		def node2 = pieces[1] as int
		nodes.each {
			if (it.num == node1 && it.num < node2) {
				it.children << nodes.find{it.num == node2}
			}
			else if (it.num == node2 && it.num < node1) {
				it.children << nodes.find{it.num == node1}
			}
		}
		curNode++
		if (curNode == n-1) {
			def r
			if (nodes.size()) {
				r = nodes[0]
			}
			def t = new Two1(r, n)
			out.println "Case #${testNum++}: $t.answer"
			curNode = 0
			lineNum = 0
		}
	}
	lineNum++
}
out.close()
@Canonical
class Two1 {
	Node r
	int totalNodes
	def getAnswer() {
		if (!r) {
			return 0
		}
		def answer = Math.max(recursiveFindAnswer(r), 1)
		(totalNodes - (((((answer / 2) as int) * 2) + 1))) / 2 as int
	}
	def recursiveFindAnswer(Node r) {
		if (r.children.size() == 2) {
			Math.min(recursiveFindAnswer(r.children[0]), recursiveFindAnswer(r.children[1]))
		}
		else {
			r.num
		}
	}
}

@Canonical
class Node {
	def num
	List<Node> children = new ArrayList<Node>()
}