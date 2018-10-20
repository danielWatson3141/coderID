import java.util.*;
import java.io.*;
public class codeRound21
{
  static int count=100;
  public static void main (String[]args)throws IOException
  {
 //   Scanner s=new Scanner (new File("in.txt"));
         Scanner s=new Scanner (new File ("A-small-attempt1.in"));
    PrintWriter out=new PrintWriter (new FileWriter("out.txt"));
    int cases=s.nextInt();
    for (int n=0;n<cases;n++)
    {
      count=100;
      int devices=s.nextInt();
      int switches=s.nextInt();
      ArrayList<String> start=new ArrayList<String>();
      ArrayList<String> end=new ArrayList<String>();
      for (int x=0;x<devices;x++)
      {
        start.add(s.next());
      }
      
      for (int x=0;x<devices;x++)
      {
        end.add(s.next());
      }
                ArrayList<String> newArr3= new ArrayList<String>();
    newArr3.addAll(start);
      recurse (1,0,false,start,end);
      recurse (1,1,true,newArr3,end);
      out.print ("Case #"+(n+1)+": ");
      if (count==100)
        out.println ("NOT POSSIBLE");
      else out.println (count);
    }
    out.close();
  }
  public static boolean check(ArrayList<String>test,ArrayList<String>answer)
  {
    for (int c=0;c<answer.size();c++)
    {
      if (test.contains(answer.get(c)))
      {
        test.remove(test.indexOf(answer.get(c)));
      }
      else 
        return false;
    }
    return true;
  }
  public static void switchOn (int i, ArrayList<String> arr)
  {
    for (int v=0;v<arr.size();v++)
    {
      String temp=arr.get(v);
      if (temp.charAt(i-1)=='1')
        arr.set(v,temp.substring(0,i-1)+"0"+temp.substring(i));
      else
        arr.set(v,temp.substring(0,i-1)+"1"+temp.substring(i));
    }
  }
  public static void recurse (int switchNum,int moves, boolean onOff,ArrayList<String>arr, ArrayList<String>ans)
  {
    if (switchNum>arr.get(0).length())return;
    if (moves>count)return;
    
    if (onOff)
    {
      switchOn (switchNum, arr);
    }
    ArrayList<String> newArr= new ArrayList<String>();
    newArr.addAll(arr);
//System.out.println("1");
    if (check(newArr,ans))
    {
 //     System.out.println(switchNum+" "+moves+onOff);
//      for (int x=0;x<arr.size();x++)
//      {
//        System.out.print (arr.get(x)+" ");
//      }
//      System.out.println();
//      for (int x=0;x<arr.size();x++)
//      {
//        System.out.print (ans.get(x)+" ");
//      }
//            System.out.println();
      if (moves<count)
        count=moves;
      return;
    }
    
    else
    {
          ArrayList<String> newArr2= new ArrayList<String>();
    newArr2.addAll(arr);
      recurse(switchNum+1,moves+1,true,arr,ans);
      recurse(switchNum+1,moves,false,newArr2,ans);
    }     
    
  }
}
