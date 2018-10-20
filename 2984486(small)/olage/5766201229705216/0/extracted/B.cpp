#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <list>

using namespace std;

#define fr first
#define sd second
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector < vector < double > > vvd;
typedef vector < double > vd;
typedef vector < pair < double, double> > vdd;
typedef vector < vector < long long > > vvl;
typedef vector < long long > vl;


vector<ll> sub;
vl marked;

ll range(vvl G, ll root) {
	marked[root] = 1;
	ll sum = 1;

	for(unsigned long i = 0; i < G[root].size(); i++) {
		ll v = G[root][i];
		if(marked[v] != 1) {
			sum += range(G, v);
		}
	}
	sub[root] = sum;
	return sum;
}

ll dfs(vvl G, ll root) {
	marked[root] = 1;
	vl grey;
	//cout << "dfs " << root << endl;	
	for(unsigned i = 0; i < G[root].size(); i++) {
		ll v = G[root][i];
		if(marked[v] != 1) {
			grey.push_back(v);
		}
	}
/*
	for(int i = 0; i < grey.size(); i++) {
		cout << grey[i] << " ";
	}
	cout << endl;
*/
	if(grey.size() == 0) {
		return 0;
	}

	if(grey.size() == 1) {
		return sub[grey[0]];
	}
	vl wie;
	for(unsigned long i = 0; i < grey.size(); i++) {
		ll w = sub[grey[i]] - dfs(G, grey[i]);
		wie.push_back(w);
	}

	ll sum = 0;
/*	for(unsigned long i = 0; i < wie.size(); i++) {
		cout << wie[i] << " ";
	}
	cout << endl;*/
	for(int z = 0; z < 2; z++) {
		//ll min1 = 1000000000;
		ll min1 = 0;
		
		ll min1_i = 0;
		for(unsigned long i = 0; i < wie.size(); i++) {
			if(wie[i] > min1) {
				min1 = wie[i];
				min1_i = i;
			}
		}
		//cout << "max1_i " << min1_i << endl;
		sum += sub[grey[min1_i]] - wie[min1_i];
//		wie[min1_i] = 100000000;
		wie[min1_i] = 0;

		grey[min1_i] = -1;
	}
/*	
	for(unsigned long i = 0; i < wie.size(); i++) {
		cout << wie[i] << " ";
	}
	cout << endl;*/
/*
	for(unsigned long i = 0; i < wie.size(); i++) {
		wie[i] += 1;// sub[grey[i]];

	}
*/
	for(unsigned long i = 0; i < wie.size(); i++) {
	//	cout << wie[i] << " ";
		if(grey[i] != -1) {
			sum += sub[grey[i]];
		}
//		sum += wie[i];
	}
//	cout << endl;
	return sum;

	/*
		 for(unsigned long i = 0; i < G[root].size(); i++) {
		 for(unsigned long j = 0; j < G[root].size(); j++) {



		 }
		 }
		 */

	return 0;
}

ll solve(vvl G, ll root)
{
	sub.clear();
	sub.resize(G.size());
	marked.clear();
	marked.resize(G.size());

	range(G, root);
	marked.clear();
	marked.resize(G.size());
/*
	for(unsigned long i = 0; i < sub.size(); i++) {
		cout << sub[i] << " ";
	}
	cout << endl;
*/
	return dfs(G, root);
}

int main()
{
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++) {
		vvl G;
		ll N;
		cin >> N;
		G.resize(N);
		for(int i = 0; i < (N - 1); i++) {
			ll a, b;
			cin >> a >> b;
			a--;
			b--;
			G[a].push_back(b);
			G[b].push_back(a);
		}

		ll res = 100000;
		for(int i = 0; i < N; i++) {
			ll c = solve(G, i);
			if(c < res) {
				res = c;
			}
		}
		cout << "Case #" << t << ": " << res << endl;
	}


	return 0;
}
