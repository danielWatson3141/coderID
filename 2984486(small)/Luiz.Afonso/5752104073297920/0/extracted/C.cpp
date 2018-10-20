#include <bits/stdc++.h>
using namespace std;

#define fr(a,b,c) for (int a = b; a < c; ++a)
#define db(x) cerr << #x " == " << x<<  endl
#define _ << ", " <<
typedef long long ll;


#define F first
#define S second

map<vector<int>, int> cnt;

void bt(const vector<int>& p, int idx) {
	if (idx == p.size()) {
		cnt[p]++;
		//fr(i,0,p.size()) cerr << p[i] << " "; cerr << "\n";
		return;
	}
	fr(i,0,p.size()) {
		vector<int> q = p;
		swap(q[i], q[idx]);
		bt(q, idx+1);
	}
}

int m, array[2000];

int main() {
	int p[] = {0,1,2,3,4,5,6};
	int n = 5;
	bt(vector<int>(p, p+n), 0);
	
	int fat = 1, tt = 1;
	fr(i,1,n+1) fat *= i;
	fr(i,0,n) tt *= n;
	double ww =  tt / (double)fat;
	
	/*
	map<int, vector<vector<int> > > rev;
	for (map<vector<int>, int>::iterator it = cnt.begin(); it != cnt.end(); ++it) {
		vector<int> p = it->first;
		fr(i,0,p.size()) cerr << p[i] << " ";
		cerr << "-> " << it->second << (it->S < ww ? " GOOD" : " BAD") << "\n";
		rev[it->S].push_back(p);
	}
	for (map<int, vector<vector<int> > >::iterator it = rev.begin(); it != rev.end(); ++it) {
		db(it->F);
		fr(i,0,it->S.size()) {
			vector<int> p = it->S[i];
			fr(i,0,p.size()) cerr << p[i] << " "; cerr << "\n";
		}
	}
	*/
	db (ww);

	int t, caso = 1;
	for (cin >> t; caso <= t; ++caso) {
		printf("Case #%d: ", caso);
		cin >> m;
		fr(i,0,m) cin >> array[i];
		
		vector<int> seq;
		fr(i,0,n) {
			int s = 0;
			fr(j,i*m/n,(i+1)*m/n) s += array[j];
			
			seq.push_back(s*2);
		}
		int coord[20];
		fr(i,0,n) coord[i] = seq[i];
		sort(coord, coord + n);
		fr(i,0,n) {
			int w = lower_bound(coord,coord+n, seq[i]) -coord;
			seq[i] = w;
			coord[w]--;
		}
		
		//fr(i,0,n) cerr << seq[i] << " "; cerr << "\n";
		//db(cnt[seq]);	
		if (1 <= array[0] && array[0] <= 500) puts("BAD");
		else puts("GOOD");
		continue;
			
		if (cnt[seq] < ww) puts("GOOD");
		else puts("BAD");
	}
	return 0;
}
