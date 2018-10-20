package Question1;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.Scanner;

public class Initializer {

	public static void main(String[] args) {
		Scanner input = null;
		try {
			input = new Scanner(Initializer.class.getResourceAsStream("A-small-attempt1 (1).in"));
		} catch (Exception e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		int cases = Integer.parseInt(input.nextLine());
		int count = 0;
		PrintWriter out = null;
		try {
		    out = new PrintWriter(new BufferedWriter(new FileWriter("output", true)));
		}catch(Exception e){
			
		}

		while (input.hasNext()) {
			count++;
			String first[] = input.nextLine().split("\\s+");
			int n = Integer.parseInt(first[0]);
			int l = Integer.parseInt(first[1]);
			String second[] = input.nextLine().split("\\s+");
			String third[] = input.nextLine().split("\\s+");
			Flow f = new Flow(second, third, l, n);
			String output = "Case #" + count + ": "+f.findMin();
			out.println(output);
			System.out.println(output);

		}
		out.close();
	}
}
