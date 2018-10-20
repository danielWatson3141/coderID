#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <numeric>

using namespace std;
typedef long long LL;

const int N=500;
const int INF=~0U>>1;

char s1[200][200],s2[200][200];
string p1[200],p2[200];
vector<int>turn;
int solve(int n,int l) {
    int ret=0;
    for (int j=0; j<l; j++) {
        int c1=0,c2=0;
        for (int i=1; i<=n; i++) {
            if (s1[i][j]=='1')
                c1++;
        }
        for (int i=1; i<=n; i++) {
            if (s2[i][j]=='1')
                c2++;
        }
        if (c1==c2&&n-c1==c1){
            turn.push_back(j);
        }
        else if (c1==c2) continue;
        else if (c1==n-c2) {
            for (int i=1;i<=n;i++){
                if (s1[i][j]=='1')
                    s1[i][j]='0';
                else s1[i][j]='1';
            }
            ret++;
        }
        else return -1;
    }
    return ret;
}
bool ok;int ans;
int n,l;
void dfs(int dep,int ret){
    if (dep>turn.size()) {
        bool flag=true;
        for (int i=1; i<=n; i++) {
            p1[i]=string(s1[i]);
            p2[i]=string(s2[i]);
        }
        sort(p1+1,p1+1+n);
        sort(p2+1,p2+1+n);
        for (int i=1; i<=n; i++) {
            for (int j=0; j<l; j++) {
                if (p1[i][j]!=p2[i][j])
                    flag=false;
            }
        }
        if (flag){
            ans=min(ans,ret);
            ok=true;
        }
        return;
    }
    int j=turn[dep-1];
    for (int i=1;i<=n;i++){
        if (s1[i][j]=='1')
            s1[i][j]='0';
        else s1[i][j]='1';
    }
    ret++;
    dfs(dep+1,ret);
    ret--;
    for (int i=1;i<=n;i++){
        if (s1[i][j]=='1')
            s1[i][j]='0';
        else s1[i][j]='1';
    }
    dfs(dep+1,ret);
}
int main() {
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for (int cas=1; cas<=T; cas++) {
        scanf("%d %d",&n,&l);
        turn.clear();
        for (int i=1; i<=n; i++)
            scanf("%s",s1[i]);
        for (int i=1; i<=n; i++)
            scanf("%s",s2[i]);
        printf("Case #%d: ",cas);
        int ret=solve(n,l);
        if (ret==-1) printf("NOT POSSIBLE\n");
        else if (turn.size()>0){
            ok=false;ans=INF;
            dfs(1,0);
            if (!ok) printf("NOT POSSIBLE\n");
            else printf("%d\n",ret+ans);
        }
        else {
            bool flag=true;
            for (int i=1; i<=n; i++) {
                p1[i]=string(s1[i]);
                p2[i]=string(s2[i]);
            }
            sort(p1+1,p1+1+n);
            sort(p2+1,p2+1+n);
            for (int i=1; i<=n; i++) {
                for (int j=0; j<l; j++) {
                    if (p1[i][j]!=p2[i][j])
                        flag=false;
                }
            }
            if (!flag){
                printf("NOT POSSIBLE\n");
            }
            else {
                printf("%d\n",ret);
            }
        }
    }
    return 0;
}
