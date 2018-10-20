#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <ctime>
using namespace std;
const int N = 5;
int num[150];
int f[11];
int n;
void init() {
    f[0] = 1;
    for (int i = 1; i <= n; i++)
        f[i] = f[i-1] * i;
    //for (int i = 1; i <= n; i++) cout << f[i] << " "; cout << endl;
}
int kt(int s[],int n)//n表示该排列有n个数
{
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        int temp = 0;
        for(int j = i + 1; j < n; j++)
          if(s[j] < s[i])
             temp ++;
        sum += f[n - 1 - i] * temp;//f[n]表示n的阶乘
    }
    return sum + 1;
}
int a[6];
void solve(int n) {
    for (int i = 0; i < n; i++) {
        a[i] = i;
    }
  //  cout << " ** " << kt(a, n) << endl;
    for (int i = 0; i < n; i++) {
        int p = rand() % n;
        swap(a[i],a[p]);
    }
    num[kt(a, n)]++;
}
int b[1000+10];
int main() {


    srand(time(NULL));
    n = N;
    init();
    //for (int i = n; i >= 1; i--) a[n-i] = i-1;
    //cout << " /// " << kt(a,n) << endl;
    memset(num, 0, sizeof(num));
    for (int i = 0; i < 12000000; i++) {
        solve(n);
    }
   // for (int i = 1; i <= 6; i++) cout << num[i] << " "; cout << endl;
    freopen("C-small-attempt6.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T, cas = 0;

    scanf("%d",&T);
    int m;
    scanf("%d",&m);
    while (T--) {


        for (int i = 0; i < m; i++) scanf("%d",b+i);
        int tmp = kt(b, n);
        int fg;
        if (abs(num[tmp] - 100000) <= 30000 ) {
            fg = 1;
        }else fg = 0;
       // fg = rand() % 2;
        printf("Case #%d: ",++cas);
        printf("%s\n",fg ? "GOOD" : "BAD");
    }
    return 0;
}
