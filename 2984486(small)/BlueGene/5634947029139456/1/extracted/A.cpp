#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <ctime>
#include <iterator>
#include <utility>
#include <numeric>
#include <functional>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>

using namespace std;

int n, m;
vector<int> a, b, c;

int main()
{
    freopen("A-large.in.txt", "r", stdin);
    freopen("A-large.out.txt", "w", stdout);
    int TestCase;
    cin >> TestCase;
    for (int Test = 1; Test <= TestCase; ++Test)
    {
        cout << "Case #" << Test << ": ";
        cin >> n >> m;
        string s;
        a.clear();
        b.clear();
        for (int i = 0; i < n; ++i)
        {
            cin >> s;
            a.push_back(0);
            for (int j = 0; j < m; ++j, a[i] <<= 1)
                a[i] ^= (s[j] == '1' ? 1 : 0);
        }
        for (int i = 0; i < n; ++i)
        {
            cin >> s;
            b.push_back(0);
            for (int j = 0; j < m; ++j, b[i] <<= 1)
                b[i] ^= (s[j] == '1' ? 1 : 0);
        }
        sort(b.begin(), b.end());
        int Ans = 0x7FFFFFFF;
        for (int i = 0; i < n; ++i)
        {
            int opt = a[0] ^ b[i];
            int cnt = 0;
            for (int j = opt; j; j -= j & -j, ++cnt);
            if (cnt >= Ans)
                continue;
            c = a;
            for (int i = 0; i < n; ++i)
                c[i] ^= opt;
            sort(c.begin(), c.end());
            if (b == c)
                Ans = cnt;
        }
        if (Ans == 0x7FFFFFFF)
            cout << "NOT POSSIBLE" << endl;
        else
            cout << Ans << endl;
    }
    return 0;
}
