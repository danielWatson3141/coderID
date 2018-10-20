
#include <cstdio>
#include <vector>

using namespace std;

struct Nd {
	vector<Nd *> cs;
};

int nn;
Nd ns[1100];

int sb(Nd *r, Nd *p) {
	int n = 1;
	for (Nd *c : r->cs) {
		if ( c == p ) continue;
		n += sb(c, r);
	}
	return n;
}

int dd(Nd *r, Nd *p) {
	size_t ss = r->cs.size();
	if ( p ) {
		if ( ss == 1 ) return 0;
		if ( ss == 2 ) {
			Nd *c = r->cs[0];
			if ( c == p )
				c = r->cs[1];
			return sb(c, r);
		}
	} else {
		if ( ss == 0 ) return 0;
		if ( ss == 1 ) return sb(r->cs[0], r);
	}
	
	struct PP {
		int sb, dd;
	};
	vector<PP> cc;
	cc.reserve(ss);

	int bst = 1000000;
	int tot = 0;
	for (Nd *c : r->cs) {
		if ( c == p ) {
			cc.push_back(PP{10000, 10000});
		} else {
			cc.push_back(PP{sb(c, r), dd(c, r)});
			tot += cc.back().sb;

		}
	}

	for (size_t i = 0; i < ss; ++i) {
		if ( r->cs[i] == p ) continue;
		for (size_t j = i+1; j < ss; ++j) {
			if ( r->cs[j] == p ) continue;
			int x = tot - cc[i].sb - cc[j].sb + cc[i].dd + cc[j].dd;
			bst = min(bst, x);
		}
	}
	return bst;
}

int pp() {
	scanf("%d", &nn);
	for (int i = 0; i < nn-1; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		ns[x].cs.push_back(&ns[y]);
		ns[y].cs.push_back(&ns[x]);
	}

	int a = 100000;
	for (int i = 1; i <= nn; ++i) {
		a = min(a, dd(&ns[i], nullptr));
	}

	for (auto &n : ns)
		n.cs.clear();
	return a;
}


int main() {
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; ++i) {
		printf("Case #%d: %d\n", i, pp());
	}
	return 0;
}
