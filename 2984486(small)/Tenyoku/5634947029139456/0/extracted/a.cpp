#include <cstdio>
#include <algorithm>
using namespace std;

int n, l;
char input[41];
long long int a[150], b[150];

int main()
{
    int T;
    scanf("%d", &T);
    for(int cas=1; cas<=T; ++cas)
    {
        scanf("%d %d", &n, &l);
        for(int i=0; i<n; ++i)
        {
            scanf("%s", input);
            a[i] = 0;
            for(int j=0; j<l; ++j)
                a[i] = a[i]*2+input[j]-'0';
        }
        for(int i=0; i<n; ++i)
        {
            scanf("%s", input);
            b[i] = 0;
            for(int j=0; j<l; ++j)
                b[i] = b[i]*2+input[j]-'0';
        }
        int ans=100;
        sort(b, b+n);
        for(int i=0; i<n; ++i)
        {
            int ta[150];
            for(int j=0; j<n; ++j) ta[j] = a[j];
            int tmp = 0;
            for(int j=0; j<l; ++j)
                if((ta[0]&((long long)1<<j)) != ((long long)b[i]&(1<<j)))
                {
                    ++tmp;
                    for(int k=0; k<n; ++k)
                        ta[k] ^= ((long long)1<<j);
                }
            sort(ta, ta+n);
            bool flag = 1;
            for(int j=0; j<n&&flag; ++j)
                if(ta[j] != b[j]) flag = 0;
            if(flag) ans = min(ans, tmp);
        }
        printf("Case #%d: ", cas);
        if(ans == 100) puts("NOT POSSIBLE");
        else printf("%d\n", ans);
    }
    return 0;
}
