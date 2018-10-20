#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <iostream>
#include <sstream>
using namespace std;

const int maxn = 200;

int t, n, l;
char  A[maxn][maxn], B[maxn][maxn] ;
int  AA[maxn],BB[maxn];
bool f[maxn];

int main() {
    //freopen("A-large.in", "r", stdin);
    //freopen("A-large.out", "w", stdout);
	scanf("%d", &t);
	for(int cas = 1; cas <= t; cas++){
        scanf("%d%d", &n, &l);
        for(int i = 0; i < n; i++){
            scanf("%s", &A[i]);
        }
        //for(int i = 0; i < n; i++) for(int j = 0; j < l ; j++) printf("%c ", A[i][j]+'0');
        memset(AA, 0, sizeof(AA));
        for(int i = 0; i < n; i ++){
                for(int j = 0; j < l; j ++){
                    AA[i] <<= 1;
                    AA[i] |= (int)(A[i][j]-'0');
                }
            }

        int ans = 0x7fffffff;
        sort(AA, AA+n);
        for(int i = 0; i < n; i++){
            scanf("%s", &B[i]);
        }
        for(int i = 0; i < n; i ++){
            memset(f, 0, sizeof(f));
            memset(BB, 0 , sizeof(BB));
            int cnt = 0;
            for(int j = 0; j < l ;j++){
                if(A[i][j] != B[0][j]){
                    f[j] = 1;
                    cnt++;
                }
            }
            //cout << cnt ;
            if(cnt >= ans) continue;
            for(int i = 0; i < n; i ++){
                for(int j = 0; j < l; j ++){
                    BB[i] <<= 1;
                    int tt = (int)(B[i][j]-'0');
                    if(f[j] == 0) BB[i] |= (int)(B[i][j] - '0');
                    else BB[i] |= (1-(int)(B[i][j] - '0'));
                }
            }
            sort(BB, BB+n);
           // cout << "B" ;for(int i = 0; i < n; i++) cout << BB[i] << " "; cout << endl;
           // cout << "A" ;for(int i = 0; i < n; i++) cout << AA[i] << " "; cout << endl;
            bool ok  = 1;
            for(int i = 0; i < n; i ++){
                if(BB[i] != AA[i]){
                    ok = 0;
                    break;
                }
            }
            if(ok) ans = cnt;
        }
        if(ans != 0x7fffffff) printf("Case #%d: %d\n", cas, ans);
        else printf("Case #%d: NOT POSSIBLE\n", cas);
	}
	return 0;
}
