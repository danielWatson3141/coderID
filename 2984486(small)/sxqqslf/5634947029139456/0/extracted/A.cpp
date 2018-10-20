#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;
ifstream fin("1.in");
ofstream fout("1.out");

int n, l, T, ans;
string a[200], b[200];

void dfs(int x, int step)
{
    if (x == l) {
        bool flag = 1;
        bool use[20] = {0};
        for (int i=0; i<n; i++)
        {
            bool ok = 0;
            for (int j=0; j<n; j++)
                if (!use[j] && a[i] == b[j]) { use[j] = 1; ok = 1; break; }
            if (!ok) { flag = 0; break; }
        }
        if (flag) ans = min(ans, step);
        return ;
    }
    dfs(x+1, step);
    for (int i=0; i<n; i++) a[i][x] = (a[i][x]=='0')?'1':'0';
    dfs(x+1, step+1);
    for (int i=0; i<n; i++) a[i][x] = (a[i][x]=='0')?'1':'0';
}

void solve()
{
    fin >> T;
    for (int t=1; t<=T; t++) {
        fin >> n >> l;
        for (int i=0; i<n; i++) fin >> a[i];
        for (int i=0; i<n; i++) fin >> b[i];
        ans = 20;
        dfs(0, 0);
        fout << "Case #" << t << ": ";
        if (ans == 20) fout << "NOT POSSIBLE\n";
        else fout << ans << endl;
    }
}

int main()
{
    solve(); return 0;
}
