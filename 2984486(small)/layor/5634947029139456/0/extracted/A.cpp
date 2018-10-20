/*
 * File Name: A.cpp
 * Create Time: 08:55:42,星期六, 26 四月 2014.
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

int t,n,l;
bool vis[160];
string s[3][160];
int a[11];
const string im="NOT POSSIBLE";
inline int Cmp(string a,string b){
    int ans=0;
    rep(i,0,l){
        if(a[i]!=b[i]) ans++;
    }
    if(ans>1) return INF;  
    return ans;
}
int main() {
    //ios::sync_with_stdio(false);
    DATA("A-small-attempt1.in","A.out");
    t=input();
    rep(ca,1,t+1){
        n=input(),l=input();
        rep(i,0,n) cin>>s[0][i];
        rep(i,0,n) cin>>s[1][i];
        sort(s[0],s[0]+n),sort(s[1],s[1]+n);
        rep(i,1,n+1) a[i]=i;
        int ans=INF;
        int all=(1<<l);
        rep(i,0,all){
            rep(j,0,n){
                s[2][j]=s[0][j];
            }
            int num=0;
            rep(j,0,l){
                if(i&(1<<j)){
                    num++;
                    rep(k,0,n){
                        if(s[2][k][j]=='0') s[2][k][j]='1';
                        else s[2][k][j]='0';             
                    }
                }
            }
            if(num>=ans) continue;
            clr(vis);
            rep(j,0,n){
                rep(k,0,n){
                    if(!vis[k] && s[2][j] == s[1][k]){
                        vis[k]=1;
                        break;
                    }
                }
            }
            int tag=1;
            rep(j,0,n){
                if(vis[j]==0){
                    tag=0;break;
                }
            }
            if(tag) ans=min(ans,num);
        }
        printf("Case #%d: ",ca);
        ans==INF?cout<<im<<endl:cout<<ans<<endl;
    }
    return 0;
}
