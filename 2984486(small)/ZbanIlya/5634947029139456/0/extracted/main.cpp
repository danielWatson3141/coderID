#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>


using namespace std;

#define ll long long
#define y1 _dfdfdfd


const int maxn = 1 << 10;
const int inf = 1000000007;
const int mod = 1000000007;

int n, l;
string a[maxn], b[maxn];
 
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        cout << "Case #" << test << ": ";
        
        cin >> n >> l;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        sort(b, b + n);
        
        multiset<string> st;
        for (int i = 0; i < n; i++) st.insert(b[i]);
        int ans = inf;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            vector<char> v;
            for (int k = 0; k < l; k++) {
                if (a[i][k] != b[0][k]) v.push_back(1);
                else v.push_back(0);
                sum += v[k];
            }
            multiset<string> st2;
            for (int j = 0; j < n; j++) {
                string cur = "";
                for (int k = 0; k < l; k++) {
                    char c = a[j][k] - '0';
                    c ^= v[k];
                    cur += c + '0';
                }
                st2.insert(cur);
            }
            if (st == st2) {
                ans = min(ans, sum);
            }
        }
        if (ans == inf) cout << "NOT POSSIBLE" << endl;
        else cout << ans << endl;
    }

	return 0;
}
