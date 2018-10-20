#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

#define MAXN (150+10)

int T;
int n, l;
string a[MAXN], b[MAXN], b1[MAXN];
int c[MAXN];
int ans;

void getc(string a, string b)
{
    for (int i = 0;i < l;++i)
        if (a[i] != b[i]) c[i] = 1;
        else c[i] = 0;
}

string change(string a)
{
    string b;

    b= a;
    for (int i = 0;i < l;++i)
    {
        if (c[i] == 1) b[i] = '1'+'0'-a[i];
        else b[i] = a[i];
      //  cout << 1 << b[i] << endl;
    }
   // cout << "a" << b << endl;
    return b;
}

void sort(string *a, int n)
{
    string k;

    for (int i = 0;i < n;++i)
        for (int j = i+1;j < n;++j)
        {

            if (a[i] > a[j])
            {
                k = a[i];
                a[i] = a[j];
                a[j] = k;
            }
        }
}


void doit()
{
    int k;
    bool flag;

    scanf("%d%d", &n, &l);
    for (int i = 0;i < n;++i)
        cin >> b[i];
    for (int i = 0;i < n;++i)
        cin >> a[i];

  //  cout << a[0] << endl;
    sort(a, n);

    //   printf("s");
    ans = l+1;
    for (int i = 0;i < n;++i)
    {
     //   printf("%d\n", i);
        getc(b[i], a[0]);
        k  = 0;
        for (int j = 0;j < l;++j)
            if (c[j] == 1) ++k;
       // printf("%d\n", k);
        if (k >= ans) continue;
        for (int j = 0;j < n;++j)
        {
            b1[j] = change(b[j]);
          //  cout << b1[j] << endl;
        }
        sort(b1, n);
        flag = true;
        for (int j = 0;j < n;++j)
            if (b1[j] != a[j])
            {
                flag = false;
                break;
            }
        if (flag) ans = k;
    }
    if (ans == l+1) printf("NOT POSSIBLE\n");
    else printf("%d\n", ans);
}

int main()
{
    freopen("A-small.in", "r", stdin);
    freopen("A.out","w", stdout);
    scanf("%d", &T);
    for (int q = 1;q <= T;++q)
    {
        printf("Case #%d: ", q);
        doit();
    }
    return 0;
}
