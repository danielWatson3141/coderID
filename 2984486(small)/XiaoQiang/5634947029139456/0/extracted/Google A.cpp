#include<cstdio>
#include<algorithm>
using namespace std;
int count1(int x){
    //printf("count %d\n", x);
    int ans = 0;
    while(x!=0){
        if(x%2==1){
            ans+=1;
            x = (x-1)/2;
        }
        else{
            x = x/2;
        }
    }
    return ans;
}
int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int nCases, _case = 1;
    scanf("%d", &nCases);
    char s[40];
    int n, l;
    int mink;
    int K;
    int a[20], b[20], c[20];
    int tmp, flag;
    while(nCases--){
        scanf("%d%d", &n, &l);
        K = (1<<l)-1;
        //printf("%d\n", K);
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        for(int i = 0; i < n; i++){
            scanf("%s", s);
            tmp = 1;
            for(int j = 0; j < l; j++){
                if(s[j] == '1'){
                    a[i]+= tmp;
                }
                tmp*=2;
            }
        }
        sort(a, a+n);
        for(int i = 0; i < n; i++){
            scanf("%s", s);
            tmp = 1;
            for(int j = 0; j < l; j++){
                if(s[j] == '1'){
                    b[i]+= tmp;
                }
                tmp*=2;
            }
        }
        /*for(int i = 0; i < n; i++){
            printf("%d ", a[i]);
        }
        printf("\n");
        for(int i = 0; i < n; i++){
            printf("%d ", b[i]);
        }
        printf("\n");*/
        mink = -1;
        for(int i = 0; i <= K; i++){
            for(int j = 0; j < n; j++){
                c[j] = b[j]^i;
            }
            /*for(int i = 0; i < n; i++){
                printf("%d ", c[i]);
            }
            printf("\n");*/
            sort(c, c+n);
            flag = true;
            for(int j = 0; j < n; j++){
                if(c[j] != a[j]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                tmp = count1(i);
                if(tmp<mink||mink < 0){
                    mink = tmp;
                }
            }
        }
        if(mink < 0){
            printf("Case #%d: NOT POSSIBLE\n", _case++);
        }else{
            printf("Case #%d: %d\n", _case++, mink);
        }
    }
    return 0;
}
