#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <cstring>
#include <string>
using namespace std;

#define pairii pair<double, int>
#define llong long long
#define pb push_back
#define sortall(x) sort((x).begin(), (x).end())
#define INFI  numeric_limits<int>::max()
#define INFLL numeric_limits<llong>::max()
#define INFD  numeric_limits<double>::max()
#define FOR(i,s,n) for (int (i) = (s); (i) < (n); (i)++)
#define FORZ(i,n) FOR((i),0,(n))

bool comp(const pairii& p1, const pairii& p2) {
    return p1.first < p2.first;
}

double score() {
    int n;
    scanf("%d", &n);
    double res = 0;
    int thresh = n/3;
    FORZ(i,n) {
        int b; scanf("%d", &b);
        int tmp = b-(i+1);
        if (tmp >= 0 && tmp <= thresh) {
            res += thresh-tmp;
        }
    }
    return res;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    
    int t;
    scanf("%d", &t);
    vector<pairii> scores(t);
    FORZ(i,t) {
        scores[i].first = score();
        scores[i].second = i;
    }
    sort(scores.begin(), scores.end(), comp);
    vector<string> res(t, "BAD");
    FORZ(i,t/2) res[scores[i].second] = "GOOD";
    FORZ(i,t) {
        cout << "Case #" << i+1 << ": " << res[i] << endl;
    }
    
    return 0;
}

