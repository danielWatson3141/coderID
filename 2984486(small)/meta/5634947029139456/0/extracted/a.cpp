#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

vector<ll> o, d;
vector<int> co, cd;
int n, l;

bool check() {
    for (int i = 0; i < l; i++) {
        if (co[i] != cd[i]) return false;
    }
    for (int i = 0; i < n; i++) {
        if (!(binary_search(d.begin(), d.end(), o[i]))) return false;
    }
    return true;
}

void sw(int idx) {
    // cerr << "sw\n";
    co[idx] = n - co[idx];
    for (int i = 0; i < n; i++) {
        o[i] = o[i] ^ (1 << idx);
    }
}

bool try_with(int idx, int count) {
    // cerr << idx << " " << count << endl;
    if (idx + count > l) return false;
    if (count == 0) {
        return check();
    }
    if (co[idx] == cd[idx]) {
        if (try_with(idx + 1, count)) return true;
    }
    if (co[idx] == n - cd[idx]) {
        sw(idx);
        if (try_with(idx + 1, count - 1)) return true;
        sw(idx);
    }
    return false;
}

int main() {
    int tcc;
    cin >> tcc;
    for (int tc = 1; tc <= tcc; tc++) {
        cin >> n >> l;
        o.clear();
        d.clear();
        co.clear(); co.resize(l);
        cd.clear(); cd.resize(l);
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            ll v = 0;
            for (int j = 0; j < l; j++) {
                v = v << 1;
                if (s[j] == '0') continue;
                v++;
                co[l - 1 - j]++;
            }
            o.push_back(v);
        }
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            ll v = 0;
            for (int j = 0; j < l; j++) {
                v = v << 1;
                if (s[j] == '0') continue;
                v++;
                cd[l - 1 - j]++;
            }
            d.push_back(v);
        }
        sort(d.begin(), d.end());
        int a;
        for (a = 0; a <= l; a++) {
            if (try_with(0, a)) break;
        }
        printf("Case #%d: ", tc);
        if (a <= l) {
            printf("%d\n", a);
        } else {
            printf("NOT POSSIBLE\n");
        }
    }
    return 0;
}
