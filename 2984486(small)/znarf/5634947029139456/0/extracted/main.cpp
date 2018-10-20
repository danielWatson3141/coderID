#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <iterator>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <climits>

using namespace std;
typedef long long LL;
typedef vector<int> vi;
typedef vector<string> vs;

#define foru(i,a,b) for(int i=int(a);i<int(b);i++)
#define ford(i,a,b) for(int i=int(a);i>=int(b);i--)
#define feach(it,c) for( typeof(c.begin()) it=c.begin();it!=c.end();it++)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define fri freopen("A-small-attempt2.in","r",stdin)
//#define fri freopen("input.txt","r",stdin)
#define fro freopen("output.txt","w",stdout)
#define clr(v,x) memset(v,x,sizeof v)
#define MAX 200

vs outl;
vs flow;

int dp[MAX];
int N;
vs change(int x,vs t){
    foru(i,0,t.size()){
        if(t[i][x]=='0')t[i][x]='1';
        else t[i][x]='0';
    }
    return t;
}

bool verify(vs t){
    //flow
    sort(flow.begin(),flow.end());
    sort(t.begin(),t.end());
    //cout<<"n: "<<t.size()<<endl;
    foru(i,0,t.size()){
        //cout<<flow[i]<<"=="<<t[i]<<endl;
        if(flow[i].compare(t[i])!=0)return false;
    }

    return true;
}

int get(int id,vs t) {
    if(verify(t))return 0;
    if (id == N) return 1000000000;

    //if (dp[id]!= -1) return dp[id];
    return min(get(id+1,t),1+get(id+1,change(id,t)));
}

int main()
{
    fri;
    fro;
    int test,n,l;
    scanf("%d",&test);
    foru(cases,1,test+1){
        scanf("%d %d",&n,&l);
        //cerear
        outl.clear();
        flow.clear();
        N=l;
        string cad;
        foru(i,0,n){
            cin>>cad;
            outl.pb(cad);
        }

        foru(i,0,n){
            cin>>cad;
            flow.pb(cad);
        }
        clr(dp,-1);
        vs t = outl;
        int k=get(0,t);
        cout<<"Case #"<<cases<<": ";
        if(k==1000000000)puts("NOT POSSIBLE");
        else cout<<k<<endl;
    }
    return 0;
}
