import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;


public class Q3 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		File file = new File("input.txt");  
		File dest = new File("output.txt");  
		BufferedReader reader = new BufferedReader(new FileReader(file));  
		BufferedWriter writer  = new BufferedWriter(new FileWriter(dest));  
		String data = reader.readLine();
		int num = Integer.parseInt(data);
		for (int t = 1; t <= num; t++){
			writer.write("Case #"+t+": ");
			data = reader.readLine();
			int N = Integer.parseInt(data);
			data = reader.readLine();
			String value[] = data.split(" ");
			int output[] = new int[N];
			int tt = 0;
			for (int i = 0; i < N; i++) {
				output[i] = Integer.parseInt(value[i]);
				if (output[i] > i)
					tt++;
			}
			if ( tt > 500+16)
				writer.write("BAD\n");
			else
				writer.write("GOOD\n");
		}
		reader.close();
		writer.flush();
		writer.close();
	}

}
