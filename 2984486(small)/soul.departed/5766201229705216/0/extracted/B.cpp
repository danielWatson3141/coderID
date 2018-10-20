#include <vector>
#include <list>
#include <map>
#include <set>
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
#include <queue>
#include <string>
#include <cstring>

using namespace std;

#define FOR(i,a,b)   	for(int (i)=(a);(i)<(b);(i)++)
#define PB           	push_back
#define INF          	(1 << 29)
#define DEBUG(___x)     cout<<#___x<<" = ["<<___x<<"]"<<endl
#define SORT(___a)      sort(___a.begin(),___a.end())
#define RSORT(___a)     sort(___a.rbegin(),___a.rend())
#define PI           	3.141592653589793238
#define MP           	make_pair
#define PII          	pair<int,int>
#define ALL(___v)       (___v).begin(), (___v).end()
#define VS           	vector<string>
#define VI           	vector<int>
#define S            	size()
//#define B				begin()
#define E				end()
#define print(___v)     {cout<<"[";if(___v.S)cout<<___v[0];FOR(___i,1,___v.S)cout<<","<<___v[___i];cout<<"]\n";}
#define clr(___x, ___v)	memset(___x, ___v , sizeof ___x);
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)


int tu(int val) {return (1 << val);}
bool iset(int mask, int id) {if((mask & tu(id) ) != 0)return true;return false;}
void doset(int &mask, int id) {mask |= tu(id);}
void dounset(int &mask, int id) {mask = mask & (~tu(id));}

typedef long long 					bint;
template<typename T> string tos( T a ) 	{ stringstream ss; string ret; ss << a; ss >> ret; return ret;}

int memo[1009][1009], N, amemo[1009][1009];
VI adj[1009];

int gcnt(int u, int p) {
    int &ret = amemo[u][p];
    if(-1 != ret)return ret;
    
    ret = 1;
    int L = adj[u].S ;
    FOR(i,0,L) {
        int v = adj[u][i];
        if(v == p)continue;
        
        ret += gcnt(v, u);
    }
    
    return ret;
}

int dp(int u, int p) {
    
    int &ret = memo[u][p];
    if(-1 != ret)return ret;
    
    ret = INF;
    VI cost, lost; int L = adj[u].S; int tcost = 0; int lcost = 0;
    FOR(i,0,L) {
        int v = adj[u][i];
        if(v == p)continue;
        
        int ns = dp(v, u);
        int lc = gcnt(v, u);
        
        cost.PB(ns);
        lost.PB(lc);
        
        lcost += lc;
        tcost += ns;
    }
    
    if(cost.S == 0)ret = 0;
    else if(cost.S == 1)ret = lost[0];
    else {
        
        int l = cost.S;
        FOR(i,0,l)FOR(j,i+1,l) {
            int ra = lcost + cost[i] + cost[j] - lost[i] - lost[j];
            ret = min(ret, ra);
        }
    }
    
    return ret;
}

int main() {


	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B_small_out.txt", "w", stdout);

    int T;
    cin >> T;
    
    FOR(t,0,T) {
        clr(memo, -1); clr(amemo, -1);
        FOR(i,0,1009)adj[i].clear();
        
        cin >> N;
        
        int va, vb;
        FOR(i,0,N-1) {
            cin >> va >> vb; va-- ; vb--;
            adj[va].PB(vb);adj[vb].PB(va);
        }
        
        int res = N;
        FOR(i,0,N) {
            int ra = dp(i, i);
            res = min(res, ra);
        }
        
        printf("Case #%d: %d\n", t+1, res);
    }

	return 0;
}

