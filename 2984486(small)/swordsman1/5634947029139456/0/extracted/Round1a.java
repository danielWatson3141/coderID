package gcj2014;

import java.io.File;
import java.io.IOException;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Set;

import com.google.common.base.Charsets;
import com.google.common.base.Joiner;
import com.google.common.base.Splitter;
import com.google.common.collect.Lists;
import com.google.common.collect.Sets;
import com.google.common.io.Files;

public class Round1a {
	private static final String FILE_READ = System.getProperty("user.dir") + "/src/data/1A/A-small-attempt1.in";
	private static final String NOT_POSSIBLE = "NOT POSSIBLE";
	private static final boolean DEBUG = false;
	
	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		List<String> lines = Files.readLines(new File(FILE_READ), Charsets.UTF_8);
		int caseCount = 1;
		
		for (int i = 1; i < lines.size(); i += 3) {
			int size = Integer.valueOf(Lists.newArrayList(Splitter.on(' ').split(lines.get(i))).get(1));
			
			Set<String> initial = Sets.newHashSet(Splitter.on(' ').split(lines.get(i + 1)));
			Set<String> required = Sets.newHashSet(Splitter.on(' ').split(lines.get(i + 2)));
			
			int minSwitches = findMinSwitch(initial, required, size);
			System.out.println("Case #" + caseCount++ + ": " + (minSwitches == -1 ? NOT_POSSIBLE : minSwitches));
			if (DEBUG) {System.out.println("----------");}
		}
	}

	
	public static int findMinSwitch(Set<String> initial, Set<String> required, int size) {
		if (DEBUG) {
			System.out.println(size);
			System.out.println(initial);
			System.out.println(required);
		}
		
		
		if (initial.equals(required)) {
			return 0;
		}
		
		Set<Set<String>> switchesTried = Sets.newHashSet();
		Queue<QueueElement> queue = new LinkedList<QueueElement>();
		
		for (int i = 0; i < size; i++) {
			Set<String> next = flipIthBitOutlets(initial, i);
			
			if (next.equals(required)) {
				return 1;
			}
			
			switchesTried.add(next);
			queue.add(new QueueElement(next, 1));
		}
		
		while (!queue.isEmpty()) {
			QueueElement qe = queue.poll();
			
			for (int i = 0; i < size; i++) {
				Set<String> next = flipIthBitOutlets(qe.next, i);
				if (next.equals(required)) {
					return qe.count + 1;
				}
				
				if (switchesTried.contains(next)) {continue;}
				queue.add(new QueueElement(next, qe.count + 1));
				switchesTried.add(next);
			}
		}
		
		return -1;
	}
	
	public static Set<String> flipIthBitOutlets(Set<String> initial, int i){
		initial = Sets.newHashSet(initial);
		Set<String> result = Sets.newHashSet();
		
		for (String outlet: initial) {
			result.add(flipIthBit(outlet, i));
		}
		return result;
	}
	
	public static String flipIthBit(String outlet, int i) {
		char[] outletChars = outlet.toCharArray();
		if (outletChars[i] == '0') {outletChars[i] = '1';}
		else if (outletChars[i] == '1') {outletChars[i] = '0';}

		return String.valueOf(outletChars);
	}
	
	static class QueueElement {
		public QueueElement(Set<String> next, int count) {
			this.next = next;
			this.count = count;
		}
		
		Set<String> next;
		int count = 0;
	}
}
