/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package googlecodejam2014_r2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

/**
 *
 * @author Miguel Alejo
 */
public class ChargingChaos {

    private static int numCases;
    private static double c, f, x;
    private static final Scanner scan = new Scanner(System.in);
    private static final double[] tiempos = new double[100];
    private static final String[] iniciales = new String[150];
    private static final String[] finales = new String[150];
    private static List<Integer> cantidades = new ArrayList<>();

    private static List<Integer> resultados = new ArrayList<Integer>();

    private static List<List<Set<Integer>>> evalFinales = new ArrayList<>();

    public static void main(String args[]) throws IOException {

        int N = 0;
        int L = 0;

        numCases = scan.nextInt();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        for (int nu = 0; nu < numCases; nu++) {
            evalFinales = new ArrayList<>();
            N = scan.nextInt();
            L = scan.nextInt();

            
            String nada1 = scan.nextLine();
            
            
            
             String temp = scan.nextLine();
             String[] tokens = temp.split(" ");
             for (int i = 0; i < N; i++) {
             iniciales[i] = tokens[i];
             }

             temp = scan.nextLine();
             tokens = temp.split(" ");
             for (int i = 0; i < N; i++) {
             finales[i] = tokens[i];
             }
             
            
           // String scan.nextLine();
            
            
            
        /*    ArrayList<String> result = new ArrayList<String>();
            String line = "";
            while ((line = scan.nextLine()) != null) {
                result.add(line);
            }
*/

            /*String temp = br.readLine();
             String[] tokens = temp.split(" ");
             for (int i = 0; i < N; i++) {
             iniciales[i] = tokens[i];
             }

             temp = br.readLine();
             tokens = temp.split(" ");
             for (int i = 0; i < N; i++) {
             finales[i] = tokens[i];
             }
             */
            /*for (int i = 0; i < N; i++) {
                
                
                
             iniciales[i] = scan.nextLine();
             }
            
             for (int i = 0; i < N; i++) {
             finales[i] = scan.nextLine();
             }
             */
            for (int i = 0; i < N; i++) {
                evalFinales.add(contenido(iniciales[i], N));
            }
            List<Set<Integer>> autxLis = evalFinales.get(0);

            cantidades = new ArrayList<>();

            for (int j = 0; j < N; j++) {
                Set<Integer> auxHash = autxLis.get(j);

                boolean lotienentodos = true;

                for (int k = 1; k < evalFinales.size(); k++) {
                    List<Set<Integer>> aTemp = evalFinales.get(k);

                    boolean locontiene = false;

                    for (int l = 0; l < N; l++) {
                        Set<Integer> sTemp = aTemp.get(l);
                        if (auxHash.equals(sTemp)) {
                            locontiene = true;
                            break;
                        }
                    }
                    if (!locontiene) {
                        lotienentodos = false;
                        break;
                    }
                }

                if (lotienentodos) {
                    cantidades.add(auxHash.size());
                }
            }

            if (cantidades.isEmpty()) {
                resultados.add(-1);
                //System.out.println("Case #2: NOT POSSIBLE");
            } else {
                // buscar el minimo tamanio
                int minimo = cantidades.get(0);
                for (int i = 1; i < cantidades.size(); i++) {
                    int auxint = cantidades.get(i);
                    if (auxint < minimo) {
                        minimo = auxint;
                    }
                }
                resultados.add(minimo);
                //System.out.println("Case #3: "+minimo);            
            }
        }

        for (int otro = 0; otro < numCases; otro++) {
            if (resultados.get(otro).intValue() != -1) {
                System.out.println("Case #" + (otro + 1) + ": " + resultados.get(otro));
            } else {
                System.out.println("Case #" + (otro + 1) + ": NOT POSSIBLE");
            }
        }


        /*for (int i = 0; i < evalFinales.size(); i++) {

         System.out.println(" eval: " + i + ": " + evalFinales.get(i));
         }*/
        //  //print(iniciales, N);
        // print(finales, N);
    }

    private static List<Set<Integer>> contenido(String token, int N) {
        List<Set<Integer>> lista = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            lista.add(evaluacion(token, finales[i]));
        }
        return lista;
    }

    private static Set<Integer> evaluacion(String token1, String token2) {
        HashSet<Integer> set = new HashSet<>();

        for (int i = 0; i < token1.length(); i++) {
            if (token1.charAt(i) != token2.charAt(i)) {
                set.add(i);
            }
        }
        return set;
    }

    private static void print(String a[], int N) {
        for (int i = 0; i < N; i++) {
            System.out.println("" + a[i]);
        }

    }

}
