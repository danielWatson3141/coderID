#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>
using namespace std;
vector<int> table[1005];
int cost[1005];
int countChild[1005];
int v[1005];
int num(int x);
int cmp(const void *x, const void *y){
    return *(int*)x - *(int*)y;
}
int R;
int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("PB_big.out","w+", stdout);
    int tn, t, x, y, small, n, i;
    scanf("%d", &tn);
    for(t=1;t<=tn;t++){
        scanf("%d", &n);
        for(i=1;i<=n;i++)
            table[i].clear();

        for(i=1;i<n;i++){
            scanf("%d%d", &x,&y);
            table[x].push_back(y);
            table[y].push_back(x);
        }
        for(small=n,x=1;x<=n;x++){
            R=x;
            memset(cost, 0, sizeof(cost));
            memset(countChild, 0, sizeof(countChild));
            memset(v, 0, sizeof(v));
            countChild[x] = num(x);
            if(cost[x]<small)
                small = cost[x];
            //printf("\n");
        }
        printf("Case #%d: %d\n", t, small);
    }
    return 0;
}
int tmp[1005];
int num(int x){

    int i, child;

    //printf("x =%d\n",x);
    v[x]=1;

    for(i=0,child=1;i<table[x].size();i++){
       if(!v[table[x][i]]){
        //printf("visit %d\n", table[x][i]);
        countChild[table[x][i]] = num(table[x][i]);
        child+=countChild[table[x][i]];
       }
    }
    countChild[x]=child;
    //printf("child[%d]:%d\n", x, child);
    if(x==R){
        if(table[x].size()<=1)
        cost[x] = countChild[x]-1;
        else{
            for(i=0;i<table[x].size();i++){
                cost[x] += countChild[table[x][i]];
                tmp[i] = cost[table[x][i]] - countChild[table[x][i]];
            }
            qsort(tmp, table[x].size(), sizeof(table[x][0]), cmp);
            //printf("%d %d\n", tmp[0],tmp[1]);
            cost[x]+=tmp[0]+tmp[1];
        }

    }
    else{
        if(table[x].size()<=2)
            cost[x] = countChild[x]-1;
        else{
            for(i=0;i<table[x].size();i++){
                cost[x] += countChild[table[x][i]];
                tmp[i] = cost[table[x][i]] - countChild[table[x][i]];
            }
            qsort(tmp, table[x].size(), sizeof(table[x][0]), cmp);
            cost[x]+=tmp[0]+tmp[1];
        }
    }
    //printf("cost[%d]:%d\n", x, cost[x]);
    return child;
}
