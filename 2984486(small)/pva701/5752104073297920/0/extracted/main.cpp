#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <ctime>
#include <cstdlib>
using namespace std;
const int N = 1005;
//wrong
//217653
//256236

//good
//233776
//267111
//240000 wrong
//250000 ok

int randint(int x, int y) {
    return rand() % (y - x + 1) + x;
}

int cntInv(int a[], int n) {
    int inv = 0;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (a[i] > a[j]) inv++;
    return inv;
}

int gen(int n) {
    int a[N] = {0};
    for (int i = 0; i < n; ++i)
        a[i] = i;
    for (int k = 0; k < n; ++k) {
        int p = randint(0, n - 1);
        swap(a[k], a[p]);
    }
    return cntInv(a, n);
}




const int WRONG_INV = 240000;
const int GOOD_INV =  250000;
int a[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    int cnt = cntInv(a, n);
    if (abs(cnt - WRONG_INV) < abs(cnt - GOOD_INV))
        cout << "BAD\n";
    else
        cout << "GOOD\n";
    //for (int i = 0; i < edges.size(); ++i) cout << dp[i] << " ";cout << endl;
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
