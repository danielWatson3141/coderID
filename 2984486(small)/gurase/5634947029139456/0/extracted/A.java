import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/**
 * 
 * @author gmann
 */
public class A
{

	private BufferedReader reader;
	private BufferedWriter writer;

	/**
	 * @param args
	 *            the command line arguments
	 */
	public static void main(String[] args)
	{
		A a = new A(args[0]);
		a.runTests();
	}

	public A(String fileName)
	{
		// Open file
		File file = new File(fileName);
		try
		{
			reader = new BufferedReader(new FileReader(file));
			writer = new BufferedWriter(new FileWriter(file + ".out"));
		}
		catch (IOException e)
		{
			// Failed to open new buffered reader
			System.err.println("Failed to open FileReader");
			e.printStackTrace();
			System.exit(-1);
		}
	}

	private void runTests()
	{
		// Read number of test cases
		int numberOfTests = 0;

		try
		{
			// Read number of tests (first line)
			numberOfTests = Integer.parseInt(reader.readLine());
		}
		catch (NumberFormatException | IOException e)
		{
			// Failed to read a line
			System.err.println("Failed to read a line");
			e.printStackTrace();
			System.exit(-1);
		}

		for (int testCase = 1; testCase <= numberOfTests; testCase++)
		{
			try
			{
				String[] input = reader.readLine().split(" ");
				
				int numOutlets = Integer.valueOf(input[0]);
				int numBits = Integer.valueOf(input[1]);
				
				Set<Integer> expectedFlow = new HashSet<>();
				Set<Integer> actualFlow = new HashSet<>();
				String[] expectedFlowLine = reader.readLine().split(" ");
				String[] actualFlowLine = reader.readLine().split(" ");
				
				for (int i = 0; i < numOutlets; i++)
				{
					Integer expectedOutlet = Integer.parseInt(expectedFlowLine[i], 2);
					Integer actualOutlet = Integer.parseInt(actualFlowLine[i], 2);
					expectedFlow.add(expectedOutlet);
					actualFlow.add(actualOutlet);
				}
				
				Integer numSwitches = findSwitches(numBits, expectedFlow, actualFlow);
				
				String response = "NOT POSSIBLE";
				if (numSwitches != 999)
				{
					response = numSwitches.toString();
				}

				writer.write("Case #" + testCase + ": " + response);
				writer.newLine();
			}
			catch (IOException e)
			{
				e.printStackTrace();
			}
		}

		try
		{
			reader.close();
			writer.flush();
			writer.close();
		}
		catch (IOException e)
		{
			e.printStackTrace();
		}
	}
	
	public Integer findSwitches(int numBits, Set<Integer> expectedFlow, Set<Integer> actualFlow)
	{
		List<Integer> currentActual = new ArrayList<>();
		Integer best = 999;
		for (int i = 0; i < Math.pow(2, numBits); i++)
		{
			for (Integer outlet : actualFlow)
			{
				currentActual.add(outlet ^ i);
			}
			
			if (currentActual.containsAll(expectedFlow) && Integer.bitCount(i) < best)
			{
				best = Integer.bitCount(i);
			}
			
			currentActual.clear();
		}
		
		return best;
	}
}
