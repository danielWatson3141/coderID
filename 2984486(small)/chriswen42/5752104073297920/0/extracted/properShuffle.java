//Christian Wen
//Proper Shuffle

import java.util.*;
import java.io.*;

public class properShuffle {
  
  public static void main (String args[]) throws IOException {
    
    int tests;
    int number [];
    double count;
    int z;
    
    boolean check;
    boolean actualCheck;
    
    String s;
    String stringArray [];
    
    BufferedReader bis = new BufferedReader(new FileReader("C-small-attempt10.in"));
    
    Writer writer = new BufferedWriter(new OutputStreamWriter(
    new FileOutputStream("output.txt"), "utf-8"));
    
    s = bis.readLine();
    tests = Integer.parseInt(s);
    
    for (int i = 1; i <= tests; i++)
    {
      s = bis.readLine();
      s = bis.readLine();
      count = 0;
      stringArray = s.split(" ");
      
      number = new int [1000];
      
      for (int y = 0; y < 1000; y++)
      {
        number[y] = Integer.parseInt(stringArray[y]);
      }
      
      for (int x = 1; x < 999; x++)
      {
        
        if (x == number [x])
        {
          if (x > 250 && x <= 750)
          {
            count = count - 1.5;
          }
          else
          {
            count--;
          }
          
        }
        else if (number[x-1]==x)
        {
          if (x <= 250 || x > 750)
          {
            count = count + 1.5;
          }
          else
          {
            count++;
          }
        }
        check = false;
        
        for(int y = x+1; y < x+501 ; y ++)
        {
          if (y >= 1000)
          {
            z= y-1000;
          }
          else
          {
            z=y;
          }
          if (number[z] == x)
          {
            check = true;
          }
        }
        if (check)
        {
          count = count - 0.5;
        }
        else
        {
          count = count + 0.5;
        }
      }
      if (count >= 1)
      {
      writer.write("Case #" + i + ": " + "BAD" + "\n");
      }
      else
      {
        writer.write("Case #" + i + ": " + "GOOD" + "\n");
      }
      
    }
    
    writer.close();
  }
}
      