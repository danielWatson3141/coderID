#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cmath>
#include <deque>
#include <set>
#include <ctime>


using namespace std;

#define MAXN 1024*1024
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()
#define R(a) ((a)%mod)

typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PI;
typedef vector<PI> VPI;
typedef vector<VPI> VVPI;
typedef vector<VVPI> VVVPI;
typedef vector<VVI> VVVI;

int t, n, p;
int a[1024];

int main (int argc, char const* argv[])
{
	cin >> t;
	for (int cs = 0; cs < t; cs += 1)
	{
		cin >> n;
		p = 0;
		for (int i = 0; i < n; i += 1)
		{
			cin >> a[i];
			for (int j = 0; j < i; j += 1)
				p += (a[i]>a[j]);
		}
		cout << "Case #" << cs+1 << ": ";
		if(p % 2 == 1)
		{
			cout << "GOOD\n";
		}
		else	cout << "BAD\n";
		
	}
	return 0;
}














