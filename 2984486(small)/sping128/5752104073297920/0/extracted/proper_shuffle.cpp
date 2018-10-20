//
// proper_shuffle.cpp
//
// Siwakorn Srisakaokul - ping128
// Written on Friday, 25 April 2014.
//

#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <algorithm>
#include <map>
#include <ctype.h>
#include <string.h>

#include <assert.h>
#include <time.h>


using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<PII, int> PII2;

#define MAXN 1005

int in[MAXN];
int N;
int y[MAXN];

int random1(int x[], int n) {
    for (int i = 0; i < n; i++) {
        x[i] = i;
    }
    for (int i = 0; i < n; i++) {
        int p = rand() % n;
        swap(x[i], x[p]);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (i == x[i]) {
            cnt++;
        }
    }
    /*
    cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (x[i] > x[j])
                cnt++;
        }
    }
    */
    return cnt;
}


int random2(int x[], int n) {
    for (int i = 0; i < n; i++) {
        x[i] = i;
    }
    for (int i = 0; i < n; i++) {
        int p = (rand() % (n - i)) + i;
        swap(x[i], x[p]);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (i == x[i]) {
            cnt++;
        }
    }
    /*
    cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (x[i] > x[j])
                cnt++;
        }
    }
    */
    return cnt;
}


void solve() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &in[i]);
    }
    int a = 0;
    for (int i = 0; i < N; i++) {
        if (in[i] == i) {
            a++;
        }
    }

    if (a == 0) printf("GOOD\n");
    else printf("BAD\n");
}


int main() {
    /*
    int aaa = 0;
    int bbb = 0;
    srand (time(NULL));
    map<int, int> M;
    for (int i = 0; i < 1000; i++) {
        int x = random2(y, 1000);
        M[x]++;
    }

    for (int i = 0; i < 10; i++) cout << i << "---  " << M[i] << endl;
    */
    /*
    cout << "-----" << endl;
    for (int i = 0; i < 30; i++) 
        bbb += random2(y, 10);
    cout << aaa << "#" << bbb << endl;
    */
    int test;
    scanf("%d", &test);
    for (int i = 0; i < test; i++) {
        printf("Case #%d: ", i + 1);
        solve();
    }
    return 0;
}
