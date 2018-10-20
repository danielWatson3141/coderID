package codejam2014;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Random;

public class ProperShuffle {

	int cases = 0;
	ArrayList<RoundOneB> list = new ArrayList<RoundOneB>();
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ProperShuffle properShuffle = new ProperShuffle();
		properShuffle.read();
		for (int i = 0; i < properShuffle.cases; i++) {
			String out = "Case #" + (i + 1) + ": ";
			System.out.print(out);
			properShuffle.list.get(i).solver();
		}
	}
	public void read() {
		FileReader dFileReader = null;
		BufferedReader br = null;
		String urlString = "/Users/ColinMac/Documents/JavaWorkSpace/LeetCode/src/codejam2014/RoundOneProblemB.in";
		try {
			dFileReader = new FileReader(new File(urlString));
			br = new BufferedReader(dFileReader);
			String s = null;
			s = br.readLine();
			cases = Integer.valueOf(s);
			for (int i = 0; i < cases; i++) {
				int num;
				//number and length
				s = br.readLine();
				num=Integer.valueOf(s);
				int[] input=new int[num];
				//in
				s = br.readLine();
				 String[] strings = s.split(" ");
				for (int j = 0; j < num; j++) {
					input[j]=Integer.valueOf(strings[j]);
				}
				//game
				RoundOneB game=new RoundOneB(num, input);
				list.add(game);
			}
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			try {
				br.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
}

class RoundOneB {
	private int num;
	private int[] in;
	public RoundOneB(int num,int[] in) {
		this.num=num;
		this.in=in;
	}
	public void solver() {
		int l1=0;
		int l2=0;
		for (int i = 0; i < 10000; i++) {
			l1+=count(in,methodA());
		}
		for (int i = 0; i < 10000; i++) {
			l2+=count(in,methodB());
		}
		if(l1>l2)
			System.out.println("BAD");
		else {
			System.out.println("GOOD");
		}
	}
	private long count(int[] a, int[] b) {
		long counter=0;
		for (int i = 0; i < b.length; i++) {
			counter+=Math.abs(a[i]-b[i]);
		}
		return counter;
	}
	private int[] methodA() {
		int[] sample=new int[num];
		for (int i = 0; i < num; i++) {
			sample[i]=i;
		}
		Random random=new Random();
		for (int i = 0; i < num; i++) {
			int p=random.nextInt(num-i)+i;
			int tmp=sample[i];
			sample[i]=sample[p];
			sample[p]=tmp;
		}
		return sample;
	}
	private int[] methodB() {
		int[] sample=new int[num];
		for (int i = 0; i < num; i++) {
			sample[i]=i;
		}
		Random random=new Random();
		for (int i = 0; i < num; i++) {
			int p=random.nextInt(num-1);
			int tmp=sample[i];
			sample[i]=sample[p];
			sample[p]=tmp;
		}
		return sample;
	}
}