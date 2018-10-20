#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <stack>
using namespace std;

#define For(i,n) for(int i=0; i<(n); i++)
#define mp(a,b) make_pair((a),(b))
typedef long long ll;
typedef pair<int,int> pii;

char opak(char a) {
    if(a=='0') return '1';
    return '0';
}

void solve(int num) {
    vector<string> O;
    int n,l;
    scanf("%d %d",&n,&l);
    char C[47];
    string s;
    For(i,n) {
        scanf(" %s",C);
        s=C;
        O.push_back(s);
    }
    string prv;
    set<string> D;
    For(i,n) {
        scanf(" %s",C);
        s=C;
        D.insert(s);
        if(i==0) prv=s;
    }
    int res=-1;
    set<string> S;
    For(i,n) {
        vector<int> zmen;
        For(j,l) if(prv[j]!=O[i][j]) zmen.push_back(j);
        S=D;
        For(j,n) {
            string p=O[j];
            For(k,zmen.size()) p[zmen[k]]=opak(p[zmen[k]]);
            S.erase(p);
        }
        if(S.size()>0) continue;
        if(res==-1) res=zmen.size();
        else res=min(res,(int)zmen.size());
    }
    printf("Case #%d: ",num);
    if(res!=-1) printf("%d\n",res);
    else printf("NOT POSSIBLE\n");
}

int main() {
    int t;
    scanf("%d",&t);
    For(i,t) solve(i+1);
return 0;
}
