import java.awt.Graphics;
import java.lang.reflect.Array;
import java.math.BigInteger;
import java.net.URL;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Scanner;
import java.util.TreeMap;



public class asas {
	
	// b is devices
	
	int nn, rans,ans;
	ArrayList<Integer> arr;
	
	long[] a; long[] b; int l, n;
	boolean  possible;
	
	boolean isMatch(){
		Arrays.sort(a);
		Arrays.sort(b);
		for(int i = 0 ; i < n ; i ++)
			if(a[i] != b[i]) return false;
		return true;
	}
	
	void dfs(int idx, int tans){
		if(idx >= nn){
			if(isMatch()){
				rans = Math.min(rans, ans + tans);
				possible = true;
			}
			return ;
		}
		
		dfs(idx + 1, tans);
		if(tans + ans < rans){
			long x = Long.valueOf(1) << arr.get(idx);
			for(int i = 0 ; i < n ; i ++)
				b[i] ^= x;
			dfs(idx + 1, tans + 1);
			for(int i = 0 ; i < n ; i ++)
				b[i] ^= x;
		}
	}
	
	public int Cal(){
		arr = new ArrayList<Integer>();
		
		possible = true;
		ans = 0;
		// classify
		for(int i = 0 ; i < l ; i ++){
			long x = Long.valueOf(1) << i;
			int aone = 0, bone = 0;
			for(int j = 0 ; j < n ; j ++)
				if((a[j] & x) != 0){
					aone ++;
				}
			for(int j = 0 ; j < n ; j ++)
				if((b[j] & x) != 0)
					bone ++;
			if(aone != bone && n - aone != bone){
				possible = false;
				break;
			}
			
			if(aone + aone == n){
				arr.add(i);
			}
			else if(aone == n - bone){
				ans ++;
				for(int j = 0 ; j < n ; j ++)
					b[j] ^= x;
			}
		}
		
		
		if(possible){
			possible = false;
			nn = arr.size();
			rans = 999999999;
			dfs(0, 0);
		}
		
		return possible?rans:-1;
	}

	public asas(){
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for(int cc = 1 ; cc <= t ; cc ++){
			n = sc.nextInt();
			l = sc.nextInt();
			a = new long[n];
			b = new long[n];
			for(int i = 0 ; i < n ; i ++){
				
				String s = sc.next();
				long tar = 0;
				for(int j = 0 ; j < s.length() ; j ++){
					long x = Long.valueOf(1) << j;
					if(s.charAt(j) == '1')
						tar += x;
				}
				a[i] = tar;
			}
			
			for(int i = 0 ; i < n ; i ++){
				
				String s = sc.next();
				long tar = 0;
				for(int j = 0 ; j < s.length() ; j ++){
					long x = Long.valueOf(1) << j;
					if(s.charAt(j) == '1')
						tar += x;
				}
				b[i] = tar;
			}
			
			int res = Cal();
			
			System.out.println("Case #" + Integer.toString(cc) + ": " + (res == -1 ? "NOT POSSIBLE" : Integer.toString(res)));
		}
	}
	
	public static void main(String[] args){
		asas A = new asas();
	}
}
