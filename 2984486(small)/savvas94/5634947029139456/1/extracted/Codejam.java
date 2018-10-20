/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.UnsupportedEncodingException;
import java.util.Scanner;

/**
 *
 * @author Savvas
 */
public class Codejam {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException, IOException {
        // TODO code application logic here
        
        BufferedWriter output = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("output.txt")));
        BufferedReader input = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt"), "cp1253"));
        
        Scanner in = new Scanner(input);
        int numOfCases = in.nextInt();
        
        for (int ppp = 0; ppp < numOfCases; ppp++) {        
        
            int n = in.nextInt();
            int l = in.nextInt();
            String[] outlets;
            String[] devices;
in.nextLine();
            String line1 = in.nextLine();
            String line2 = in.nextLine();
            outlets = line1.split(" ");
            devices = line2.split(" ");
               
            int min = l+1;

            StringBuilder tempOut;
            boolean[] switches = new boolean[l];
            boolean[] selectedDevs = new boolean[n];

            for (int i = 0; i < devices.length; i++) {
                String dev = devices[i];
                boolean flag2 = true;
                for (int j = 0; j < outlets.length; j++) {

                    for (int aa = 0; aa < switches.length; aa++) {
                        switches[aa] = false;
                    }
                    for (int k = 0; k < selectedDevs.length; k++) {
                        selectedDevs[k] = false;
                    }
                    selectedDevs[i] = true;

                    tempOut = new StringBuilder(outlets[j]);
                    int counter = 0;
                    for (int k = 0; k < l; k++) {
                        if(dev.charAt(k)!=tempOut.charAt(k))
                        {
                            if(tempOut.charAt(k)=='0'){
                                tempOut.setCharAt(k, '1');
                            }
                            else{
                                tempOut.setCharAt(k, '0');
                            }
                            switches[k] = true;
                            ++counter;
                        }
                    }
                    for (int k = 0; k < outlets.length; k++){
                        if(k!=j)
                        {
                            tempOut = new StringBuilder(outlets[k]);
                            for (int m = 0; m < l; m++) {
                                if(switches[m]){
                                    if(tempOut.charAt(m)=='0'){
                                        tempOut.setCharAt(m, '1');
                                    }
                                    else{
                                        tempOut.setCharAt(m, '0');
                                    }
                                }
                            }
                            boolean flag = false;
                            for (int m = 0; m < selectedDevs.length; m++) {
                                if(!selectedDevs[m])
                                {
                                    if(tempOut.toString().equals(devices[m]))
                                    {
                                        selectedDevs[m]=true;
                                        flag = true;
                                        break;
                                    }
                                }

                            }
                            if(!flag){
                                break;
                            }

                        }                    
                    }


                    for (int k = 0; k < selectedDevs.length; k++) {
                        if(!selectedDevs[k]){
                            flag2=false;
                            break;
                        }                    
                    }

                    if(flag2){
                        if(counter<min){
                            min = counter;
                        }
                    }
                }

            }
            output.append("Case #"+(ppp+1)+": ");
            if(min<=l){
                output.append(""+min);
            }
            else{
                output.append("NOT POSSIBLE");
            }
            output.newLine();
        }
        output.close();
        
    }
}
