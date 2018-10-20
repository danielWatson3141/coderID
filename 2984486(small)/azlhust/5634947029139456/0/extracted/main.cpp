#include <map>
#include <set>
#include <queue>
#include <ctime>
#include <cmath>
#include <string>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define all(a) a.begin(),a.end()
#define clr(a) memset(a,0,sizeof(a))
#define fill(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<pair<int,int> > VII;

const double eps = 1e-8;
const double pi = acos(-1.0);

char s[155];
LL num[155], num1[155];


int T;
bool cmp(LL a, LL b){
    return (a >> T) < (b >> T);
}

int main(){
    freopen("1.in","r",stdin);
    freopen("out.txt","w",stdout);
    int tt, cal=0, i, n, l, j;
    scanf("%d",&tt);
    while(tt--){
        printf("Case #%d: ", ++cal);
        scanf("%d%d",&n,&l);
        for(i=1;i<=n;++i){
            scanf("%s",s);
            num[i] = 0;
            for(j=0;j<l;++j){
                num[i] = num[i]*2+(s[j]=='1');
            }
        }
        for(i=1;i<=n;++i){
            scanf("%s",s);
            num1[i] = 0;
            for(j=0;j<l;++j){
                num1[i] = num1[i]*2+(s[j]=='1');
            }
        }

        int tot = 0;
        T = l-1;

        int sa = 0, ssa=0;
        bool flag;
        for(i=0;i<l;++i){
            sort(num1+1,num1+n+1, cmp);
            sort(num+1,num+n+1, cmp);
            int tot1=0, tot2=0;
            for(j=1;j<=n;++j){
                tot1 += (num[j]>>T)&1;
                tot2 += (num1[j]>>T)&1;
            }
            if(tot1*2==n && tot2*2==n){
                sa ++;
                flag = true;
            } else
                flag = false;
            for(j=1;j<=n;++j)
            if((num[j]>>T) != (num1[j]>>T)) break;
            if(j!=n+1){
                if(flag) ssa++;
                tot++;
                for(j=1;j<=n;++j)
                num[j] = num[j]^(1LL<<T);
                sort(num+1,num+n+1, cmp);
                for(j=1;j<=n;++j)
                if((num[j]>>T) != (num1[j]>>T)) break;
                if(j!=n+1) break;
            }
            T--;
        }
        if(i!=l) puts("NOT POSSIBLE");
        else printf("%d\n", tot-ssa+min(sa-ssa, ssa));
    }
    return 0;
}

