// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890LL
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-10
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
using namespace std;
// mylittledoge

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for(int t =0; t < T; t++) {
		cout << "Case #" << t+1 << ": ";
		int N,L;
		cin >> N >> L;
		vector<string> S(N),D(N);
		for(int i =0; i < N; i++) cin >> S[i];
		for(int i =0; i < N; i++) cin >> D[i];
		int ans =L+1;
		for(int i =0; i < N; i++) {
			string s =D[i];
			int a =0;
			for(int j =0; j < L; j++) {
				s[j] =(int)(S[0][j] != s[j])+'0';
				a +=(int)('1' == s[j]);}
			set<string> S1,S2;
			for(int j =1; j < N; j++) {
				string s2 =S[j];
				for(int k =0; k < L; k++) if(s[k] == '1') s2[k] ='0'+(1-s2[k]+'0');
				S1.insert(s2);}
			for(int j =0; j < N; j++) if(j != i) S2.insert(D[j]);
			if(S1 == S2) ans =min(ans,a);}
		if(ans == L+1) cout << "NOT POSSIBLE\n";
		else cout << ans << "\n";}
	return 0;}

// look at my code
// my code is amazing
