#include <iostream>
using namespace std;

long double p[1000][1000], q[1000][1000];
int n = 1000;

void cp(long double p[1000][1000], long double q[1000][1000]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            p[i][j] = q[i][j];
}

void solve() {
    long double rate = 1;
    int x;
    int _;
    cin >> _;
    for (int i = 0; i < n; i++) {
        cin >> x;
        rate *= p[x][i] * n;
    }
    if (rate > 1) 
        cout << "BAD" << endl;
    else
        cout << "GOOD" << endl;
}

int main() {
    for (int i = 0; i < n; i++)
        p[i][i] = 1;
    for (int i = 0; i < n; i++) {
        //cout << i << endl;
        cp(q, p);
        for (int j = 0; j < n; j++)
            q[j][i] /= n;
        for (int j = 0; j < n; j++)
            if (i != j)
                for (int k = 0; k < n; k++) {
                    q[k][j] = p[k][j] * (n - 1) / n + p[k][i] / n;
                    q[k][i] += p[k][j] / n;
                }
        cp(p, q);
    }

    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        printf("Case #%d: ", i);
        solve();
    }
}
