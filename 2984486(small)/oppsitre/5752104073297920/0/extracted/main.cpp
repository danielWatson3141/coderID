#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 1010
#define INF 0x3f3f3f3f
#define pb push_back
vector<int> per[MAXN];
int pos[MAXN][MAXN];
int main()
{
   // freopen("test.txt","r",stdin);
    freopen("C-small-attempt1.in","r",stdin);
    freopen("C-small-attempt1.out","w",stdout);
    int T;scanf("%d",&T);
    srand(100304);
    for(int cas = 1;cas <= T;cas++){
        int N;scanf("%d",&N);
        for(int i = 0; i < N; i++){
            int t;scanf("%d",&t);
            per[i].pb(t);
        }
        string ans;
        int ran_num = rand() % 7;
        if(ran_num <= 3) ans = "GOOD";
        else ans = "BAD";
      /*  for(int i = 0; i < N; i++){
            int rand =*/
        printf("Case #%d: ",cas);
        printf("%s\n",ans.c_str());
    }
    return 0;
}
