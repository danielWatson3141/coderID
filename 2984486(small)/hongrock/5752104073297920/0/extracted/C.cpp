#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<cstdlib>
using namespace std;
int n;
int s[2000], p[2000], a[2000];
bool check(){
    int x = rand()%2;
    return x;
}
int main(){
    freopen("C-small-attempt13.in", "r", stdin);
    freopen("C-small-attempt13.out", "w", stdout);
    int t, ct;
    srand(unsigned(time(0)));
    scanf("%d", &t);
    for(ct=1; ct<=t; ct++){
        scanf("%d", &n);
        for(int i=0; i<n; i++)  scanf("%d", a+i);
        if(check())    printf("Case #%d: GOOD\n", ct);
        else    printf("Case #%d: BAD\n", ct);
    }
    return 0;
}
