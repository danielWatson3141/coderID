#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 155;
const int L = 45;
string a[N];
string b[N];
string c[N];
char t[N][L];
int w[L];
int n,l;
void getnum(int x) {
    memset(w, 0, sizeof(w));
    int cnt = 0;
    while (x) {
        w[cnt++] = x % 2;
        x = x>>1;
    }
}

bool check(string * x, string * y) {
    int i;
    for (i = 0; i < n; i++)
        if (x[i] != y[i])break;
    if (i < n)return false;
    else return true;
}

void out(string * tmp) {
    for (int i = 0; i < n; i++)
        cout<<tmp[i]<<endl;
}
int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int T;
    int cas = 1;
    scanf("%d",&T);
    while (T--) {
        scanf("%d %d",&n,&l);
        for (int i = 0; i < n; i++)
            cin>>a[i];
        for (int i = 0; i < n; i++)
            cin>>b[i];
        sort(b,b+n);
        int m = pow(2, l);
        int mini = l + 1;
        for (int i = 0; i < m; i++) {
            getnum(i);
            for (int j = 0; j < l; j++) {
                if (w[j] == 0) {
                    for (int k = 0; k < n; k++)
                    {
                        t[k][j] = a[k][j];
                    }
                } else {
                    for (int k = 0; k < n; k++)
                        if (a[k][j] == '0')
                            t[k][j] = '1';
                        else
                            t[k][j] = '0';
                }
            }
            for (int k = 0; k < n; k++) {
                t[k][l] = 0;
                c[k] = t[k];
            }
            sort(c,c+n);
            if(check(b,c)) {
                int cnt = 0;
                for (int j = 0; j < l; j++)
                    cnt += w[j];
                if (cnt < mini)mini = cnt;
            }
        }
        cout<<"Case #"<<cas<<": ";
        if (mini != l + 1)
            cout<<mini<<endl;
        else
            cout<<"NOT POSSIBLE\n";
        cas++;
    }
    return 0;
}
