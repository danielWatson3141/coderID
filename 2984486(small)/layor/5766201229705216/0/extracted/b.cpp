/*
 * File Name: b.cpp
 * Create Time: 09:38:11,星期六, 26 四月 2014.
 * Author: qqspeed
 */

#include<algorithm>
#include<bitset>
#include<deque>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<limits>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<vector>
#include<complex>
using namespace std;

#define FOR(i,b,e) for(__typeof(b)i=(b);i!=(e);i++)
#define FOR_EACH(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();i++)
#define rep(i,s,t) for(int i=s;i<t;i++)
#define INF ~0U>>2
#define L t<<1
#define	R t<<1|1
#define PI acos(-1.0)
#define clr(a) memset(a,0,sizeof(a))
typedef complex<double>Com;
typedef pair<int,int> ii;
typedef long long ll;
typedef unsigned long long ull;

inline void DATA(char *s,char *d){
    freopen(s,"r",stdin);
    freopen(d,"w",stdout);
}

inline int input(){
    int ret=0;bool isN=0;char c=getchar();
    while(c<'0' || c>'9'){
        if(c=='-') isN=1;
        c=getchar();
    }
    while(c>='0' && c<='9'){
        ret=ret*10+c-'0';c=getchar();
    }
    return isN?-ret:ret;
}

inline void output(int x){
    if(x<0){
        putchar('-');x=-x;
    }
    int len=0,data[10];
    while(x){
        data[len++]=x%10;x/=10;
    }
    if(!len)	data[len++]=0;
    while(len--)
        putchar(data[len]+48);
    putchar('\n');
}

vector<int>e[20];
int t,n;
int a,b;
int root;
int out[20];
int c[20];
bool vis[20];
int cnt;
int son[20];
inline int dfs(int now,int pre){
    int s=e[now].size();int ans=0;
    rep(i,0,s){
        int j=e[now][i];
        if(!vis[j]&&j!=pre){
            ans+=dfs(j,now);
        }
    }
    return son[now]=ans;
}
inline bool ok(int now,int pre){
    int tag=0,s=e[now].size(),num=0;
    //cout<<now<<" "<<pre<<endl;
    cnt++;

    int c[20];
    rep(i,0,s){
        int id=e[now][i];
        if(!vis[id] && id!=pre){
           c[num++]=id;
        }
    }
    if(num!=0 && num!=2){
        return 0;
    }
    if(num==0) return 1;
    else if(num==2){
        int x=ok(c[0],now);
        int y=ok(c[1],now);
        if(x==0 || y==0 || abs(son[c[0]]-son[c[1]])>2) return 0;
        return 1;
    }
}
int main() {
    //ios::sync_with_stdio(false);
    DATA("B-small-attempt2.in","B.out");
    t=input();
    rep(ca,1,t+1){
        n=input();
        clr(out);
        rep(i,0,20) e[i].clear();
        rep(i,1,n){
            a=input(),b=input();
            out[a]++,out[b]++;
            e[a].push_back(b),e[b].push_back(a);
        }
        int all=(1<<n),ans=n-1;
        rep(i,0,all){
            clr(vis);
            int num=0;
            rep(j,1,n+1){
                if(i&(1<<(j-1))){
                    num++;vis[j]=1;
                }
            }
            if(num>=ans) continue;
            rep(j,1,n+1){
                if(!vis[j]){
                    root=j;clr(son);dfs(root,0);
                    cnt=0;
                    if(ok(root,0)!=0){
                        if(cnt==n-num){
                            ans=min(ans,num);break;
                        }
                    }
                }
            }
        }
        printf("Case #%d: %d\n",ca,ans);
    }
    return 0;
}
