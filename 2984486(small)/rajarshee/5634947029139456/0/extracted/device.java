
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
    static void display(String x[])
    {
        for(int i=0;i<x.length;i++)
        {
            System.out.print(x[i]+" ");
        }
    }
    
   
    public static void main(String args[])throws IOException
    {
        
        BufferedReader b=new BufferedReader(new InputStreamReader(System.in));
        int T=Integer.parseInt(b.readLine());
        Scanner s; int N,L;
        String outlet[],device[];
        for(int i=1;i<=T;i++)
        {
            s=new Scanner(b.readLine());
            N=s.nextInt();
            L=s.nextInt();
            outlet=new String[N];
            device=new String[N];
            s=new Scanner(b.readLine());
            for(int j=0;s.hasNext();j++)
                outlet[j]=s.next();
            s=new Scanner(b.readLine());
            for(int j=0;s.hasNext();j++)
                device[j]=s.next();
            int p=L+1;
            String temp[]=new String[N];
            for(int j=0;j<(int)Math.pow(2,L);j++)
            {
                String t=Integer.toBinaryString(j);
               
                for(int k=t.length();k<L;k++)
                    t="0"+t;
                for(int k=0;k<N;k++)
                {
                    temp[k]="";
                    for(int l=0;l<t.length();l++)
                    {
                        if(t.charAt(l)=='1')
                        {
                            if(outlet[k].charAt(l)=='1')
                                temp[k]+="0";
                            else
                                temp[k]+="1";
                        }
                        else
                            temp[k]+=outlet[k].charAt(l);
                    }
                }
                Arrays.sort(temp);
                Arrays.sort(device);
                int c=0;
                if(Arrays.equals(temp, device))
                {
                    for(int k=0;k<t.length();k++)
                    {
                        if(t.charAt(k)=='1')
                            c++;
                    }
                    p= Math.min(p, c);
                }
                
            }
       /*
            int c=-1,p=-1;
            for(int j=0;j<N;j++)
            {
                
                for(int k=0;k<L;k++)
                {
                    if(device[j].charAt(k)!=outlet[j].charAt(k))
                        c++;
                }
                if(p!=c&&c!=-1)
                {
                    System.out.println("Case #"+i+": NOT POSSIBLE");
                    break;
                }
                p=c;
            }
               */
            if(p==L+1)
                System.out.println("Case #"+i+": NOT POSSIBLE");
            else
            System.out.println("Case #"+i+": "+p);
        }
    }
}
