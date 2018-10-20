#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

uint64_t string_to_uint64(string s)
{
    uint64_t bit = 1;
    uint64_t result = 0;
    for (int i = int(s.size())-1; i >= 0; i--)
    {
        if (s[i] == '1')
        {
            result += bit;
        }
        bit <<= 1;
    }
    return result;
}

int count_set_bits(uint64_t n)
{
    int count = 0;
    while (n)
    {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

void solve()
{
    int N, L;
    cin >> N >> L;
    uint64_t outlets[150];
    for (int i = 0; i < N; i++)
    {
        string outlet;
        cin >> outlet;
        outlets[i] = string_to_uint64(outlet);
    }
    uint64_t devices[150];
    for (int i = 0; i < N; i++)
    {
        string device;
        cin >> device;
        devices[i] = string_to_uint64(device);
    }

    uint64_t mat[150][150];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            mat[i][j] = outlets[i] ^ devices[j];
        }
    }

    uint64_t result_set[150];
    int result_count = 0;
    uint64_t temp[150];
    for (int i = 0; i < N; i++)
    {
        sort(mat[i], mat[i]+N);
        if (i == 0)
        {
            copy(mat[i], mat[i]+N, result_set);
            result_count = N;
        }
        else
        {
            auto it = set_intersection(result_set, result_set+result_count,
                                       mat[i], mat[i]+N,
                                       temp);
            result_count = it - temp;
            copy(temp, temp+result_count, result_set);
        }
    }
    if (!result_count)
    {
        cout << "NOT POSSIBLE" << endl;
        return;
    }
    cout << count_set_bits(result_set[0]) << endl;
}

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}

