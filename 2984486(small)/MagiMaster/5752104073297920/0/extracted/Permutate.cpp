#include <iostream>
#include <vector>
using namespace std;

typedef vector<int>::iterator iter;

class Permutate {
public:

	// http://www.cp.eng.chula.ac.th/~piak/teaching/algo/algo2008/count-inv.htm
	int merge(vector<int> a, vector<int> b, vector<int> &c) {
		c = vector<int>();
		int count = 0;
		int i = 0, j = 0;
		while(i < a.size() && j < b.size()) {
			if(a[i] < b[j]) {
				c.push_back(a[i]);
				++i;
			} else {
				c.push_back(b[j]);
				++j;
				count += a.size() - i;
			}
		}

		c.insert(c.end(), a.begin() + i, a.end());
		c.insert(c.end(), b.begin() + j, b.end());
		return count;
	}

	int count(vector<int> &p) {
		if(p.size() == 1)
			return 0;

		int n = p.size() / 2;
		vector<int> a(p.begin(), p.begin() + n);
		vector<int> b(p.begin() + n, p.end());

		int ra = count(a);
		int rb = count(b);
		int rc = merge(a, b, p);
		return ra + rb + rc;
	}

	void go(istream &in, ostream &out) {
		int t;
		in >> t;

		for(int i = 1; i <= t; ++i) {
			int n;
			in >> n;

			vector<int> p;
			for(int j = 0; j < n; ++j) {
				int x;
				in >> x;
				p.push_back(x);
			}

			int j = count(p);

			if((n % 2) == (j % 2))
				out << "Case #" << i << ": GOOD" << endl;
			else
				out << "Case #" << i << ": BAD" << endl;
		}
	}
};