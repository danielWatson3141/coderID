#include<iostream>
#include<cstdio>
#include<algorithm>
#include<memory.h>
#include<vector>
#include<stack>
#include<queue>
#include<cassert>
#include<cstdlib>
#include<cmath>
#include<map>
#include<utility>
#include<cstring>

#define DEBUG(x) cout<<#x<<"= "<<x<<endl
#define DEBUGARR(x,i,f) for(int iter = i; iter <= f; ++iter) printf("%s[%d]=%d\n",#x, iter, x[iter])
#define MAX(a,b) ((a)>(b))? (a):(b)
#define MAX3(a,b,c) MAX(a,MAX(b,c))
#define MIN(a,b) ((a)<(b))? (a):(b)
#define MIN3(a,b,c) MIN(a,MIN(b,c))
#define bit(n,i) (n&(1<<(i-1)))
#define setbit(n,i) n |= (1<<(i-1))
#define inf (1<<30)
#define SETZERO(x) memset( x, 0, sizeof(x))
#define SETMIN1(x) memset( x, -1, sizeof(x))
#define CLEAR(x) while(!x.empty()) x.pop();
#define FOR(i,in,fin) for( i = (in); i <= (fin); ++i)
#define FORL(i,in,fin) for( i = (in); i < (fin); ++i)
#define FORD(i,in,fin) for( i = (in); i >= (fin); --i)
#define INC(a,b,c) ((a)<=(b) && (b)<=(c))
#define pb push_back
#define si(x) scanf("%d",&x)
#define pi(x) printf("%d\n",x)
#define sll(x) scanf("%lld",&x)
#define pll(x) printf("%lld\n",x)
#define sortv(v) sort(v.begin(),v.end())
#define sortar(a,i,n) sort(a+i,a+i+n)
#define findmp(mp,x) (mp.find(x)!=mp.end())
typedef long long ill;
using namespace std;
typedef pair <int,int> pii;
const int mod = 1000000007;
//code begins here
char mat[151][41],mat1[151][41];
char m1[151][41];
int main()
{
    #ifndef ONLINE_JUDGE
        freopen( "a.in", "r", stdin);
        freopen("a.out","w",stdout);
    #endif
    int t,test_case;
    scanf("%d",&t);
    FOR(test_case,1,t)
    {
        printf("Case #%d: ",test_case);
        int i,j,k;
        int n,l;
        si(n),si(l);
        FOR(i,0,n-1){
            scanf("%s",mat[i]);
            //perm.push_back(i);
        }
        FOR(i,0,n-1)
            scanf("%s",mat1[i]);
        //cout<<"hello";
        int flag=0,ans=100;
        map <string,int> mp;
        FOR(i,0,n-1){
            int flip[41]={},tmp=0;
            FOR(j,0,l-1){
                flip[j]=(mat[0][j]!=mat1[i][j]);
                tmp+=flip[j];
            }
            FOR(k,0,n-1){
                FOR(j,0,l-1){
                        m1[k][j] = ((mat1[k][j]-'0')^flip[j]);
                        m1[k][j] += '0';
                }
                m1[k][l]=0;
                string tmps = m1[k];
                mp[tmps]++;
            }
            FOR(k,0,n-1){
                    if(mp[mat[k]])
                    {
                        mp[mat[k]]--;
                    }
                    else
                    {
                        break;
                    }
            }
            if(k==n)
                ans = min(ans,tmp);
            mp.clear();
        }
        if(ans==100)
            printf("NOT POSSIBLE\n");
        else
            pi(ans);
    }
}


