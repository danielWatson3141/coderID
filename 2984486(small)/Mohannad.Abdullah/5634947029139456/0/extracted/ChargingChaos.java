import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;


public class ChargingChaos {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("input"));

		
		int t = Integer.parseInt(br.readLine());

		int kase = 0;
		
		while(kase++ < t) {
			String [] temp = br.readLine().split(" ");
			int n = Integer.parseInt(temp[0]);
			int l = Integer.parseInt(temp[1]);
			
			String [] outlets = br.readLine().split(" ");
			String [] devices = br.readLine().split(" ");
			
			Arrays.sort(outlets);
			Arrays.sort(devices);
			
			HashSet<String> set = new HashSet<String>();
			
			String goal = convert(devices);
			Queue<String []> q1 = new LinkedList<String[]>();
			Queue<String []> q2 = new LinkedList<String[]>();
			
			String start = convert(outlets);
			set.add(start);
			q1.add(outlets);
			
			int levels = -1;
			boolean gameFinished = false;
			
			while (!gameFinished && !q1.isEmpty()) {
				levels++;
//				System.out.println(levels);
				while (!gameFinished && !q1.isEmpty()) {
					String [] current = q1.poll();
					String form = convert(current);
//					System.out.println("\t" + form + " q1.size" + q1.size());
					if (form.equals(goal)) {
						gameFinished = true;
						break;
					}
					
					for (int i = 0; i < current[0].length(); i++) {
						String [] flipped = flip(current, i);
						Arrays.sort(flipped);
						String flippedForm = convert(flipped);
						
//						System.out.println("\t\tFlipping " + i + " " + flippedForm);
						if (set.add(flippedForm)) {
//							System.out.println("\t\t\t" + form + " --> " + flippedForm);
							q2.add(flipped);
						}
					}
				}
				Queue<String []> tempQueue = q1;
				q1 = q2;
				q2 = tempQueue;
			}
//			System.out.println(set.size());
			System.out.print("Case #" + kase + ": ");
			if (gameFinished) {
				System.out.println(levels);
			}
			else {
				System.out.println("NOT POSSIBLE");
			}
		}

	}

	private static String[] flip(String[] current, int i) {
		String [] copy = new String [current.length];
		
		for (int j = 0; j < copy.length; j++) {
			char []outlet = current[j].toCharArray();
			outlet[i] = outlet[i] == '1' ? '0' : '1';
			copy[j] = new String(outlet);
//			System.out.println("\t" + current[j] + " --> " + copy[j]);
		}
		return copy;
	}

	private static String convert(String[] devices) {
		StringBuffer buf = new StringBuffer(devices.length * devices[0].length());
		for (String string : devices) {
			buf.append(string);
		}
		return buf.toString();
	}

}
