#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <string>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
int n,L;
char a[200][200];
char b[200][200];
int need[200];
int bit[200];

LL ia[200];
LL ib[200];

LL xo[200];

int cnt;
int ans;
map<LL,int>mp;
map<LL,int>::iterator it;
void dfs(int deep){
    if (deep==L) {
        int lim=0;
        for (int i=0;i<n;i++) {
            it=mp.find(ia[i]);
            if (it!=mp.end()){
                if (it->second == 0){
                    lim++;
                    it->second = 1;
                }
            }
        }
        if (lim == n) {
            if (cnt<ans) ans=cnt;
        }
        for (it=mp.begin();it!=mp.end();it++) it->second=0;
        return;
    }
    if (bit[deep]==need[deep]) {
        dfs(deep+1);
    }
    if (bit[deep]==n-need[deep]) {
        xo[deep] = ( 1LL << (L-deep-1) );
        for (int i=0;i<n;i++){ia[i]^=xo[deep];}
        cnt++;
        if (cnt<ans) dfs(deep+1);
        cnt--;
        for (int i=0;i<n;i++){ia[i]^=xo[deep];}
    }
}

int main()
{
    freopen("A-small-attempt0 (1).in","r",stdin);
    freopen("out123.txt","w",stdout);
    int T;
    int cas=0;
    scanf("%d",&T);
    while (T--) {
        memset(need,0,sizeof(need));
        memset(bit,0,sizeof(bit));
        ans = INF;
        mp.clear();
        scanf("%d%d",&n,&L);
        for (int i=0;i<n;i++){
            scanf("%s",a[i]);
            LL x=0;
            for (int j=0;j<L;j++){
                x<<=1;
                x|=(a[i][j]-'0');
            }
            ia[i]=x;
        }
        for (int i=0;i<n;i++){
            scanf("%s",b[i]);
            LL x=0;
            for (int j=0;j<L;j++){
                x<<=1;
                x|=(b[i][j]-'0');
            }
            ib[i]=x;
            mp[x]=0;
        }
        for (int i=0;i<L;i++) {
            for (int j=0;j<n;j++){
                need[i]+=(b[j][i] == '1');
            }
        }
        for (int i=0;i<L;i++){
            for (int j=0;j<n;j++){
                bit[i]+=(a[j][i]=='1');
            }
        }
        //for (int i=0;i<L;i++) cout<<bit[i]<<" ";cout<<endl;
        //for (int i=0;i<L;i++) cout<<need[i]<<" ";cout<<endl;
        //for (int i=0;i<n;i++) cout<<oct<<ia[i]<<" ";cout<<endl;
        //for (int i=0;i<n;i++) cout<<oct<<ib[i]<<" ";cout<<endl;
        cnt=0;
        dfs(0);
        if (ans==INF) {
            printf("Case #%d: NOT POSSIBLE\n",++cas);
        }
        else{
            printf("Case #%d: %d\n",++cas,ans);
        }
    }
    return 0;
}
