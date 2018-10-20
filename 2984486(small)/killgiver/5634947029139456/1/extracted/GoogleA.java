import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;
import java.util.TreeSet;

public class GoogleA
{
	public static void main(String[] args) throws Exception
	{
//		 String filename = "E:/Users/KC/Desktop/google_round1/test.in";
		String filename = "E:/Users/KC/Desktop/google_round1/A-small-attempt5.in";
		Scanner reader = new Scanner(new File(filename));
		BufferedWriter writer = new BufferedWriter(new FileWriter(filename.replace(".in", ".out")));
		int tCases = reader.nextInt();
		for (int i = 0; i < tCases; i++)
		{
			int n = reader.nextInt();
			int length = reader.nextInt();
			int[] outlets = new int[length];
			int[] devices = new int[length];
			List<int[]> oArr = new ArrayList<>();
			List<int[]> dArr = new ArrayList<>();

			for (int j = 0; j < n; j++)
			{
				String outletsStr = reader.next();
				int[] o = new int[length];
				for (int k = 0; k < length; k++)
				{
					int onIsOne = Integer.parseInt("" + outletsStr.charAt(k));
					outlets[k] += onIsOne;
					o[k] = onIsOne;
				}
				oArr.add(o);
			}

			for (int j = 0; j < n; j++)
			{
				String devicesStr = reader.next();
				int[] d = new int[length];
				for (int k = 0; k < length; k++)
				{
					int onIsOne = Integer.parseInt("" + devicesStr.charAt(k));
					devices[k] += onIsOne;
					d[k] = onIsOne;
				}
				dArr.add(d);
			}

			// for (int[] o : outletsArr)
			// System.out.println(Arrays.toString(o));

			int count = 0;
			for (int x = 0; x < length; x++)
			{
				if (outlets[x] != devices[x])
				{
					if (n - outlets[x] == devices[x])
					{
						// System.out.println(x);
						count++;
						for (int[] o : oArr)
							o[x] = o[x] == 1 ? 0 : 1;
					}
					else
					{
						count = -1;
						break;
					}
				}
			}

			List<Solution> possibles = new LinkedList<>();
			Solution temp = new Solution();
			temp.config = oArr;
			temp.count = count;
			possibles.add(temp);
			if (count != -1)
			{
				for (int x = 0; x < length; x++)
				{
					if (outlets[x] == n - outlets[x])
					{
						List<Solution> clonePossible = new LinkedList<>(possibles);
						for (Solution aSol : possibles)
						{
							if (!equalSoFar(aSol.config, dArr, x + 1))
							{
								// System.out.println(x);
								aSol.count = aSol.count + 1;
								for (int[] o : aSol.config)
									o[x] = o[x] == 1 ? 0 : 1;
								if (!equalSoFar(aSol.config, dArr, x + 1))
								{
									if(!clonePossible.remove(aSol))
										System.out.println("MISSING");
								}
							}
							else
							{
								List<int[]> clone = new ArrayList<>();
								for (int[] tempConfig : aSol.config)
								{
									clone.add(Arrays.copyOf(tempConfig, tempConfig.length));
								}
								for (int[] o : clone)
									o[x] = o[x] == 1 ? 0 : 1;
								if (equalSoFar(clone, dArr, x + 1))
								{
									Solution s = new Solution();
									s.config = clone;
									s.count = aSol.count + 1;
									clonePossible.add(s);
								}
							}
						}
						possibles = clonePossible;
					}
				}
			}

			List<Solution> clonePossible = new LinkedList<>(possibles);
			for (Solution aSol : possibles)
			{
				if (!equalSoFar(aSol.config, dArr, length))
				{
					clonePossible.remove(aSol);
				}
			}
			
			
			count = -1;
			for (Solution fSol : clonePossible)
			{
				if (count == -1 || count > fSol.count)
					count = fSol.count;
			}

			// System.out.println("FLIPPED");
			// for (int[] o : outletsArr)
			// System.out.println(Arrays.toString(o));

			String output = count == -1 ? "NOT POSSIBLE" : "" + count;

			String result = "Case #" + (i + 1) + ": " + output;
			System.out.println(result);
			writer.write(result + "\n");

		}
		reader.close();
		writer.close();
	}

	private static boolean equalSoFar(List<int[]> outlets, List<int[]> devices, int upTo)
	{
		TreeSet<String> outletSort = new TreeSet<>(new Comparator<String>() {
			@Override
			public int compare(String o1, String o2)
			{
				int result = o1.compareTo(o2);
				return result == 0 ? -1 : result;
			}
		});
		TreeSet<String> deviceSort = new TreeSet<>(new Comparator<String>() {
			@Override
			public int compare(String o1, String o2)
			{
				int result = o1.compareTo(o2);
				return result == 0 ? -1 : result;
			}
		});
		for (int x = 0; x < outlets.size(); x++)
		{
			outletSort.add(Arrays.toString(Arrays.copyOf(outlets.get(x), upTo)));
			deviceSort.add(Arrays.toString(Arrays.copyOf(devices.get(x), upTo)));
		}

		Iterator<String> outletIter = outletSort.iterator();
		Iterator<String> deviceIter = deviceSort.iterator();

		// System.out.println("START");
		// for (String o : outletSort)
		// System.out.println(o);
		// System.out.println("DEVICE");
		// for (String o : deviceSort)
		// System.out.println(o);
		// System.out.println("END");

		while (outletIter.hasNext())
		{
			String o = outletIter.next();
			String d = deviceIter.next();
			// System.out.println(o + " :: " + d);
			if (!o.equals(d))
			{
				return false;
			}
		}
		return true;
	}

	private static int idGen = 0;

	private static class Solution
	{
		List<int[]> config;
		int count;
		int id;

		public Solution()
		{
			this.id = idGen++;
		}

		@Override
		public int hashCode()
		{
			final int prime = 31;
			int result = 1;
			result = prime * result + id;
			return result;
		}

		@Override
		public boolean equals(Object obj)
		{
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Solution other = (Solution) obj;
			if (id != other.id)
				return false;
			return true;
		}
	}
}
