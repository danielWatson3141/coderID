package codejam2014;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;

public class ChargingChaos {
	int cases = 0;
	ArrayList<RoundOneA> list = new ArrayList<RoundOneA>();
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ChargingChaos chargingChaos = new ChargingChaos();
		chargingChaos.read();
		for (int i = 0; i < chargingChaos.cases; i++) {
			String out = "Case #" + (i + 1) + ": ";
			int o= chargingChaos.list.get(i).solver();
			if(o!=-1){
				out +=o;
				System.out.println(out);
			}else{
				out +="NOT POSSIBLE";
				System.out.println(out);
			}
		}
	}
	public void read() {
		FileReader dFileReader = null;
		BufferedReader br = null;
		String urlString = "/Users/ColinMac/Documents/JavaWorkSpace/LeetCode/src/codejam2014/RoundOneProblemA.in";
		try {
			dFileReader = new FileReader(new File(urlString));
			br = new BufferedReader(dFileReader);
			String s = null;
			s = br.readLine();
			cases = Integer.valueOf(s);
			for (int i = 0; i < cases; i++) {
				int num;
				int stringLength;
				ArrayList<String> input=new ArrayList<String>();
				ArrayList<String> output=new ArrayList<String>();
				//number and length
				s = br.readLine();
				String[] strings = s.split(" ");
				num=Integer.valueOf(strings[0]);
				stringLength=Integer.valueOf(strings[1]);
				//in
				s = br.readLine();
				strings = s.split(" ");
				for (int j = 0; j < num; j++) {
					input.add(strings[j]);
				}
				//out
				s = br.readLine();
				strings = s.split(" ");
				for (int j = 0; j < num; j++) {
					output.add(strings[j]);
				}
				//game
				RoundOneA game=new RoundOneA(num, stringLength, input, output);
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

class RoundOneA {
	private int num;
	private int stringLength;
	private ArrayList<String> input;
	private ArrayList<String> output;
	public RoundOneA(int num,int stringLength,ArrayList<String> input,ArrayList<String> output) {
		this.num=num;
		this.stringLength=stringLength;
		this.input=input;
		this.output=output;
	}
	public int solver() {
		//no flip
		if(equal(input, output))
			return 0;
		ArrayList<ArrayList<Integer>> fliplist=findFlip(stringLength);
		for (int i = 0; i < fliplist.size(); i++) {
			ArrayList<String> newList=flip(input, fliplist.get(i));
			if(equal(newList, output))
				return fliplist.get(i).size();
		}
		return -1;
	}
	private ArrayList<ArrayList<Integer>> findFlip(int length) {
		ArrayList<ArrayList<Integer>> resultList=new ArrayList<ArrayList<Integer>>();
		for (int i = 1; i < Math.pow(2, length); i++) {
			ArrayList<Integer> list=new ArrayList<Integer>();
			char[] chars=Integer.toBinaryString(i).toCharArray();
			int l=length-1;
			for (int j=chars.length-1;j>=0; j--) {
				if(chars[j]=='1')
					list.add(l);
				l--;
			}
			resultList.add(list);
		}
		return resultList;
	}
	private ArrayList<String> flip(ArrayList<String> input, ArrayList<Integer> object) {
		ArrayList<String> newArrayList=new ArrayList<String>();
		for (int i = 0; i < num; i++) {
			char[] chars=input.get(i).toCharArray();
			for (int j = 0; j < object.size(); j++) {
				int k=object.get(j);
				if(chars[k]=='0')
					chars[k]='1';
				else {
					chars[k]='0';
				}	
			}
			newArrayList.add(String.copyValueOf(chars));
		}
		return newArrayList;
	}
	private boolean equal(ArrayList<String> input,ArrayList<String> output) {
		HashMap<String, Boolean> found=new HashMap<String, Boolean>();
		for (int i = 0; i < num; i++) {
			found.put(input.get(i), true);
		}
		for (int i = 0; i < num; i++) {
			if (!found.containsKey(output.get(i))) {
				return false;
			}
		}
		return true;
	}
}
