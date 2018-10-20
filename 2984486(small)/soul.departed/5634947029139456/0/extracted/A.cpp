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
#define INF          	INT_MAX
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

string A[500], B[500], NA[500];

char op(char ch) {
    if(ch == '0')return '1';
    return '0';
}

int main() {


	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A_small_out.txt", "w", stdout);
	
	int T, N, L;
	cin >> T;
	
	FOR(t,0,T) {
        cin >> N >> L;
        
        int res = L+2;
        
        FOR(i,0,N)cin >> A[i];
        FOR(i,0,N)cin >> B[i];
        
        FOR(i,0,N)FOR(j,i+1,N) {
            if(B[i] > B[j])swap(B[i], B[j]);
        }
        
        int ln = tu(L);
        
        FOR(mask, 0, ln) {
            
            FOR(i,0,N)NA[i] = A[i];
            FOR(i,0,L)if(iset(mask, i)) {
                FOR(j,0,N)NA[j][i] = op(NA[j][i]);
            }
            
            FOR(i,0,N)FOR(j,i+1,N) {
                if(NA[i] > NA[j])swap(NA[i], NA[j]);
            }
            
            bool ok = true;
            FOR(i,0,N)if(NA[i] != B[i]) {
                ok = false;
                break;
            }
            if(ok) {
                res = min(res, __builtin_popcount(mask) );
            }
        }
        
        if(res == L+2)printf("Case #%d: NOT POSSIBLE\n", t+1);
        else printf("Case #%d: %d\n", t+1, res);
	}

	return 0;
}

