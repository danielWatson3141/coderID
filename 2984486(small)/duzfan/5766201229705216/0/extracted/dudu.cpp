#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 1005;

#define fo(i , st , en) for (int i = st; i <= en; i++)
#define Me(x , y) memset(x , y , sizeof(x))

struct _two{
    int a , b;
}edge[N + N];

int st[N];
int t , n;
int f[N + N];

void Init(){
    scanf("%d" , &n); Me(st , 0); int x , y , tot = 1;
    fo (i , 1 , n - 1){
        scanf("%d%d" , &x , &y);
        edge[++tot] = (_two){y , st[x]}; st[x] = tot;
        edge[++tot] = (_two){x , st[y]}; st[y] = tot;
    }
}

void dfs(int cur){
    if (f[cur]) return; int x = edge[cur].a;
    int max1 = 0 , max2 = 0;
    for (int i = st[x]; i; i = edge[i].b)
        if ((i ^ 1) != cur){
            dfs(i);
            if (max1 <= f[i]){
                max2 = max1; max1 = f[i];
            }
            else
                if (max2 < f[i])  max2 = f[i];
        }
    if (max2) f[cur] = max1 + max2 + 1; else f[cur] = 1;
}

void Work(){
    int ans = 0; Me(f , 0);
    fo (i , 1 , n){
        edge[1].a = i;
        f[1] = 0; dfs(1); ans = max(ans , f[1]);
    }
    printf("%d\n" , n - ans);
}

int main(){
    freopen("1.in" , "r" , stdin);
    freopen("1.out" , "w" , stdout);
    scanf("%d" , &t);
    fo (i , 1 , t){
        printf("Case #%d: " , i);
        Init();
        Work();
    }
    return 0;
}

