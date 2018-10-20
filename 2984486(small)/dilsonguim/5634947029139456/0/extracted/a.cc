#include <bits/extc++.h>
#include <iostream>

using namespace std;

//#define NDEBUG
#ifdef NDEBUG
#define DEBUG if (false)
#else
#define DEBUG if (true)
#endif
#define WRITE(x) DEBUG { cout << (x) << endl; }
#define WATCH(x) DEBUG { cout << #x << " = " << (x) << endl; }
//#define ALL(x) (x).begin(), (x).end()
//#define FORN(i, a, b) for(typeof(b) i = (a); i < (b); ++i)
//#define FOREACH(i, c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)

typedef long long ll;

int solve(const vector<string>& outlets, const set<string>& devices, const int n, const int l){
	int sol = l + 1;
	for(const auto& t : devices){
		string mask;
		for(int i = 0; i < l; i++){
			mask += outlets[0][i] == t[i] ? '0' : '1';
		}
		bool ok = true;
		for(int i = 0; i < n; i++){
			string res;
			for(int j = 0; j < l; j++){
				if(mask[j] == '0'){
					res += outlets[i][j];
				}else if(outlets[i][j] == '0'){
					res += '1';
				}else{
					res += '0';
				}
			}
			if(devices.find(res) == devices.end()){
				ok = false;
				break;
			}
		}
		if(ok){
			int cost = 0;
			for(int j = 0; j < l; j++) if(mask[j] == '1') cost++;
			sol = min(sol, cost);
		}
	}
	return sol;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int ntc;
	cin >> ntc;
	for(int tc = 0; tc < ntc; tc++){
		int n, l;
		cin >> n >> l;

		vector<string> outlets(n);
		set<string> devices;
		for(int i = 0; i < n; i++){
			cin >> outlets[i];
		}
		for(int i = 0; i < n; i++){
			string device;
			cin >> device;
			devices.insert(device);
		}

		int sol = solve(outlets, devices, n, l);
		cout << "Case #" << (tc + 1) << ": ";
		if(sol > l){
			cout << "NOT POSSIBLE";
		}else{
			cout << sol;
		}
		cout << '\n';
	}
}
