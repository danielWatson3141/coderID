#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
using namespace std;
ifstream fin("A-small-attempt0.in");

const int NMAX = 160;
const int LMAX = 50;
int t, n, l, caseCnt(0), ans;
string init[NMAX], devi[NMAX], bacu[NMAX];
void solve(int prev);
int main()
{
	cin.rdbuf(fin.rdbuf());
	cin >> t;
	while(t --){
		cin >> n >> l;
		for(int i = 0; i < n; ++ i)
			cin >> init[i];
		for(int i = 0; i < n; ++ i)
			cin >> devi[i];
		copy(init, init + NMAX, bacu);
		ans = ~(1 << 31);
		solve(0);
		if(ans == ~(1 << 31))
			cout << "Case #" << ++ caseCnt << ": NOT POSSIBLE" << endl;
		else
			cout << "Case #" << ++ caseCnt << ": " << ans << endl;
	}
}
void solve(int prev)
{
	if(prev == l){
		int visit[LMAX];
		memset(visit, 0, LMAX * sizeof(int));
		for(int i = 0; i < n; ++ i){
			bool flag = false;
			for(int j = 0; j < n; ++ j){
				if(init[i] == devi[j]){
					if(!visit[j]){
						visit[j] = 1;
						flag = true;
						break;
					}
				}
			}
			if(!flag){
				return;
			}
		}
		int diffCnt(0);
		for(int i = 0; i < l; ++ i)
			if(init[0][i] != bacu[0][i])
				++ diffCnt;
		ans = min(ans, diffCnt);
		return;
	}
	for(int i = 0; i < 2; ++ i){
		if(i != 0){
			for(int j = 0; j < n; ++ j){
				if(init[j][prev] == '0')
					init[j][prev] = '1';
				else
					init[j][prev] = '0';
			}
		}
		solve(prev + 1);
	}
}

