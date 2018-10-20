#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
	int N, L;
	cin >> N >> L;
	set<int> s;
	for (int i = 0; i < N; i++) {
	    string x;
	    cin >> x;
	    int a = bitset<10>(x).to_ulong();
	    s.insert(a);
	}

	vector<int> v(N);
	for (int i = 0; i < N; i++) {
	    string x;
	    cin >> x;
	    v[i] = bitset<10>(x).to_ulong();
	}

	int res = 1 << 20;

	for (int i = 0; i < 1 << L; i++) {
	    bitset<10> mask(i);
	    
	    set<int> y;
	    for (int x : v) {
		bitset<10> m(x);
		int z = (m ^ mask).to_ulong();
		y.insert(z);
	    }
	    if (s == y)
		res = min<int>(res, mask.count());
	}

	if (res == 1 << 20) {
	    cout << "Case #" << t << ": " << "NOT POSSIBLE" << endl;
	} else {
	    cout << "Case #" << t << ": " << res << endl;
	}
    }
    return 0;
}
