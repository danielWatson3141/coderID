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
int first[200];

int f(int ind, int cnter=0){
	//cout << "_" << ind << "_";	For(i, 0, n) cout << flow[i] << ' ';	cout << endl;

	bool good = true;
	For(i, 0, n){
		if(st.find(flow[i]) == st.end())
		{ good = false; break; }
	}
	if(good) return 0;
	if(flip[ind] || ind >= l) return -1;
	
	//if(first[ind] < cnter) return -1;
	//else first[ind] = cnter;
	//cout << "___#" << ind << "#__";	For(i, 0, n) cout << flow[i] << ' ';	cout << endl;

	int mn = -1;
	For(i, 0, n){
		if(flow[i][ind] == '0')
			flow[i][ind] = '1';
		else flow[i][ind] = '0';
	}
	flip[ind] = true;

	For(i, ind+1, l+1){
		int nw = f(i, cnter+1);
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
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
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
		For(i, 0, l) first[l] = l+1;

		For(i, 0, l){
			int nw_ans = f(i);
			if(ans == -1 || (nw_ans!=-1 && nw_ans<ans)) ans = nw_ans;
			if(ans == 1) break;
		}

		cout << "Case #" << tc << ": ";
		if(ans == -1) cout << "NOT POSSIBLE\n";
		else cout << ans << endl;
	}
}
/*
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