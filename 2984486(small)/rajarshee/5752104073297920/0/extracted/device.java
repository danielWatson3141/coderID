
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author rajarshee
 */
class device {
  
   
    public static void main(String args[])throws IOException
    {
        
        BufferedReader b=new BufferedReader(new InputStreamReader(System.in));
        int T=Integer.parseInt(b.readLine());
        Scanner s; 
        for(int i=1;i<=T;i++)
        {
            s=new Scanner(b.readLine());
            int r=(int)(Math.random()*100);
            if(r%2==0)
                System.out.println("Case #"+i+": BAD");
            else
                System.out.println("Case #"+i+": GOOD");
           
        }
    }
}
