import java.util.*;
import java.io.*;
public class A
{
  static int min=9999;
  public static boolean compare(ArrayList<String>tempSwitches, ArrayList<String>tempDevices)
  {
    ArrayList<String> switches=(ArrayList<String>)tempSwitches.clone();
    ArrayList<String> devices=(ArrayList<String>)tempDevices.clone();
    while(!devices.isEmpty())
    {
      if(switches.contains(devices.get(0)))
      {
        switches.remove(switches.indexOf(devices.get(0)));
        devices.remove(0);
      }
      else
        return false;
    }
    return true;
  }
  public static ArrayList<String> change(ArrayList<String>temp, int index)
  {
    ArrayList<String> switches=(ArrayList<String>)temp.clone();
    for(int x=0;x<switches.size();x++)
    {
      char[] tempString=switches.get(x).toCharArray();
      if(tempString[index]=='1')
      tempString[index]='0';
      else
        tempString[index]='1';
      switches.set(x,new String(tempString));
    }
    return switches;
  }
  public static void recur(ArrayList<String>switches,ArrayList<String>devices,int index,int l,int changes)
  {
    if(compare(switches,devices))
    {
      min=Math.min(min,changes);
      return;
    }
    for(int x=index+1;x<l;x++)
    {
      recur(change(switches,x),devices,x,l,changes+1);
    }
  }
  public static void main(String[]args)throws IOException
  {
    Scanner in=new Scanner(new FileReader("A-small-attempt1.in"));
    PrintWriter out=new PrintWriter(new FileWriter("A.out"));
    int num=in.nextInt();
    for(int asd=1;asd<=num;asd++)
    {
      out.print("Case #"+asd+": ");
      min=9999;
      int n=in.nextInt();
      int l=in.nextInt();
      ArrayList<String> switches=new ArrayList<String>();
      ArrayList<String> devices=new ArrayList<String>();
      for(int x=0;x<n;x++)
        switches.add(in.next());
      for(int x=0;x<n;x++)
        devices.add(in.next());
      recur(switches,devices,-1,l,0);
      if(min!=9999)
      out.println(min);
      else
        out.println("NOT POSSIBLE");
    }
    in.close();
    out.close();
  }
}