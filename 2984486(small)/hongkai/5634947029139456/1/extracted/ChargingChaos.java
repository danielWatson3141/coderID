import java.util.*;
import java.io.*;

public class ChargingChaos {
	public static void main(String[] args)throws IOException {
		Scanner kb = new Scanner(System.in);
		PrintWriter out = new PrintWriter(new File("chaos.out"));
		int cases = kb.nextInt();
		
		for(int i=1; i <= cases; i++) {
			int outlets = kb.nextInt();
			int len = kb.nextInt();
			
			MyList[] flow = new MyList[outlets];
			MyList[] devices = new MyList[outlets];
			for(int j=0; j < outlets; j++) 
				flow[j] = new MyList(kb.next());
			for(int j=0; j < outlets; j++) 
				devices[j] = new MyList(kb.next());
			Arrays.sort(flow);
			Arrays.sort(devices);
			int maxDist = 10000;
			for(int j=0; j < outlets; j++) {
				int dist = MyList.dist(devices[0], flow[j]);
				if(dist >= maxDist)
					continue;
				for(int k=0; k < len; k++)
					if(flow[j].outlet[k] != devices[0].outlet[k])
						for(MyList ml: flow)
							ml.flip(k);
				Arrays.sort(flow);
				boolean eq = true;
				for(int n = 0; n < outlets; n++) {
					if(devices[n].compareTo(flow[n]) != 0){
						eq = false;
						break;
					}
				}
				if(eq) {
					maxDist = dist;
				}
				for(MyList ml: flow)
					ml.reset();
				Arrays.sort(flow);
			}
			
			String ans = "NOT POSSIBLE";
			if(maxDist < 1000)
				ans = ""+maxDist;
			out.println("Case #" + i + ": "+ans);
			
		}
		out.close();
	}
}

class MyList implements Comparable<MyList> {
	public boolean[] outlet;
	public String orig;
	
	public MyList(String orig){
		// this.outlet = outlet;
		this.orig = orig;
		int size = orig.length();
		outlet = new boolean[size];
		reset();/*
		for(int i=0; i < size; i++) {
			outlet[i] = orig.charAt(i) == '1';
		} */
	}
	
	public int compareTo(MyList other) {
		for(int i=0; i < outlet.length; i++) {
			if(other.outlet[i] && !outlet[i])
				return 1;
			if(!other.outlet[i] && outlet[i])
				return -1;
		}
		return 0;
	}
	public void flip(int ind) {
		outlet[ind] = !outlet[ind];
	}
	public void reset(){
		for(int i=0; i < orig.length(); i++) {
			outlet[i] = orig.charAt(i) == '1';
		}
	}
	public static int dist(MyList a, MyList b){
		int diff = 0;
		for(int i=0; i < a.orig.length(); i++) {
			if(a.orig.charAt(i) != b.orig.charAt(i))
				diff++;
		}
		return diff;
	}
}