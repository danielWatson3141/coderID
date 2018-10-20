#include <cstdio>
#include <vector>
#include <unordered_map>

using namespace std;

void Read(vector<unsigned long long> &a, int n) {
    a.resize(n, 0);
    char str[50];
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        for (int j = 0; str[j] != 0; j++)
            if (str[j] == '1') a[i] |= 1LL << (long long)j;
    }
}

bool Mark(vector<unsigned long long> &a, unordered_map<unsigned long long, int>&c, unsigned long long s) {
    c.rehash(a.size());
    for (unsigned long long val : a) {
           // printf("%llu\n", val ^ s);
        c[val ^ s]++;
    }
}

bool Same(unordered_map<unsigned long long, int>&c, unordered_map<unsigned long long, int>&d) {
    for (auto item : c) {
        auto it = d.find(item.first);
        if (it == d.end() || it->second != item.second) return false;
    }
    return true;
}

int CountDigit(unsigned long long s) {
    int ret = 0;
    for (; s > 0;ret += (s&1), s >>=1);
    return ret;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        int n, l;
        scanf("%d%d", &n, &l);
        vector<unsigned long long> a;
        vector<unsigned long long> b;
        Read(a, n);Read(b, n);
        int best = n * l;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                //if (i != 0 || j != 1)continue;
                unsigned long long s = a[i] ^ b[j];
                int cnt = CountDigit(s);
                unordered_map<unsigned long long, int> c;
                unordered_map<unsigned long long, int> d;
                Mark(a, c, s);
                Mark(b, d, 0);
                if (Same(c, d) && cnt < best) {
                    best = cnt;
                }
        }
        if (best == n * l) printf("Case #%d: NOT POSSIBLE\n", cas);
        else printf("Case #%d: %d\n", cas, best);
    }
    return 0;
}
