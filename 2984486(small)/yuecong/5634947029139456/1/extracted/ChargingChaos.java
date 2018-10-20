import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class ChargingChaos {
	public static void main (String args[]) throws FileNotFoundException, IOException{
		Scanner scanner = new Scanner(new File("A-large.in"));
		PrintWriter pw = new PrintWriter(new File("A-large.out"));
		int t = scanner.nextInt();
		for(int i = 1; i <= t; i++){
			int n = scanner.nextInt();
			int l = scanner.nextInt();
			List<Long> first = new ArrayList<Long>();
			List<Long> second = new ArrayList<Long>();
			List<Long> result = new ArrayList<Long>();
			for (int j = 0; j < n; j++){
				first.add(scanner.nextLong(2));
			}
			for (int j = 0; j < n; j++){
				second.add(scanner.nextLong(2));
			}
			for(int a = 0; a < first.size(); a++){
				for(int b = 0; b < second.size(); b++){
					boolean found = true;
					long flag = first.get(a) ^ second.get(b);
					List<Long> one = new ArrayList<Long>();
					List<Long> two = new ArrayList<Long>();
					for(int counter = 0; counter < first.size(); counter++){
						one.add(first.get(counter));
						two.add(second.get(counter));
					}
					int j = 0;
					while(j<one.size()){
						boolean possible = false;
						int k = 0;
						while(k<two.size()){
							if((one.get(j)^two.get(k)) == flag){
								one.remove(j);
								two.remove(k);
								possible = true;
								break;
							}else{
								k++;
							}
						}
						if(!possible){
							found = false;
							break;
						}
					}
					if(found){
						result.add(flag);
					}
				}
			}
			
			if(result.size() == 0){
				pw.println("Case #" + i + ": NOT POSSIBLE");
			}else{
				int bits = calculateBits(result.get(0));
				for(int j = 0; j < result.size(); j++){
					int thisBits = calculateBits(result.get(j));
					if(bits > thisBits){
						bits = thisBits;
					}
				}
				pw.println("Case #" + i + ": " + bits);
			}
		}
		scanner.close();
		pw.close();
	}
	
	private static int calculateBits(Long n) {
		int count = 0;
		while(n>0){
			if((n&1) > 0){
				count++;
			}
			n /= 2;
		}
		return count;
	}
}
