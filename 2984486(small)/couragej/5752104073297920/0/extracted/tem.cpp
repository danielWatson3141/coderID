#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <math.h>
#include <time.h>
using namespace std;
typedef long long LL;
const int N = 1005;
const int M = 1005;
const int INF = 0x3f3f3f3f;
int n;
int a[N], b[N];

int num1, num2;

void work1() {
    for (int k = 0; k < n; k++) {
        a[k] = k;
    }

    for (int k = 0; k < n; k++) {
        int p = rand()%n;
        while(p < k) {
            p = rand()%n;
        }
        swap(a[k], a[p]);
    }
    bool flag = 1;
    for (int k = 0; k < n; k++) {
        //printf("%d ", a[k]);
        if(a[k] != b[k]) {
            flag = 0;
            break;
        }
    }
    if (flag) {
        num1++;
    }
    //puts("");
}

void work2() {
    for (int k = 0; k < n; k++) {
        a[k] = k;
    }
    //srand( (unsigned)time( NULL ) );
    for (int k = 0; k < n; k++) {
        int p = rand()%n;
        swap(a[k], a[p]);
    }
    bool flag = 1;
    for (int k = 0; k < n; k++) {
        //printf("%d ", a[k]);
        if(a[k] != b[k]) {
            flag = 0;
            break;
        }
    }
    if(flag) {
        num2++;
    }
//    puts("");
}

int main () {
    //freopen("3.in", "r", stdin);
    //freopen("3.out", "w", stdout);
    int cases;
    scanf ("%d", &cases);
    for (int cas = 1; cas <= cases; cas++) {
        scanf ("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf ("%d", &b[i]);
        }
        srand( (unsigned)time( NULL ) );
        num1 = 0, num2 = 0;
        for(int i = 0; i < n+1; i++) {
            work1();
        }
        //puts("");
        for(int i = 0; i < n+1; i++) {
            work2();
        }
        printf("Case #%d: ", cas);
        if(num1 > num2) {
            puts("GOOD");
        }
        else {
            puts("BAD");
        }
    }






    return 0;
}
