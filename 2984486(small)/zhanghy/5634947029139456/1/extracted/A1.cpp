#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long LL;

const int maxn = 1000000;
const int INF = 1000000000;

int T,N,l,L;

char ch[160][50],ta[160][50];

int numa[160],numb[160];

struct node {
    int x,y,tot;
    LL key;
};

node p[maxn];

void add(int x,int y,LL key,int tot) {
   // cout<<x<<" "<<y<<" "<<key<<" "<<tot<<endl;
    l++; p[l].x = x; p[l].y = y; p[l].key = key; p[l].tot = tot;
}

bool cmp(node a,node b) {
    return a.key < b.key;
}

int main() {
    freopen("A2.in","r",stdin);
    freopen("A2.out","w",stdout);
    scanf("%d",&T);
    for (int kase = 1;kase <= T; kase++) {
        scanf("%d%d",&N,&L); l = 0;
        for (int i = 1;i <= N; i++) scanf("%s",ch[i]);
        for (int i = 1;i <= N; i++) scanf("%s",ta[i]);
        for (int i = 1;i <= N; i++) {
            for (int j = 1;j <= N; j++) {
                LL w = 1,p = 0; int td = 0;
                for (int k = 0;k < L; k++) {
                    if (ch[i][k] != ta[j][k]) { td++; p += w; }
                    w = w*2;
                }
                add(i,j,p,td);
            }
        }
        sort(p+1,p+l+1,cmp);
        for (int i = 1;i <= N; i++) numa[i] = numb[i] = 0;
        int st = 0,as = 1,ans = INF,ts = 0;
        numa[p[1].x] = numb[p[1].y] = 1; ts = 1;
        if (ts == N) ans = min(ans,p[1].tot);
       // cout<<p[1].x<<" "<<p[1].y<<" "<<p[1].key<<" "<<p[1].tot<<endl;
        for (int i = 2;i <= l; i++) {
         //   cout<<p[i].x<<" "<<p[i].y<<" "<<p[i].key<<" "<<p[i].tot<<endl;
            if (p[i].key != p[i-1].key) {
                as++;
                numa[p[i].x] = numb[p[i].y] = as; ts = 1;
                if (ts == N) ans = min(ans,p[i].tot);
            }else {
                if (numa[p[i].x] != as && numb[p[i].y] != as) {
                    numa[p[i].x] = numb[p[i].y] = as; ts++;
                 //   cout<<i<<" "<<ts<<endl;
                    if (ts == N) ans = min(ans,p[i].tot);
                }
            }
        }
        printf("Case #%d: ",kase);
        if (ans == INF) printf("NOT POSSIBLE\n");
        else {
            printf("%d\n",ans);
        }
    }
    return 0;
}
