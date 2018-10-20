import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class One {

	public static ArrayList<int[]> flips = new ArrayList<int[]>();
			
	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(
					System.in));
			int ntest = Integer.parseInt(br.readLine());
			int[] res = new int[ntest];

			for (int p = 0; p < ntest; p++) {
				
				flips.clear();
				
				String[] in = br.readLine().split(" ");
				long n = Long.parseLong(in[0]);
				long l = Long.parseLong(in[1]);

				String[] in1 = br.readLine().split(" ");
				ArrayList<String> flow = new ArrayList<String>();
				for (int x = 0; x < n; x++) {
					flow.add((in1[x]));
				}

				String[] in2 = br.readLine().split(" ");
				ArrayList<String> device = new ArrayList<String>();
				for (int x = 0; x < n; x++) {
					device.add(in2[x]);
				}

				if (check(n, flow, device)) {
					res[p] = 0;
				} else {
					
					int[] arr = new int[(int)l];
					for (int i = 1; i <= l; i++) {
						arr[i-1] = i;
					}		

					for(int i = 1; i <= l; i++) {
						printCombination(arr,(int)l,i);
					}
					
					boolean notPossible = true;
					for (int q = 0; q < flips.size(); q++) {

						int[] current = flips.get(q);
						// System.out.println("Flipping " + current);

						ArrayList<String> tempFlow = new ArrayList<String>();

						for (int w = 0; w < current.length; w++) {

							int no = current[w];//Character.getNumericValue(current.charAt(w));
							//System.out.println(no);
							no -= 1;

							for (int h = 0; h < n; h++) {

								StringBuilder flowx;
								if (w == 0) {
									flowx = new StringBuilder(flow.get(h));
									char ch = flowx.charAt(no);
									if (ch == '0')
										flowx.setCharAt(no, '1');
									else
										flowx.setCharAt(no, '0');
									tempFlow.add(flowx.toString());

								} else {

									flowx = new StringBuilder(tempFlow.get(h));
									char ch = flowx.charAt(no);
									if (ch == '0')
										flowx.setCharAt(no, '1');
									else
										flowx.setCharAt(no, '0');
									tempFlow.set(h, flowx.toString());
								}

							}
						}
						if (check(n, tempFlow, device)) {
							notPossible = false;
							res[p] = current.length;
							break;
						}
					}

					if (notPossible) {
						res[p] = -1;
					}
				}

			}
			print(ntest, res);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public static boolean check(long n, ArrayList<String> flow,
			ArrayList<String> device) {

		// for (int y = 0; y < n; y++) {
		// System.out.print(flow.get(y) + " ");
		// }
		// Loop for each port
		boolean success = false;

		if (device.containsAll(flow)) {
			success = true;
		}
		return success;

	}

	public static void print(int ntest, int res[]) {
		for (int p = 0; p < ntest; p++) {
			int c = p + 1;
			if (res[p] == -1) {
				System.out.println("Case #" + c + ": " + "NOT POSSIBLE");
			} else {
				System.out.println("Case #" + c + ": " + res[p]);
			}

		}
	}
	
	public static void printCombination(int arr[], int n, int r)
	{
	    // A temporary array to store all combination one by one
	    int data[] =  new int[r];
	 
	    // Print all combination using temprary array 'data[]'
	    combinationUtil(arr, data, 0, n-1, 0, r);
	}
	 
	/* arr[]  ---> Input Array
	   data[] ---> Temporary array to store current combination
	   start & end ---> Staring and Ending indexes in arr[]
	   index  ---> Current index in data[]
	   r ---> Size of a combination to be printed */
	public static void combinationUtil(int arr[], int data[], int start, int end, int index, int r)
	{
	    // Current combination is ready to be printed, print it
	    if (index == r)
	    {	int[] comb = new int[r];
	        for (int j=0; j<r; j++) {
	            comb[j] = data[j];
	        	//System.out.print(data[j] + " ");
	        }	
	        //System.out.println();
	        flips.add(comb);
	        return;
	    }
	 
	    // replace index with all possible elements. The condition
	    // "end-i+1 >= r-index" makes sure that including one element
	    // at index will make a combination with remaining elements
	    // at remaining positions
	    for (int i=start; i<=end && end-i+1 >= r-index; i++)
	    {
	        data[index] = arr[i];
	        combinationUtil(arr, data, i+1, end, index+1, r);
	    }
	}
}





