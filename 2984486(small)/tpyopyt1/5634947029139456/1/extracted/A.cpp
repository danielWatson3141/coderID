#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string a[3][200];
int b[100];

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("A.out", "w", stdout);
    
    int ts, ks, i, j, k, ans, cnt, n, l;
    cin >> ts;
    for (ks = 0; ks < ts; ks++){
        cin >> n >> l;
        for (j = 0; j < 2; j++)
            for (i = 0; i < n; i++)
                cin >> a[j][i];
        sort(a[1], a[1] + n);
        ans = l + 1;
      //  for (i = 0; i < l; i++) b[i] = 0;
      
        for (i = 0; i < n; i++){
            for (j = 0; j < n; j++)
                a[2][j] = a[0][j];
            cnt = 0;
            for (j = 0; j < l; j++)
                if (a[2][0][j] != a[1][i][j]){
              //    b[i] = b[i] ^ 1;
                   cnt++;
                   for (k = 0; k < n; k++){
                       if (a[2][k][j] == '0')
                          a[2][k][j] = '1';
                       else a[2][k][j] = '0';
                   }
                }
            sort(a[2], a[2] + n);
            for (j = 0; j < n; j++)
                if (a[2][j] != a[1][j]) break;
            if (j >= n)
               if (cnt < ans) ans = cnt;
        }
        if (ans <= l)
           printf("Case #%d: %d\n", ks + 1, ans);
        else printf("Case #%d: NOT POSSIBLE\n", ks + 1);
    }
    return 0;
}
