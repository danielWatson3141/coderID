#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
using namespace std;

int N,T,L;
unsigned long long B[60],o[160],d[160];
map<unsigned long long,int> hash;
map<unsigned long long,int>::iterator it;

bool b[160];

void st()
{
    B[0]=1;
    for(int i=1;i<50;i++)
    {
        B[i]=B[i-1]*2;
    }
}

int getnum(unsigned long long x)
{
    int cnt=0;
    for(int i=0;i<L;i++)
    {
        if((x&B[i])!=0) cnt++;
    }
    return cnt;
}

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    st();
    cin>>T;
    for(int ca=1;ca<=T;ca++)
    {
        cin>>N>>L;
        char tmp[100];
        memset(o,0,sizeof(o));
        memset(d,0,sizeof(d));
        for(int i=1;i<=N;i++)
        {
            cin>>tmp;
            for(int j=0;j<L;j++)
            {
                if(tmp[j]=='1')
                {
                    o[i]+=B[j];
                }
            }
        }
        for(int i=1;i<=N;i++)
        {
            cin>>tmp;
            for(int j=0;j<L;j++)
            {
                if(tmp[j]=='1')
                {
                    d[i]+=B[j];
                }
            }
        }
        int ans=10000;
        for(int i=1;i<=N;i++)
        {
            memset(b,0,sizeof(b));
            unsigned long long cwj=(o[1]^d[i]);
            b[i]=1;
            bool ch=true;
            for(int j=2;j<=N;j++)
            {
                bool flag=false;
                for(int k=1;k<=N;k++)
                {
                    if((o[j]^d[k])==cwj)
                    {
                        if(b[k])
                        {
                            break;
                        }
                        else
                        {
                            b[k]=1;
                            flag=true;
                            break;
                        }
                    }
                }
                if(!flag)
                {
                    ch=false;
                    break;
                }
            }
            if(ch)
            {
                ans=min(ans,getnum(cwj));
            }
        }
        if(ans==10000) cout<<"Case #"<<ca<<": NOT POSSIBLE"<<endl;
        else cout<<"Case #"<<ca<<": "<<ans<<endl;
    }
    return 0;
}



