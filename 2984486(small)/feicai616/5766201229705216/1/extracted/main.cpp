#include <iostream>
#include <cstring>
#include <stdio.h>
#include <math.h>
#include <set>
#include <queue>
#include <vector>
#include <new>
#include <algorithm>
#include <map>
using namespace std;
#define pb push_back
#define mp make_pair
#define MatN 4
#define N 1000007
#define MOD 1000000007
#define lyl   printf("ok\n")
typedef  pair<int,int> pii;
typedef long long LL;
struct Tree{
    //int pre;
    vector<int> zi;
}tree[2002];

int sou(int k,int pre){
    vector<int> tmp;
    tmp.clear();
    int len=tree[k].zi.size();
    // printf("sss %d  %d\n",k,len);
    for (int i=0;i<len;i++){
        if (pre!=tree[k].zi[i]) tmp.pb(tree[k].zi[i]);

    }
    int tmpl=tmp.size();
    if (tmpl>=2){
        int max1=-1,max2=-1;
        for (int i=0;i<tmpl;i++){
            int ans=sou(tmp[i],k);
            if (max1==-1) max1=ans;
            else if (max2==-1) max2=ans;
            else if (ans>max1) max2=max1,max1=ans;
            else if (ans>max2) max2=ans;
        }
        //printf("sssmax %d %d\n", k,max1+max2+1);
        return max1+max2+1;
    }else {
        return 1;
    }
}
int main(){
    int casen;
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%d",&casen);
    for (int casei=0;casei<casen;casei++){
        int n;
        scanf("%d",&n);
        //printf("sgg %d  %d\n",casen,n);
        for (int i=0;i<=n;i++){ tree[i].zi.clear();}
        for (int i=0;i<n-1;i++){
            int lx,rx;
            scanf("%d%d",&lx,&rx);
            tree[lx].zi.pb(rx);
            tree[rx].zi.pb(lx);
             //printf("sgg %d  %d\n",i,tree[3].zi.size());
        }
        int maxx=-1;
        for (int i=1;i<=n;i++){
            maxx=max(maxx,sou(i,-1));
          // printf("Case #%d: %d\n",casei+1,n-maxx);
        }
        printf("Case #%d: %d\n",casei+1,n-maxx);
    }
}
