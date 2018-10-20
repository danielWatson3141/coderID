package Round1A;

import java.io.*;
import java.util.*;

public class ProblemA {
	
	public static int countOccurrences(String haystack, char needle)
	{
	    int count = 0;
	    for (int i=0; i < haystack.length(); i++)
	    {
	        if (haystack.charAt(i) == needle)
	        {
	             count++;
	        }
	    }
	    return count;
	}
	
  private static String solve(Scanner in){
  	int n = in.nextInt();
  	int l = in.nextInt();
  	LinkedHashSet<Long> e = new LinkedHashSet<Long>();
  	LinkedHashSet<Long> d = new LinkedHashSet<Long>();
  	for(int i=0; i<n; i++){
  		String s = in.next();
  		e.add(Long.parseLong(s,2));
  	}
  	for(int i=0; i<n; i++){
  		String s = in.next();
  		d.add(Long.parseLong(s,2));
  	}
  	long max = (long)(Math.pow(2, l));
  	long min = l+1;
  	for(long i=0; i<max; i++){
  		LinkedHashSet<Long> r = new LinkedHashSet<Long>();
  		for(long nl : e){
  			r.add(nl^i);
  		}
  		r.removeAll(d);
  		if(r.size()==0){
  			String s1 = Long.toBinaryString(i);
  			int aux = countOccurrences(s1,'1');
  			if(aux<min)
  				min=aux;
  		}
  	}
  	if(min==l+1) return "NOT POSSIBLE";
  	return "" + min;
  }

  public static void main(String[] args) {
  	String file = "Round1A\\ProblemAsmall";
  	try{
  		System.out.println(file);
  		Scanner in = new Scanner(new File(file + ".in"));
  		PrintWriter out = new PrintWriter(new File(file + ".out"));
  		int T = in.nextInt(); in.nextLine();
  		for (int i = 1; i <= T; i++) {
  			String s = "Case #" + i + ": " + ProblemA.solve(in);
  			out.println(s);
  			System.out.println(s);
  		}
  		out.close();
  	}catch(Exception e){ e.printStackTrace(); }
  }
}