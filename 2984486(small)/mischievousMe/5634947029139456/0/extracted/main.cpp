#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
#include<stack>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include<climits>
using namespace std;

typedef long long ll;
typedef vector<string> vs;
# define pb push_back


int main() {
    freopen("/Users/shalini/Downloads/Asmall.txt","r",stdin);
    freopen("/Users/shalini/Downloads/smallSol.txt", "w", stdout);
    int n,l,t,caseno = 0;
    cin>>t;
    while(t--) {
        ++caseno;
        cin>>n>>l;
        vs switches, devices;
        string s;
        for(int i = 0;i < n;++i) {
            cin>>s;
            switches.pb(s);
        }
        for(int i = 0;i < n;++i) {
            cin>>s;
            devices.pb(s);
        }
        sort(devices.begin(),devices.end());
        int mn = INT_MAX;
        for(int i = 0;i < n;++i) {
            vs nswi = switches;
            int cnt = 0;
            for(int j = 0;j < l;++j) {
                if(devices[i][j] != nswi[0][j]) {
                    ++cnt;
                    for(int k = 0;k < n;++k) {
                        nswi[k][j] = ((nswi[k][j] == '0')?'1':'0');
                    }
                }
            }
            
            sort(nswi.begin(),nswi.end());
            if(nswi == devices) {
                mn = min(mn,cnt);
            }
        }
        if(mn == INT_MAX) {
            cout<<"Case #"<<caseno<<": NOT POSSIBLE\n";
        }
        else {
            cout<<"Case #"<<caseno<<": "<<mn<<"\n";
        }
    }
    return 0;
}