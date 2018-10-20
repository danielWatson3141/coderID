#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#include <vector>
#include <utility>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;

template<typename T>inline string to_str(const T& v) {
    ostringstream os; os << v; return os.str();
}
template<typename T>inline T to_obj(const string& v) {
    istringstream is(v); T r; is>>r; return r;
}
template<class T>inline int cMin(T& a, T b) {return b<a ? a=b,1 : 0;}
template<class T>inline int cMax(T& a, T b) {return a<b ? a=b,1 : 0;}

#define CLR(A,v) memset(A, v, sizeof(A))
#define MP(a,b)  make_pair(a, b)
#define F0(i, n) for(int i=0; i<(n); ++i)
#define F1(i, n) for(int i=1; i<=(n); ++i)

typedef uint64_t u64;

int N, L;
u64  src[256], dst[256], G[256];

int needFlip(int idx) {
    u64 mask = idx ? ~((u64(1)<<idx) - 1) : ~u64(0);
    F0(i, N)
        if ((src[i] & mask) != (dst[i] & mask))
            return true;
    return false;
}

int check(int idx) {
    u64 mask = idx ? ~((u64(1)<<idx) - 1) : ~u64(0);
    F0(i, N)
        if ((src[i] & mask) != (dst[i] & mask))
            return true;
    return false;
}

int calc() {
    sort(src, src+N);
    sort(dst, dst+N);
    int bitEnd = 1<<L;
    int ans = 1<<20;
    for(int bit=0; bit<bitEnd; ++bit) {
        F0(i, N) G[i] = src[i];
        int cur = 0;
        F0(i, L) {
            if (bit & (1<<i)) {
                ++cur;
                int  c = 1<<i;
                F0(j, N) G[j] ^= c;
            }
        }
        sort(G, G+N);
        bool OK = true;
        F0(i, N) if (G[i] != dst[i]) {OK = false; break;}
        if (OK) {
            ans = min(cur, ans);
        }
    }
    return ans > L ? -1 : ans;
    // int ret = 0;
    // for(int i=L-1; i>=0; --i) {
    //     if (needFlip(i))
    //         ret++;
    //     u64 bit = u64(1) << i;
    //     F0(j, N) src[i] ^= bit;
    //     sort(src, src+N);
    //     if (!check(i))
    //         return -1;
    // }
    // return ret;
}

u64 get() {
    char buf[64];
    scanf("%s", buf);
    u64  ret = 0;
    F0(i, L) {
        ret = (ret << 1) | (buf[i] - '0');
    }
    return ret;
}

int main(int argc, char *argv[]) {
    int T;
    scanf("%d", &T);
    F1(iT, T) {
        scanf("%d%d", &N, &L);
        F0(i, N) src[i] = get();
        F0(i, N) dst[i] = get();
        int ans = calc();
        printf("Case #%d: ", iT);
        if (ans < 0)
            printf("%s\n", "NOT POSSIBLE");
        else printf("%d\n", ans);
    }
    return 0;
}
