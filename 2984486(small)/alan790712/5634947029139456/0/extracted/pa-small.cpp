#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;

int T, R, C;
char ori[20][20], change[20][20], test[20][20];

int getBit(int x, int i)
{
    if((x&(1<<i))>0) return 1;
    return 0;
}

int cntBit(int x)
{
    int i, cnt=0;;
    for(i=0;i<C;i++){
        if(getBit(x, i)==1) cnt++;
    }
    return cnt;
}


int cmp(const void*p, const void*q)
{
    char *a=(char*)p, *b=(char*)q;
    return strcmp(a,b);
}

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("myA-small.out", "w", stdout);
    int now, i, j, b, t;
    int ans;

    scanf("%d", &T);
    for(t=1;t<=T;t++){
        ans=200;
        scanf("%d%d", &R, &C);
        for(i=0;i<R;i++) scanf("%s", ori[i]);
        qsort(ori, R, sizeof(ori[0]), cmp);
        /*printf("*\n");
        for(i=0;i<R;i++) printf(" %s\n", ori[i]);
        printf("*\n");*/
        for(i=0;i<R;i++) scanf("%s", change[i]);

        for(now=0;now<(1<<C);now++){
            for(i=0;i<C;i++){
                b=getBit(now, i);
                for(j=0;j<R;j++){
                    /*printf("r:%d, c:%d\n", j, i);*/
                    if(b==0) test[j][i]=change[j][i];
                    else{
                        if(change[j][i]=='1') test[j][i]='0';
                        else test[j][i]='1';
                    }
                }
            }
            for(j=0;j<R;j++) test[j][C]='\0';
            /*printf("now:%d\n", now);
            for(j=0;j<R;j++) printf("%s\n", test[j]);*/
            qsort(test, R, sizeof(test[0]), cmp);
            /*printf("\n");
            for(i=0;i<R;i++) printf("%s\n", test[i]);*/
            for(i=0;i<R;i++){
                if(strcmp(test[i],ori[i])!=0) break;
            }

            if(i==R){
                ans=min(ans,cntBit(now));
            }
        }
        if(ans==200) printf("Case #%d: NOT POSSIBLE\n", t);
        else printf("Case #%d: %d\n", t, ans);
    }



    return 0;
}
