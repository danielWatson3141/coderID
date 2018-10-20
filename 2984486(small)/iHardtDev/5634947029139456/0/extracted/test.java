import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;


public class test {
	
	static int score = -1;
	static String[] sockets;
	static String[] tempSockets;
 	static String[] devices;
 	static int L;
	static int N;
	static int tempScore;
	
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int numTestCases = s.nextInt();
		
		for(int TestCase = 0; TestCase < numTestCases; TestCase++){
			score = -1;
			N = s.nextInt();
			L = s.nextInt();
			s.nextLine();
			
			sockets = s.nextLine().split(" ");
			devices = s.nextLine().split(" ");
			tempSockets = Arrays.copyOf(sockets, sockets.length);
			
//			System.err.println(">>" + Arrays.toString(tempSockets));
			
			tempScore = 0;
			for(int i = 0; i<N; i++){
				tempScore = 0;
				if(devices[0].equals(sockets[i])){
					if(checkAll()){
						if(score == -1)
							score = tempScore;
						else if(tempScore < score)
							score = tempScore;
					}
				}
				else{
					fixBits(devices[0],sockets[i]);
					if(checkAll2()){
						if(score == -1)
							score = tempScore;
						else if(tempScore < score)
							score = tempScore;
					}
				}
//				System.out.println(score + " < reg | temp > " + tempScore);
					
				
			}
			
			System.out.println("Case #" + (TestCase + 1) + ": " + (score == -1 ? "NOT POSSIBLE" : score));
			
		}
	}
	
	public static boolean checkAll(){
		boolean[] isUsed = new boolean[N];
		
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				if(devices[i].equals(sockets[j]) && !isUsed[j]){
					isUsed[j]  = true;
				}
			}
			
		}
		for(boolean b : isUsed)
			if(!b)
				return false;
		return true;
	}
	
	public static boolean checkAll2(){
		boolean[] isUsed = new boolean[N];
		
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				if(devices[i].equals(tempSockets[j]) && !isUsed[j]){
					isUsed[j]  = true;
				}
			}
			
		}
		for(boolean b : isUsed)
			if(!b)
				return false;
		return true;
	}
	
	public static void fixBits(String target, String oneToBeFixed){
		tempScore = 0;
		tempSockets = Arrays.copyOf(sockets, sockets.length);
//		System.out.println("in: " + Arrays.toString(tempSockets));
		for (int i = 0; i<L; i++){
			
			if(target.charAt(i) == oneToBeFixed.charAt(i)){
				continue;
			}else{
				tempScore++;
				for(int j = 0; j < tempSockets.length; j++){
					char[] tempCharArray = tempSockets[j].toCharArray();
					tempCharArray[i] = tempCharArray[i] == '1' ? '0' : '1';
					
					String tmp = "";
					for(int k = 0; k < tempCharArray.length; k++) tmp = tmp + "" + tempCharArray[k];
					tempSockets[j] = tmp;
			
				}
			}
			
			
		}
//		System.out.println("fixed: " + Arrays.toString(tempSockets));
	}
}
