#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <cstring>



using namespace std;
#define INFY 100000000

int main() {
    freopen("/Users/arunamahesh/A-small-attempt0.in","r",stdin);
    freopen("/Users/arunamahesh/GCJ_output.txt","w",stdout);
    int t; cin>>t;
    for(int T = 1;T <= t;T++) {
        int n,l;
        cin>>n>>l;
        vector<string> init(n);
        vector<int> toget(n,0);
        for(int i = 0;i < n;i++) {
            cin>>init[i];
        }
        for(int i = 0;i < n;i++) {
            string s; cin>>s;
            for(long j = s.length() - 1;j >= 0;j--) {
                toget[i]+= (s[j] - '0')<<(s.length() - j - 1);
            }
        }
        vector<string> temp(n);
        sort(toget.begin(),toget.end());
        int min = INFY;
        for(int i = 0;i < 1<<l;i++) {
            temp = init;
            for(int k = 0;k < l;k++) {
                if(!(1<<k & i)) continue;
                for(int j = 0;j < n;j++) {
                    temp[j][k] = temp[j][k] == '1' ? '0' : '1';
                }
            }
            vector<int> convin(n);
            for(int i = 0;i < n;i++) {
                string s = temp[i];
                for(long j = s.length() - 1;j >= 0;j--) {
                    convin[i]+= (s[j] - '0')<<(s.length() - j - 1);
                }
            }
            sort(convin.begin(),convin.end());
            if(toget == convin) {
                int cnt = 0;
                for(int j = 0;j < l;j++) {
                    if(1<<j & i) cnt++;
                }
                min = cnt < min ? cnt : min;
            }
        }
        if(min == INFY) {
            cout<<"Case #"<<T<<": "<<"NOT POSSIBLE"<<endl;
        }
        else {
            cout<<"Case #"<<T<<": "<<min<<endl;
        }
    }
}