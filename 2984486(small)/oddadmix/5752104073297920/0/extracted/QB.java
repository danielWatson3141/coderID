import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;


public class QB {
	static int caseNo=0;
	static List<String> results;
	static int no_of_rounds = 0;
	static boolean[] switched_swtich;
	static int[] input;
	static int cc = 0;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		results = new ArrayList<String>();
		try (BufferedReader br = new BufferedReader(new FileReader("C-small-attempt2.in")))
		{
 
			String sCurrentLine;
			int count = 0 ;
			while ((sCurrentLine = br.readLine()) != null) {
				if(count ==0){
					no_of_rounds = Integer.parseInt(sCurrentLine);
				}
				else if(count==1){
					cc = Integer.parseInt(sCurrentLine);
				}else if(count==2){
					String[] parts = sCurrentLine.split(" ");
					input = new int[parts.length];
					for(int i=0;i<parts.length;i++){
						input[i] = Integer.parseInt(parts[i]);
					}
					solve();
				}
				count++;
				if(count==3){
					count=1;
				}
			}
 
		} catch (IOException e) {
			e.printStackTrace();
		} 
		
		Writer writer = null;

		try {
		    writer = new BufferedWriter(new OutputStreamWriter(
		          new FileOutputStream("output.txt"), "utf-8"));
		    for(String out: results){
		    	writer.write(out+System.getProperty("line.separator"));
		    }
		    
		} catch (IOException ex) {
		  // report
		} finally {
		   try {writer.close();} catch (Exception ex) {}
		}
	}
	public static void solve()
	{
		String which = "GOOD";
		int good=0;
		for(int i=1;i<=cc;i++){
			if(input[i-1]<i){
				good++;
			}
		}
		if(good<480){
			which="BAD";
		}
		
		caseNo++;
		results.add("Case #"+caseNo+": "+which);
	}
	
	
	
	

}
