#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;


char s[2][220][55];
int n,l;
struct FF
{
    string s;
    int cnt,i,j;
}p[200 * 200];
int tot;
void get(int i ,int j)
{
    p[tot].s = "";
    p[tot].i = i;
    p[tot].j = j;
    p[tot].cnt = 0;
    for (int k = 0; k < l; k++) {

        if (s[0][i][k] == s[1][j][k]) p[tot].s = p[tot].s + (char)('0' + 0);
        else {
            p[tot].s = p[tot].s + (char)('0' + 1);
            p[tot].cnt++;
        }
    }
    tot++;
}
bool cmp(FF a,FF b)
{
    if (a.cnt == b.cnt) return a.s < b.s;
    return a.cnt < b.cnt;
}
const int maxm = 200 * 200;
const int maxn = 400;
struct EE
{
    int to,ne;
}e[2 * maxm];
int head[maxn],L,matc[maxn],N;
bool use[maxn];
void init()
{
    L = 0;
    memset(head,-1,sizeof(head));
    N = 2 * n;
}
void adde(int u,int v)
{
    e[L].to = v;
    e[L].ne = head[u];
    head[u] = L++;
}
bool check(int u)
{
    for (int i = head[u]; i != -1; i = e[i].ne) {
        int v = e[i].to;
        if (matc[v] == u) continue;
        if (!use[v]) {
            use[v] = true;
            if (matc[v] == -1 || check(matc[v])) {
                matc[v] = u;
                matc[u] = v;
                return true;
            }
        }
    }
    return false;
}
int match()
{
    int ret = 0;
    memset(matc,-1,sizeof(matc));
    for (int u = 0; u < N; u++) {
        if (matc[u] != -1) continue;
        memset(use,0,sizeof(use));
        if (check(u))
            ret++;
    }
    return ret;
}

int main()
{
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A-small-attempt1.out","w",stdout);
    int T;
    int cas = 1;
    cin>>T;
    while (T--) {
        scanf("%d%d",&n,&l);
        for (int i = 0 ; i< n; i++) scanf("%s",s[0][i]);
        for (int i = 0 ; i< n; i++) scanf("%s",s[1][i]);
        tot = 0;
        for (int i = 0 ; i < n; i++)
            for (int j = 0; j < n; j++) get(i,j);
        sort(p,p + tot,cmp);
        int ans = -1;
        for (int i = 0; i < tot;) {
            init();
            int j;
            for (j = i; j < tot && p[j].s == p[i].s; j++) {
                adde(p[j].i,n + p[j].j);
                adde(n + p[j].j,p[j].i);
            }
            if (match() == n) {
                ans = p[i].cnt;
                break;
            }
            i = j;
        }
        if (ans == -1) printf("Case #%d: NOT POSSIBLE\n",cas++);
        else printf("Case #%d: %d\n",cas++,ans);
    }
}

