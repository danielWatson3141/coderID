#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cassert>
#include <cstdlib>
#include <cstdio>

using namespace std;

#define forall(i,n) for(int i=0; i<(int)(n); i++)

template<class T, class T1, class T2> inline bool Within(T x, T1 xMin, T2 xMax)
    {return (x >= xMin && x <= xMax);}
template<class T, class T1> inline bool Within(T x, T1 xMax)
    {return (x >= 0 && x < xMax);}


typedef unsigned long long Long;
typedef vector<Long> LongVec;

void PrintVec(const LongVec& v) {
    forall (i, v.size())
	printf("%llx ", v[i]);
    printf("\n");
}

// vDevSorted should be sorted
bool CheckSwitch(Long sw, const LongVec& vDevSorted, const LongVec& vOutlets) {
    LongVec vSwitched(vOutlets);
    forall (i, vSwitched.size())
	vSwitched[i] ^= sw;
    sort(vSwitched.begin(), vSwitched.end());
    return vSwitched == vDevSorted;
}

int CountBits(Long x) {
    int n=0;
    while (x) {
	if (x & 1)
	    n++;
	x >>= 1;
    }
    return n;
}

int MinSwitches(const LongVec& vDevSorted, const LongVec& vOutlets) {
    int best = -1;
    forall (j, vOutlets.size()) {
	cerr << "j=" << j << endl;  // DEBUG!!!
	Long sw = vDevSorted[0] ^ vOutlets[j];
	int nBits = CountBits(sw);
	cerr << "ok1" << endl; // DEBUG!!!
	if (best >= 0 && best <= nBits)
	    continue;
	cerr << "ok2" << endl; // DEBUG!!!
	if (CheckSwitch(sw, vDevSorted, vOutlets))
	    best = nBits;
	cerr << "ok3" << endl; // DEBUG!!!
    }
    return best;
}

void ReadVec(LongVec& v, int N, int L) {
    v.resize(N);
    forall (i, N) {
	string s;
	cin >> s;
	assert((int)s.length() == L);
	Long n = 0;
	forall (j, L) {
	    char c = s[j];
	    assert (c == '1' || c == '0');
	    n = (n << 1) | (c == '1' ? 1 : 0);
	}
	v[i] = n;
    }
}

int main() {
    // cout << setprecision(10);
    int nTasks;
    cin >> nTasks;
    for (int iTask=1; iTask<=nTasks; iTask++) {
	int N, L;
	cin >> N >> L;
	LongVec vOutlets(N), vDev(N);
	ReadVec(vOutlets, N, L);
	ReadVec(vDev, N, L);
	sort(vDev.begin(), vDev.end());
	cout << "Case #" << iTask << ": ";
	int best = MinSwitches(vDev, vOutlets);
	if (best >= 0)
	    cout << best << endl;
	else
	    cout << "NOT POSSIBLE" << endl;
    }
}
