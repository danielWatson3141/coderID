/**
 *
 * @author pm
 */
import java.util.*;
public class A {
    public static void main(String args[])
    {
            Scanner s=new Scanner(System.in);
            int t;
            t=s.nextInt();
            String nposs="NOT POSSIBLE";
            int n,l;
            String temp;
            for(int i=1;i<=t;++i)
            {
                    n=s.nextInt();l=s.nextInt();
                    String inp[]=new String[n];
                    int iarr[][]=new int[n][l];
                    String out[]=new String[n];
                    int jarr[][]=new int[n][l];
                    int icop[][]=new int[n][l];
                    boolean diffs[]=new boolean[l];
                    String inps[]=new String[n];
                    for(int j=0;j<n;++j)
                    {	
                            inp[j]=s.next();
                    }
                    for(int j=0;j<n;++j)
                    {
                            out[j]=s.next();
                    }
                    Arrays.sort(out);
                    //convert
                    for(int I=0;I<n;++I)
                    {
                            for(int J=0;J<l;++J)
                            {
                                    iarr[I][J]=inp[I].charAt(J)-'0';
                            }
                    }
                    for(int I=0;I<n;++I)
                    {
                            for(int J=0;J<l;++J)
                            {
                                    jarr[I][J]=out[I].charAt(J)-'0';
                            }
                    }
                    boolean poss=false;
                    boolean flag;
                    int min=l+1;
                    for(int I=0;I<n;++I)
                    {
                            flag=false;
                            for(int J=0;J<l;++J)
                            {
                                    if(iarr[0][J]==jarr[I][J])
                                    {
                                            diffs[J]=true;
                                    }
                                    else
                                    {
                                            diffs[J]=false;
                                    }
                            }
                            //copy
                            for(int a=0;a<n;++a)
                            {
                                    for(int b=0;b<l;++b)
                                    {
                                            icop[a][b]=diffs[b]?(iarr[a][b]):((iarr[a][b]+1)%2);
                                    }
                            }
                            flag=true;
                            for(int a=0;a<n;++a)
                            {
                                    temp="";
                                    for(int f=0;f<l;++f)
                                    {
                                        temp+=icop[a][f]+"";
                                    }
                                    //System.out.println(temp);
                                    inps[a]=temp;
                            }
                            Arrays.sort(inps);
                            for(int a=0;a<n && flag;++a)
                            {
                                    if(!(inps[a].equals(out[a]))){flag=false;}
                            }
                            if(flag)
                            {
                                    poss=true;
                                    int lc=0;
                                    for(int a=0;a<l;++a)lc+=!diffs[a]?1:0;
                                    min=min<lc?min:lc;
				    //System.out.println(Arrays.toString(diffs));
                            }
                    }
                    System.out.print("Case #"+i+": ");
                    if(poss)
                    {
                            System.out.println(min);
                    }
                    else
                    {
                            System.out.println(nposs);
                    }
            }
    }
}

