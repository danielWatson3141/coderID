package ronda1A;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Locale;
import java.util.Scanner;


public class ProblemA {
	
	final static String NOMBRE_PROBLEMA = "A";
    final static String DIRECTORIO = "C:/GCJ/1A/" + NOMBRE_PROBLEMA + "/";
    final static String NOMBRE_ENTRADA = "A-small-attempt1.in";
    final static String NOMBRE_SALIDA = "out.txt";
    
    
    int L;
    long number[] = {0};
    BitSet mask;
    
    public void nextSwitch(BitSet[] switches)
    {
    	mask = BitSet.valueOf(number);
    	System.out.println(number[0] + " + " + mask);

    	for (int i = 0; i < switches.length; i++)
    	{
    		System.out.println("Switches " + i + " = " + switches[i]);
    		switches[i].xor(mask);
    		System.out.println("xor " + i + " = " + switches[i]);
    	}
    	
    	number[0]++;
    }

    
    public int checkall(BitSet[] devices, BitSet[] switches)
    {
    	System.out.println("Check " + Arrays.toString(devices) + " - " + Arrays.toString(switches));
    	int positives = 0;
    	for (int d = 0; d < devices.length; d++)
    	{
    		for (int s = 0; s < switches.length; s++)
    		{
    			if (devices[d].equals(switches[s]))
    			{
    				positives++;
    				break;
    			}
    		}
    	}
    	
    	return positives;
    }
   
    
	
    public void resolver(Scanner sc, PrintWriter pw) throws InterruptedException
    {
    	int N = sc.nextInt();
    	L = sc.nextInt();
    	
    	mask = new BitSet(L);
    	
    	BitSet devices[] = new BitSet[N];
    	BitSet switches[] = new BitSet[N];
    	
    	for (int i = 0; i < N; i++)
    	{
    		String binary = String.format("%"+L+"s", sc.nextBigInteger().toString()).replace(' ', '0');
    		devices[i] = new BitSet(binary.length());
    		
    		for (int k = 0; k < binary.length(); k++)
    		{
    			if( binary.charAt(k) == '1' )
    				devices[i].set(k);
    		}
    		
    		System.out.println(devices[i]);
    	}
    	
    	for (int i = 0; i < N; i++)
    	{
    		String binary = String.format("%"+L+"s", sc.nextBigInteger().toString()).replace(' ', '0');
    		switches[i] = new BitSet(binary.length());
    		
    		for (int k = 0; k < binary.length(); k++)
    		{
    			if( binary.charAt(k) == '1' )
    				switches[i].set(k);
    		}
    		
    		System.out.println(switches[i]);
    	}
    	
    	
    	// Check
    	int remaining = 2 << L;
    	System.out.println(remaining);
    	int positives = checkall(devices, switches);
    	System.out.println("positives = " + positives);
    	while (positives < N && remaining != 0)
    	{
    		BitSet[] aux = new BitSet[switches.length];
    		
    		for (int i = 0; i < switches.length; i++)
    			aux[i] = (BitSet) switches[i].clone();
    		
    		System.out.println("==Switches1" + Arrays.toString(switches));
    		nextSwitch(aux);
    		System.out.println("==Switches2" + Arrays.toString(switches));
    		positives = checkall(devices, aux);
    		System.out.println("positives = " + positives);
    		remaining--;
    		System.out.println(mask);
    	}
    	
    	System.out.println(mask);
    	System.out.println(mask.cardinality());
    	
    	if (remaining == 0)
    		pw.println("NOT POSSIBLE");
    	else
    		pw.println(mask.cardinality());
     }

	public static void main(String[] args) throws Exception {
		System.out.println(NOMBRE_PROBLEMA);
        Scanner sc = new Scanner(new FileReader(DIRECTORIO + NOMBRE_ENTRADA));
        sc.useLocale(new Locale("en"));
        PrintWriter pw = new PrintWriter(new FileWriter(DIRECTORIO + NOMBRE_SALIDA));
        int ncasos = sc.nextInt();
        for (int casoNum = 0; casoNum < ncasos; casoNum++) {
            System.out.println("Procesando caso " + (casoNum + 1));
            pw.print("Case #" + (casoNum+1) + ": ");
            new ProblemA().resolver(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }

}
