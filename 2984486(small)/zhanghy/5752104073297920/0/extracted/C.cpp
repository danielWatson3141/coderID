#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <time.h>

using namespace std;

const int maxn = 2000;

int T,N,a[maxn];
int main() {
    srand(time(0));
    freopen("C1.in","r",stdin);
    freopen("C1.out","w",stdout);
    scanf("%d",&T);
    for (int kase = 1;kase <= T; kase++) {
        scanf("%d",&N);
        bool flag = true;
        for (int i = 0;i < N; i++) {
            scanf("%d",&a[i]);
            if (a[i] != i) flag = false;
        }
        printf("Case #%d: ",kase);
        if (flag) printf("BAD\n");
        else {
                int k = rand()%3;
                if (k)
                printf("GOOD\n");
                else printf("BAD\n");
        }
    }
    return 0;
}
