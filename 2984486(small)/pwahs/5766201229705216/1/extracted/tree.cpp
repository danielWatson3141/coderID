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

vector< set<int> > tree;
vector< map<int, pii> > info;

void compute_info(int i, int j) {
    if (info[i].find(j) != info[i].end()) return;
    int sum = 1;
    int del = 0;
    vector<int> sec;
    for(set<int>::iterator it = tree[j].begin(); it != tree[j].end(); it ++){
        if (*it==i) continue;
        compute_info(j,*it);
        pii inf = info[j][*it];
        sum += inf.first;
        del += inf.second;
        sec.push_back(inf.first - inf.second);
    }
    
    if (sec.size()==0) {
        del = 0;
    } else if (sec.size()==1) {
        del = sum - 1;
    } else {
        sort(sec.begin(), sec.end());
        for (int k = 0; k < sec.size()-2; k++){
            del += sec[k];
        }
    }
    info[i][j] = mp(sum, del);
   // cerr << i << "->" << j << ": (" << sum << "," << del << ")\n";
}

int solve(int testnr){
    int N;
    cin >> N;
    
    tree.clear();
    info.clear();
    tree.resize(N);
    info.resize(N);
    
    for (int i=0;i<N-1;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
       // cerr << a << "," << b << endl;
        tree[a].insert(b);
        tree[b].insert(a);
    }
    
    for (int i=0;i<N;i++){
        for(set<int>::iterator it = tree[i].begin(); it != tree[i].end(); it++) {
            compute_info(i,*it);
        }
    }
    
    int best = N-1;
    
    for (int j=0;j<N;j++){
        
        vector<int> sec;
        int sum = 0, del = 0;
        for(set<int>::iterator it = tree[j].begin(); it != tree[j].end(); it ++){
            pii inf = info[j][*it];
            sum += inf.first;
            del += inf.second;
            sec.push_back(inf.first - inf.second);
        }
        if (sec.size()==1) {
            del = sum - 1;
        } else {
            sort(sec.begin(), sec.end());
            for (int k = 0; k < sec.size()-2; k++){
                del += sec[k];
            }
        }
        best = min(del, best);
    //    cerr << j << ": " << del << endl;
    }
    if (N==2) return 1;
    return best;
}

int main(){

    init();
    
    int T;
    cin >> T;
    for(int i=1;i<=T;i++){
        cout << "Case #" << i << ": " << solve(i) << "\n";
    }
    
    return 0;
}
