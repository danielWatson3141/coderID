#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <hash_map>
#include <string>
#include <map>
#include <set>
#include <queue>

#if 0
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
typedef int256_t lll;
typedef uint256_t ulll;
#endif

using namespace std;
using namespace std::tr1;
using namespace stdext;

typedef __int64 ll;
typedef unsigned __int64 ull;

int T, N;
map<int, list<int> > g;

// not including node
int count_rm(int node, int par) {
    int result = 0;
    list<int>& children = g[node];
    for (list<int>::iterator it1 = children.begin(); it1 != children.end(); ++it1) {
        if (*it1 != par)
            result += 1 + count_rm(*it1, node);
    }
    return result;
}

int solve(int node, int par) {
    list<int>& children = g[node];

    int min_result = count_rm(node, par);

    for (list<int>::iterator it1 = children.begin(); it1 != children.end(); ++it1) {
        if (*it1 == par) continue;
        list<int>::iterator it2 = it1;
        for (it2 = it1, ++it2; it2 != children.end(); ++it2) {
            if (*it2 == par) continue;
            int res = 0;
            for (list<int>::iterator it3 = children.begin(); it3 != children.end(); ++it3) {
                if (*it3 != *it1 && *it3 != *it2 && *it3 != par) {
                    res += 1 + count_rm(*it3, node);
                }
            }
            res += solve(*it1, node) + solve(*it2, node);
            min_result = min(min_result, res);
        }
    }
    return min_result;
}

int main(int argc, char* argv[]) {
    cin >> T;
    for (int t = 0; t != T; ++t) {
        g.clear();
        cout << "Case #" << (t + 1) << ": ";
        cin >> N;
        for (int n = 1; n < N; ++n) {
            int v1, v2;
            cin >> v1 >> v2;
            g[v1].push_back(v2);
            g[v2].push_back(v1);
        }
        int min_cnt = N;
        for (int n = 1; n < N; ++n) {
            min_cnt = min(min_cnt, solve(n, -1));
        }
        cout << min_cnt << "\n"; 
    }
    return 0;
}
