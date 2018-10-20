#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

void _run() {
    int n, l;
    cin >> n >> l;
    vector<string> initials(n), requires(n);
    for (int i = 0; i < n; i++) {
        cin >> initials[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> requires[i];
    }
    sort(begin(requires), end(requires));

    int min_filp = -1;
    for (int i = 0; i < (1 << l); i++) {
        vector<string> temps(initials);
        bitset<10> b(i);
        int filp = 0;
        for (int j = 0; j < b.size(); j++) {
            if (b[j]) {
                for (auto& temp : temps) {
                    temp[j] = (temp[j] == '0') ? '1' : '0';
                }
                filp++;
            }
        }
        sort(begin(temps), end(temps));

        bool match = true;
        for (int j = 0; j < n; j++) {
            if (temps[j] != requires[j]) {
                match = false;
                break;
            }
        }

        if (match) {
            min_filp = (min_filp < 0) ? filp : min(min_filp, filp);
        }
    }

    if (min_filp < 0) {
        cout << "NOT POSSIBLE" << endl;
    } else {
        cout << min_filp << endl;
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        printf("Case #%d: ", i + 1);
        _run();
    }
}
