import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;


public class mainClass {

	public static void main(String[] args) {
		File f = new File("A-small-attempt1.in");
		File out = new File("chargingChaos1.out");
		FileInputStream fin;
		Scanner sin = null;
		try {
			fin = new FileInputStream(f);
			FileWriter fout = new FileWriter(out);
			try {
				sin = new Scanner(fin);
				int numOfCases = sin.nextInt();
				for(int casenum = 0; casenum<numOfCases; casenum++)
				{
					int n = sin.nextInt();
					int l = sin.nextInt();
					int[] electricFlow = new int[n];
					for(int i=0; i<n; i++)
					{
						electricFlow[i] = sin.nextInt(2);
					}
					int[] devicesRequire = new int[n];
					for(int i=0; i<n; i++)
					{
						devicesRequire[i] = sin.nextInt(2);
					}
					
					//For the small data set, I'm just going to brute force this.
					//Basically, if there is some number I can xor each of the
					//required voltages with to get the currents, possibly in a different order
					//Then that's a solution.
					
					Arrays.sort(devicesRequire);
					int switchesFlipped = 0;
					boolean done = false;
					ArrayList<Integer> solutions = new ArrayList<Integer>();
					while(!(done))
					{
						int[] newFlow = new int[n];
						for(int i=0; i<n; i++)
						{
							newFlow[i] = (electricFlow[i])^(switchesFlipped); 
						}
						Arrays.sort(newFlow);
						boolean matching=true;
						for(int i=0; i<newFlow.length; i++)
						{
							if(newFlow[i]!=devicesRequire[i])
							{
								matching=false;
								break;
							}
						}
						if(matching)
							solutions.add(switchesFlipped);
						switchesFlipped++;
						if(switchesFlipped>=Math.pow(2, l+1))
							done = true;
					}
					try {
						fout.write("Case #" + (casenum+1) + ": ");
						if(solutions.size()==0)
						{
							fout.write("NOT POSSIBLE\n");
						}
						else
						{
							int min = l;
							for(Integer i: solutions)
							{
								int numOfBits = 0;
								int copy = i;
								while(copy>0)
								{
									if(copy%2==1)
										numOfBits++;
									copy>>=1;
								}
								if(numOfBits<min)
									min = numOfBits;				
							}
							fout.write(min + "\n");
						}
						fout.flush();
					} catch (IOException e1) {e1.printStackTrace();}
				}
			} finally {
				sin.close();
				fout.close();
			}
		}
		catch(IOException e)
		{}
	}
	
	
}
