#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;
#define pb push_back
#define MP make_pair
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,l,h) for(int i=(l);i<=(h);++i)
#define DWN(i,h,l) for(int i=(h);i>=(l);--i)
typedef long long LL;
typedef pair<int,int> PII;

int num[2][40][2];
vector<LL>f0,f1;
vector<LL>g;
int flag[40];


struct Node{
    LL pos;
    int id;
    Node(LL pos,int id):pos(pos),id(id){}
};

int getnum(LL temp){
    int ret=0;
    while(temp){
        if(temp&1)  ret++;
        temp>>=1;
    }
    return ret;
}

bool check(){
    sort(f0.begin(),f0.end());
    REP(i,f0.size())    if(f0[i]!=f1[i])    return 0;
    return 1;
}

int bfs(int n,int L){
    queue<Node>q;
    q.push(Node(0,0));
    while(!q.empty()){
        Node temp = q.front(); q.pop();

        REP(i,n)    f0[i]^=temp.pos;
        if(check())    return getnum(temp.pos);
        REP(i,n)    f0[i]^=temp.pos;

        FOR(i,temp.id,L-1)  q.push(Node(temp.pos | 1ll<<i , i+1));
    }
    return -1;
}


int solve(int n,int L){
    memset(num,0,sizeof(num));
    memset(flag,0,sizeof(flag));
    sort(f1.begin(),f1.end());


    long long temp=0;
    int ans=0;
    REP(len,L){
        if(abs(num[0][len][0]-num[0][len][1]) != abs(num[1][len][0]-num[1][len][1]) ) return -1;
        else {
            if(num[0][len][0] == num[0][len][1])    flag[len]=1;
            else temp|=(1ll<<len),ans++;
        }
    }
    int ret=bfs(n,L);
    if(ret==-1) return -1;
    else return ans + ret;
}

int main()
{
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    int casnum;
    cin>>casnum;
    int n,L;
    string str;
    FOR(cas,1,casnum){
        cin>>n>>L;
        f0.clear(),f1.clear();
        REP(i,n){
            cin>>str;
            LL temp=0;
            REP(len,L){
                if(str[len]=='1')   temp|=(1ll<<len),num[0][len][1]++;
                else num[0][len][0]++;
            }
            f0.pb(temp);
        }
        REP(i,n){
            cin>>str;
            LL temp=0;
            REP(len,L){
                if(str[len]=='1')   temp|=(1ll<<len),num[1][len][1]++;
                else num[1][len][0]++;
            }
            f1.pb(temp);
        }




        printf("Case #%d: ",cas);
        int ans=solve(n,L);
        if(ans==-1) puts("NOT POSSIBLE");
        else cout<<ans<<endl;
        //puts("*************");
    }

    return 0;
}
