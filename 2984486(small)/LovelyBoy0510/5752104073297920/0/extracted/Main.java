import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;

public class Main {

	public static void main(String[] args) {
		String inputFile = args[0];
		String outputFile = args[1];

		File file = new File(inputFile);
		File ouptutFile = new File(outputFile);
	
		if (!file.exists() ) return ;
		Integer testCaseNum = 0;
	
		try (
				FileReader fr = new FileReader(file);
				BufferedReader br = new BufferedReader(fr);
				FileWriter fw = new FileWriter(outputFile);
				BufferedWriter bw = new BufferedWriter(fw);
		) {
			String line = null;
			line = br.readLine();
		
			testCaseNum = Integer.parseInt(line);
		
			for (int i =0; i < testCaseNum; i++) {
				line = br.readLine();
				int num = Integer.parseInt(line);
				line = br.readLine();
				String answer = solveJam(num, line);
				
				bw.write(String.format("Case #%d: ", i+1));
				bw.write(String.format("%s\n", answer));	
			}
			
		} catch ( Exception e) {
			e.printStackTrace();
		}
	}
	
	public static String solveJam(int num, String line) {
		String [] splitedInt = line.split(" ");
		
		for ( int i =0; i < num/2; i++) {
			int number = Integer.parseInt(splitedInt[i]);
			
			if ( i == number ) 
				return "BAD";
			
		}

		return "GOOD";
	}
	

}
