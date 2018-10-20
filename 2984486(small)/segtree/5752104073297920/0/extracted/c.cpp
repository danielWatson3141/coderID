#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int T,n;
struct tmp {long long x,y,z;} l[125];
bool cmp1(tmp a,tmp b) {return a.x<b.x;}
bool cmp2(tmp a,tmp b) {return a.y<b.y;}
int main()
{
    freopen("i.txt","r",stdin);
    freopen("o.txt","w",stdout);
    scanf("%d",&T);
    for(int i=1;i<=T;++i)
    {
        scanf("%d",&n); int x; l[i].x=i; l[i].y=0;
        for(int j=0;j<n;++j) {scanf("%d",&x); l[i].y+=abs(x-j)*abs(x-j)*abs(x-j);}
    }
    sort(l,l+T,cmp2);
    for(int i=0;i<T;++i) l[i].z=(i*2<T);
    sort(l,l+T,cmp1);
    for(int i=0;i<T;++i) printf("Case #%d: %s\n",i+1,l[i].z?"BAD":"GOOD");
    return 0;
}
