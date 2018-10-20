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
#include <fstream>
using namespace std;


#define REP(i,n) for(int i=0; i<n; i++)
#define REPs(i,x,n) for(int i=x; i<n; i++)
#define SZ(x) x.size()
#define VVII vector< vector< pair<int, int> > > 
#define mem(f, a) memset(f, a, sizeof(f))
#define all(c) (c).begin(), (c).end()
#define PB push_back
#define MP make_pair
#define epsil 1e-9
#define infinit  1e8
#define ll long long
#define PI pair<int, int>
#define X first
#define Y second

//bool A[1000];

int main()
{
	ifstream cin("A-small-attempt0.in");
	ofstream cout("out.txt");
	int t; cin >> t;
	REP(i, t){
		cout << "Case #" << i + 1 << ": ";
		int N, L;
		cin >> N >> L;
		vector<string> init(N), req(N), temp;
		vector<bool> flip(L);
		REP(j, N) cin >> init[j];
		REP(j, N) cin >> req[j];
		string first = req[0];
		int minans = infinit;
		REP(j, N)
		{
			bool good = 1;
			int ans = 0;
			vector<string> tsw = req;
			REP(k, L){
				if (first[k] != init[j][k]) flip[k] = 1, ans++;
				else flip[k] = 0;
			}
			REP(k, N){
				string temp = init[k];
				REP(k, L) if (flip[k]) {
					if (temp[k] == '0') temp[k] = '1'; else temp[k] = '0';
				}
				auto it = find(all(tsw), temp);
				if (it != tsw.end()) tsw.erase(it);
				else{
					good = 0; break;
				}
			}
			if (!good) continue;
			if (ans < minans) minans = ans;
			//flip = calc(first, init[j]);
		}
		if (minans<infinit) cout << minans << endl; 
		else cout << "NOT POSSIBLE" << endl;
	}
	return 0;
}