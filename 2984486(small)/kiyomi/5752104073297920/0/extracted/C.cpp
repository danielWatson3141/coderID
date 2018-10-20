#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int T, n, a[1234];
string ans[1234];

int main() {

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    vector < pair <int, int> > v;

    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        int inv = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (a[i] > a[j])
                    inv++;
        v.push_back(make_pair(inv, t));
    }

    sort(v.begin(), v.end());

    for (int t = 0; t < T; t++) {
        int test = v[t].second;
        //printf("%d %d\n", v[t].first, v[t].second);
        if (t <= 50)
            ans[test] = "BAD";
        else if (t <= 55)
            ans[test] = "GOOD";
        else if (t <= 60)
            ans[test] = "BAD";
        else
            ans[test] = "GOOD";
    }

    for (int i = 1; i <= T; i++) {
        int b = rand() % 2;
        if (b)
            ans[i] = "GOOD";
        else
            ans[i] = "BAD";
    }

    for (int t = 1; t <= T; t++)
        cout << "Case #" << t << ": " << ans[t] << "\n";

    return 0;

}
