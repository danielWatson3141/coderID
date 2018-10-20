
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;


public class Program3
{
  public long createSwitch(int[] metadata, String initial[],String required[])
  {
  long ans=0;
  int valid[] = getValid(initial,required);
  Boolean b= false;
    b= checkforEqual(initial,required);
  if(b==true)
    return 0;
  for(int length=1;length<=valid.length;length++)
  {
    switch(length)
    {
      case 1:
        for(int i=0;i<valid.length;i++)
        {
          int num [] = {valid[i]};
          b = compare(num,initial,required);
          if(b==true)
            return length;
        }
        break;
      case 2:
        for(int i=0;i<valid.length;i++)
        {
          for(int j=i+1;j<valid.length;j++)
          {
            int num[] = {valid[i],valid[j]};
            b = compare(num,initial,required);
            if(b==true)
              return length;
          }
        }
        break;
      case 3:
        for(int i1=0;i1<valid.length;i1++)
        {
          for(int i2=i1+1;i2<valid.length;i2++)
          {
            for(int i3=i2+1;i3<valid.length;i3++)
            {
              int num[] = {valid[i1],valid[i2],valid[i3]};
              b = compare(num,initial,required);
              if(b==true)
                return length;
            }
          }
        }

        break;
      case 4:
        for(int i4=0;i4<valid.length;i4++)
        {
          for(int i1=i4+1;i1<valid.length;i1++)
        {
          for(int i2=i1+1;i2<valid.length;i2++)
          {
            for(int i3=i2+1;i3<valid.length;i3++)
            {
              int num[] = {valid[i1],valid[i2],valid[i3],valid[i4]};
              b = compare(num,initial,required);
              if(b==true)
                return length;
            }
          }
        }
        }
        break;
      case 5:
        for(int i5=0;i5<valid.length;i5++)
        {
        for(int i4=i5+1;i4<valid.length;i4++)
        {
          for(int i1=i4+1;i1<valid.length;i1++)
          {
            for(int i2=i1+1;i2<valid.length;i2++)
            {
              for(int i3=i2+1;i3<valid.length;i3++)
              {
                int num[] = {valid[i1],valid[i2],valid[i3],valid[i4],valid[i5]};
                b = compare(num,initial,required);
                if(b==true)
                  return length;
              }
            }
          }
        }
        }
        break;
      case 6:
        for(int i6=0;i6<valid.length;i6++)
        {
          for(int i5=i6+1;i5<valid.length;i5++)
          {
            for(int i4=i5+1;i4<valid.length;i4++)
            {
              for(int i1=i4+1;i1<valid.length;i1++)
              {
                for(int i2=i1+1;i2<valid.length;i2++)
                {
                  for(int i3=i2+1;i3<valid.length;i3++)
                  {
                    int num[] = {valid[i1],valid[i2],valid[i3],valid[i4],valid[i5],valid[i6]};
                    b = compare(num,initial,required);
                    if(b==true)
                      return length;
                  }
                }
              }
            }
          }
        }
        break;
      case 7:
        for(int i7=0;i7<valid.length;i7++)
        {
          for(int i6=i7+1;i6<valid.length;i6++)
        {
          for(int i5=i6+1;i5<valid.length;i5++)
          {
            for(int i4=i5+1;i4<valid.length;i4++)
            {
              for(int i1=i4+1;i1<valid.length;i1++)
              {
                for(int i2=i1+1;i2<valid.length;i2++)
                {
                  for(int i3=i2+1;i3<valid.length;i3++)
                  {
                    int num[] = {valid[i1],valid[i2],valid[i3],valid[i4],valid[i5],valid[i6],valid[i7]};
                    b = compare(num,initial,required);
                    if(b==true)
                      return length;
                  }
                }
              }
            }
          }
        }
    }
        break;
      case 8:
        for(int i8=0;i8<valid.length;i8++)
        {
          for(int i7=i8+1;i7<valid.length;i7++)
          {
            for(int i6=i7+1;i6<valid.length;i6++)
            {
              for(int i5=i6+1;i5<valid.length;i5++)
              {
                for(int i4=i5+1;i4<valid.length;i4++)
                {
                  for(int i1=i4+1;i1<valid.length;i1++)
                  {
                    for(int i2=i1+1;i2<valid.length;i2++)
                    {
                      for(int i3=i2+1;i3<valid.length;i3++)
                      {
                        int num[] = {valid[i1],valid[i2],valid[i3],valid[i4],valid[i5],valid[i6],valid[i7],valid[i8]};
                        b = compare(num,initial,required);
                        if(b==true)
                          return length;
                      }
                    }
                  }
                }
              }
            }
          }
        }
        break;
      case 9:
        for(int i9=0;i9<valid.length;i9++)
        {
          for(int i8=i9+1;i8<valid.length;i8++)
          {
            for(int i7=i8+1;i7<valid.length;i7++)
            {
              for(int i6=i7+1;i6<valid.length;i6++)
              {
                for(int i5=i6+1;i5<valid.length;i5++)
                {
                  for(int i4=i5+1;i4<valid.length;i4++)
                  {
                    for(int i1=i4+1;i1<valid.length;i1++)
                    {
                      for(int i2=i1+1;i2<valid.length;i2++)
                      {
                        for(int i3=i2+1;i3<valid.length;i3++)
                        {
                          int num[] = {valid[i1],valid[i2],valid[i3],valid[i4],valid[i5],valid[i6],valid[i7],valid[i8],valid[i9]};
                          b = compare(num,initial,required);
                          if(b==true)
                            return length;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        break;
      case 10:
        for(int i10=0;i10<valid.length;i10++)
        {
          for(int i9=0;i9<valid.length;i9++)
          {
            for(int i8=i9+1;i8<valid.length;i8++)
            {
              for(int i7=i8+1;i7<valid.length;i7++)
              {
                for(int i6=i7+1;i6<valid.length;i6++)
                {
                  for(int i5=i6+1;i5<valid.length;i5++)
                  {
                    for(int i4=i5+1;i4<valid.length;i4++)
                    {
                      for(int i1=i4+1;i1<valid.length;i1++)
                      {
                        for(int i2=i1+1;i2<valid.length;i2++)
                        {
                          for(int i3=i2+1;i3<valid.length;i3++)
                          {
                            int num[] = {valid[i1],valid[i2],valid[i3],valid[i4],valid[i5],valid[i6],valid[i7],valid[i8],valid[i9],valid[i10]};
                            b = compare(num,initial,required);
                            if(b==true)
                              return length;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        break;


    }
  }
  return 100;
  }


  public boolean compare(int num1[],String[] initial,String required[])
  {

    String initial1[] = new String[initial.length];
    int ptr=0;
    for(String s : initial)
    {
      StringBuilder sb = new StringBuilder(s);
      for(int num:num1)
      {
        if(sb.charAt(num)=='0')
          sb.replace(num,num+1,"1");
        else
          sb.replace(num,num+1,"0");
      }
      initial1[ptr] = sb.toString();
      ptr++;
    }
    return checkforEqual(initial1,required);
  }


  public int[] getValid(String initial[],String req[])
  {
    ArrayList<Integer> validList = new ArrayList<Integer>();
    for(int i=0;i<initial[0].length();i++)
    {
     int count1=0,count2=0;
     for(String s: initial)
     {
       if(s.charAt(i)=='0')
         count1++;
     }
     for(String r:req)
     {
       if(r.charAt(i)=='1')
         count2++;
     }
     if(count1==count2)
       validList.add(i);
    }
    int size = validList.size();
    int output[] = new int[size];
    int j=0;
    for(Integer i : validList)
    {
      output[j]=i;
      j++;
    }
    return output;
  }

  public boolean checkforEqual(String[] input1,String[] input2)
  {
    int count=0;
    for(String s:input1)
    {
      for(String r: input2)
      {
        if(s.equals(r))
        {
          count++;
          break;
        }
      }
    }
    if (count==input1.length)
      return true;
    else
      return false;
  }
  public static void main(String []args) throws IOException
  {
    BufferedReader br=null;
    PrintWriter pw=null;
    String output[];
    Program3 pg1= new Program3();
    try
    {
      br = new BufferedReader(new FileReader("/home/siddhesh/Downloads/A-small-attempt1.in"));
      pw = new PrintWriter("/home/siddhesh/Downloads/1A-small.out","UTF-8");
      int tcases = Integer.parseInt(br.readLine());
      output = new String[tcases];
      //DECLARE YOUR INPUT HERE
      int input1[] = new int[2];
      String input2[];
      String input3[];
      for(int i =0;i<tcases;i++)
      {
        pg1 = new Program3();
        input1 = convertStringToIntArray(br.readLine());
        input2 = br.readLine().split(" ");
        input3 = br.readLine().split(" ");
        output[i] = "Case #"+(i+1)+": ";

        long ans =  pg1.createSwitch(input1,input2,input3);
        if(ans==100)
          output[i]+="NOT POSSIBLE";
        else
          output[i]+=ans;
        System.out.println(output[i]);
        pw.println(output[i]);
      }
    }
    finally {
      br.close();
      pw.close();
    }
    }
  private static int[] convertStringToIntArray(String input)
  {
    String stringsplit[] = input.split(" ");
    int []output = new int[stringsplit.length];
    for(int i =0; i<stringsplit.length;i++)
    {
      output[i]  = Integer.parseInt(stringsplit[i]);
    }
    return output;
  }
}

