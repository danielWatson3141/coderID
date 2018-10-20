#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>

using namespace std;
#define LL long long
#define MX 151
#define MOD 1000002013

#define p(x) printf("%d",x)
#define inp(x) scanf("%d",&x)



using namespace std;
int cnt,n,l;
string str[MX],rqr[MX],news[MX];
bool chng[50];
void flip(int j,int k)
{
    cnt=0;
    for(int i=0;i<l;i++)
    {
        if(str[j][i]!=rqr[k][i])
        {
            cnt++;
            chng[i]=1;
        }
    }
}
char sw(char c)
{
    if(c=='0') return '1';
    else return '0';
}
void eql(void)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<l;j++)
        {
            if(chng[j])
            news[i][j]=sw(str[i][j]);
            else
            news[i][j]=str[i][j];
        }
    }
}

bool check()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<l;j++)
        {
            if(news[i][j]!=rqr[i][j])
            return 0;
        }
    }
    return 1;
}
int main()
{
    int t=0;
    inp(t);
    for(int i =1;i<=t;i++)
    {
        cout<<"Case #"<<i<<": ";
        inp(n);
        inp(l);
        for(int j=0;j<n;j++)
        {
            cin>>str[j];
            news[j]=str[j];
        }
        for(int j=0;j<n;j++)
        {
            cin>>rqr[j];
        }
        sort(rqr,rqr+n);
        int ans = 50;
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                for(int p=0;p<l;p++)
                chng[p]=0;
                
                flip(j,k);
                if(cnt<ans)
                {
                    eql();
                    sort(news,news+n);
                    if(check())
                    ans = cnt;
                }
            }
        }
        if(ans!=50)
        cout<<ans<<endl;
        else
        cout<<"NOT POSSIBLE\n";
    }
    return 0;
}