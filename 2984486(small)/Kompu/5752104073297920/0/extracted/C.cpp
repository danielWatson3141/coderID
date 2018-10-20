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

LL Merge(VI& a, VI& b, int p, int q, int r)
{
    int i = p, j = q + 1, s = p;
    LL wyn = 0, ile_druga = 0;
    while (i <= q && j <= r)
    {
        if (a[i] <= a[j])
        {
            b[s] = a[i];
            i++;
            wyn += ile_druga;
        }
        else
        {
            b[s] = a[j];
            j++;
            ile_druga++;
        }
        s++;
    }
    while (i <= q)
    {
        b[s] = a[i];
        i++;
        s++;
        wyn += ile_druga;
    }
    while (j <= r)
    {
        b[s] = a[j];
        j++;
        s++;
    }
    for (int it = p; it <= r; it++) a[it] = b[it];
    return wyn;
}
LL MergeSort(VI& a, VI& b, int p, int r)
{
    LL wyn = 0;
    if (p == r) return wyn;
    int q = (p + r)/2;
    wyn += MergeSort(a, b, p, q);
    wyn += MergeSort(a, b, q + 1, r);
    wyn += Merge(a, b, p, q, r);
    return wyn;
}
LL Inwersje(VI& a)
{
    VI b(SIZE(a));
    return MergeSort(a, b, 0, SIZE(a) - 1);
}

int main()
{
	int t, n;
	scanf("%d", &t);
	FOR(o, 1, t)
	{
		scanf("%d", &n);
		VI numb(n);
		REP(x, n) scanf("%d", &numb[x]);
		//printf("%lld\n", Inwersje(numb));
		printf("Case #%d: ", o);
		if(abs(Inwersje(numb) - 249750) > 10000) printf("BAD\n");
		else printf("GOOD\n");
		
	}
	return 0;
}
