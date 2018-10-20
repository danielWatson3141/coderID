package gcj2014;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class R1A2014A {
	public static void main(String[] args) throws IOException {
		BufferedReader in = null;
		
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			
			int testCaseNum = Integer.parseInt(in.readLine());
			
			for(int i=1; i<=testCaseNum; i++) {
				String[] firstRowElems = in.readLine().split(" ");
				int n = Integer.parseInt(firstRowElems[0]);
				int l = Integer.parseInt(firstRowElems[1]);
				String[] a = in.readLine().split(" ");
				String[] b = in.readLine().split(" ");
				
				
				System.out.print("Case #" + i + ": ");
				System.out.print(test(n, l, a, b));
				System.out.println();
			}
		}
		catch(IOException ioe) {
			throw ioe;
		}
		finally {
			if(in != null) {
				in.close();
			}
		}
	}
	
	
	
	public static String test(int n, int l, String[] a, String[] b) {
		Arrays.sort(b);
		
		try {
			List<String> result = test2(n, l, a, b);
			if(result.size() == 0) {
				throw new NoCandidateException();
			}
			int min = Integer.MAX_VALUE;
			for(int i=0; i<result.size(); i++) {
				int count = 0;
				String str = result.get(i);
				for(int j=0; j<l; j++) {
					char c = str.charAt(j);
					if(c == '1') {
						count++;
					}
				}
				min = Math.min(min, count);
			}
			return Integer.toString(min);
		}
		catch(NoCandidateException e) {
			return "NOT POSSIBLE";
		}
	}
	
	public static List<String> test2(int n, int l, String[] a, String[] b) throws NoCandidateException {
		ArrayList<String> result = new ArrayList<String>();
		
		if(l==0) {
			result.add("");
			return result;
		}
		
		ArrayList<String> substrArrayA_startsWith0 = new ArrayList<String>();
		ArrayList<String> substrArrayA_startsWith1 = new ArrayList<String>();
		ArrayList<String> substrArrayB_startsWith0 = new ArrayList<String>();
		ArrayList<String> substrArrayB_startsWith1 = new ArrayList<String>();
		for(int i=0; i<n; i++) {
			String stra = a[i];
			if(stra.charAt(0) == '0') {
				substrArrayA_startsWith0.add(stra.substring(1, l));
			}
			else {
				substrArrayA_startsWith1.add(stra.substring(1, l));
			}
			
			String strb = b[i];
			if(strb.charAt(0) == '0') {
				substrArrayB_startsWith0.add(strb.substring(1, l));
			}
			else {
				substrArrayB_startsWith1.add(strb.substring(1, l));
			}
		}
		
		String[] a0 = new String[substrArrayA_startsWith0.size()];
		for(int i=0; i<substrArrayA_startsWith0.size(); i++) {
			a0[i] = substrArrayA_startsWith0.get(i);
		}
		String[] a1 = new String[substrArrayA_startsWith1.size()];
		for(int i=0; i<substrArrayA_startsWith1.size(); i++) {
			a1[i] = substrArrayA_startsWith1.get(i);
		}
		String[] b0 = new String[substrArrayB_startsWith0.size()];
		for(int i=0; i<substrArrayB_startsWith0.size(); i++) {
			b0[i] = substrArrayB_startsWith0.get(i);
		}
		String[] b1 = new String[substrArrayB_startsWith1.size()];
		for(int i=0; i<substrArrayB_startsWith1.size(); i++) {
			b1[i] = substrArrayB_startsWith1.get(i);
		}
		Arrays.sort(a0);
		Arrays.sort(a1);
		
		List<String> res1 = null;
		List<String> res2 = null;
		if(substrArrayA_startsWith0.size() == substrArrayA_startsWith1.size() && substrArrayB_startsWith0.size() == substrArrayB_startsWith1.size()) {
			try {
				res1 = test2(a0.length, l-1, a0, b0);
				res2 = test2(a1.length, l-1, a1, b1);
				res1 = getUnion(res1, res2);
				for(int i=0; i<res1.size(); i++) {
					result.add("0" + res1.get(i));
				}
			}
			catch(NoCandidateException e) {
				;
			}
			
			try {
				res1 = test2(a1.length, l-1, a1, b0);
				res2 = test2(a0.length, l-1, a0, b1);
				res1 = getUnion(res1, res2);
				for(int i=0; i<res1.size(); i++) {
					result.add("1" + res1.get(i));
				}
			}
			catch(NoCandidateException e) {
				;
			}
		}
		else if(substrArrayA_startsWith0.size() == substrArrayB_startsWith0.size()) {
			try {
				res1 = test2(a0.length, l-1, a0, b0);
				res2 = test2(a1.length, l-1, a1, b1);
				res1 = getUnion(res1, res2);
				for(int i=0; i<res1.size(); i++) {
					result.add("0" + res1.get(i));
				}
			}
			catch(NoCandidateException e) {
				throw e;
			}
		}
		else if(substrArrayA_startsWith1.size() == substrArrayB_startsWith0.size()) {
			try {
				res1 = test2(a1.length, l-1, a1, b0);
				res2 = test2(a0.length, l-1, a0, b1);
				res1 = getUnion(res1, res2);
				for(int i=0; i<res1.size(); i++) {
					result.add("1" + res1.get(i));
				}
			}
			catch(NoCandidateException e) {
				throw e;
			}
		}
		else {
			throw new NoCandidateException();
		}
		
		return result;
		
	}
	
	
	public static List<String> getUnion(List<String> a, List<String> b) {
		ArrayList<String> result = new ArrayList<String>();
		
		for(int i=0; i<a.size(); i++) {
			String stra = a.get(i);
			for(int j=0; j<b.size(); j++) {
				String strb = b.get(j);
				if(stra != null && stra.equals(strb)) {
					result.add(stra);
				}
			}
		}
		
		return result;
	}
}


class NoCandidateException extends Exception {
	
}
