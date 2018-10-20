#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int l;
string a[222], b[222];
int res, cnt;

void change(int i){
    for (int j = 1; j <= n; j++)
        if (a[j][i] == '1') a[j][i] = '0';
        else a[j][i] = '1';
}

bool Equal(int i, int step){
    for (int k = 0; k <= step; k++)
        if (a[i][k] != b[i][k]) return false;

    return true;
}

void attempt(int step){
    if (step >= l){
        res = min(cnt, res);
        return ;
    }

    for (int i = 0; i <= 1; i++){
        if (i == 1){
            change(step);
            cnt++;
        }

        sort(a + 1, a + n + 1);

        for (int j = 1; j <= n; j++)
            if (!Equal(j, step)) goto exits;

        attempt(step + 1);

        exits:

        if (i == 1){
            change(step);
            cnt--;
        }
    }
}

int main(){
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    scanf("%d", &t);

    for (int tt = 1; tt <= t; tt++){
        res = 1000000;
        cnt = 0;

        scanf("%d %d", &n, &l);
        scanf("\n");

        for (int i = 1; i <= n; i++) cin >> a[i];
        scanf("\n");
        for (int i = 1; i <= n; i++) cin >> b[i];
        scanf("\n");

        sort(b + 1, b + n + 1);

        attempt(0);

        cout << "Case #" << tt << ": ";
        if (res == 1000000) cout << "NOT POSSIBLE";
        else cout << res;

        cout << endl;
    }
    return 0;
}
