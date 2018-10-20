#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

inline unsigned to_num(const std::string& s)
{
    unsigned r = 0;
    unsigned t = 1;
    for (char c: s)
    {
        if (c == '1') r |= t;
        t <<= 1;
    }
    return r;
}

inline int count_bits(unsigned value)
{
    unsigned r = 0;
    while (value > 0)
    {
        r += value & 1;
        value >>= 1;
    }
    return r;
}

int main()
{
    int t;
    cin >> t;
    for (int qq = 1; qq <= t; ++qq)
    {
        int n, l;
        cin >> n >> l;

        vector<unsigned> a(n), b(n);
        for (int i = 0; i < n; ++i)
        {
            string s;
            cin >> s;
            a[i] = to_num(s);
        }
        for (int i = 0; i < n; ++i)
        {
            string s;
            cin >> s;
            b[i] = to_num(s);
        }

        sort(b.begin(), b.end());

        vector<unsigned> t(n);
        int result = l + 1;
        for (int att = 0; att < (1u << l); ++att)
        {
            for (int i = 0; i < n; ++i)
                t[i] = a[i] ^ att;
            sort(t.begin(), t.end());

            if (b == t)
            {
                result = min(result, count_bits(att));
                if (result <= 1) break; // shortcut
            }
        }

        cout << "Case #" << qq << ": ";
        if (result <= l)
            cout << result << endl;
        else
            cout << "NOT POSSIBLE" << endl;
    }

    return 0;
}
