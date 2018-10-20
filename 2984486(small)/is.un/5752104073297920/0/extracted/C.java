package gcj.r1a;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;
import java.util.Scanner;

public class C {

	Scanner scanner;


	private void solve() throws FileNotFoundException {
//		System.out.println(aveBad(1000));
//		System.out.println(aveGood(1000));
//		System.out.println((aveBad(1000) + aveGood(1000)) / 2);
		
//		System.out.println(rBad(1000));
//		System.out.println(rGood(1000));
		
		File input = new File("data/r1a/C-small-attempt1.in");
		scanner = new Scanner(input);

		File test = new File("data/r1a/C.out");
		PrintStream out = new PrintStream(new FileOutputStream(test));
		System.setOut(out);

		int testCase = scanner.nextInt();
		scanner.nextLine();

		for (int i = 1; i <= testCase; i++) {
			System.out.printf("Case #%d: %s\n", i, solveCase());
		}
	}
	

	Random random = new Random();
	private String solveCase() {
		int n = scanner.nextInt();
		int a[] = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = scanner.nextInt(); 
		}
		double rr = rating(a);
		return (rr < 0 ? "BAD" : "GOOD");
	}
	
	private void good(int arr[]) {
		for (int i = 0; i < arr.length; i++) {
			swap(arr, i, i + random.nextInt(arr.length - i));
		}
	}
	private void bad(int arr[]) {
		for (int i = 0; i < arr.length; i++) {
			swap(arr, i, random.nextInt(arr.length));
		}
	}
	
	private int r(int[] arr) {
		int ans = 0;
		for (int i = 0; i < arr.length; i++) {
			for (int j = i + 1; j < arr.length; j++) {
				if (arr[i] > arr[j]) {
					ans++;
				}
			}
		}
		return ans;
	}
	
	private double gravityCenter(int[] arr) {
		double ans = 0;
		for(int i = 0; i < arr.length; i++) {
			ans += i * arr[i];
		}
		return ans / arr.length;
	}
	
	private double aveBad(int n) {
		double sum = 0;
		int times = 10000;
		for (int f = 0; f < times; f++) {
			int a[] = new int[n];
			
			for (int i = 0; i < n; i++) {
				a[i] = i;
			}
			bad(a);
			sum += rating(a);
		}
		return (double)sum / times;
	}	
	
	private double aveGood(int n) {
		double sum = 0;
		int times = 10000;
		for (int f = 0; f < times; f++) {
			int a[] = new int[n];
			
			for (int i = 0; i < n; i++) {
				a[i] = i;
			}
			good(a);
			sum += rating(a);
		}
		return (double)sum / times;
	}
	
	private double rating(int [] a) {
		return 251856 - gravityCenter(a) + r(a) - 245000;
	}
	
	private double rGood(int n) {
		long sum = 0;
		int times = 10000;
		for (int f = 0; f < times; f++) {
			int a[] = new int[n];
			
			for (int i = 0; i < n; i++) {
				a[i] = i;
			}
			good(a);
			
			if (gravityCenter(a) < 251856 && r(a) > 245000 || random.nextDouble() < 0.5) {
				sum ++;
			}
		}
		return (double)sum / times;
	}
	
	private double rBad(int n) {
		long sum = 0;
		int times = 10000;
		for (int f = 0; f < times; f++) {
			int a[] = new int[n];
			
			for (int i = 0; i < n; i++) {
				a[i] = i;
			}
			bad(a);
			
			if (gravityCenter(a) > 251856 && r(a) < 245000 || random.nextDouble() < 0.5) {
				sum ++;
			}
		}
		return (double)sum / times;
	}



	private void swap(int[] arr, int a, int b) {
		int tmp = arr[a];
		arr[a] = arr[b];
		arr[b] = tmp;
	}


	public static void main(String[] args) throws FileNotFoundException {
		new C().solve();
	}
	
}
