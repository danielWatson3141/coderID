#include <cstdio>
#include <iostream>
#include <iomanip>
#include <bitset>
#include <map>
#include <climits>

using namespace std;
const int MAXN = 151;
const int MAXL = 41;

int n, l;
typedef unsigned long long ull;
ull a[MAXN], b[MAXN];
ull read_binary()
{
    string s;
    cin >> s;
    bitset<MAXL> bs(s);
    return bs.to_ullong();
}

ull count_bits(ull x)
{
    bitset<MAXL> bs(x);
    return bs.count();
}

void process(int case_num)
{
    cin >> n >> l;
    for (int i = 0 ; i < n ; ++i)
        a[i] = read_binary();
    for (int i = 0 ; i < n ; ++i)
        b[i] = read_binary();
    ull ans = ULLONG_MAX;
    for (int i = 0 ; i < n ; ++i)
    {
        map<ull , ull> counts;
        for (int j = 0 ; j < n ; ++j)
                ++counts[b[j]];
        --counts[b[i]];
        ull mask = a[0] ^ b[i];
        bool flag = true;
        for (int j = 1 ; j < n ; ++j)
        {
            ull target = a[j] ^ mask;
            if (counts[target])
                --counts[target]; // consume one
            else
                flag = false;
        }
        if (flag)
        {
            ull bitcnt = count_bits(mask);
            if (ans > bitcnt)
                ans = bitcnt;
        }
    }
    cout << "Case #" << case_num << ": ";
    if (ans != ULLONG_MAX)
        cout << ans << endl;
    else
        cout << "NOT POSSIBLE" << endl;
}
int main()
{
    int t;
    cin >> t;
    for (int case_num = 1 ; case_num <= t ; ++case_num)
        process(case_num);
    return 0;
}
