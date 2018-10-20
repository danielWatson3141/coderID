#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
#define maxn 160
#define eps 1e-7
using namespace std;

#ifdef __int64
    typedef __int64 LL;
#else
    typedef long long LL;
#endif


string str[maxn],tar[maxn],tmp[maxn];

int n,l;

void filp(int pos){
    for(int j=0;j<n;j++){
        str[j][pos]=(str[j][pos]-'0')^1+'0';
    }
}

int ans;
bool ok;
void dfs(int pos,int now){
    if(pos==l){
        bool v=true;
        for(int i=0;i<n;i++){
            tmp[i]=str[i];
        }

        sort(tmp,tmp+n);
        for(int i=0;i<n;i++){
            if(tmp[i]!=tar[i])return ;
        }
        ans=min(ans,now);
        return;
    }
    int cnt = 0,c=0;
    if(!ok)return ;
    for(int i=0;i<n;i++){
        if(str[i][pos]=='1')cnt++;
        if(tar[i][pos]=='1')c++;
    }
    if(cnt!=c&&n-cnt!=c){
        ok=false;
        return ;
    }

    if(cnt==c){
        dfs(pos+1,now);
    }else if(n-cnt==c){
        filp(pos);
        dfs(pos+1,now+1);
        filp(pos);
    }
}

int main(){
    freopen("A-large.in","r",stdin);
    freopen("out.out","w",stdout);

    int cas=0,i,j,k;
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&l);
        for(i=0;i<n;i++){
            cin>>str[i];
        }

        for(i=0;i<n;i++){
            cin>>tar[i];
        }

        sort(tar,tar+n);
        ans = inf;
        ok=true;
        dfs(0,0);

        printf("Case #%d: ",++cas);
        if(ans==inf){
            puts("NOT POSSIBLE");
        }else{
            printf("%d\n",ans);
        }
    }
    return 0;
}
