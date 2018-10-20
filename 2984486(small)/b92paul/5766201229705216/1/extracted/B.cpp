#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;
const int N=1010;
vector<int >edge[N];
int n;
void add(int a,int b){
    edge[a].push_back(b);
    edge[b].push_back(a);
}
int cmp(int a,int b){
    return a>b;
}
int visit[N];
int V;
int dfs(int x){
    //printf("%d",x);
    vector<int >tmp;
    int t;
    for(int i=0;i<edge[x].size();i++){
        if(visit[edge[x][i]]!=V){
            visit[edge[x][i]]=V;
            t=dfs(edge[x][i]);
            tmp.push_back(t);
        }
    }
    if(tmp.size()<=1)return 1;
    sort(tmp.begin(),tmp.end(),cmp);
    return 1+tmp[0]+tmp[1];
}
int main(){
    int T,idx=0;
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)edge[i].clear();
        for(int i=0;i<n-1;i++){
            int a,b;
            scanf("%d %d",&a,&b);
            add(a,b);
            
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            V++;visit[i]=V;
            ans=max(ans,dfs(i));
        }
        idx++;
        printf("Case #%d: %d\n",idx,n-ans);
    }
}
