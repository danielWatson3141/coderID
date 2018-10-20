#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
#include<stack>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include<climits>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
# define pb push_back

vector<vi >v;

int drop[1001];
int tot;

int func(int i,int n) {
    ++tot;
    int m = (int)v[i].size();
    int cnt = 1;
    drop[i] = 1;
    int mx = 0;
    for(int j = 0;j < (1<<m);++j) {
        if(__builtin_popcount(j) != 2) {
            continue;
        }
        int child = 0;
        for(int k = 0;k < m;++k) {
            if(j & (1<<k)) {
                if(drop[v[i][k]] == 0) {
                    ++child;
                }
            }
        }
        if(child == 2) {
            int calc = 0;
            for(int k = 0;k < m;++k) {
                if(j & (1<<k)) {
                    if(drop[v[i][k]] == 0) {
                        calc+=func(v[i][k],n);
                    }
                }
            }
            mx = max(mx,calc);
        }
    }
    drop[i] = 0;
    return cnt+mx;
}


int main() {
    freopen("/Users/shalini/Downloads/Bsmall.txt","r",stdin);
    freopen("/Users/shalini/Downloads/bsmallSol.txt", "w", stdout);
    int t;
    cin>>t;
    int caseno = 0;
    while(t--) {
        ++caseno;
        v.clear();
        v.resize(1001);
        tot = 0;
        memset(drop, 0, sizeof(drop));
        int n,x,y;
        cin>>n;
        for(int i = 0;i < (n-1);++i) {
            cin>>x>>y;
            v[x].pb(y);
            v[y].pb(x);
        }
        int mx = 0;
        for(int i = 1;i <= n;++i) {
            int ans = func(i,n);
           //cout<<i<<" "<<tot<<"\n";
            mx = max(mx,ans);
        }
       // cout<<tot<<"\n";
        cout<<"Case #"<<caseno<<": "<<(n-mx)<<"\n";
        
    }
    return 0;
}