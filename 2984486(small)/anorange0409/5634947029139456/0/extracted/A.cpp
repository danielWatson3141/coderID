#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

string a[200],b[200],c[200],d[200];
int N, L;

string xxx(string p, string q){
    string tmp = p;
    for (int i = 0; i < L; i++)
        if (p[i] == q[i])
            tmp[i] = '0';
        else tmp[i] = '1';
    return tmp;
}
int count(string x){
    int sum = 0;
    for (int i = 0; i < L; i++)
        if (x[i] == '1') sum++;
    return sum;
}

bool ok(string x){
    for (int i = 0; i < N; i++){
        c[i] = xxx(a[i], x);
        d[i] = b[i];
    }
    sort(c , c + N);
    sort(d, d + N);
    for (int i = 0; i < N; i++)
        if (c[i] != d[i]) return false;
    return true;
}

int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small.out","w",stdout);
    int T;
    cin >> T;
    for (int o = 1; o <= T; o++){
        cin >> N >> L;
        for (int i = 0; i < N; i++){
            cin >> a[i];
           // cout <<a[i]<< endl;
        }
        for (int i = 0; i < N; i++)
            cin >> b[i];

        int ans = 1000000;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++){
                string x = xxx(a[i], b[j]);
                if (ok(x))
                    ans = min(ans, count(x));
            }
        printf("Case #%d: ", o);
        if (ans == 1000000)
            printf("NOT POSSIBLE\n");
        else
            cout << ans << endl;

    }
}
