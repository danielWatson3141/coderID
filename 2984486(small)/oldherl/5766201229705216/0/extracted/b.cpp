#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
int g[1111][1111],g0[1111];
int f[1111];
int root;

int dfs(int x) {
    int cnt=0,m1=0,m2=0;
    for(int i=0;i<g0[x];i++) {
        int y=g[x][i];
        if (f[y]==-1) {
            f[y]=x;
            int t=dfs(y);
            cnt++;
            if (t>m1) {
                m2=m1;
                m1=t;
            } else if (t>m2) {
                m2=t;
            }
        }
    }
    //cout<<"root="<<root<<" dfs("<<x<<"): cnt="<<cnt<<" m1="<<m1<<" m2="<<m2<<endl;
    if (cnt<=1) return 1;
    return m1+m2+1;
}

int main() {
    int TT;
    cin>>TT;
    for(int T=1;T<=TT;T++) {
        cin>>n;
        for(int i=0;i<n;i++) g0[i]=0;
        for(int i=0;i<n-1;i++) {
            int x,y;
            cin>>x>>y;
            x--; y--;
            g[x][g0[x]++]=y;
            g[y][g0[y]++]=x;
        }
        int ans=0;
        for(root=0;root<n;root++) {
            for(int i=0;i<n;i++) f[i]=-1;
            f[root]=-2;
            int t=dfs(root);
            if (t>ans) ans=t;
        }
        cout<<"Case #"<<T<<": ";
        cout<<n-ans;
        cout<<endl;
    }
    return 0;
}