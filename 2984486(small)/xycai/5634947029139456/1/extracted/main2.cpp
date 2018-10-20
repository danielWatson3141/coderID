#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#define MAX_N 155

using namespace std;

string a[MAX_N];
string b[MAX_N];
string c[MAX_N];
int n,l;

char inv(char a)
{
    if (a=='0') return '1';
    return '0';
}

int main()
{
//    freopen("A-large.in", "r", stdin);
//    freopen("A-large.out", "w", stdout);
    int t;
    int cases=1;
    scanf("%d", &t);
    while(t--)
    {
        int ans = 45;
        scanf("%d%d",&n,&l);
        for (int i=0;i<n;++i)
        {
            cin>>a[i];
        }
        for(int i=0;i<n;++i)
        {
            cin>>b[i];
        }
        sort(a, a+n);
//        sort(b, b+n);
//        for (int i=0;i<n;++i) printf("a %s ", a[i].c_str()); puts("");
//        for (int i=0;i<n;++i) printf("%s ", b[i].c_str()); puts("");
        for (int i=0;i<n;++i)
        {
            for (int j=0;j<n;++j)
            {
                bool tem[45];
                int tcnt = 0;
                memset(tem, 0, sizeof(tem));
                for (int k=0;k<l;++k)
                {
                    if (a[i][k]!=b[j][k])
                    {
                        tem[k] = true;
                        tcnt ++;
                    }
                }
                for (int jj=0;jj<n;++jj)
                {
                    c[jj] = b[jj];
                    for (int k=0;k<l;++k)
                    {
                        if (tem[k])
                        {
                            c[jj][k] = inv(b[jj][k]);
                        }
                    }
                }
                sort(c, c+n);
                bool flag = true;
                for (int jj=0;jj<n;++jj)
                {
                    if (a[jj] != c[jj]) flag = false;
                }
                if (flag)
                {
                    ans = ans<tcnt?ans:tcnt;
                }
            }
        }
        printf("Case #%d: ",cases++);
        if (ans == 45) puts("NOT POSSIBLE");
        else printf("%d\n", ans);
    }
    return 0;
}
