#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>
#include <complex>
#include <queue>
using namespace std;
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Ford(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
#define sr(x) (int)x.size()
#define BUG(x) {cout << #x << " = " << x << endl;}
#define PR(x,a,b) {cout << #x << " = "; For(_,a,b) cout << x[_] << ' '; cout << endl;}
#define Bit(s,i) ((s&(1<<i))>0)
#define Two(x) (1<<x)
const int modul = 1000000007;
const int nmax = 10000;
const double e = 1e-8;
const double pi = acos(-1);
typedef long long ll;
typedef pair<int,int> pii;
int n,m,stest;
int s[nmax],F[nmax];
vector <int> head[nmax];
void DFS(int u,int pa) {
    int min1,min2;
    s[u] = 1;
    min1=min2=modul;
    For(i,0,sr(head[u])-1) {
        int v = head[u][i];
        if (v==pa) continue;
        DFS(v,u);
        s[u]+=s[v];
        if (F[v]-s[v]<min1) {
            min2 = min1;
            min1 = F[v]-s[v];
        } else min2 = min(min2,F[v]-s[v]);
    }
    F[u] = s[u]-1;
    if (min1!=modul && min2!=modul) F[u] = min( F[u], s[u]-1 + min1+min2 );
}
int main() {
    freopen("input.txt","r",stdin);
    freopen("outputB.txt","w",stdout);
    ios::sync_with_stdio(false);
    cin >> stest;
    For(test,1,stest) {
        cin >> n;
        For(i,1,n) head[i].clear();
        For(i,1,n-1) {
            int u,v;cin >> u >> v;
            head[u].push_back(v);
            head[v].push_back(u);
        }
        int res = modul;
        For(i,1,n) {
            DFS(i,0);
            res = min(res,F[i]);
            //BUG(i);
            //BUG(F[i]);
        }
        cout << "Case #" << test << ": " << res << endl;
    }
    return 0;
}




