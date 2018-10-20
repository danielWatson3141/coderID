import java.io.*;
import java.util.*;


public class Main{
	
	
	private static ArrayList<String> get(ArrayList<String> flows, char c, int index){
		ArrayList<String> result = new ArrayList<String>();
		for (String flow : flows)
			if (flow.charAt(index) == c)
				result.add(flow);
		return result;	
	}
	
	
	
	private static ArrayList<String> findFlippings(int n, int l, ArrayList<String> outlets, ArrayList<String> devices, int index){
		ArrayList<String> result = new ArrayList<String>();
		if (index == l){
			result.add("");
			return result;
		}

		ArrayList<String> outletOnes = get(outlets, '1', index);
		ArrayList<String> deviceOnes = get(devices, '1', index);
		ArrayList<String> outletZeros = get(outlets, '0', index);
		ArrayList<String> deviceZeros = get(devices, '0', index);
		
		
		if (outletOnes.size() == deviceZeros.size()){
			ArrayList<String> f1 = findFlippings(outletZeros.size(), l, outletZeros, deviceOnes, index+1);
			ArrayList<String> f0 = findFlippings(outletOnes.size(), l, outletOnes, deviceZeros, index+1);
			
			f1.retainAll(f0);
			for (String s : f1)
				result.add("1" + s);	
		}
		
		if (outletOnes.size() == deviceOnes.size()){
			ArrayList<String> f1 = findFlippings(outletOnes.size(), l, outletOnes, deviceOnes, index+1);
			ArrayList<String> f0 = findFlippings(outletZeros.size(), l, outletZeros, deviceZeros, index+1);
			
			f1.retainAll(f0);
			
			for (String s : f1)
				result.add("0" + s);	
		}

		return result;
	}
	
	
	private static int countOnes(String s){
		int count = 0;
		for (int i = 0; i < s.length(); ++i)
			if (s.charAt(i) == '1')
				++count;
		return count;
	}
	
	public static void main(String[] args){
		FastReader in = FastReader.SYSTEM_READER;
		int t = in.nextUnsignedInt();
		
		for (int tc = 1; tc <= t; ++tc){
			int n = in.nextUnsignedInt();
			int l = in.nextUnsignedInt();
			
			ArrayList<String> outlets = new ArrayList<String>(n);
			for (int i = 0; i < n; ++i)
				outlets.add(in.nextUnspacedString());
				
			ArrayList<String> devices = new ArrayList<String>(n);
			for (int i = 0; i < n; ++i)
				devices.add(in.nextUnspacedString());
			
			ArrayList<String> flippings = findFlippings(n, l, outlets, devices, 0);
			int min = Integer.MAX_VALUE;
			for (String flipping : flippings){
				int count = countOnes(flipping);
				if (count < min)
					min = count;
			}
			
			System.out.printf("Case #%d: %s\n", tc, min == Integer.MAX_VALUE ? "NOT POSSIBLE" : String.valueOf(min)); 
		}
	}	
}

final class FastReader{
	
	public static final FastReader SYSTEM_READER = new FastReader(System.in);
	
	private final InputStream in;
	private final byte[] buffer = new byte[1<<16];
	private int pos, count;
	
	public FastReader(InputStream in){
		this.in = in;
		pos = count = 0;
	}
	
	public int nextUnsignedInt(){
		int c;
		while ((c = read()) < '0');
		
		int result = c - '0';
		while ((c = read() - '0') >= 0)
			result = 10*result + c;
		return result;
	}
	
	public int nextInt(){
		int c;
		while (((c = read()) < '0') && (c != '-'));
		
		boolean isNegative = false;
		if (c == '-'){
			isNegative = true;
			c = read();
		}
		
		int result = c - '0';
		while ((c = read() - '0') >= 0)
			result = 10*result + c;
		return isNegative ? -result : result;
	}
	
	
	public String nextUnspacedString(){
		StringBuilder s = new StringBuilder();
		int c;
		while ((c = read()) < 33);
		s.append((char)c);
		while ((c = read()) >= 33)
			s.append((char)c);
		return s.toString();
	}
	
	public char nextNonWhitespaceChar(){
		int c;
		while ((c = read()) < 33);
		return (char)c;
	}
	
    
	private boolean fillBuffer(){
		try{
			return (count = in.read(buffer, pos = 0, buffer.length)) > 0;
		} catch (Exception e){
			return false;
		}
	}
	
	
	public int read(){
		if (pos == count)
			if (!fillBuffer())
				return -1;
		return buffer[pos++];
	}
	
}

