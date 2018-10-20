#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int a[1004];
int N;

int main(){
    freopen("C-small-attempt1.in","r",stdin);
    freopen("C.out","w",stdout);
    int T;
    cin >> T;
    for (int o = 1; o <= T; o++){
        cin >> N;
        int sum = 0;
        for (int i = 1; i <= N; i++){
            scanf("%d", a + i);
            if (i <= 500) sum += a[i];
        }
        double d = (sum / 250250.0);
        if (d >= 0.975 && d <= 1.025)
            printf("Case #%d: GOOD\n", o);
        else
            printf("Case #%d: BAD\n", o);
    }
}
