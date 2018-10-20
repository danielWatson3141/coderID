#include <map>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long int llint;

llint gen_hash(char *s, int l) {
	llint r = 0LL;
	for (int j = 0; j < l; j++) {
		r <<= 1;
		r |= s[j] == '1' ? 1 : 0;
	}
	return r;
}

int count_bits(llint b) {
	int r = 0;
	while (b) {
		b &= (b - 1LL);
		r++;
	}
	return r;
}

int main() {
	int t, T;
	int n, l;
	int k, j;
	int r, c;
	map< llint, map< int, int > > m;
	llint i[151];
	llint o[151];
	llint d;
	char s[41];
	scanf("%d", &T);
	for (t = 1; t <= T; t++) {
		m.clear();
		scanf("%d%d", &n, &l);
		for (k = 0; k < n; k++) {
			scanf("%s", s);
			i[k] = gen_hash(s, l);
		}
		for (k = 0; k < n; k++) {
			scanf("%s", s);
			o[k] = gen_hash(s, l);
		}
		for (j = 0; j < n; j++) {
			for (k = 0; k < n; k++) {
				d = i[j] ^ o[k];
				m[d][k] = j;
			}
		}
		r = l + 1;
		for (map< llint, map< int, int > >::iterator mi = m.begin();
			mi != m.end();
			mi++) {
			if (mi->second.size() == n) {
				d = mi->first;
				c = count_bits(d);
				if (c < r) {
					r = c;
				}
			}
		}
		printf("Case #%d: ", t);
		if (r > l) {
			puts("NOT POSSIBLE");
		} else {
			printf("%d\n", r);
		}
	}
	return EXIT_SUCCESS;
}
