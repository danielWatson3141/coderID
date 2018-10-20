#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>

#define SORT(x) sort(x.begin(),x.end())
#define REVERSE(x) reverse(x.begin(),x.end())
#define mp(x,y) make_pair(x,y)

using namespace std;

typedef unsigned long long ull;
typedef vector<int> VI;
typedef vector<VI> VII;

int main()
{
    ios_base::sync_with_stdio(false);

    freopen("charge.in","r",stdin);
    freopen("charge.out","w",stdout);
    int T;
    cin>>T;
    int t = 1;
    while(T--){


        int N,L;
        cin>>N>>L;
        vector<string> outs;
        for(int k=0;k<N;k++){
            string a;cin>>a;
            outs.push_back(a);
        }
        vector<string> devs;
        for(int k=0;k<N;k++){
            string a;cin>>a;
            devs.push_back(a);
        }

        int ya[200];
        memset(ya,0,sizeof(ya));
        int mn = 100000;

        for(int k=0;k<(1<<L);k++){
        vector<string> act = outs;
        memset(ya,0,sizeof(ya));
            for(int i=0;i<outs.size();i++){
                for(int j=0;j<L;j++){
                    if( k & (1<<j) ){
                        if(act[i][j]=='1')act[i][j]='0';
                        else act[i][j]='1';
                    }
                }
            }
            int cnt = 0;
            for(int aa=0;aa<N;aa++){
                for(int bb=0;bb<N;bb++){
                    if(act[aa]==devs[bb] && !ya[aa]){
                        cnt++;
                        ya[aa] = 1;
                    }
                }
            }

        if(cnt == N){
            mn = min(mn,__builtin_popcount (k));
        }

        }
    if(mn!=100000)cout<<"Case #"<<t<<": "<<mn<<endl;
    else cout<<"Case #"<<t<<": "<<"NOT POSSIBLE"<<endl;
    t++;
    }

    return 0;
}
