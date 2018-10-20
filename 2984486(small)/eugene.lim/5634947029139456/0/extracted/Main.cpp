#include <cstdio>
#include <cstring>
#include <map>
#include <deque>
#include <vector>

using namespace std;

typedef vector<long long> vll;

vll A, B;

bool check() {
	map<long long, bool> c;
	c.clear();
	for (int i=0; i<(int)B.size(); i++) {
		c[B[i]] = true;
	}
	for (int i=0; i<(int)A.size(); i++) {
		if (c.count(A[i]) == 0) return false;
	}
	return true;
}

int main() {
	int T, N, L, i, j, l, c, o;
	bool found;
	long long x, res;
	vll cur;
	map<long long, bool> m;
	deque<long long> q;
	deque<vll> ql;
	char s[50];
	scanf("%d", &T);
	c = 1;
	while (T--) {
		scanf("%d %d", &N, &L);
		A.clear();
		B.clear();
		for (i=0; i<N; i++) {
			scanf("%s", s);
			x = 0;
			l = strlen(s);
			for (j=1; j<=l; j++) {
				if (s[l-j] == '1') {
					x |= (1 << (j-1));
				}
			}
			A.push_back(x);
		}
		for (i=0; i<N; i++) {
			scanf("%s", s);
			x = 0;
			l = strlen(s);
			for (j=1; j<=l; j++) {
				if (s[l-j] == '1') {
					x |= (1 << (j-1));
				}
			}
			B.push_back(x);
		}
		if (check()) { 
			printf("Case #%d: %d\n", c++, 0);
			continue;
		}
		m.clear();
		q.clear();
		ql.clear();
		m[0] = true;
		q.push_back(0);
		ql.push_back(A);
		found = false;
		res = 0;
		while (!q.empty()) {
			x = q.front(); q.pop_front();
			cur = ql.front(); ql.pop_front();
			for (i=0; i<L; i++) {
				if ((x & (1<<i)) == 0 && m.count((x|(1<<i))) == 0) {
					res = (x|(1<<i));
					A = vll();
					for (j=0; j<N; j++) {
						A.push_back(cur[j] ^ (1<<i));
					}
					found = check();
					if (found) break;
					q.push_back(res);
					ql.push_back(A);
					m[res] = true;
				}
			}
			if (found) break;
		}
		if (!found) printf("Case #%d: NOT POSSIBLE\n", c++);
		else {
			o = 0;
			for (i=0; i<L; i++) {
				if ((res & (1<<i)) != 0) o++;
			}
			printf("Case #%d: %d\n", c++, o);
		}
	}
	return 0;
}
