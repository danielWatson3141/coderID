#include <bits/stdc++.h>
using namespace std;

#define fr(a,b,c) for (int a = b; a < c; ++a)
#define db(x) cerr << #x " == " <<  x << endl
#define _ << ", " <<

#define MN 2000
#define MM 10000
int ult[MN], prox[MM], vert[MM], z;
#define add(a,b) vert[z] = b, prox[z] = ult[a], ult[a] = z++

typedef pair<int,int> pii;
#define F first
#define S second

int n;
pii go(int x, int y = -1) {
	vector<pii> s;
	for (int w = ult[x]; ~w; w = prox[w]) {
		if (vert[w] == y) continue;
		s.push_back(go(vert[w], x));
	}
	sort(s.begin(), s.end());
	int tam = 1;
	fr(i,0,s.size()) tam += s[i].F;
	
	if (s.size() == 0) return pii(tam, 0);
	if (s.size() == 1) return pii(tam, s[0].F);
	if (s.size() == 2) return pii(tam, s[0].S + s[1].S);
	
	vector<int> d;
	fr(i,0,s.size()) d.push_back(s[i].F-s[i].S);
	sort(d.begin(), d.end());
	
	return pii(tam, tam-d[s.size()-1]-d[s.size()-2]-1);
}

int main() {
	int t, caso = 1;
	for (cin >> t; caso <= t; ++caso) {
		printf("Case #%d: ", caso);
		memset(ult,-1,sizeof ult); z = 0;
		cin >> n;
		fr(i,1,n) {
			int a, b;
			cin >> a >> b;
			--a, --b;
			add(a,b), add(b,a);
		}
		
		int r = 100000;
		fr(i,0,n) r = min(r, go(i).S);
		printf("%d\n", r);
	}
	return 0;
}
