/*
  Aditya Gourav
  @adi_pearl / @aditya_pearl

*/
#include<bits/stdc++.h>
using namespace std;

//scanning
#define si(x) scanf("%d",&x)
#define ss(x) scanf("%s",x)
#define ssWSP(x) scanf(" %[^\r\n]",x)
#define sill(x) scanf("%lld",&x)
#define sd(x) scanf("%lf",&x)

//debugging
#define dbm1(msg,x) cerr<<(msg)<<" "<<(x)<<endl;
#define dbm2(msg,x,y) cerr<<(msg)<<" "<<(x)<<" "<<(y)<<endl;
#define dbm3(msg,x,y,z) cerr<<(msg)<<" "<<(x)<<" "<<(y)<<" "<<(z)<<endl;
#define dbm(msg) cerr<<(msg)<<endl;
#define db1(x) cerr<<(x)<<endl;
#define db2(x,y) cerr<<(x)<<" "<<(y)<<endl;
#define db3(x,y,z) cerr<<(x)<<" "<<(y)<<" "<<(z)<<endl;

//printing to console
#define pi(x) printf("%d\n",x)
#define pi2(x,y) printf("%d %d\n",x,y)
#define pill(x) printf("%lld\n",x)
#define pd(x) printf("%lf\n",x)
//others
#define ForInc(var,beg,end) for(int var=beg;var<=end;++var)
#define advForInc(var,beg,end,inc) for(int var=beg;var<=end;var+=inc)
#define ForDec(var,end,beg) for(int var=end;var>=beg;--var)
#define F(i,n) ForInc(i,0,n-1)
#define F1(i,n) ForInc(i,1,n)
#define ipArray(arr,size) ForInc(i,0,size-1) si(arr[i]);
#define ipllArray(arr,size) ForInc(i,0,size-1) sill(arr[i]);
#define ii pair<int,int>
#define mp make_pair
#define pb push_back
#define READ(f) freopen(f,"r",stdin);
#define WRITE(f) freopen(f,"w",stdout);
#define TEST int testcases; cin>>testcases;for(;testcases;--testcases)

template<typename T> T gcd(T a, T b) { return (b == 0) ? abs(a) : gcd(b, a % b); }
template<typename T> inline T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<typename T> inline T mod(T a, T b) { return (a % b + b) % b; }
template<typename T> inline T sqr(T x) { return ((x) * (x)); }

const double EPS = 1e-9;
const double BIG = 1e19;
const int INF = INT_MAX;

typedef long long ll;

/* Main Code starts here :) */
char d[150+10][50],s[150+10][50];
int n,l,ans;
inline bool check(){
    vector<bool> flag(n,0);
    F(i,n){
        int sel=-1;
        F(j,n){
            bool f1=1;
            F(k,l)if(d[i][k]!=s[j][k]){f1=0;break;}
            if(f1){sel=j;break;}
        }
        if(sel==-1 || flag[sel]==1)return 0;
        else flag[sel]=1;
    }
    return 1;
}
inline void flip(char &x){
    if(x=='1')x='0';
    else x='1';
}
void solve(int l, int cl){
    if(l<0){
        if(check())ans=min(ans,cl);
        return;
    }
    solve(l-1,cl);
    F(i,n)flip(s[i][l]);
    solve(l-1,cl+1);
    F(i,n)flip(s[i][l]);
}
int main(){
    READ("small.in");
    WRITE("small.out");
    int t;cin>>t;
    for(int case_id=1;case_id<=t;++case_id){
        si(n);si(l);
        F(i,n)ss(s[i]);
        F(i,n)ss(d[i]);
        ans=INT_MAX;
        solve(l-1,0);
        printf("Case #%d: ",case_id);
        if(ans!=INT_MAX)printf("%d\n",ans);
        else printf("NOT POSSIBLE\n");
    }

}
