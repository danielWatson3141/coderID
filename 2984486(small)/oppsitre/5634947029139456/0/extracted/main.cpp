#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 100
#define INF 0x3f3f3f3f
string outlet[MAXN],flow[MAXN];
bool swi[MAXN];
string sout[MAXN],sflow[MAXN];
int check(string A,string B,int N){
    memset(swi,false,sizeof(swi));
    for(int i = 0; i < A.length(); i++)
        if(A[i] != B[i]) swi[i] = true;
    for(int i = 0; i < N; i++){
        sflow[i] = outlet[i];
        sout[i] = flow[i];
    }
    for(int i = 0; i < N; i++){
        for(int j = 0;  j < B.length(); j++){
            if(swi[j]){
                if(sflow[i][j] == '0') sflow[i][j] = '1';
                else sflow[i][j] = '0';
            }
        }
    }
    sort(sout,sout + N);
    sort(sflow,sflow + N);
   /* for(int i = 0; i < N; i++)
        cout<<sout[i]<<' ';
    cout<<endl;
    for(int i = 0; i < N; i++)
        cout<<sflow[i]<<' ';
    cout<<endl;*/
    for(int i = 0; i < N; i++)
        if(sout[i] != sflow[i]) return -1;
    int ans = 0;
    for(int i = 0; i < A.length(); i++)
        if(swi[i]) ans++;
    return ans;
}
int main()
{
  //  freopen("test.txt","r",stdin);
    freopen("A-small-attempt2.in","r",stdin);
    freopen("A-small-attempt2.out","w",stdout);
    int T;scanf("%d",&T);
    for(int cas = 1;cas <= T;cas++){
        int N,L;
        scanf("%d%d",&N,&L);
        for(int i = 0; i < N; i++)
            cin >> outlet[i];
        for(int i = 0; i < N; i++)
            cin>> flow[i];
        int ans = INF;
        for(int i = 0 ; i < N ;i++)
            for(int j = 0; j < N; j++){
                int tans = check(outlet[i],flow[j],N);
                if(tans != -1) ans = min(tans,ans);
            }
        printf("Case #%d: ",cas);
        if(ans != INF)
            printf("%d\n",ans);
        else printf("NOT POSSIBLE\n");
    }
    return 0;
}
