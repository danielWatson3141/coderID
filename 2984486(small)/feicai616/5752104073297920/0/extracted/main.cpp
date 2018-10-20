#include <iostream>
#include <cstring>
#include <stdio.h>
#include <math.h>
#include <set>
#include <queue>
#include <vector>
#include <new>
#include <algorithm>
#include <map>
using namespace std;
#define pb push_back
#define mp make_pair
#define MatN 4
#define N 1000007
#define MOD 1000000007
#define lyl   printf("ok\n")
typedef  pair<int,int> pii;
typedef long long LL;
bool zihuan[10002];
int a[10002];
int jjj[10002];
int main(){
    int casen;
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%d",&casen);
    memset(jjj,0,sizeof(jjj));
    for (int casei=0;casei<casen;casei++){
        int n;
       scanf("%d",&n);int ji=0;for (int i=0;i<n;i++) zihuan[i]=false;
        for (int i=0;i<n;i++){scanf("%d",&a[i]);}
int        maxx=10000;
      for (int i=0;i<n;i++){
          if (!zihuan[i]){
              int cici=0;
              ji++;
              int tmp=i;
              while (!zihuan[tmp]){
                  zihuan[tmp]=true;
                  tmp=a[i];
                  cici++;
              }
              maxx=min(cici,maxx);
          }
      }
      jjj[ji]++;
        if (ji<=627){
            printf("Case #%d: GOOD\n",casei+1);
        }else{
            printf("Case #%d: BAD\n",casei+1);
        }
    }
    int sum=0;
    for (int i=0;i<=1000;i++){
        sum+=jjj[i];
       // printf("%d %d %d\n",i,jjj[i],sum);
    }
}
