#include <iostream>
#include <algorithm>
#include <set>
#include <cstdlib>

using namespace std;

#define LL unsigned long long
#define N 1000
#define B 35

set<LL> a;
set<LL> b;
int va[1000];
int vb[1000];

void gen()
{
	for (int i = 0; i < 7000000; ++i)
	{
		for (int i = 0; i < N; ++i)
			va[i] = vb[i] = i; 
		for (int i = 0; i < N; ++i)
		{
			int r1 = rand()%(N-i)+i;
			int r2 = rand()%N;
			swap(va[i], va[r1]);
			swap(vb[i], vb[r2]);
		}
		LL b1 = 0;
		LL b2 = 0;
		for (int i = 0; i < N; ++i)
		{
			b1 = b1*B+(va[i]+1);
			b2 = b2*B+(vb[i]+1);
		}
		a.insert(b1);
		b.insert(b2);
	}
}

int main()
{
	srand(time(NULL));
	gen();
	int t;
	cin >> t;
	for (int x = 1; x <= t; ++x)
	{
		int n;
		cin >> n;
		LL bx = 0;
		for (int i = 0; i < n; ++i)
		{
			int val;
			cin >> val;
			bx = bx*B+val+1;
		}
		bool ca = a.find(bx) != a.end();
		bool cb = b.find(bx) != b.end();
		cout << "Case #" << x << ": ";
		if (ca && cb || !ca && !cb)
			cout << (rand()%2 == 0 ? "GOOD\n" : "BAD\n");
		else if (ca)
			cout << "GOOD\n";
		else
			cout << "BAD\n";
	}
	return 0;
}
