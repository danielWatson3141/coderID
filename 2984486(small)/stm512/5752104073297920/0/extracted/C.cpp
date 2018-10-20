#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>

using namespace std;

int T, N;
int a[1010];

int main()
{
    //freopen("C-small-attempt0.in", "r", stdin);
    //freopen("C-small-attempt1.in", "r", stdin);
    freopen("C-small-attempt3.in", "r", stdin);
    freopen("C-small.out", "w", stdout);
    
    //freopen("C-large.in", "r", stdin);
    //freopen("C-large.out", "w", stdout);
    
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        printf("Case #%d: ", t);
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
            scanf("%d", &a[i]);
        bool found = false;
        int cnt = 0;
        for (int i = 0; i < N; i++)
            if (a[i] == i) {
                cnt++;
            }
       // if (a[0] == 0 || a[N - 1] == (N - 1))
         //   found = true;
        if (cnt > 1)
            found = true;
        if (found) printf("BAD\n");
        else
            printf("GOOD\n");
                
    }
    return 0;
}