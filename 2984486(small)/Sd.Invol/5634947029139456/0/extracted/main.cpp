#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <cstring>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long LL;

#define N 1005

int n , L , ca;
LL a[N] , b[N] , c[N];
char s[N];
void work()
{
    printf("Case #%d: " , ++ ca);
    int i , j , k;
    scanf("%d%d",&n,&L);
    for (i = 0 ; i < n ; ++ i) {
        scanf("%s" , s) , a[i] = 0;
        for (j = 0 ; s[j] ; ++ j)
            a[i] <<= 1 , a[i] |= s[j] - '0';
    }
    for (i = 0 ; i < n ; ++ i) {
        scanf("%s" , s) , b[i] = 0;
        for (j = 0 ; s[j] ; ++ j)
            b[i] <<= 1 , b[i] |= s[j] - '0';
    }
    sort(b , b + n);
    int ans = 1 << 30;
    for (i = 0 ; i < n ; ++ i) {
        for (j = 0 ; j < n ; ++ j) {
            int x = a[i] ^ b[j];
            for (k = 0 ; k < n ; ++ k)
                c[k] = a[k] ^ x;
            sort(c , c + n);
            for (k = 0 ; k < n ; ++ k)
                if (c[k] != b[k])
                    break;
            if (k >= n)
                ans = min(ans , __builtin_popcount(x));
        }
    }
    if (ans == 1 << 30)
        puts("NOT POSSIBLE");
    else
        printf("%d\n" , ans);
}

int main()
{
    freopen("1.txt" , "r" , stdin);
    freopen("2.txt" , "w" , stdout);

    int _ ; scanf("%d",&_); while (_ --)
        work();
    return 0;
}
