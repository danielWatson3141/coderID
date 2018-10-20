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
int mark[1111];
pair<int,int> no[1111];
int no1[1111];
int tree[1111];
int arr[1111][1111];
int main()
{
    R;W;
    int t;cin>>t;
    int kase=0;
    while(t--)
    {
        kase++;
        printf("Case #%d: ",kase);
        int n;cin>>n;
        memset(arr,0,sizeof(arr));
        for(int i=0;i<n-1;i++)
        {
            int a,b;
            cin>>a>>b;
            a--;b--;
            arr[a][b]=1;
            arr[b][a]=1;
        }
        int ans=1;
        for(int i=0;i<n;i++)
        {
            for(int k=0;k<n;k++)
            {
                mark[k]=0;
            }
            //int temp=0;
            no[i].F=0;
            no1[i]=0;
            mark[i]=1;
            queue<int> Q;
            Q.push(i);
            while(!Q.empty())
            {
                int f=Q.front();
                Q.pop();
                for(int j=0;j<n;j++)
                {
                    if(arr[f][j]&&mark[j]==0)
                    {
                        no[j].F=no[f].F+1;
                        no1[j]=no1[f]+1;
                        mark[j]=1;
                        Q.push(j);
                    }
                }
                
            }
            for(int k=0;k<n;k++)no[k].S=k;
            sort(no,no+n);
            memset(tree,0,sizeof(tree));
            for(int k=n-1;k>=0;k--)
            {
                int in=no[k].S;
                tree[in]=1;
                int a=-1,b=-1,c=-1,d=-1;
                for(int re=0;re<n;re++)
                {
                    if(arr[re][in]&&no1[re]>no1[in])
                    {
                        if(a==-1)
                        {
                            a=re;
                            b=tree[re];
                        }
                        else
                        {
                            if(c==-1||d<tree[re])
                            {
                                c=re;
                                d=tree[re];
                            }
                            if(d>b)
                            {
                                swap(a,c);
                                swap(b,d);
                            }
                        }
                    }
                }
                if(c!=-1)
                {
                    tree[in]+=(b+d);
                }
            }
            ans=max(ans,tree[i]);
            
            
            
            
        }
        cout<<n-ans<<endl;
        
        
        
        
        
    }
}
