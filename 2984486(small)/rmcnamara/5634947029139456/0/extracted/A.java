import java.io.File;
import java.io.FileInputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;


public class A {
	public static void main( String[] args ) throws Exception{
		System.setIn(new FileInputStream("asmall.in"));
		System.setOut(new PrintStream(new File("asmall.out")));
		
		Scanner in = new Scanner(System.in);
		
		int t = in.nextInt();
		for ( int caseno = 1; caseno <= t; caseno++ ){
			ArrayList<String> wall = new ArrayList<String>();
			int n = in.nextInt();
			int l = in.nextInt();
			//todo kill line
			for ( int i = 0; i < n; i++ ){
				wall.add(in.next());
			}
			
			HashSet<String> dev = new HashSet<String>();
			
			//todo kill line
			for ( int i = 0; i < n; i++ ){
				dev.add(in.next());
			}
			//System.out.println("hel");
			////System.out.println(dev);
			//System.out.println(wall);
			
			int min = Integer.MAX_VALUE;
			String init = dev.iterator().next();
			for ( int i = 0;i < n; i++ ){
				// attempt to match with 
				HashSet<Integer> flips = new HashSet<Integer>();
				String out = wall.get(i);
				for ( int j = 0; j < out.length(); j++ ){
					if ( out.charAt(j) != init.charAt(j) ){
						flips.add(j);
					}
				}
				
				HashSet<String> wallflip = new HashSet<String>();
				for ( String s : wall ){
					String newString = "";
					for ( int j = 0; j < s.length(); j++ ){
						char c = s.charAt(j);
						if ( flips.contains(j)){
							c = (c == '0')?'1':'0';
						}
						newString += c;
					}
					wallflip.add(newString);
				}
				boolean valid = true;
				
				for ( String s : wallflip ){
					if( !dev.contains(s)){
						valid = false;
					}
				}
				if ( valid ){
					min = Math.min(flips.size(), min);
				}	
			}
			
			String ret = "";
			if ( min == Integer.MAX_VALUE ){
				ret = "NOT POSSIBLE" ;
				
			}
			else{
				ret += min;
			}
			
			System.out.println("Case #" + caseno + ": " + ret);
			
		}
		
	}
}
