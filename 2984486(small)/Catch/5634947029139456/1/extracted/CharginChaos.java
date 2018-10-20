import java.io.*;
import java.util.*;

public class CharginChaos
{
  public static void main (String [] args) throws IOException
  {
    BufferedReader read = new BufferedReader (new FileReader ("A-large.in"));
    PrintWriter print = new PrintWriter (new FileWriter ("output.txt"));
    int iterations = Integer.parseInt (read.readLine ());
    for (int count = 1; count <= iterations; count ++)
    {
      String [] inputs = read.readLine ().split (" ");
      boolean [] [] starting = new boolean [Integer.parseInt (inputs [0])][Integer.parseInt (inputs [1])];
      boolean [] [] ending = new boolean [Integer.parseInt (inputs [0])][Integer.parseInt (inputs [1])];
      String [] line1 = read.readLine ().split (" ");
      String [] line2 = read.readLine ().split (" ");
      for (int x = 0; x < line1.length; x ++)
      {
        for (int y = 0; y < line1 [x].length (); y ++)
        {
          if (line1 [x].charAt (y) == '1')
            starting [x][y] = true;
          else
            starting [x][y] = false;
          if (line2 [x].charAt (y) == '1')
            ending [x][y] = true;
          else
            ending [x][y] = false;
        }
      }
      int lowest = 200;
      for (int x = 0; x < starting.length; x ++)//go through different change values
      {
        boolean [] switchPresses = new boolean [Integer.parseInt (inputs [1])];//whether or not switch at position is switched. 
        for (int z = 0; z < switchPresses.length; z ++)
          switchPresses [z] = false;
        for (int y = 0; y < Integer.parseInt (inputs [1]); y ++)//set switch values to the start changing values. 
        {
          if ((starting [x][y] && !ending [0][y]) || (!starting [x][y] && ending [0][y]))
            switchPresses [y] = true;
        }
        boolean works = true;
        for (int z = 0; z < starting.length; z ++)//check if works for each case. 
        {
          boolean [] cases = new boolean [switchPresses.length];
          for (int w = 0; w < switchPresses.length; w ++)
          {
            if (switchPresses [w])
              cases [w] = !starting [z][w];
            else
              cases [w] = starting [z][w];
          }
          boolean within = false;
          for (int q = 0; q < starting.length; q ++)//check if starting value is inside ending values
          {
            boolean same = true;
            for (int e = 0; e < switchPresses.length; e ++)
            {
              if (cases [e] != ending [q][e])
                same = false;
            }
            if (same)
              within = true;
          }
          if (!within)
            works = false;
        }
        if (works)
        {
          int numberOfSwitches = 0;
          for (int z = 0; z < switchPresses.length; z ++)
            if (switchPresses [z])
            numberOfSwitches ++;
          if (numberOfSwitches < lowest)
            lowest = numberOfSwitches;
        }
      }
      print.print ("Case #" + count + ": ");
      if (lowest != 200)
        print.println (lowest);
      else
        print.println ("NOT POSSIBLE");
    }
    print.close ();
  }
}