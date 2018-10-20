#include<fstream>
#include<string.h>
#include<cmath>
#include<stdio.h>
using namespace std;

ifstream fin("C-small-attempt1 (1).in");
ofstream fout("ans.out");


long double dp[10001];
long double dp2[10001];
long double g[1001][1001];
int n=1000;
int main()
{
    int i,j,k,t,times;
    
    for(t=1;t<=n;t++)
    {
    
    dp[t]=1.0;
    for(i=1;i<=n;i++)
    {
        if(i!=t)
        dp[i]=0.0;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            dp2[j]=0;
        }
        for(j=1;j<=n;j++)
        {
             if(j!=i)
             {
               dp2[i]+=dp[j]/((long double)(n));
               dp2[j]+=dp[i]/((long double)(n));
               dp2[j]+=dp[j]*((long double)(n-1))/((long double)(n));
             }
             else
             {
                dp2[i]+=dp[i]/((long double)(n));
             }
        }
        
        for(j=1;j<=n;j++)
        {
            dp[j]=dp2[j];
        }
        
        
        
    }
    
    
    for(j=1;j<=n;j++)
    {
        g[t][j]=dp[j];
    }
    /*
    for(j=1;j<=n;j++)
        {
        cout.precision(4);
        cout.setf(ios::fixed);
        cout<<dp[j]<<' ';
        }
        cout<<endl;
        system("pause");
        */
    }
    /*
    for(j=1;j<=n;j++)
    {
       cout<<g[300][j]<<' ';
    }
    cout<<endl;
    */
    int yy=0;
    long double zz=0,tmp;
    long double ans[1001];
    int r[1001];
    fin>>t;
    for(times=1;times<=t;times++)
    {
        fin>>n;
        ans[times]=0.0;
        for(i=1;i<=n;i++)
        {
            fin>>r[i];
            ans[times]+=(g[r[i]][i]-1.0/((long double)(n)));
        }
        
        //fout<<ans<<endl;
        //zz+=ans[times];
        /*
        fout<<"Case #"<<times<<": ";
        if(ans>0.001)
        {
            fout<<"BAD"<<endl;
            yy++;
        }
        else
        {
            fout<<"GOOD"<<endl;
        }
        */
    }
    //fout<<zz/1000.0<<endl;
    
    for(i=1;i<=t;i++)
    {
        tmp=ans[i]+1e-7;
        yy=0;
        for(j=1;j<=t;j++)
        {
            if(ans[j]<tmp)
            {
                yy++;
            }
        }
        
        if(yy==60)
        {
            for(j=1;j<=t;j++)
            {
                fout<<"Case #"<<j<<": ";
                if(ans[j]<tmp)
                {
                    fout<<"GOOD"<<endl;
                }
                else
                {
                    fout<<"BAD"<<endl;
                }
            }
        }
    }
    
    
    system("pause");
    return 0;
}
