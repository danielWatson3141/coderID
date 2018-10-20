#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
vector< vector<int> > v;
vector<int> deg,c;
int dfs(int i,bool *vst) {
    if(vst[i]) return 0;
    int cnt=0;
    vst[i]=true;
    for(int j=0;j<v[i].size();j++) {
        int k=v[i][j];
        if(!vst[k]) cnt++;
    }
    deg[i]=cnt;
    cnt=1;
    for(int j=0;j<v[i].size();j++) {
        int k=v[i][j];
        if(!vst[k]) {
            cnt+=dfs(k,vst);
        }
    }
    c[i]=cnt;
    return cnt;
}
int dfs1(int i,bool *vst) {
    if(vst[i]==true) return 0;
    vst[i]=true;
    //cout<<i<<" "<<endl;
    if(deg[i]>2) {
        int sum=0,mn=10000,mn1=10000;
        for(int j=0;j<v[i].size();j++) {
            int k=v[i][j];
            if(!vst[k]) {
                int p=dfs1(k,vst);
                if(p<mn) {
                    mn1=mn;
                    mn=p;
                } else if(p<mn1){
                    mn1=p;
                }
                sum+=p;
            }
        }
        return sum-mn-mn1;
    } else if(deg[i]==0) {
        return 0;
    } else if(deg[i]==1) {
        return c[i]-1;
    } else if(deg[i]==2){
        return dfs1(v[i][0],vst)+dfs1(v[i][1],vst);
    }
}
int main() {
    int t,n,a,b;
    scanf("%d",&t);
    for(int t1=1;t1<=t;t1++) {
        scanf("%d",&n);
        v.clear();
        v.resize(n);
        for(int i=0;i<n-1;i++) {
            scanf("%d%d",&a,&b);a--;b--;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        int ans=100000;
        for(int k=0;k<n;k++) {
            deg.clear();
            c.clear();
            deg.resize(n);
            c.resize(n);
            bool *vst=new bool[n];
            for(int i=0;i<n;i++) vst[i]=false;
            dfs(k,vst);
            //for(int i=0;i<n;i++) cout<<c[i]<<" ";cout<<endl;
            //for(int i=0;i<n;i++) cout<<deg[i]<<" ";cout<<endl;
            for(int i=0;i<n;i++) vst[i]=false;
            int pp=dfs1(k,vst);
            if(pp<ans) ans=pp;
        }
        printf("Case #%d: %d\n",t1,ans);
    }
    return 0;
}
