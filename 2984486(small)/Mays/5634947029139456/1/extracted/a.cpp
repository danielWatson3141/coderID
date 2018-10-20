#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
typedef long long ll;
using namespace std;
const int maxn = 153;
const int maxl = 45;

ll ori[maxn],fin[maxn];
ll shu[maxn];
char str[maxl];
int n,l;
int ok,step;
ll tot;

void init(){
        memset(ori,0,sizeof ori);
        memset(fin,0,sizeof fin);
        step = maxn;
}

void input(){
     for(int i = 0; i < n; i ++){
        scanf("%s",str);
        ll temp = 0;
        for(int j = 0; j < l; j++){
             temp += ((str[j] == '1' ? 1 : 0) << j);
        }
        ori[i] = temp;
    }
    for(int i = 0; i < n; i ++){
        scanf("%s",str);
        ll temp = 0;
        for(int j = 0; j < l; j++){
             temp += ((str[j] == '1' ? 1 : 0) << j);
        }
        fin[i] = temp;
    }
}
int county(ll a){
    int ans = 0;
    while(a > 0){
        ans += (a & 1);
        a = (a >> 1);
    }
    return ans;
}

void faire(){
    sort(fin,fin+n);
    //printf("sort fin \n");
   /* for(int i = 0; i < n; i ++)
        printf("%lld\n",fin[i]);
    printf("\n");
   */for(int i = 0; i < n; i++){
        ll temp = (fin[0] ^ ori[i]);
        for(int j = 0; j < n; j++){
            shu[j] = (ori[j] ^ temp);
        }
        sort(shu,shu+n);
        ok = 1;
        for(int j = 0; j < n ; j++){
            if(shu[j] != fin[j]){
                ok = 0;
                break;
            }
        }
        if(ok) step = min(step,county(temp));
    }
}

int main(){
    int t,nc = 0;
    freopen("A-large.in","r",stdin);
    freopen("alarge.out","w",stdout);
    cin >> t;
    while(t--){
        printf("Case #%d: ",++nc);
        init();
        scanf("%d%d",&n,&l);
        input();
        faire();
        if(step == maxn){printf("NOT POSSIBLE\n"); continue;}
        printf("%d\n",step);
    }
    return 0;
}
