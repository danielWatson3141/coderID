#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <hash_map>
#include <string>
#include <map>
#include <set>
#include <queue>

#if 0
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
typedef int256_t lll;
typedef uint256_t ulll;
#endif

using namespace std;
using namespace std::tr1;
using namespace stdext;

typedef __int64 ll;
typedef unsigned __int64 ull;

int T, N, L;
int outlet[160];
int device[160];

int NumberOfSetBits(int i)
{
     i = i - ((i >> 1) & 0x55555555);
     i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
     return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

int main(int argc, char* argv[]) {
    cin >> T;
    for (int t = 0; t != T; ++t) {
        cout << "Case #" << (t + 1) << ": ";
        cin >> N >> L;
        for (int n = 0; n != N; ++n) {
            int val = 0;
            char ch;
            for (int l = 0; l != L; ++l) {
                cin >> ch;
                if (ch == '0') { val <<= 1; }
                else if (ch == '1') { val <<= 1; val = val | 1; }
                else {
                    throw int(0);
                }
            }
            outlet[n] = val;
        }
        for (int n = 0; n != N; ++n) {
            int val = 0;
            char ch;
            for (int l = 0; l != L; ++l) {
                cin >> ch;
                if (ch == '0') { val <<= 1; }
                else if (ch == '1') { val <<= 1; val = val | 1; }
                else {
                    throw int(0);
                }
            }
            device[n] = val;
        }
        sort(device, device + N);
        int outlet1[160];
        int min_count = 1024;
        for (int mask = 0; mask != 1024; ++mask) {
            int count = NumberOfSetBits(mask);
            if (count < min_count) {
                for (int n = 0; n != N; ++n) {
                    outlet1[n] = outlet[n] ^ mask;
                }
                sort(outlet1, outlet1 + N);
                bool ok = true;
                for (int n = 0; ok && n != N; ++n) {
                    ok = (outlet1[n] == device[n]);
                }
                if (ok) {
                    min_count = count;
                }
            }
        }
        if (min_count == 1024)
            cout << "NOT POSSIBLE\n"; 
        else
            cout << min_count << "\n"; 
    }
    return 0;
}
