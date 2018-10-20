/*
 *Kartik Singal @ ka4tik
 */
#include<bits/stdc++.h>
using namespace std;
#define s(n) scanf("%d",&n)
vector<string> a,b;
int main()
{
    freopen("in","r",stdin);
    freopen("out","w",stdout);

    int test;s(test);
    int kase=0;
    while(test--)
    {
        kase++;

        int N,M;
        s(N);s(M);
        a.resize(N);
        b=a;
        for(int i=0;i<N;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<N;i++)
        {
            cin>>b[i];
        }
        sort(b.begin(),b.end());
        int poss=1;
        int ans=INT_MAX;
        for(int k=0;k<(1<<M);k++)
        {
            int flag=1;
            vector<string> t=a;
            for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
            {
                if((1<<j)&k)
                {
                    if(t[i][j]=='0')
                        t[i][j]='1';
                    else
                        t[i][j]='0';
                }
            }
            sort(t.begin(),t.end());
            if(t==b)
            {
                ans=min(ans,__builtin_popcount(k));
            }
        }
        if(ans==INT_MAX)
            printf("Case #%d: NOT POSSIBLE\n",kase);
        else
            printf("Case #%d: %d\n",kase,ans);
    }

    return 0;
}

