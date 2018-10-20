//Christian Wen
//Charging Chaos

import java.util.*;
import java.io.*;

public class chargingChaos {
  
  public static void main (String args[]) throws IOException {
    
    int tests;
    int num;
    int length;
    int changes [];
    int lowest;
    
    String s;
    String stringArray [];
    String initial [];
    String needed [];
    String altered [];
    
    boolean check;
    
    BufferedReader bis = new BufferedReader(new FileReader("A-small-attempt1.in"));
    
    Writer writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("output.txt"), "utf-8"));
    
    s = bis.readLine();
    tests = Integer.parseInt(s);
    
    for (int i = 1; i <= tests; i++)
    {
      lowest = 9999;
      
      s = bis.readLine();
      stringArray = s.split (" ");
      num = Integer.parseInt(stringArray[0]);
      length = Integer.parseInt(stringArray[1]);
      
      s = bis.readLine();
      initial = s.split(" ");
      
      s = bis.readLine();
      needed = s.split (" ");
      
      Arrays.sort (needed);
      
      altered = new String [num];
      
      changes = new int [length];
      
      for (int x = 0; x < length; x++)
      {
        changes[x] = 0;
      }
      
      for (int x = 0; x < num; x++)
      {
        altered[x] = initial[x];
      }
      Arrays.sort (altered);
      
      check = true;
      boolean actualCheck = true;
      int blah = 0;
      while (check)
      {
        if (altered [blah].equals (needed[blah]))
        {
        }
        else
        {
          check = false;
          actualCheck = false;
        }
        blah++;
        if (blah == num)
          check = false;
      }
      if (actualCheck)
      {
        lowest = 0;
      }
          
      for (int x = 1; x < (Math.pow(2,length)-1); x++)
      {
        changes = addOne(changes, length);
        for (int y = 0; y < num; y ++)
        {
          altered[y] = alterString(length, changes, initial [y]);
                   
        }
        Arrays.sort (altered);
        
        check = true;
        actualCheck = true;
        int z = 0;
        while (check)
        {
          if (altered [z].equals (needed[z]))
          {
          }
          else
          {
            check = false;
            actualCheck = false;
          }
          z++;
          if (z == num)
          check = false;
        }
        if (actualCheck)
        {
          int countOnes = 0;
          
          for (int y = 0; y < length; y++)
          {
            if (changes[y]==1)
            {
              countOnes++;
            }
          }
          if (countOnes < lowest)
          {
            lowest = countOnes;
          }
          
        }
      }
      
      if (lowest == 9999)
      {
      writer.write("Case #" + i + ": " + "NOT POSSIBLE" + "\n");
      }
      else
      {
        writer.write("Case #" + i + ": " + lowest + "\n");
      }
      System.out.println(i);
    }
    
    writer.close();
  }
  
  public static String alterString (int length, int changes [], String input)
  {
    String output = "";
    for (int x = 0; x < length; x++)
    {
      if (changes[x] == 0)
      {
        if (input.charAt(x) == '0')
        {
        output += "0";
        }
        else
        {
          output += "1";
        }
      }
      else
      {
        if (input.charAt(x) == '1')
        {
        output += "0";
        }
        else
        {
          output += "1";
        }
      }
    }
    return output;
    
  }
                                      
  private static int [] addOne (int input [], int length)
  {
    input [0] = input [0] + 1;
    for (int x = 0; x < length; x++)
    {
      if ( input[x] == 2)
      {
        input[x+1] = input [x+1] + 1;
        input [x] = 0;
      }
    }
    return input;
  }
  
}
      
     
      
      