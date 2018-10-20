/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<stack>
#include<set>
#include<utility>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)

using namespace std;
int N;
vector<int> neigh[1200];
int dp[1001][1001];
int deb = 0;
int getans(int u, int bk){
    if(dp[u][bk] != -1)
        return dp[u][bk];
    int &ans = dp[u][bk];
    if((int)neigh[u].size()-bool(bk) <= 1){
        ans = 1;
    }else{
        int max1 = 0, max2 = 0;
        for(int i = 0;i<neigh[u].size();i++){
            if(neigh[u][i] != bk){
                max2 = max(getans(neigh[u][i], u), max2);
                if(max1<max2)
                    swap(max1, max2);
            }
        }
        ans = max1+max2+1;
    }
    return ans;
}
int main()
{
    int z = 0;
    in_T{
        z++;
        in_I(N);
        int x, y;
        for(int i = 1;i<=N;i++)
            neigh[i].clear();
        for(int i = 1;i<=N;i++)
            for(int j = 0;j<=N;j++)
                dp[i][j] = -1;

        for(int i = 0;i<N-1;i++){
            in_I(x);
            in_I(y);
            neigh[x].push_back(y);
            neigh[y].push_back(x);
        }
        for(int i = 1;i<=N;i++){
//            if(z == 3 && i == 2)
//            deb = 1;
            getans(i, 0);
//            deb = 0;
        }
        int ans = 0;
        for(int i = 1;i<=N;i++)
        {
//            cout<<i<<" "<<dp[i][0]<<endl;
                if(dp[i][0] != -1)
                    ans = max(ans, dp[i][0]);
        }
        cout<<"Case #"<<z<<": "<<N-ans<<endl;
    }
}
