package ronda1A;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;


public class ProblemC {
	
	final static String NOMBRE_PROBLEMA = "C";
    final static String DIRECTORIO = "C:/GCJ/1A/" + NOMBRE_PROBLEMA + "/";
    final static String NOMBRE_ENTRADA = "C-small-attempt0.in";
    final static String NOMBRE_SALIDA = "output.txt";
	
    public void resolver(Scanner sc, PrintWriter pw) throws InterruptedException
    {
    	int N = sc.nextInt();
    	
    	int numbers[] = new int[N];
    	int points = N;
    	
    	for (int i = 0; i < N; i++)
    	{
    		if (numbers[i] == i)
    			points -= 25;
    		if (i > 0 && numbers[i] > numbers[i-1])
    			points -= 15;
    		if (i > 0 && numbers[i] == numbers[i-1] + 1)
    			points -= 45;
    	}
    	
    	System.out.println(points);
    	if (points >= 333)
    		pw.println("GOOD");
    	else
    		pw.println("BAD");
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
            new ProblemC().resolver(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }

}
