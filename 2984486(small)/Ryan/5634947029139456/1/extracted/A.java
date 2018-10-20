import java.util.Arrays;
import java.util.Scanner;
import java.io.BufferedReader;

public class A{
  private static final int BAD=10000;

  public static void main(String[] args){
    Scanner scanner=new Scanner(System.in);
    final int cases=scanner.nextInt();

    for(int t=0;t<cases;t++){
      int n=solve(scanner);
      if(n==BAD)
        System.out.println("Case #"+(t+1)+": NOT POSSIBLE");
      else
        System.out.println("Case #"+(t+1)+": "+n);
    }
  }

  private static long parse(String string){
    long ret=0;
    for(int i=0;i<string.length();i++)
      if(string.charAt(i)=='1')
        ret|=1L<<i;
    return ret;
  }

  private static int bits(long n){
    int ret=0;
    while(n>0){
      if((n&1)==1)
        ret++;
      n/=2;
    }
    return ret;
  }

  private static boolean works(long[] deviceNeed,long[] outlet,long solution){
    long[] a=new long[deviceNeed.length];
    long[] b=new long[deviceNeed.length];
    for(int i=0;i<a.length;i++){
      a[i]=deviceNeed[i];
      b[i]=outlet[i]^solution;
    }
    Arrays.sort(a);
    Arrays.sort(b);
    for(int i=0;i<a.length;i++)
      if(a[i]!=b[i])
        return false;
    return true;
  }

  private static int solve(Scanner scanner){
    int devices=scanner.nextInt();
    int flow=scanner.nextInt();
    long[] deviceNeed=new long[devices];
    long[] outlet=new long[devices];
    for(int i=0;i<devices;i++)
      deviceNeed[i]=parse(scanner.next());
    for(int i=0;i<devices;i++)
      outlet[i]=parse(scanner.next());
    int best=BAD;
    for(int i=0;i<devices;i++)
      for(int j=0;j<devices;j++){
        long solution=deviceNeed[i]^outlet[j];
        if(works(deviceNeed,outlet,solution))
          best=Math.min(best,bits(solution));
      }
    return best;
  }
}
