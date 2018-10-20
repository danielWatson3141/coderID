#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
#include <vector>
#include <list>
#include <stack>
#include <bitset>
#include <string>
#include <stack>
#include <set>
#include <map>
#include<string>
#include <deque>
#include <ctime>

#define ALL(i,n)    for(i = 0; i < (n); i++)
#define FOR(i,a,b)  for(i = (a); i < (b); i++)
#define SET(p)      memset(p,-1,sizeof(p))
#define CLR(p)      memset(p,0,sizeof(p))
#define s(n)	    scanf("%d",&n)
#define P(n)	    printf("%d\n",n)
#define sl(n)	    scanf("%lld",&n)
#define pl(n)	    printf("%lld\n",n)
#define sf(n)       scanf("%lf",&n)
#define ss(n)       scanf("%s",n)
#define F first
#define S second
#define LL long long
#define ULL unsigned long long
#define pb push_back
using namespace std;
#define R freopen("in","r",stdin)
#define W freopen("out","w",stdout)
using namespace std;
string a[11],b[11];
string str[11];
int main()
{
    R;W;
    int t;cin>>t;
    int kase=0;
    while(t--)
    {
        kase++;
        printf("Case #%d: ",kase);
        int n,l;
        cin>>n>>l;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            
        }
        for(int i=0;i<n;i++)
            
        {
            cin>>b[i];
        }
        sort(b,b+n);
        int ans=INT_MAX;
        for(int i=0;i<1<<l;i++)
        {
            for(int i=0;i<n;i++)
            {
                str[i]=a[i];
            }
            int temp=i;
            int in=0;
            while(temp)
            {
                if(temp&1)
                {
                    for(int i=0;i<n;i++)
                    {
                        string h;
                        h=str[i];
                        str[i]=h.substr(0,in)+(h[in]=='0'?'1':'0')+h.substr(in+1,l-in+1);
                    }
                }
                temp>>=1;
                in++;
            }
            sort(str,str+n);
            int flag=1;
            for(int i=0;i<n;i++)
            {
                if(str[i]!=b[i])flag=0;
            }
            if(flag)ans=min(ans,__builtin_popcount(i));
        }
        if(ans==INT_MAX)cout<<"NOT POSSIBLE"<<endl;
        else cout<<ans<<endl;
        
        
        
    }
}
