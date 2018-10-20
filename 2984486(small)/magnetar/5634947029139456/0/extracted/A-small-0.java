import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Compiled with Oracle Java 8 (jdk1.8.0) on Mac OS X 10.9.2 (Intel).
 *
 * Problem statement:
 *
 *
 * @author magnetar <magnetar.fields@gmail.com>
 */
public class ChargingChaos {

    /** CONSTANTS ***********************************************************/
    public static final boolean DEBUG = false;
    public static final String FILENAME = "A-small-0";

    //region Class Members -----------------------------------------------------------/

    //endregion

    //region Boilerplate -------------------------------------------------------------/
    private File inputfile = new File("/Users/codejam/source/" + FILENAME + ".in");
    private File outfile = new File("/Users/codejam/source/" + FILENAME + ".out");
    private BufferedWriter writer = null;

    public static void main(String[] args) {
        new ChargingChaos();
    }

    public ChargingChaos() {
        System.out.println("Charging Chaos entry by Magnetar <magnetar.fields@gmail.com>");
        try (Scanner scan = new Scanner(new BufferedReader(new FileReader(inputfile)))) {
            writer = new BufferedWriter(new FileWriter(outfile));
            process(scan);
        } catch (Exception ex) {
            ex.printStackTrace();
        } finally {
            try {
                if (writer != null)
                    writer.close();
            } catch (IOException ioex) {
                ioex.printStackTrace();
            }
        }
        System.out.println("Exit OK");
    }

    public void write() throws Exception {
        writer.newLine();
        if (!DEBUG) {
            System.out.println();
        }
    }

    public void write(String str) throws Exception {
        writer.write(str);
        writer.newLine();
        if (!DEBUG) {
            System.out.println(str);
        }
    }

    public void write(String str, boolean newline) throws Exception {
        if (newline) {
            writer.write(str);
            writer.newLine();
            if (!DEBUG) {
                System.out.println(str);
            }
        } else {
            writer.write(str);
            if (!DEBUG) {
                System.out.print(str);
            }
        }
    }

    public void print() {
        if (DEBUG) {
            System.out.println();
        }
    }

    public void print(int i) {
        print(Integer.toString(i));
    }

    public void print(int i, boolean newline) {
        print(Integer.toString(i), newline);
    }

    public void print(double i) {
        print(Double.toString(i));
    }

    public void print(double i, boolean newline) {
        print(Double.toString(i), newline);
    }

    public void print(String str) {
        if (DEBUG) {
            System.out.println(str);
        }
    }

    public void print(String str, boolean newline) {
        if (DEBUG) {
            if (newline)
                System.out.println(str);
            else
                System.out.print(str);
        }
    }
    //endregion

    /** process() ***********************************************************/
    public void process(Scanner scan) throws Exception {
        int T = scan.nextInt(); // number of test cases
        for (int casen = 1; casen <= T; casen++) {
            print("Case #" + casen + ": ");
            //region Parse test case inputs ---------------------------------------------------/
            
            int N = scan.nextInt();
            int L = scan.nextInt();
            
            print("N = " + N + ", L = " + L);
            
            int[][] matrix = new int[N][L];
            int[][] goal = new int[N][L];
            
            for (int i = 0; i < N; i++) {
                String term = scan.next();
                for (int j = 0; j < L; j++) {
                	matrix[i][j] = Integer.parseInt(term.substring(j, j+1));
                }
            }

            for (int i = 0; i < N; i++) {
                String term = scan.next();
                for (int j = 0; j < L; j++) {
                	goal[i][j] = Integer.parseInt(term.substring(j, j+1));
                }
            }
            
            int foundi = -1;
            List<Integer> sols = new ArrayList<>();
            for (int i = 0; i < (Math.pow(2, L)); i++) {
            	if (flip(matrix, i, goal)) {
            		
                	String f = "%"+L+"s";
                	String pat = String.format(f, Integer.toBinaryString(i));
            		int onecount = 0;
            		for (int j = 0; j < pat.length(); j++) {
            			if (pat.substring(j, j+1).equals("1"))
            				onecount++;
            		}
            		sols.add(onecount);
            	}
            }
            Collections.sort(sols);
            if (sols.size() >= 1) {
            	foundi = sols.get(0);
            }
            sols.clear();
            
            
            //endregion

            //region Logic loop ------------------------------------------------------/


            //endregion End logic loop ---------------------------------------------/
            if (foundi > -1) {
            	print("foundi = " + foundi);
            	write("Case #" + casen + ": " + foundi);
            } else {
            	print("foundi = " + "NOT POSSIBLE");
            	write("Case #" + casen + ": " + "NOT POSSIBLE");
            }
        }
    }
    
    private void printMatrix(int[][] matrix) {
    	int N = matrix.length;
    	int L = matrix[0].length;
    	for (int i = 0; i < N; i++) {
    		print("Outlet " + i + ": ", false);
    		for (int j = 0; j < L; j++) {
    			print(matrix[i][j], false);
    		}
    		print();
    	}
    	print ("---------------------------------");
    }
    
    private boolean flip(int[][] matrix, int pattern, int[][] goal) {
    	int N = matrix.length;
    	int L = matrix[0].length;
    	int[][] copy = new int[N][L];    	
    	
    	for (int i = 0; i < N; i++) {
    		for (int j = 0; j < L; j++) {
    			copy[i][j] = matrix[i][j];
    		}
    	}    	
    	print("Pre-flip: ");
    	printMatrix(copy);
    	String f = "%"+L+"s";
    	String pat = String.format(f, Integer.toBinaryString(pattern));
    	for (int i = 0; i < pat.length(); i++) {
    		if (pat.subSequence(i, i+1).equals("1")) {
    			flipOne(copy, i);
    		}
    	}
    	print("Post-flip: ");
    	printMatrix(copy);
    	return isMatch(copy, goal);
    }
    
    private void flipOne(int[][] matrix, int col) {
    	int N = matrix.length;
    	int L = matrix[0].length;
    	//print("flip col " + col);
    	//printMatrix(matrix);
		for (int j = 0; j < N; j++) {
			if (matrix[j][col] == 0) 
				matrix[j][col] = 1;
			else
				matrix[j][col] = 0;
		}
    }
    
    private boolean isMatch(int[][] matrix, int[][] goal) {
    	int N = matrix.length;
    	int L = matrix[0].length;
    	int[][] copy = new int[N][L];
    	
    	for (int i = 0; i < N; i++) {
    		for (int j = 0; j < L; j++) {
    			copy[i][j] = matrix[i][j];
    		}
    	}
    	
    	boolean ismatch = false;
    	for (int i = 0; i < N; i++) {
    		boolean rowmatch = false;
    		int foundj = -1;
    		for (int j = 0; j < N; j++) {
    			boolean dealbreaker = false;
    			for (int k = 0; k < L; k++) {
    				if (copy[j][k] != goal[i][k]) {
    					dealbreaker = true;
    					break;
    				}
    			}
    			if (!dealbreaker) {
    				rowmatch = true;
    				foundj = j;
    				break;
    			}
    		}
    		if (rowmatch == true) {
    			copy[foundj][0] = -1;
    			if (i == N - 1) {
    				ismatch = true;
    			}
    			continue;
    		} else {
    			break;
    		}
    	}
    	return ismatch;
    }
}
