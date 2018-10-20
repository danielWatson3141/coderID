
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author David
 */
public class Switches {
    static int[][] diff;
    public static void main (String[] args) throws IOException
    {
        Scanner in = new Scanner(new BufferedReader(new FileReader("input.in")));
        PrintWriter out = new PrintWriter(new FileWriter("output.txt"));
        int cases = Integer.parseInt(in.next());
        for (int i = 1; i <= cases; i++)
        {
            int n = Integer.parseInt(in.next());
            int l = Integer.parseInt(in.next());
            outlets = new ArrayList<String>();
            for(int j = 0; j < n; j++)
            {
                outlets.add(in.next());
            }
            devices = new ArrayList<String>();
            for(int j = 0; j < n; j++)
            {
                devices.add(in.next());
            }
            int min = 9999;
            for(int j = 0;j < n; j++)
            {
                difference(outlets.get(0), devices.get(j));
                if(switches.size() < min)
                {
                    if(check())
                    {
                        min = switches.size();
                    }
                }
            }
            out.printf("Case #%d: ", i);
            if(min!=9999) out.println(min);
            else out.println("NOT POSSIBLE");
        }
        out.close();
    }
    static boolean check()
    {
        ArrayList<String> temp = (ArrayList<String>)outlets.clone();
        
        for(String device : devices)
        {
            for(int index :switches)
            {
                if(device.charAt(index)=='0')
                {
                    device = device.substring(0, index) + "1"+device.substring(index+1);
                }
                else
                {
                    device = device.substring(0, index) + "0"+device.substring(index+1);
                }
            }
            if(temp.contains(device))
            {
                temp.remove(temp.indexOf(device));
            }
            else return false;
        }
        return true;
    }
    static ArrayList<Integer> switches;
    static ArrayList<String> outlets;
    static ArrayList<String> devices;
    static void difference(String outlet, String device)
    {
        switches = new ArrayList<Integer>();
        
        for (int i = 0; i < outlet.length(); i++)
        {
            if(outlet.charAt(i)!=device.charAt(i)) switches.add(i);
        }
       
    }
}
