#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define dbg(args...) {debug,args; cerr << endl;}

#define mp make_pair
#define mt(a,b,c) mp(a,mp(b,c))
#define P1(a) (a).first
#define P2(a) (a).second
#define T1(a) (a).first
#define T2(a) (a).second.first
#define T3(a) (a).second.second
#define INF 1e20
#define EPS 1e-8

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> tiii;

class debu{
	public:
	template<class someClass>
	debu & operator,(someClass arg){
		cerr << arg << " ";
		return *this;
	}
} debug;


void init(){
    cout << setprecision(8)<< fixed;
}

int solve(int testnr){
    ll n, L;
    cin >> n >> L;
    
    set<ll> outlet;
    set<ll> device;
    
    char c;
    
    for(int i=0;i<n;i++){
        int num = 0;
        for (int j=0;j<L;j++){
            cin >> c;
            num <<= 1;
            num += (c=='1'?1:0);
        }
        outlet.insert(num);
    }
    
    for(int i=0;i<n;i++){
        int num = 0;
        for (int j=0;j<L;j++){
            cin >> c;
            num <<= 1;
            num += (c=='1'?1:0);
        }
        device.insert(num);
    }
    
    int best = L+1;
    ll p = 0;
    
    for(set<ll>::iterator it = outlet.begin(); it != outlet.end() ; it++){
        ll dev = *(device.begin());
        p = (*it) ^ (dev);
        bool works = true;
        for (set<ll>::iterator devit = device.begin(); devit != device.end() ; devit++){
            ll newout = p ^ (*devit);
            if (outlet.find(newout) == outlet.end()){
                works = false;
                break;
            }
        }
        if (works){
            int count = 0;
            while (p){
                count += p%2;
                p>>=1;
            }
            best = min(best, count);
        }
    }
    if (best == L+1){
        cout << "NOT POSSIBLE";
    } else {
        cout << best;
    }
    return 0;
}

int main(){

    init();
    
    int T;
    cin >> T;
    for(int i=1;i<=T;i++){
        cout << "Case #" << i << ": ";
        solve(i); 
        cout << "\n";
    }
    
    return 0;
}
