#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cmath>
#include <limits>
#include <string>
#include <cstring> // memset
#include <iostream> // cin, cout

#include <sstream> // topcoder testcase

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;

#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define REP(i, a, b) for (int i = int(a); i < int(b); i++) // a to b, and variable i is local!

#define DEBUG(x) do { std::cerr << #x << ": " << x << std::endl; } while (0)

main()
{
    // Number of Testcases
    int T;
    int N,L;
    cin >> T;

    for(int i=0;i<T;i++){
        cin >> N >> L;
        vector<string> outlets;
        vector<string> flows;
        REP(j,0,N){
            string s; cin>>s;
            outlets.push_back(s);
        }
        sort(all(outlets));
        REP(j,0,N){
            string s; cin>>s;
            flows.push_back(s);
        }
        sort(all(flows));
        int mini=1000;

        for(int j=0; j<(1<<L);j++){
            vector<string> v(flows);
            for(int b=0;b<L;b++){
                if((j&(1<<b))!=0){
                    REP(x,0,N) v[x][b]=v[x][b]=='0' ? '1':'0';
                }
            }
            sort(all(v));
            if(v==outlets){
                mini=min(mini,__builtin_popcount(j));
            }
        }
        if(mini==1000)
            cout << "Case #" << (i+1) << ": " << "NOT POSSIBLE" << endl;
        else
            cout << "Case #" << (i+1) << ": " << mini << endl;
    }

    return 0;
}
