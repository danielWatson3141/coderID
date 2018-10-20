#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char a[200][50];
char b[200][50];
#define LL __int64
int n, l;
LL sa[200], sb[200];
LL cal(char s[]){
    LL res=0;
    for(int i=0; i<l; i++)  res = res*2 + s[i]-48;
    return res;
}
bool f[200];
int dis(char s1[], char s2[]){
    memset(f,0,sizeof(f));
    int res=0;
    for(int i=0; i<l; i++){
        if(s1[i]!=s2[i]){
            res++;
            f[i]=1;
        }
    }
    return res;
}
char tmp[50];
bool check(){
    for(int i=0; i<n; i++){
        for(int j=0; j<l; j++){
            if(f[j]){
                tmp[j] = (a[i][j]=='1'?'0':'1');
            }
            else{
                tmp[j] = a[i][j];
            }
        }
        sa[i] = cal(tmp);
    }
    sort(sa, sa+n);
    for(int i=0; i<n; i++){
        if(sa[i]!=sb[i])    return false;
    }
    return true;
}
int main(){
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int t, ct;
    scanf("%d", &t);
    for(ct=1; ct<=t; ct++){
        scanf("%d %d", &n, &l);
        for(int i=0; i<n; i++){
            scanf("%s", a[i]);
            sa[i] = cal(a[i]);
        }
        for(int i=0; i<n; i++){
            scanf("%s", b[i]);
            sb[i] = cal(b[i]);
        }
        sort(sa, sa+n);
        sort(sb, sb+n);
        int cnt=0;
        bool flag=0;
        for(cnt; cnt<l; cnt++){
            for(int i=0; i<n; i++){
                if(dis(a[0], b[i])==cnt){
                    if(check()){
                        flag=1;
                        break;
                    }
                }
            }
            if(flag)    break;
        }
        if(flag)    printf("Case #%d: %d\n", ct, cnt);
        else    printf("Case #%d: NOT POSSIBLE\n", ct);
    }
    return 0;
}
