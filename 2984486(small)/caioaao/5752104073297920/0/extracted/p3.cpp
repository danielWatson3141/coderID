#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

vector<ii> els;

int main(){
	int t, n;
	cin >> t;
	for(int c = 1; c <= t; c++){
		cout << "Case #" << c << ": ";
		cin >> n;
		
		els.assign(n,ii());
		
		for(int i = 0; i < n; i++){
			cin >> els[i].first;
			els[i].second = i;
		}
		sort(els.begin(), els.end());
		
		ll negs = 0, poss=0;
		
		for(int i = 0; i < n; i++){
			if(i > els[i].second) negs++;
			else poss++;
		}
		if(abs(negs - poss) < 23) cout << "GOOD\n";
		else cout << "BAD\n";
	}
}
