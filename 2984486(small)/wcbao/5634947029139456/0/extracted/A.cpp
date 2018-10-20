#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#define clr(A) memset(A,0,sizeof(A))
#define mm 100005
#define eps  (1e-8)
using namespace std;
typedef long long LL;
typedef pair<int,int > P;
typedef unsigned int ULL;
const int INF = 10000000;

vector<P> by[mm];
int x[mm],y[mm];
int N,X,Y;
LL a[mm],b[mm],c[mm];

LL get()
{
    char st[100];
    LL res = 0;
    scanf("%s",st);
    for(int i =0;st[i]!='\0';i++)
    res = (res<<1)|(st[i]-'0');
    return res;
}
int cal(LL rs)
{
    int res =0;
    while(rs){
        res+=(rs&1);rs>>=1;
    }
    return res;
}
int main()
{
     int T,C = 0;
//    freopen("BUAA.in","r",stdin);
//    freopen("gcj.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        int L;
        printf("Case #%d: ",++C);
        scanf("%d%d",&N,&L);
        for(int i = 1;i<=N;i++)
        a[i] = get();
        for(int  i = 1;i<=N;i++)
        b[i] = get();
        sort(a+1,a+1+N);

        int ans = L+1;
        for(int i = 1;i<=N;i++){
            LL res = b[i]^a[1];
            for(int j = 1;j<=N;j++)
            c[j] = b[j]^res;
            sort(c+1,c+N+1);
            int f = 1;
            for(int j = 1;j<=N;j++)
            if(c[j]!=a[j]) f = 0;

            if(f) ans = min(ans, cal(res));
        }
        if(ans>L) printf("NOT POSSIBLE\n");
        else printf("%d\n",ans);
    }
    return 0;
}
