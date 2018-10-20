#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <sstream>
#include <map>
#include <set>
#include <memory.h>
#include <numeric>
#include <assert.h>

using namespace std;

#define pb push_back
#define FOR(i,a,b) for (int _n(b), i(a); i < _n; i++) 
#define REP(i,n) FOR(i,0,n)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define CL(a,v) memset((a),(v),sizeof(a))
#define mp make_pair
#define X first
#define Y second 
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c)) 

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> VI; 


int g[107][107];
int v[107];
int d[107];
int n;

bool is_full;

void print_v(int* v) {
    REP(i,n) cout<<v[i]<<" ";
    cout<<endl; 
}

void dfs(int k) {
    v[k] = 1;
    int ch = 0;
    REP(i,n) {
        if (d[i] ==0 && v[i]==0 && g[k][i] == 1) {
            ch ++;
            dfs(i);
        }
    }

    //cout<<"childs "<<k<<" "<<ch<<endl;
    if (ch!=0 && ch != 2) is_full = false;
}

int brute() {
    int M = 1;
    REP(i,n) M*=2;
    int res = n;
    //cout<<M<<endl;
    REP(i,M) {
        CL(d, 0); 
        is_full = true;
        int num = 0;
        REP(k, n) {
            int is = i & (1<<k);
            if (is) {
                d[k] = 1;
                num ++;
            }
        }
        //print_v(d);
        REP(ii,n) {
            CL(v, 0); 
            if (d[ii]==0) {
                //cout<<"Enter : "<<ii<<endl;
                is_full = true;
                dfs(ii);
                int ok = 1;
                REP(p,n) {
                    if (d[p] == 0 && v[p] == 0) ok = 0;
                }
                // if (is_full) {
                //     cout<<"Fants: "<<endl;
                //     print_v(d);
                // }
                //cout<<"Res: "<<cnt << " "<< is_full<<endl;
                if (ok && is_full) {
                    res = min(res, num);
                }
            }
        } 
    }
    return res;
}

int main()
{
    
#ifndef ONLINE_JUDGE
    freopen("input2.txt","r",stdin);
    freopen("output2.txt","w",stdout);
#endif

    int T; cin>>T;


    REP(t,T) {
        cin>>n;
        CL(g,0); CL(v,0);
        REP(i, n-1) {
            int x,y; cin>>x>>y;
            g[x-1][y-1] = g[y-1][x-1] = 1;
        }
        int res = brute();
        cout<<"Case #"<<t+1<<": "<<res<<endl;
    }
    return 0;
}
