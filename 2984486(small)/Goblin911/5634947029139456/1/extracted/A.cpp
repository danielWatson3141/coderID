#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <string>
using namespace std;

int n, l, ans;
string a[50], b[50];
int flag[50];

bool dfs(int t, int sum) {
    if (t == l) {
        sort(a, a + n);
        sort(b, b + n);
        for (int i = 0; i < n; i++) if (a[i] != b[i]) {
            return false;
        }
        ans = sum;
        return true;
    }
    bool res = false;
    if (flag[t] == 1) {
        for (int j = 0; j < n; j++) if (b[j][t] == '1') 
            b[j][t] = '0'; 
        else b[j][t] = '1';
        res |= dfs(t + 1, sum + 1);
        for (int j = 0; j < n; j++) if (b[j][t] == '1') 
            b[j][t] = '0'; 
        else b[j][t] = '1';

    } else if (flag[t] == 2) {
        res |= dfs(t + 1, sum);
        if (res) return true;
        for (int j = 0; j < n; j++) if (b[j][t] == '1') 
            b[j][t] = '0'; 
        else b[j][t] = '1';
        res |= dfs(t + 1, sum + 1); 
        for (int j = 0; j < n; j++) if (b[j][t] == '1') 
            b[j][t] = '0'; 
        else b[j][t] = '1';

    } else if (flag[t] == 0) {
        res |= dfs(t + 1, sum);
    }
    return res;
}

void solve() {
    cin >> n >> l;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    memset(flag, 0, sizeof(flag)); ans = -1;
    for (int i = 0; i < l; i++) {
        int sumA = 0, sumB = 0;
        for (int j = 0; j < n; j++) sumA += a[j][i] - '0';
        for (int j = 0; j < n; j++) sumB += b[j][i] - '0';
        if (n % 2 == 0 && sumA == n / 2){
            flag[i] = 2;
            continue;
        }
        if (sumA == sumB) {
            continue;
        }
        if (sumA != sumB && sumA == n - sumB) {
            flag[i] = 1;
            ans++;
            continue;
        } else {
            printf("NOT POSSIBLE\n");
            return;
        }
    }
    if (dfs(0, 0))
        printf("%d\n", ans);
    else 
        printf("NOT POSSIBLE\n");
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        printf("Case #%d: ", i);
        solve();
    }
}
