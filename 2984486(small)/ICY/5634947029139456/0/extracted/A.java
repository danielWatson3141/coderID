import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;


public class A {
  
  static String ulta(String s) {
    String res = "";
    for(char c: s.toCharArray()) {
      if(c=='0')
        res+='1';
      else res+='0';
    }
    return res;
  }
  
  public static String ans1(String[] current, String devices[]) {
    int N = devices.length;
    int L = current[0].length();
    
    int counter = 0;
    
    Arrays.sort(current);
    Arrays.sort(devices);
    
    /*System.out.println(Arrays.toString(current));
    System.out.println(Arrays.toString(devices));
    System.out.println();*/

    for (int i=0; i<L; i++) {
      String dev = "", cur = "";
      for(int j=0; j<N; j++) {
        dev+=devices[j].charAt(i);
        cur+=current[j].charAt(i);
      }
      
      
      String ultaDev = ulta(dev);
      //System.out.println("cur: "+cur+", dev="+dev);
      if (sort(cur).equals(sort(dev)) || sort(cur).equals(sort(ultaDev))) {
        //System.out.println("equal");
        if(sort(cur).equals(sort(dev)))
          counter+=0;
        else
        if(sort(cur).equals(sort(ultaDev))) {
          counter++;
        }
      }
      else
        return "NOT POSSIBLE";
    }
    
    return ""+counter;
    
  }
  
  public static String ans(String[] current, String devices[]) {
    int N = devices.length;
    int L = current[0].length();
    
    int counter = 0;
    
    Arrays.sort(current);
    Arrays.sort(devices);
/*    System.out.println(Arrays.toString(current));
    System.out.println(Arrays.toString(devices));
System.out.println();
  */  /*
    int best = Integer.MAX_VALUE;
    
    System.out.println("0 to "+(1<<L));
    for (int i=0; i<1<<L; i++) {
     
      String arrangement[] = get(current, i);
      
      Arrays.sort(arrangement);
      System.out.println(i+": "+Arrays.toString(arrangement));

      if(equals(arrangement, devices))
        best=Math.min(best, Integer.bitCount(i));
    }
    
    if(best==Integer.MAX_VALUE)
      return "NOT POSSIBLE";
    return ""+best;*/
    int ret = Integer.MAX_VALUE;

    for (int mask = 0; mask < (1 << L); mask++) {
      char arr[][] = new char[current.length][];
      for(int i=0; i<current.length; i++)
        arr[i] = current[i].toCharArray();
      
      for (int i = 0; i < L; i++)
          if ((mask & (1 << i))!=0)
              for (int j = 0; j < N; j++) arr [j][i] = (arr [j][i] == '0' ? '1' : '0');
      
      String ret1[] = new String[current.length];
      for(int i=0; i<current.length; i++)
        ret1[i] = new String(arr[i]);
      
      Arrays.sort(ret1);
      //System.out.println(Arrays.toString(ret1));
      
      if (equals(ret1,devices)) 
        ret = Math.min (ret, Integer.bitCount(mask));
    }
    if (ret == Integer.MAX_VALUE) return "NOT POSSIBLE";
    else return ""+ret;
    
  }
  
  static boolean equals(String a[], String b[]) {
    for(int i=0; i<a.length; i++)
      if(a[i].equals(b[i]) == false)
        return false;
    return true;
  }
 static String[] get(String str[], int mask) {
    char arr[][] = new char[str.length][];
    for(int i=0; i<str.length; i++)
      arr[i] = str[i].toCharArray();
        
    for (int i=0; i<str[0].length(); i++) {
      if((mask&(1<<i))==1) {
        for(int j=0; j<str.length; j++) {
          if(arr[j][i]=='0')
            arr[j][i]='1';
          else
            arr[j][i]='0';
        }
      }
    }
    
    String ret[] = new String[str.length];
    for(int i=0; i<str.length; i++)
      ret[i] = new String(arr[i]);
    return ret;
  }
  
  static String sort(String s) {
    char arr[] = s.toCharArray();
    Arrays.sort(arr);
    return new String(arr);
  }
  
  public static void main(String[] args) {
    
    
    Scanner sc = new Scanner(System.in);
    
    int T = sc.nextInt();
    
    for (int t=1; t<=T; t++) {
      int N = sc.nextInt(); 
      int L = sc.nextInt();
      
      sc.nextLine();
      
      
      String[] current = sc.nextLine().split(" ");
      String[] devices = sc.nextLine().split(" ");      
      
      System.out.println("Case #"+t+": "+ans(current, devices));
    }
  }
}
