#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> tree[1005];
int f[1005],total[1005];
int left(int x,int pre) {
    if(total[x]!=-1) return total[x];
    int sum,i;
    for(i=sum=0;i<tree[x].size();i++)
        if(tree[x][i]!=pre)
            sum+=left(tree[x][i],x);
    return total[x]=sum+1;
}
int remain(int x,int pre) {
    if(f[x]!=-1) return f[x];
    if((pre==-1&&tree[x].size()<2)||(pre!=-1&&tree[x].size()<3))
        return f[x]=left(x,pre)-1;
    int sum,i,y,j,mini;
    vector<int> a;
    sum=left(x,pre)-1;
    for(i=0;i<tree[x].size();i++)
        if(tree[x][i]!=pre) {
            y=tree[x][i];
            a.push_back(remain(y,x)-left(y,x));
        }
    for(i=0;i<2;i++) {
        mini=i;
        for(j=i+1;j<a.size();j++)
            if(a[mini]>a[j]) mini=j;
        swap(a[mini],a[i]);
    }
    return f[x]=sum+a[0]+a[1];
}
int main() {
    int t,T,x,y,n,i,j,mini;
    scanf("%d",&T);
    for(t=1;t<=T;t++) {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            tree[i].clear();
        for(i=0;i<n-1;i++) {
            scanf("%d%d",&x,&y);
            tree[x].push_back(y);
            tree[y].push_back(x);
        }
        mini=5000;
        for(i=1;i<=n;i++) {
            for(j=1;j<=n;j++) f[j]=total[j]=-1;
            if(mini>remain(i,-1)) mini=f[i];
        }
        printf("Case #%d: %d\n",t,mini);
    }
    return 0;
}
