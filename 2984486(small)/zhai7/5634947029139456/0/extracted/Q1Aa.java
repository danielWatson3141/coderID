import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.TimeUnit;

import javax.swing.JFileChooser;
import javax.swing.filechooser.FileNameExtensionFilter;



public class Q1Aa {

	int cn;
	Child[] ch;

	public static void main(String[] args) throws ExecutionException, Throwable{
		JFileChooser jfc = new JFileChooser("./iofile");
		jfc.setFileFilter(new FileNameExtensionFilter(null, "in"));
		while(jfc.showOpenDialog(null) != JFileChooser.APPROVE_OPTION);
		File fi = jfc.getSelectedFile();
		String fo = fi.getPath();
		fo = fo.substring(0, fo.length() - 2) + "out";
		PrintStream ps = new PrintStream(fo);
		
		Q1Aa q = new Q1Aa();
		q.ReadInput(fi);
		
		boolean large = fi.getName().contains("large");
		q.PrintOutput(ps, large);
		ps.close();
	}
	
	void ReadInput(File fi) throws IOException{
		Scanner in = new Scanner(fi);
		Scanner line = new Scanner(in.nextLine());
		cn = line.nextInt();
		line.close();
		ch = new Child[cn];
		for(int c = 0; c < cn; c++){
			ch[c] = new Child(in);
		}
		in.close();
	}
	
	
	void PrintOutput(PrintStream ps, boolean large) throws IOException, Throwable, ExecutionException{
		if(large){
			ExecutorService exec = Executors.newFixedThreadPool(Runtime.getRuntime().availableProcessors());
			Future[] fc = new Future[cn];
			for(int c = 0; c < cn; c++){
				fc[c] = exec.submit(ch[c]);
			}
			exec.shutdown();
			for(int c = 0; c < cn; c++){
				while(!fc[c].isDone())
					Thread.sleep(10000);
				ps.format("Case #%d: %s\n", c + 1, ch[c].result);
			}
		}
		else{
			for(int c = 0; c < cn; c++){
				ch[c].run();
				ps.format("Case #%d: %s\n", c + 1, ch[c].result);
			}
		}
	}
	
	static class Child implements Runnable{
		String result = "";
		int nn, ll;
		int sum[][];
		Set<Long> out = new HashSet<Long>();
		Set<Long> dev = new HashSet<Long>();
		
		Child(Scanner in){
			Scanner line = new Scanner(in.nextLine());
			nn = line.nextInt();
			ll = line.nextInt();
			line.close();
			sum = new int[2][ll];
			line = new Scanner(in.nextLine());
			for(int i = 0; i < nn; ++i){
				String str = line.next();
				out.add(Long.parseLong(str, 2));
				for(int j = 0; j < ll; ++j){
					if(str.charAt(j) == '1')
						++sum[0][ll - j - 1];
				}
			}
			line.close();
			line = new Scanner(in.nextLine());
			for(int i = 0; i < nn; ++i){
				String str = line.next();
				dev.add(Long.parseLong(str, 2));
				for(int j = 0; j < ll; ++j){
					if(str.charAt(j) == '1')
						++sum[1][ll - j - 1];
				}
			}
			line.close();
		}

		Map<Long, Integer> set2map(long mask, long poss, Set<Long> set){
			Map<Long, Integer> map = new HashMap<Long, Integer>();
			poss = ~poss;
			for(Long i: set){
				long j = (i & poss) ^ mask;
				if(map.containsKey(j))
					map.put(j, map.get(j) + 1);
				else
					map.put(j, 1);
			}
			return map;
		}
		
		int bit(long mask, long poss){
			int tz = Long.numberOfTrailingZeros(poss); 
			if(tz == Long.SIZE){
				return Long.bitCount(mask);
			}
			poss ^= 1 << tz;
			int ret = -1;
			if(set2map(mask, poss, out).equals(set2map(0, poss, dev)))
				ret = bit(mask, poss);
			mask ^= 1 << tz;
			if(set2map(mask, poss, out).equals(set2map(0, poss, dev))){
				int r = bit(mask, poss);
				if(ret < 0)
					ret = r;
				else if(r >= 0 && r < ret)
					ret = r;
			}
			return ret;
		}
		
		int Calc(){
			long mask = 0;
			long poss = 0;
			for(int i = 0; i < ll; ++i){
				int s = sum[0][i], t = sum[1][i];
				if(s != t && s + t != nn)
					return -1;
				if(s != t)
					mask ^= 1 << i;
				else if(s + t == nn)
					poss ^= 1 << i;
			}
			return bit(mask, poss);
		}
		
		@Override
		public void run() {
			int ret = Calc();
			if(ret >= 0)
				result = Integer.toString(ret);
			else
				result = "NOT POSSIBLE";
			result = result.trim();
		}
		
	}
}