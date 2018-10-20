#include <cstdio>
#include <algorithm>

#define FO(i,a,b) for (int i = (a); i < (b); i++)

using namespace std;

#define N 1000

int n;

int main() {
    n = N;

    int T;
    scanf("%d", &T);
    FO(Z,1,T+1) {
        printf("Case #%d: ", Z);
        scanf("%d", &n);
        int P[N];
        FO(i,0,n) scanf("%d", &P[i]);

        int c = 0;
        FO(i,0,n) c += P[i] == i;

        if (c >= 1) printf("BAD\n");
        else printf("GOOD\n");
    }

    return 0;
}

