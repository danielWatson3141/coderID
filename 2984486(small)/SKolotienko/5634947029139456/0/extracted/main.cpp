#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <set>

using namespace std;

const int INF = 2000000000;
const __int64 INF64 = 4000000000000000000LL;

//const string fileNameBase = "A-sample";
const string fileNameBase = "A-small-attempt1";

int T;
int n;

vector<int> mt;
vector<char> used;
bool try_kuhn(int v, const vector<vector<int>>& g)
{
	if( used[v] )  return false;
	used[v] = true;
	for( size_t i = 0; i<g[v].size(); ++i ) {
		int to = g[v][i];
		if( mt[to] == -1 || try_kuhn(mt[to], g) ) {
			mt[to] = v;
			return true;
		}
	}
	return false;
}

int main( int argc, char* argv[] )
{
//#ifdef TEST
//#pragma warning(disable: 4996)
	freopen((fileNameBase + ".in").c_str(), "r", stdin);
	freopen((fileNameBase + ".out").c_str(), "w", stdout);
//#endif

	cin >> T;
	for( int Ti = 1; Ti <= T; Ti++ ) {
		int n;
		int l;
		cin >> n >> l;
		vector<long long> outlets(n, 0);
		vector<long long> devices(n, 0);

		for( int i = 0; i < n; i++ ) {
			string s;
			cin >> s;
			for( int j = 0; j < l; j++ ) {
				outlets[i] |= (long long)(s[j] == '1') << j;
			}
		}

		for( int i = 0; i < n; i++ ) {
			string s;
			cin >> s;
			for( int j = 0; j < l; j++ ) {
				devices[i] |= (long long)(s[j] == '1') << j;
			}
		}


		bool ansGood = true;
		int ansCount = INF;
		for( long long x = 0; x < (1LL << l); x++ ) {
			set<long long> A;
			for( int i = 0; i < n; i++ ) {
				A.insert(outlets[i] ^ x);
			}
			bool good = true;
			for( int i = 0; i < n; i++ ) {
				set<long long>::iterator iter = A.find(devices[i]);
				if( iter == A.end() ) {
					good = false;
					break;
				}
				A.erase(iter);
			}
			if( !good ) continue;
			int count = 0;
			for( int i = 0; i < l; i++ ) {
				count += (x & (1LL << i)) > 0;
			}
			ansCount = min(ansCount, count);
		}
		ansGood = ansCount < INF;

		cout << "Case #" << Ti << ": ";
		if( !ansGood ) {
			cout << "NOT POSSIBLE";
		} else {
			cout << ansCount;
		}
		cout << "\n";
	}
	
	return 0;
}