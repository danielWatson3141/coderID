import java.util.*;
import java.io.*;
import java.lang.*;
public class a {
	public static void main(String[] args) {
        Scanner sc = null;
        PrintWriter pw = null;
        
        try {
            String inputFile = args[0];
            String outputFile = args[1];
            int n = 0;
            
            sc = new Scanner(new FileReader(inputFile));
            pw = new PrintWriter(new FileWriter(outputFile));
            n = Integer.parseInt(sc.nextLine());
            
            for(int id = 1; id <= n; id++){
                int x = sc.nextInt();
                int l = sc.nextInt();
                int count;
                
                sc.nextLine();
                
                String[] outlets = sc.nextLine().split(" ");
                String[] devices = sc.nextLine().split(" ");
                
                Arrays.sort(outlets);
                Arrays.sort(devices);

                ArrayList<Integer> bits = new ArrayList<Integer>();
                int switches = 0;
                boolean possible = false;
                ArrayList<String> dev = new ArrayList<String>(Arrays.asList(devices));
                
                for(String O : outlets) {
                    switches = 0;
                    bits.clear();
                    for(count = 0; count < O.length(); count++) {
                        if(O.charAt(count) != devices[0].charAt(count)) {
                            bits.add(count);
                            switches++;
                        }
                    }
                    
                    for(count = 0; count < outlets.length; count++) {
                        StringBuilder cur = new StringBuilder(outlets[count]);
                        for(int b: bits) {
                            if(cur.charAt(b) == '0') {
                                cur.setCharAt(b, '1');
                            }
                            else {
                                cur.setCharAt(b, '0');
                            }
                        }
                        
                        if(dev.indexOf(cur.toString()) < 0) {
                            possible = false;
                            break;
                        }
                        else
                            possible = true;
                    }
                    if(possible)
                        break;
                }
                
                
                pw.print("Case #" + id + ": ");
                
                if(possible)
                    pw.print(switches);
                else
                    pw.print("NOT POSSIBLE");
                pw.println();
            }
        }
        catch (Exception e) {
			System.out.println("Invalid Arguments!");
		}
        finally {
            if (pw != null) { 
                pw.flush();
                pw.close(); 
            } 
            if (sc != null) {
                sc.close();
            }
        } 
	}
}