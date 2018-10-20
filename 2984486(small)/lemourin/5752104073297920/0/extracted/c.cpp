#include <cstdio>
#include <algorithm>
#include <random>
#define scanf(args...) (scanf(args) ? : 0)
const int MAXN = 1005;

int n;
int T[MAXN];
std::random_device device;
std::mt19937 twister(device());

int random(int a, int b) {
    std::uniform_int_distribution<int> dist(a, b);
    return dist(twister);//rand()%(b-a+1)+a;
}

int bad(int* T, int n) {
    for (int i=0; i<n; i++)
        T[i] = i;
    for (int i=0; i<n; i++) {
        int p = random(0, n);
        std::swap(T[i], T[p]);
    }
}

int good(int* T, int n) {
    for (int i=0; i<n; i++)
        T[i] = i;
    for (int i=0; i<n; i++) {
        int p = random(i, n);
        std::swap(T[i], T[p]);
    }
}

int inverseCount(int* T, int n) {
    int res = 0;
    for (int i=0; i<n; i++)
        for (int j=0; j+1<n; j++) {
            if (T[j] > T[j+1]) {
                std::swap(T[j], T[j+1]);
                res++;
            }
        }
    return res;
}

int main() {
    int invbad = 0, invgood = 0;
    for (int i=0; i<100; i++) {
        bad(T, 1000);
        int c1 = inverseCount(T, 1000);
        invgood += c1;
        //printf("bad: %d\n", c1);
        good(T, 1000);
        int c2 = inverseCount(T, 1000);
        invbad += c2;
        //printf("good: %d\n", c2);
    }
    int avgbad = invbad/100, avggood = invgood/100;
    //printf("avg bad: %d, good: %d\n", invgood/100, invbad/100);

    int t;
    scanf("%d", &t);

    for (int test=1; test<=t; test++) {
        int n;
        scanf("%d", &n);
        for (int i=0; i<n; i++)
            scanf("%d", &T[i]);
        int c = inverseCount(T, n);
        int d1 = std::abs(c-avgbad), d2 = std::abs(c-avggood);
        
        printf("Case #%d: ", test);
        if (d1 < d2)
            printf("BAD\n");
        else
            printf("GOOD\n");
    }
}
