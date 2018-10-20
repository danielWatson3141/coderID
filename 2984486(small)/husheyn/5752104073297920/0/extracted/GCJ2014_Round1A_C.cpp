#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int T, N;
int a[1000];

int main() {
    freopen("C-small-attempt2.in", "r", stdin);
	freopen("C-small-attempt2.out", "w", stdout);
    cin >> T;
    for(int t = 1; t <= T; t++) {
        cin >> N;
        for(int i = 0; i < N; i++)
            cin >> a[i];
        double p = 0;
        for(int i = 0; i < N; i++) {
            if (a[i] == i)
                p += (double)(N - i - 1) / (N - i);
            for(int j = i + 1; j < N; j++)
                if (a[j] == i)
                    a[j] = a[i];
        }
        if (p < 5)
            cout << "Case #" << t << ": GOOD" << endl;
        else
            cout << "Case #" << t << ": BAD" << endl;
    }
    //system("pause");
    return 0;
}
