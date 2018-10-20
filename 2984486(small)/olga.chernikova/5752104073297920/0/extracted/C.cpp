#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int maxn = 100;

void Print() {
    int a[maxn];
    int cnt = 0;
    for (int i = 0; i < maxn; ++i) {
        a[i] = i;
    }
    for (int i = 0; i < maxn; ++i) {
        int u = rand()%maxn;
        swap(a[i], a[u]);
    }
    for(int i = 0; i < maxn; ++i) {
        if (a[i] < 2 && i > maxn/2) ++cnt;
    }
    cout << cnt << endl;
}

void Print1() {
    int a[maxn];
    int cnt = 0;
    for (int i = 0; i < maxn; ++i) {
        a[i] = i;
    }
    for (int i = 0; i < maxn; ++i) {
        int u = i + rand()%(maxn - i);
        swap(a[i], a[u]);
    }
    for(int i = 0; i < maxn; ++i) {
        if (a[i] < 2 && i > maxn/2) ++cnt;
    }
    cout << cnt << endl;
}

int main() {
    /*for (int i = 0; i < 10; ++i) {
        Print1();
    }
    cout << "----------" << endl;
    for (int i = 0; i < 10; ++i) {
        Print();
    } */
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int N;
        cin >> N;
        int fl = 0;
        for (int i = 0; i < N; ++i) {
            int x;
            cin >> x;
            if ((x == 0 || x == 1) && i > N / 2)  fl += 1;
        } 
        if (fl == 2 || (fl == 1 && rand()%2)) {
            printf("Case #%d: BAD\n", test);
        } else {
            printf("Case #%d: GOOD\n", test);
        }
    }
}