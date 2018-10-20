import java.util.ArrayList;
import java.util.Scanner;
import java.io.BufferedReader;

public class C{
  public static interface Randomize{
    double[][] randomize(double[][] prob,int k);
  }

  public static class GoodRandomize implements Randomize{
    public double[][] randomize(double[][] prob,int k){
      int n=prob.length;
      double[][] ret=new double[n][n];

      for(int val=0;val<n;val++)
        for(int pos=0;pos<n;pos++){
          if(pos<k)
            ret[val][pos]=prob[val][pos];
          else if(pos==k)
            for(int other=k;other<n;other++)
              ret[val][pos]+=prob[val][other]/(n-k);
          else
            ret[val][pos]=(1./(n-k))*prob[val][k] + (n-k-1.)/(n-k)*prob[val][pos];
        }

      return ret;
    }
  }

  public static class BadRandomize implements Randomize{
    public double[][] randomize(double[][] prob,int k){
      int n=prob.length;
      double[][] ret=new double[n][n];

      for(int val=0;val<n;val++)
        for(int pos=0;pos<n;pos++){
          if(pos==k)
            for(int other=0;other<n;other++)
              ret[val][pos]+=prob[val][other]/n;
          else
            ret[val][pos]=(1./n)*prob[val][k] + (n-1.)/n*prob[val][pos];
        }

      return ret;
    }
  }

  static private double[][] getAffinity(Randomize randomize,int n){
    double[][] affinity=new double[n][n];

    for(int i=0;i<n;i++)
      affinity[i][i]=1;

    for(int k=0;k<n;k++)
      affinity=randomize.randomize(affinity,k);

    return affinity;
  }

  private static double score(int[] array,double[][] affinity){
    double ret=0;
    for(int i=0;i<array.length;i++){
      double s=affinity[array[i]][i];
      ret+=s;
    }
    return ret;
  }

  public static void main(String[] args){
    Scanner scanner=new Scanner(System.in);
    final int cases=scanner.nextInt();

    int N=1000;
    Randomize good=new GoodRandomize(),bad=new BadRandomize();
    double[][] goodAffinity=getAffinity(good,N),badAffinity=getAffinity(bad,N);

    for(int t=0;t<cases;t++){
      final int n=scanner.nextInt();
      int[] array=new int[n];
      for(int i=0;i<n;i++)
        array[i]=scanner.nextInt();
      double goodScore=score(array,goodAffinity),badScore=score(array,badAffinity);
      if(goodScore>=badScore)
        System.out.println("Case #"+(t+1)+": GOOD");
      else
        System.out.println("Case #"+(t+1)+": BAD");
    }
  }
}
