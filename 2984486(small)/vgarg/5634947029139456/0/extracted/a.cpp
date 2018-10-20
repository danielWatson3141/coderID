#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

vector<int> m(1024);

int cnt(int a)
{
    int c = 0;
    while (a){
        if (a&1)c++;
        a>>=1;
    }
    return c;
}

bool cmp(const int &a, const int &b)
{
    return cnt(a) < cnt(b);
}

void genmask(int l)
{
    int e = 1<<l, i;
    for (i = 0; i < e; i++){
        m[i] = i;
    }
    sort(m.begin(), m.begin()+e, cmp);
}

int main()
{
    freopen("A-small-attempt1.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int t, T, n, l;
    string s;
    cin >> T;
    for (t = 1; t <= T; t++){
        cin >> n >> l;
        vector<string> a, b;
        for (int i = 0; i < n; i++){
            cin >> s;
            a.push_back(s);
        }
        for (int i = 0; i < n; i++){
            cin >> s;
            b.push_back(s);
        }
        genmask(l);
        /*for (int i = 0; i < (1<<l); i++){
            cerr << m[i] << endl;
        }*/
        int c = 0;
        bool yes=false;
        for (int i = 0; i < (1<<l); i++){
            for (int j = 0; j < l; j++){
                if (m[i]&(1<<j)){
                    for (int k = 0; k < n; k++){
                        a[k][j] = (a[k][j] == '0' ? '1' : '0');
                    }
                }
            }/*
            for (int g =0;g<n;g++){
                cerr << i << ' ' << a[g] <<endl;
            }*/
            //cmp
            int found = 0;
            vector<bool> used(n, false);
            for (int j = 0; j < n; j++){
                for (int k = 0; k < n; k++){
                    if (!used[k] && a[j] == b[k]){
                        used[k] = true;
                        found++;
                    }
                }
            }
            if (found == n){
                c = i;
                yes=true;
                break;
            }
            for (int j = 0; j < l; j++){
                if (m[i]&(1<<j)){
                    for (int k = 0; k < n; k++){
                        a[k][j] = (a[k][j] == '0' ? '1' : '0');
                    }
                }
            }
        }
        if (yes){
            cout << "Case #" << t << ": " << cnt(m[c]) << '\n';
        }else{
            cout << "Case #" << t << ": NOT POSSIBLE\n";
        }
    }
}
