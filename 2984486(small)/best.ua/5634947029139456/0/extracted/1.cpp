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



void print_v(vector<string> v) {
    REP(i,v.size()) cout<<v[i]<<" ";
    cout<<endl; 
}


int calc(vector<string> o , vector<string> d ) {
    int m = o[0].size();
    int n = o.size();
    vector<map<char, int> > ho(m), hd(m);
    //print_v(o);
    //print_v(d);
    REP(i,n) {
        REP(j,m) {
            ho[j][o[i][j]]++;
            hd[j][d[i][j]]++;
        }
    }
    //cout<<hd[1]['0']<< " " << hd[1]['1'] <<endl;
    bool ok = true;
    int count = 0;
    vector<int> sw(m);
    REP(i, m) {
        int o_0 = ho[i]['0'];
        int o_1 = ho[i]['1'];
        int d_0 = hd[i]['0'];
        int d_1 = hd[i]['1'];

        //cout<<o_0<<" "<< o_1 << " "<< d_0<< " "<<d_1<<endl;

        if (o_0 == d_0 && o_1 == d_1) {
            //cout<<"non"<<endl;
            continue;
        }
        if (o_0 == d_1 && o_1 == d_0) {
            count ++ ;
            sw[i] = 1;
            //cout<<"switch"<<endl;
            continue;
        }
        return -1;
    }

    // transform
    REP(i, n) {
        REP(j, m) {
            if (sw[j]) {
                if (o[i][j] == '0') o[i][j] = '1'; else o[i][j] = '0';
            }
        } 
    }

    // last check
    vector<int> used(n);
    REP(i,n) {
        bool found = false;
        REP(j,n) {
            if (used[j] == 0 && d[i] == o[j]) {
                used[j] = 1;
                found = true;
                break;
            }
        }

        if (!found) return -1;
    }
    return count;
}

int brute(vector<string> o , vector<string> d ) {
    int m = o[0].size();
    int n = o.size();
    SORT(d);
    bool ok = false;
    int res = m+1;
    int M = 1;
    REP(i,m) M = M*2;
    //cout<<M<<endl;
    REP(i,M) {
        //cout<<i<<endl;
        vector<string> o2 = o;
        int c = 0;
        REP(j,m) {
            int v = i & (1<<j);
            //cout<<v<<endl;
            if (v) {
                c++;
                REP(k,n) {
                    if (o2[k][j] == '0') o2[k][j] = '1'; 
                    else o2[k][j] = '0';
                }
            }
        }
        SORT(o2);
        if (o2 == d) {
            ok = true;
            if (c<res) {
                res = min(res, c);
                //cout<<"best "<< i<<endl;
            }
        }
    }
    if (ok) return res;
    return -1;
}

int main()
{
    
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int T; cin>>T;
    int n, l;

    REP(t,T) {
        cin>>n>>l;
        vector<string> o(n), d(n);
        REP(i,n) cin>>o[i];
        REP(i,n) cin>>d[i];

        //int res = calc(o,d);
        int res = brute(o,d);
        //cout<<"res: "<<res<< " "<< res2<<endl;
        //if (t>3) return 0;
        // if (res != res2) {
        //     cout<<"AAAAAAAAA"<<endl;
        // }
        cout<<"Case #"<<t+1;
        if (res>-1) {
            cout<<": "<<res<<endl;
        } else {
            cout<<": NOT POSSIBLE"<<endl;
        }
    }
    return 0;
}
