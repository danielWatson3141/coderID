import java.io.*;
import java.util.*;
import static java.lang.Math.*;
//import java.util.logging.Level;
//import java.util.logging.Logger;
public class Sample

{
     BufferedReader read;
     BufferedWriter write;
     static final long one=1L;
    public static void main(String args[])
    {
        
      //  System.out.println(9612*2169+"   "+(961*169));
        try {

            new Sample().init("A-small-attempt1");
        } catch (Exception ex) {
          //  Logger.getLogger(Sample.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
     void init(String name) throws Exception
    {
        read= rf(name+".in");
        write=wf(name+".out");
        String x="";
        x = read.readLine();
        int n = Integer.parseInt(x);
        for(int i=0;i<n;i++) result( i);
        write.flush(); write.close();read.close();
   }

void result(int p) throws Exception
{
    String s1="NOT POSSIBLE";
   String ss[]=read.readLine().split(" ");
   int n=i(ss[0]),l=i(ss[1]);
   long device[]=new long[n];
   long outlet[]=new long[n];
   ss=read.readLine().split(" ");
   for(int i=0;i<n;i++)device[i]=bl(ss[i]);
    ss=read.readLine().split(" ");
   for(int i=0;i<n;i++)outlet[i]=bl(ss[i]);
    Arrays.sort(device);
    int cd[]=new int[l],co[]=new int[l];
    for(int i=0;i<l;i++)for(int j=0;j<n;j++)
    {
       if((device[j]&(one<<i))!=0)cd[i]++;
       if((outlet[j]&(one<<i))!=0)co[i]++;
    }
    long ans=one<<25;
    for(int i=0;i<(one<<l);i++)
    {
       long out[]=new long[n];
       for(int j=0;j<n;j++)out[j]=outlet[j]^i;
       Arrays.sort(out);
       boolean done=true;
       for(int k=0;k<n;k++)if(device[k]!=out[k])done=false;
       if(done)ans=Math.min(ans,Integer.bitCount(i));
    }
    if(ans<(one<<25))
    s1=""+ans;
    System.out.println("Case #"+(p+1)+": "+s1);
    write.write("Case #"+(p+1)+": "+s1+"\n");
}
long bl(String s)
{
long p=0;
for(int i=0;i<s.length();i++)if(s.charAt(i)=='1')p|=one<<i;
return p;
}


boolean isPalindrome(long l)
{
   char c[]=(""+l).toCharArray();
   for(int i=0;i<c.length;i++)if(c[i]!=c[c.length-i-1])return false;
   return true;
}
int i(String s){return Integer.parseInt(s.trim());}
long l(String s){return Long.parseLong(s.trim());}
double d(String s){return Double.parseDouble(s.trim());}
 int[] sa(String s1){String s[]=s1.trim().split(" ");int p[]=new int[s.length];for(int i=0;i<s.length;i++)p[i]=Integer.parseInt(s[i]);return p;}
 long[] la(String s)
 {
     String s1[]=s.split(" ");
     long la[]=new long[s1.length];
     for(int i=0;i<s1.length;i++)la[i]=l(s1[i]);
     return la;
 }
 double [] ld(String s)
  {
    String s1[]=s.split(" ");
    int l=s1.length;
   double d[]=new double[l];
   for(int i=0;i<l;i++)d[i]=d(s1[i]);
   return d;
 }
static BufferedWriter wf(String s) throws Exception{return new BufferedWriter(new FileWriter(new File(s)));}
static BufferedReader rf(String s) throws Exception{return new BufferedReader(new FileReader(new File(s)));}
static BufferedReader ri() throws Exception{return new BufferedReader(new InputStreamReader(System.in));}
}
