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


const int maxn = 1010;
const int inf = 1000000007;
const int mod = 1000000007;

int n = 8;
int a[maxn];
int c[maxn][maxn][2];

void genrand1() {
    for (int i = 0; i < n; i++) a[i] = i;
    for (int i = 0; i < n; i++) {
        int o = rand() % (n - i);
        swap(a[i], a[i + o]);
    }
}

void genrand2() {
    for (int i = 0; i < n; i++) a[i] = i;
    for (int i = 0; i < n; i++) {
        int o = rand() % n;
        swap(a[i], a[o]);
    }
}

bool used[maxn];
int cnt(int k) {
    for (int i = 0; i < n; i++) c[i][a[i]][k]++;
    return 0;
    memset(used, 0, sizeof(used));
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        ans++;
        int j = i;
        while (!used[j]) {
            used[j] = 1;
            j = a[j];
        }
    }
    return ans;
}

const int ITERS = 2000000;

int bads;
string solve() {
    int balance = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == 0) continue;
        int i1 = 1 + i;
        int i2 = 1 + (i + (n - 1) / 2);
        if (a[i] < i2 && a[i] >= i1) balance--;
        else balance++;
    }
    if (balance >= 215) {
        return "GOOD";
    } else {
        bads++;
        return "BAD";
    }
}

void rec(int x) {
    if (x == n) {
        //for (int i = 0; i < n; i++) c[i][a[i]][0]++;
        solve();
        return;
    }
    for (int o = 0; o < n; o++) {
        swap(a[x], a[o]);
        rec(x + 1);
        swap(a[x], a[o]);
        if (x == 2) cerr << o << endl;
    }
}

void work() {
    for (int i = 0; i < n; i++) a[i] = i;
    rec(0);
    cout << bads;
    exit(0);
    
    cout.precision(5);
    cout << fixed;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << c[i][j][0] * 1.0 / pow(n, n) << " ";
        }
        cout << endl;
    }
    exit(0);
}
 
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    //work();
    
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        cout << "Case #" << test << ": ";
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        
        cout << solve() << endl;
    }
    cerr << bads << endl;
	return 0;
}
