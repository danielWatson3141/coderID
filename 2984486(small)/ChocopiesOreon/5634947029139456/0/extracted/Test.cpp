#include <bits/stdc++.h>

using namespace std;

#define MAX 100005;
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define PI 3.14159265359
#define pb push_back
#define ppb pop_back()
#define sz size()
#define fi first
#define se second
#define all(c) (c).begin(), (c).end()

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<string> vs;
typedef pair<int,int> pii;

int t, n, l;
int vitri[11];
int ret = INF;
string a[11], b[11];
string a1[11], b1[11];

void tinh(string s1, string s2)
{
    int len = s1.sz;
    for(int i = 0 ; i < len ; i++)
        if(s1[i] != s2[i])
            vitri[i] = 1;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.ou", "w", stdout);
    cin >> t;
    for(int test = 1 ; test <= t ; test++)
    {
        ret = INF;

        cin >> n >> l;
        string tmp;

        for(int i = 0 ; i < n ; i++) { cin >> tmp; a[i] = tmp; }
        for(int i = 0 ; i < n ; i++) { cin >> tmp; b[i] = tmp; }

        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                memset(vitri, 0, sizeof(vitri));

                tinh(a[i], b[j]);

                for(int kk = 0 ; kk < n ; kk++) a1[kk] = a[kk];   // copy
                for(int kk = 0 ; kk < n ; kk++) b1[kk] = b[kk];   // copy

                //for(int kk = 0 ; kk < n ; kk++) cout << a[kk] << " "; cout << endl;
                //for(int kk = 0 ; kk < n ; kk++) cout << a1[kk] << " "; cout << endl;

                for(int kk = 0 ; kk < n ; kk++)
                {
                    for(int ll = 0 ; ll < l ; ll++)
                    {
                        if(vitri[ll]) a1[kk][ll] = (a1[kk][ll] == '1' ? '0' : '1'); // flip
                    }
                }


                sort(a1, a1 + n);
                sort(b1, b1 + n);

                bool ok = true;
                for(int ii = 0 ; ii < n ; ii++) if(a1[ii] != b1[ii]) ok = false;

                if(ok)
                {
                    int cnt = 0;

                    for(int kkk = 0 ; kkk < l ; kkk++) if(vitri[kkk]) cnt++;

                    ret = min(ret, cnt);
                }
            }
        }
        cout << "Case #" << test << ": ";

        if(ret == INF) cout << "NOT POSSIBLE" << endl;
        else cout << ret << endl;
    }
    return 0;
}
