#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

typedef uint64_t ul;
typedef size_t sz;

ul intfy(std::string s) {
    ul n = 0;
    for (sz i = 0; i < s.size(); ++i) {
        n = n * 2;
        n += (s[i] == '0' ? 0 : 1);
    }
    return n;
}

int countbits(ul n) {
    int count = 0;
    while (n != 0) {
        n = (n & (n - 1));
        ++count;
    }
    return count;
}

int main() {
    int T;
    std::cin >> T;
    for (int casenum = 1; casenum <= T; ++casenum) {
        int N, L;
        std::cin >> N >> L;
        std::vector<std::string> flows;
        std::vector<std::string> reqs;
        for (int i = 0; i < N; ++i) {
            std::string s;
            std::cin >> s;
            flows.push_back(s);
        }

        for (int i = 0; i < N; ++i) {
            std::string s;
            std::cin >> s;
            reqs.push_back(s);
        }


        std::vector<ul> flow;
        std::vector<ul> req;
        for (int i = 0; i < N; ++i) {
            flow.push_back(intfy(flows[i]));
            req.push_back(intfy(reqs[i]));
        }

        std::sort(flow.begin(), flow.end());
        std::sort(req.begin(), req.end());

        std::set<ul> poss;
        for (int i = 0; i < N; ++i) {
            poss.insert(req[0] ^ flow[i]);
        }

        for (int i = 1; i < N; ++i) {
            std::set<ul> tmp;
            for (int j = 0; j < N; ++j) {
                tmp.insert(req[i] ^ flow[j]);
            }

            std::set<ul> newposs;
            for (ul x : tmp) {
                if (poss.find(x) != poss.end()) {
                    newposs.insert(x);
                }
            }
            poss = newposs;
        }

        std::cout << "Case #" << casenum << ": ";
        if (poss.empty()) {
            std::cout << "NOT POSSIBLE" << std::endl;
        } else {
            int minbits = 65;
            for (ul x : poss) {
                minbits = std::min(minbits, countbits(x));
            }
            std::cout << minbits << std::endl;
        }
    }
}
