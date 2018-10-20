#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <algorithm>
#include <cctype>
#include <vector>
#include <queue>
#include <tr1/unordered_map>
#include <cmath>
#include <map>
#include <bitset>
#include <set>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector< ii > vii;
///////////////////////////////UTIL/////////////////////////////////
#define ALL(x) (x).begin(),x.end()
#define CLEAR0(v) memset(v, 0, sizeof(v))
#define CLEAR(v, x) memset(v, x, sizeof(v))
#define IN0(x, n) ((x) > -1 && (x) < n)
#define IN(x, a, b) ((x) >= a && (x) <= b)
#define COPY(a, b) memcpy(a, b, sizeof(a))
#define CMP(a, b) memcmp(a, b, sizeof(a))
#define REP(i,n) for(int i = 0; i<n; i++)
#define REPP(i,a,n) for(int i = a; i<n; i++)
#define REPD(i,n) for(int i = n-1; i>-1; i--)
#define REPDP(i,a,n) for(int i = n-1; i>=a; i--)
#define pb push_back
#define pf push_front
#define sz size()
#define mp make_pair
/////////////////////////////NUMERICAL//////////////////////////////
#define INCMOD(a,b,c) (((a)+b)%c)
#define DECMOD(a,b,c) (((a)+c-b)%c)
#define ROUNDINT(a) (int)((double)(a) + 0.5)
#define INF 0x3f3f3f3f
#define EPS 1e-9
/////////////////////////////BITWISE////////////////////////////////
#define CHECK(S, j) (S & (1 << j))
#define CHECKFIRST(S) (S & (-S))  //PRECISA DE UMA TABELA PARA TRANSFORMAR EM INDICE
#define SET(S, j) S |= (1 << j)
#define SETALL(S, j) S = (1 << j)-1  //J PRIMEIROS
#define UNSET(S, j) S &= ~(1 << j)
#define TOOGLE(S, j) S ^= (1 << j)
///////////////////////////////64 BITS//////////////////////////////
#define LCHECK(S, j) (S & (1ULL << j))
#define LSET(S, j) S |= (1ULL << j)
#define LSETALL(S, j) S = (1ULL << j)-1ULL  //J PRIMEIROS
#define LUNSET(S, j) S &= ~(1ULL << j)
#define LTOOGLE(S, j) S ^= (1ULL << j)
//__builtin_popcount(m)
//scanf(" %d ", &t);

int n, t;
int v[10000];

long long insertion_sort(int arr[], int length) {
 long long ans = 0LL;
 int i, j ,tmp;
 for (i = 1; i < length; i++) {
 j = i;
 while (j > 0 && arr[j - 1] > arr[j]) {
 tmp = arr[j];
 arr[j] = arr[j - 1];
 arr[j - 1] = tmp;
 j--;
 ans++;
 }
 }
 return ans;
 }

int main(){
	cin >> t;
	int ones = 0;
	REPP(ca, 1, t+1){
		cin >> n;
		REP(i, n) cin >> v[i];
		
		int cnt = 0;
		
		REP(i, n) if(v[i] == i) cnt++;
		//cout << " CNT " << cnt << endl;
		if(cnt == 1){
			long long ans = insertion_sort(v, n);
			if(ans < 235000LL) cout << "Case #" << ca << ": GOOD\n";	
			else cout << "Case #" << ca << ": BAD\n";	
			//cout << " ANS " << ans << endl;
		}
		else if(cnt < 1) cout << "Case #" << ca << ": GOOD\n";	
		else cout << "Case #" << ca << ": BAD\n";	
		
		
	}
}
