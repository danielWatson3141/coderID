#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;

void init() {
	cin.tie(0);
	ios::sync_with_stdio(false);
}

struct t_node {
	vector<string> in;
	int d;
	long long changed;
};

int main() {
	init();
	int t;
	cin >> t;
	rep(tt, t) {
		int n, l;
		cin >> n >> l;
		t_node tf;
		tf.in.resize(n);
		tf.d = 0;
		tf.changed = 0;
		vector<string> patt(n);
		rep(i,n) cin >> tf.in[i];
		rep(i,n) cin >> patt[i];
		sort( patt.begin(), patt.end() );
		queue<t_node> que;
		que.push(tf);
		cout << "Case #" << (tt+1) << ": ";
		bool found = false;
		while( !que.empty() ) {
			t_node tn = que.front();
			que.pop();
			sort( tn.in.begin(), tn.in.end() );
			bool ok = true;
			rep(i, tn.in.size()) {
				if( tn.in[i] != patt[i] ) {
					ok = false;
					break;
				}
			}
			if( ok ) {
				cout << tn.d << endl;
				found = true;
				break;
			}
			rep(i, l) {
				if( !(tn.changed & (1<<i)) ) {
					t_node ntn;
					ntn.in = tn.in;
					ntn.d = tn.d + 1;
					ntn.changed = tn.changed | (1<<i);
					rep(j, n) {
						ntn.in[j][i] = (ntn.in[j][i]=='0' ? '1' : '0');
					}
					que.push(ntn);
				}
			}
		}
		if( !found ) {
			cout << "NOT POSSIBLE" << endl;
		}
	}
	return 0;
}
