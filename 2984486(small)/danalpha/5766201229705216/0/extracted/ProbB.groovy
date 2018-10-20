import groovy.lang.Closure;

import java.util.List;

class ProbB
{
	List<Node> vertices = []
	
	public static void main(String[] argv)
	{
		String filename = argv[0]
		String justFile = filename.substring(filename.lastIndexOf('/') + 1, filename.lastIndexOf('.'))
		//String outDir = '/Users/dullivan/gcj/'
		String outDir = filename.substring(0, filename.lastIndexOf('/')+1)
		Scanner scanner
		Writer outWriter
	
		try{
			scanner = new Scanner(new FileInputStream(filename))
			outWriter = new FileWriter(outDir + justFile + '.out')
			
			int numCases = scanner.nextInt()
			
			numCases.times { caseIndex ->
				
				ProbB prob = new ProbB()
				
				
				
//				N.times {
//					
//				}
				int N = scanner.nextInt()
//				List list = []
				
				N.times {
					prob.vertices.add(new Node(index:it))
				}
				
				(N-1).times {
					int A = scanner.nextInt() - 1
					int B = scanner.nextInt() - 1
					
					println "A " + A
					println "B " + B
					
					prob.vertices[A].neighbors.add(prob.vertices[B])
					prob.vertices[B].neighbors.add(prob.vertices[A])
				}
				
				
				
				
//				println(prob.vertices)
//				prob.vertices.each{
//					println it.neighbors
//				}
				
				String answer = prob.solve()
				
				String caseString = 'Case #' + (caseIndex+1) + ': ' + answer
				println caseString
				outWriter.write(caseString)
				outWriter.write('\n')
			}
		} finally{
			scanner.close()
			outWriter.close()
		}
	}
	
	String solve()
	{
		int least = 1001
		
		vertices.each { v ->
			int canKeep = traverse(v, null)
			if(vertices.size()-canKeep < least)
			{
				least = vertices.size()-canKeep
			}
		}
		println "MEMO " + memo
		return least
	}
	
	Map<List, Integer> memo = [:]
	
	int traverse(Node n, Node parent)
	{
		println n
		List key = [n, parent]
		if(memo[key] != null)
		{
			println "returning: " + memo[key] + " n: " + n + " parent: " + parent
			return memo[key]
		}
		
		List canKeeps = []
//		List nodeCounts = []
		
		int totalCanKeep = 1
//		int totalNodes = 1
		
		int children = parent == null ? n.neighbors.size() : n.neighbors.size() - 1 
		if(children >= 2)
		{
			n.neighbors.each { 
				if(it != parent)
				{
					int result = traverse(it, n)
					canKeeps.add(result)
				}
			}
			
			canKeeps.sort()
			
			totalCanKeep += canKeeps[canKeeps.size()-1] + canKeeps[canKeeps.size()-2]
		}
			
		
		println "adding: " + totalCanKeep + " n: " + n + " parent: " + parent
		memo[key] = totalCanKeep
		
		return totalCanKeep
	}
	
	public static class Node
	{
		int index
		List<Node> neighbors = []
		
		def DFS(Closure op)
		{
			op.call(this)
			
			neighbors.each { 
				it.DFS(op)
			}	
		}
		
		def DFS2(Set<Node> found, Closure op)
		{
			if(!found.contains(this))
			{
				found.add(this)
				
				op.call(this)
				
				neighbors.each {
					it.DFS2(found, op)
				}
			}
		}
		
		def BFS(Closure op)
		{
			List<Node> stack = []
			
			stack.push(this)
			
			Node curNode
			
			while(!stack.isEmpty())
			{
				curNode = stack.pop()
				
				op.call(curNode)	
				
				curNode.neighbors.each {
					stack.push(it)
				}
			}
		}
		
		public String toString()
		{
			return index
		}
	}
	
	def binarySearch(key, imin, imax, increment, precision, Closure c)
	{
		def result
		// continue searching while [imin,imax] is not empty
		while (imax >= imin)
		{
			/* calculate the midpoint for roughly equal partition */
			def imid = imin + (imax - imin)/2

			def currentValue = c.call(imid)
			def diff = currentValue-key
			if((diff > (-1*precision)) && diff < (precision) )
			{
				return imid
			}
			// determine which subarray to search

			if (currentValue > key)
			{
				// change max index to search lower subarray
				imax = imid - increment;
			}
			else
			{
				// change min index to search upper subarray
				result = imid
				imin = imid + increment;
			}
		}
		// key not found
		//throw new RuntimeException("key not found")
		return result
	}
	
	def binaryLowest(key, imin, imax, increment, precision, Closure c)
	{
		def result
		// continue searching while [imin,imax] is not empty
		while (imax > imin)
		{
			/* calculate the midpoint for roughly equal partition */
			def imid = imin + (imax - imin)/2

			def currentValue = c.call(imid)
//			def diff = currentValue-key
//			if((diff > (-1*precision)) && diff < (precision) )
//			{
//				return imid
//			}
			// determine which subarray to search

			if (currentValue)
			{
				result = imid
				// change max index to search lower subarray
				imax = imid - increment;
			}
			else
			{
				// change min index to search upper subarray
				imin = imid + increment;
			}
		}
		// key not found
		//throw new RuntimeException("key not found")
		return result
	}
}
