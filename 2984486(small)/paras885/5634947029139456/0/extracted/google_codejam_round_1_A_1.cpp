#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

#define ll long long

vector<string> krna;
vector<string> lana;
int N;
int L;
int best;

bool is(vector<string> kk) {
	for(int i = 0; i < N; ++i)
		if(kk[i] != lana[i]) return false;
	return true;
}

void rec(vector<string> kk, int pos, int ans) {
	sort(kk.begin(), kk.end());
	if(is(kk)) {
		best = ans;
		return;
	}
	if(pos == L) {
		if(is(kk))
			best = min(ans, best);
		return;
	}
	vector<string> temp = kk;
	for(int i = 0; i < N; ++i) {
		if(temp[i][pos] == '0')
			temp[i][pos] = '1';
		else 
			temp[i][pos] = '0';
	}
	
	sort(temp.begin(), temp.end());
	if(is(temp)) {
		best = min(ans + 1, best);
		return;
	}
	rec(temp, pos + 1, ans + 1);
	rec(kk, pos + 1, ans);
}

int main()
{
	freopen("google2_1_inp.txt", "r", stdin);
	freopen("google2_1_out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	
	for(int t = 1; t <= T; ++t) {
		scanf("%d%d", &N, &L);
		
		string st;
		krna.clear();
		lana.clear();
		for(int i = 0; i < N; ++i) {
			cin>>st;
			krna.push_back(st);
		}
		
		for(int i = 0; i < N; ++i) {
			cin>> st;
			lana.push_back(st);
		}
		sort(krna.begin(), krna.end());
		sort(lana.begin(), lana.end());
		best = 1e9;
		rec(krna, 0, 0);
		printf("Case #%d: ", t);
		if(best == 1e9) {
			puts("NOT POSSIBLE");
		} else {
			printf("%d\n", best);
		}
	}
	
	return 0;
}
