import java.util.*;
import java.io.*;
public class C
{
  public static void main(String[]args)throws IOException
  {
    Scanner in=new Scanner(new FileReader("C-small-attempt0.in"));
    PrintWriter out=new PrintWriter(new FileWriter("C.out"));
    int n=in.nextInt();
    for(int asd=1;asd<=n;asd++)
    {
      out.print("Case #"+asd+": ");
      int size=in.nextInt();
      boolean good=true;
      for(int x=0;x<size;x++)
        if(in.nextInt()==x)
      {
        good=false;
        break;
      }
      if(good)
        out.println("GOOD");
      else
        out.println("BAD");
    }
    in.close();
    out.close();
  }
}