import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;

import com.google.common.base.Charsets;
import com.google.common.collect.ImmutableList;
import com.google.common.io.Files;


public class Deviation {

	public static void main(String [] args) throws IOException{
		// Read the lines of a UTF-8 text file
		ImmutableList<String> lines = Files.asCharSource(new File(args[0]), Charsets.UTF_8).readLines();
		int numCases = Integer.parseInt(lines.get(0));
		File outputFile = new File(args[1]);
		if(outputFile.exists()){
			outputFile.delete();
			outputFile.createNewFile();
		}
		PrintWriter writer = new PrintWriter(outputFile);
		for(int i = 0; i< numCases; i++){
			String numLine = lines.get(i*2+1);
			String permLine = lines.get(i*+2);
			int dev = 0;
			String [] permStrs = permLine.split(" ");
			for(int j = 0; j< permStrs.length; j++){
				int ithNum = Integer.parseInt(permStrs[j]);
				dev += (ithNum-i)*(ithNum-i);
			}
			if(dev<259313500){
				writer.println("Case #"+(i+1)+": BAD");
			}else{
				writer.println("Case #"+(i+1)+": GOOD");

			}
		}
		writer.close();
	}

}
