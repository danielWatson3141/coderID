#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n);i++)

const int INF = 1000000000;

int main()
{
    int TT; cin >> TT;
    forn(tt,TT)
    {
        int N,L; cin >> N >> L;
        vector<string> a(N), b(N);
        forn(i,N)cin >> a[i];
        forn(i,N)cin >> b[i];
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int res = INF;
        forn(pri, N)
        {
            vector<int> val(L);
            int c = 0;
            forn(i,L)
            {
                val[i] = a[pri][i] != b[0][i];
                c += val[i];
            }
            vector<string> sa = a;
            forn(i,N)
            forn(j,L)
            if (val[j])
                sa[i][j] = '0' + (!(sa[i][j] - '0'));
            sort(sa.begin(), sa.end());
            
            if (sa == b && c < res) res = c;
        }
        cout << "Case #" << tt+1 << ": ";
        if (res == INF)
            cout << "NOT POSSIBLE";
        else
            cout << res;
        cout << endl;
    }
    return 0;
}
