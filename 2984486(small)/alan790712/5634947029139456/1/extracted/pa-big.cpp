#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;

int T, R, C;
char ori[200][200], change[200][200], test[200][200];

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
    freopen("A-large.in", "r", stdin);
    freopen("myA-large.out", "w", stdout);
    int now, i, j, b, t, p;
    int ans;
    long long x;

    scanf("%d", &T);
    for(t=1;t<=T;t++){
        ans=200;
        scanf("%d%d", &R, &C);
        for(i=0;i<R;i++) scanf("%s", ori[i]);
        qsort(ori, R, sizeof(ori[0]), cmp);

        for(i=0;i<R;i++) scanf("%s", change[i]);

        for(now=0;now<R;now++){
            p=0;
            x=0;
            for(i=0;i<C;i++){
                if(change[now][i]!=ori[p][i]){
                    x+=(1<<i);
                    for(j=0;j<R;j++){
                        if(change[j][i]=='1') test[j][i]='0';
                        else test[j][i]='1';
                    }
                }
                else{
                    for(j=0;j<R;j++){
                        test[j][i]=change[j][i];
                    }
                }
            }
            for(j=0;j<R;j++) test[j][C]='\0';
            qsort(test, R, sizeof(test[0]), cmp);
            /*for(j=0;j<R;j++) printf(" %s\n", test[j]);
            printf("\n");*/
            for(i=0;i<R;i++){
                if(strcmp(test[i],ori[i])!=0) break;
            }

            if(i==R){
                ans=min(ans,cntBit(x));
            }
        }

        if(ans==200) printf("Case #%d: NOT POSSIBLE\n", t);
        else printf("Case #%d: %d\n", t, ans);
    }



    return 0;
}
