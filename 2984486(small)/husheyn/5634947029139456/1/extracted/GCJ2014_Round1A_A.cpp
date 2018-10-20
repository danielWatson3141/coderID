#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

typedef long long LL;

int T, N, L;
LL a[150], b[150], c[150];

int main() {
    freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
    cin >> T;
    for(int t = 1; t <= T; t++) {
        cin >> N >> L;
        string str;
        for(int i = 0; i < N; i++) {
            cin >> str;
            LL cur = 0;
            for(int j = 0; j < L; j++)
                cur = (cur << 1LL) + (str[j] - '0');
            a[i] = cur;
        }
        sort(a, a + N);
        for(int i = 0; i < N; i++) {
            cin >> str;
            LL cur = 0;
            for(int j = 0; j < L; j++)
                cur = (cur << 1LL) + (str[j] - '0');
            b[i] = cur;
        }
        int ans = -1;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++) {
                LL flip = a[i] ^ b[j];
                for(int k = 0; k < N; k++)
                    c[k] = b[k] ^ flip;
                sort(c, c + N);
                bool flag = 1;
                for(int k = 0; k < N; k++)
                    if (a[k] != c[k]) {
                        flag = 0;
                        break;
                    }
                if (flag) {
                    int cnt = 0;
                    while (flip) {
                        if (flip & 1LL) cnt++;
                        flip >>= 1LL;
                    }
                    if (ans == -1 || ans > cnt) ans = cnt;
                }
            }
        if (ans == -1) 
            cout << "Case #" << t << ": NOT POSSIBLE" << endl;
        else
            cout << "Case #" << t << ": " << ans << endl;
    }
    //system("pause");
    return 0;
}
