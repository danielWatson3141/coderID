#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>
//#define NDEBUG
#include <cassert>
using namespace std;
#define memsetz(NAME) memset(NAME, 0, sizeof(NAME))
typedef long long i64;

i64 mx[150], my[150], mz[150];
void main2()
{
    for (int i = 0; i < 150; i++) {
        mx[i] = 0;
        my[i] = 0;
    }
    int N, L;
    string str;
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        cin >> str;
        for (int j = 0; j < L; j++) {
            mx[i] <<= 1;
            mx[i] += str[j] - '0';
        }
    }
    for (int i = 0; i < N; i++) {
        cin >> str;
        for (int j = 0; j < L; j++) {
            my[i] <<= 1;
            my[i] += str[j] - '0';
        }
    }
    sort(my, my + N);
    int minnum = 200;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int num = 0;
            i64 temp = mx[i] ^ my[j];
            while (temp) {
                if (temp & 1) {
                    num++;
                }
                temp >>= 1;
            }
            temp = mx[i] ^ my[j];
            if (num < minnum) {
                for (int k = 0; k < N; k++) {
                    mz[k] = mx[k] ^ temp;
                }
                sort(mz, mz + N);
                bool pos = true;
                for (int k = 0; k < N; k++) {
                    if (my[k] != mz[k]) {
                        pos = false;
                        break;
                    }
                }
                if (pos) {
                    minnum = num;
                }
            }
        }
    }
    if (minnum == 200) {
        cout << "NOT POSSIBLE" << endl;
    } else {
        cout << minnum << endl;
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        printf("Case #%d: ", t);
        main2();
    }
    return 0;
}
