import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;


public class Solver {
	final String fileName = "A-small-attempt1";
	private BufferedReader reader;
	
	public Solver() throws IOException{
		FileWriter writer = new FileWriter(new File(fileName+".out"));
		reader = new BufferedReader(new FileReader(new File(fileName+".in")));
		
		String value = reader.readLine();
		for(int i = 1; i <= Integer.parseInt(value); i++){
			//Read lines here and format them for solveMe
			int length = getIntArrayFromString(reader.readLine())[1];
			writer.write("Case #"+i+": "+solveMe(getIntArrayFromBitString(reader.readLine()), getIntArrayFromBitString(reader.readLine()), length)+"\n");
		}
		writer.close();
	}
	
	private int[] getIntArrayFromString(String readLine) {
		String[] values = readLine.split(" ");
		int[] intArray = new int[values.length];
		for(int i=0; i<values.length; i++){
			intArray[i] = Integer.parseInt(values[i]);
		}
		return intArray;
	}
	
	private int[] getIntArrayFromBitString(String readLine) {
		String[] values = readLine.split(" ");
		int[] intArray = new int[values.length];
		for(int i=0; i<values.length; i++){
			intArray[i] = Integer.parseInt(values[i], 2);
		}
		return intArray;
	}

	public String solveMe(int[] initial, int[] needed, int length){
		//Solve problem here
		int counts = -1;
		Arrays.sort(needed);
		for(int i = 0; i < Math.pow(2, length); i++){
			boolean next = false;
			int[] current = new int[initial.length];
			for(int j = 0; j < initial.length; j++){
				current[j] = initial[j]^i;
			}
			Arrays.sort(current);
			for(int j = 0; j < initial.length; j++){
				if(!(needed[j] == current[j])){
					next = true;
					break;
				}
			}
			if(!next){
				if(count1s(i) < counts || counts == -1){
					counts = count1s(i);
				}
			}
		}
		if(counts == -1){
			return "NOT POSSIBLE";
		}
		return counts+"";
	}
	
	public int count1s(int i){
		int counts = 0;
		while(i != 0){
			if(i%2 == 1){
				counts++;
			}
			i = (int)Math.floor(i/2);
		}
		return counts;
	}

	public static void main(String[] args){
		try {
			@SuppressWarnings("unused")
			Solver solver = new Solver();
		} catch (IOException e) {
			e.printStackTrace();
		}
	} 
}

