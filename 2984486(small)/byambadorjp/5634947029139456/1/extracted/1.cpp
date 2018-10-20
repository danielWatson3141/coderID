#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

int n,l,ans;
char s[155];
int a[155];
int b[155];
int c[30000];
map<long long, int> mp;

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int t = 1; t <= T; t++){
        scanf("%d%d",&n,&l);
        ans = -1;
        mp.clear();
        int val = 1;
        printf("Case #%d: ",t);

        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));
        for(int i = 0; i < n; i++){
            scanf("%s",s);
            for(int j = 0; j < l; j++)
                if(s[j] == '1')
                    a[i] += (1 << j);
        }

        for(int i = 0; i < n; i++){
            scanf("%s",s);
            for(int j = 0; j < l; j++)
                if(s[j] == '1')
                    b[i] += (1 << j);
        }

        bool flag = false;
        for(int j = 0; j < n; j++)
            for(int i = j + 1; i < n; i++)
                if(b[j] == b[i])
                    flag = true;
        if(flag) {printf("NOT POSSIBLE\n"); continue;}

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++){
                int dx = a[i] ^ b[j];
                if(mp.find(dx) == mp.end()) {
                    mp[dx] = val;
                    val++;
                }
                c[mp[dx]]++;
                if(c[mp[dx]] == n){
                    int cnt = 0;
                    for(int k = 0; k < l; k++)
                        if(dx & (1 << k))
                            cnt++;
                    if(ans == -1 || cnt < ans)
                        ans = cnt;
                }
            }
        if(ans == -1)
            printf("NOT POSSIBLE\n");
        else
            printf("%d\n",ans);
    }




    return 0;
}
