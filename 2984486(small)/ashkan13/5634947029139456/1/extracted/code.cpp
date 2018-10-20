#include <iostream>
#include <string>
#include <set>
using namespace std;

//typedef long long ll;
//typedef pair<int, int> pii;
#define For(i, a, b) for (int i = (a); i < (b); i++)

int ans;
bool flip[200];
set <string> st;
int n, l;
string flow[200];

int f(const int ind){
	//cout << "_" << ind << "_";	For(i, 0, n) cout << flow[i] << ' ';	cout << endl;

	bool good = true;
	For(i, 0, n){
		if(st.find(flow[i]) == st.end())
		{ good = false; break; }
	}
	if(good) return 0;
	if(flip[ind] || ind >= l) return -1;
	
	//cout << "___#" << ind << "#__";	For(i, 0, n) cout << flow[i] << ' ';	cout << endl;

	int mn = -1;
	For(i, 0, n){
		if(flow[i][ind] == '0')
			flow[i][ind] = '1';
		else flow[i][ind] = '0';
	}
	flip[ind] = true;

	For(i, ind+1, l+1){
		int nw = f(i);
		if(nw == -1) continue;
		if(mn == -1 || nw+1 < mn)
			mn = nw+1;
		if(mn == 1) break;
	}

	For(i, 0, n){
		if(flow[i][ind] == '0')
			flow[i][ind] = '1';
		else flow[i][ind] = '0';
	}
	flip[ind] = false;
	return mn;
}

void main(){
	//*
	freopen("aa.in", "r", stdin);
	freopen("aa.out", "w", stdout);
	//*/

	int T;
	cin >> T;
	For(tc, 1, T+1){
		st.clear();
		cin >> n >> l;
		For(i, 0, n) cin >> flow[i];
		string str[200];
		For(i, 0, n) cin >> str[i];

		For(i, 0, l) flip[i] = false;
		ans = -1;
		For(i, 0, n) st.insert(str[i]);

		int ezaf = 0;
		bool poss = true;
		For(j, 0, l){
			int c10 = 0, c11 = 0;
			For(i, 0, n){
				if(str[i][j] == '0') c10++;
				if(flow[i][j] == '0') c11++;
			}
			if(c10 == c11) continue;
			if(n-c10 != c11 && c10-n != c11) poss = false;
			flip[j] = true;
			For(i, 0, n){
				if(flow[i][j] == '0')
					flow[i][j] = '1';
				else flow[i][j] = '0';
			}
			ezaf++;
		}

		if(poss){
			/*For(i, 0, l){			
				int nw_ans = f(i);
				if(ans == -1 || (nw_ans!=-1 && nw_ans<ans)) ans = nw_ans;
				if(ans == 1) break;
			}*/
			ans = ezaf;
		}

		cout << "Case #" << tc << ": ";
		if(ans == -1) cout << "NOT POSSIBLE\n";
		else cout << ans+ezaf << endl;
	}
}
/*
2
3 30
111111010101010101010101010101
111111010101010101010101011101
111111010101010101010100010101
111111010101010101010101010101
111111010101010101000111110101
111111010101010101010101000001
4

5 8
 11110101 10110011 11000111 00011101 11111100
 00101000 01111100 00100000 01111010 10100011

3 2
01 11 10
11 00 10

2 3
101 111
010 001
2 2
01 10
10 01

*/