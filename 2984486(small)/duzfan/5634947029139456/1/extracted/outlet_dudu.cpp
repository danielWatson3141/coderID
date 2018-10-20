#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

const int N = 155;

#define fo(i , st , en) for (int i = st; i <= en; i++)
#define Me(x , y) memset(x , y , sizeof(x))

ll a[N] , b[N] , at[N] , bt[N];
int n , m , t;

void Read(ll &x){
    char c;
    while (c = getchar() , c < '0' || c > '1');
    x = c - '0';
    while (c = getchar() , c >= '0' && c <= '1') x = x * 2 + c - '0';
}

void Init(){
    scanf("%d%d" , &n , &m);
    fo (i , 1 , n) Read(a[i]);
    fo (i , 1 , n) Read(b[i]);
}

void Work(){
    int ans = m + 1;
    fo (i , 1 , n){
        ll temp = a[1] ^ b[i]; int tot = 0;
        fo (j , 1 , n)
            if (j != i) bt[++tot] = b[j];
        fo (j , 1 , n) at[j - 1] = a[j] ^ temp;
        sort(bt + 1 , bt + tot + 1);
        sort(at + 1 , at + tot + 1);
        bool flag = 0;
        fo (j , 1 , tot)
            if (at[j] != bt[j]) flag = 1;
        if (!flag){
            int cur = 0;
            fo (j , 0 , m - 1)
                if (1LL << j & temp) cur++;
            if (cur < ans) ans = cur;
        }
    }
    if (ans > m) puts("NOT POSSIBLE"); else printf("%d\n" , ans);
}

int main(){
    freopen("outlet.in" , "r" , stdin);
    freopen("outlet.out" , "w" , stdout);
    scanf("%d" , &t);
    fo (i , 1 , t){
        printf("Case #%d: " , i);
        Init();
        Work();
    }
    return 0;
}


