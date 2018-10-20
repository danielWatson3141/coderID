#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <set>
#include <map>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PI;
typedef vector<PI> VPI;
typedef long long LL;
typedef vector<LL> VLL;
typedef vector<string> VS;
#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
#define FORD(x, b, e) for(int x = b; x >= (e); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define VAR(v, n) __typeof(n) v = (n)
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) ((int)(x).size())
#define PB push_back
#define MP make_pair
#define ST first
#define ND second
const int INF = 1000000001;
const double EPS = 10e-9;

int bitCount(LL n)
{
	int w = 0;
	LL b = 1l << 62;
	while(b != 0)
	{
		if((b & n) != 0) w++;
		b >>= 1;
	}
	return w;
}

int main()
{
	int t, n, l, w;
	LL b;
	bool p;
	string temp;
	cin >> t;
	FOR(o, 1, t)
	{
		cin >> n >> l;
		VLL own(n), need(n), buf(n);
		REP(x, n) 
		{
			b = 0;
			cin >> temp;
			REP(i, l) if(temp[i] == '1') b += 1l << (l - i - 1);
			own[x] = b;
		}
		REP(x, n) 
		{
			b = 0;
			cin >> temp;
			REP(i, l) if(temp[i] == '1') b += 1l << (l - i - 1);
			need[x] = b;
		}
		sort(ALL(need));
		b = 0;
		w = INF;
		REP(i, 1 << l)
		{
			REP(x, n) buf[x] = own[x] ^ b;
			sort(ALL(buf));
			p = true;
			REP(x, n) if(buf[x] != need[x])
			{
				p = false;
				break;
			}
			if(p) w = min(w, bitCount(b));
			b++;
		}
		printf("Case #%d: ", o);
		if(w == INF) printf("NOT POSSIBLE\n");
		else printf("%d\n", w);
	}
	return 0;
}
