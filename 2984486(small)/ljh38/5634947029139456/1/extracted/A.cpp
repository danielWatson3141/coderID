#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <cassert>
#include <limits>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

long long pattern(long long X, long long Y) {
    return (X ^ Y);
}

long long toN(const std::string& s) {
    long long rtn = 0;
    for (int i = 0; i != s.length(); ++i) {
        if (s[i] == '1') {
            rtn |= 1;
        }
        rtn <<= 1;
    }
    return rtn;
}

int countBits(long long n) {
    int rtn = 0;
    while (n != 0) {
        if (n & 1) {
            rtn++;
        }
        n >>= 1;
    }
    return rtn;
}

int main() {
    // ifstream in("sample.in");
    istream& in = cin;

    int C;
    in >> C;
    for (int c = 0; c != C; ++c) {
        int N, L;
        in >> N >> L;

        vector<long long> outlets;
        for (int n = 0; n != N; ++n) {
            string s;
            in >> s;
            outlets.push_back(toN(s));
        }
        vector<long long> devices;
        for (int n = 0; n != N; ++n) {
            string s;
            in >> s;
            devices.push_back(toN(s));
        }

        map<long long, int> patternCount;
        for (int i = 0; i != N; ++i) {
            for (int j = 0; j != N; ++j) {
                long long p = pattern(outlets[i], devices[j]);
                patternCount[p]++;
            }
        }

        vector<long long> candidates;
        for (map<long long, int>::const_iterator itr = patternCount.begin(); itr != patternCount.end(); ++itr) {
            assert(itr->second <= N);
            if (itr->second == N) {
                candidates.push_back(itr->first);
            }
        }

        if (candidates.empty()) {
            cout << "Case #" << (c+1) << ": " << "NOT POSSIBLE" << endl;
        } else {
            int fewest = countBits(candidates.front());
            for (int i = 0; i != candidates.size(); ++i) {
                int bits = countBits(candidates[i]);
                if (bits < fewest) {
                    fewest = bits;
                }
            }
            cout << "Case #" << (c+1) << ": " << fewest << endl;
        }
    }
    return 0;
}
