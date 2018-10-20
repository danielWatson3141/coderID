#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<string>
#include<cctype>
#include<cmath>
#include<sstream>
#include<bitset>
using namespace std;
#define LL long long
#define pb push_back
#define CLR(x,y) memset(x,y,sizeof(x))
template<class T> inline int maximize(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline int minimize(T& a,T b){if(a>b){a=b;return 1;}return 0;}
const int N=155,INF=0x3f3f3f3f;

int n,L;
string A[N],B[N],C,D[N];
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("yy.txt","w",stdout);
    ios::sync_with_stdio(false);
    int T;cin>>T;
    for(int cs=1;cs<=T;++cs)
    {
        cin>>n>>L;
        for(int i=0;i<n;++i)
        {
            cin>>A[i];
//            for(int j=0;j<L;++j) A[i][j]-='0';
        }
        for(int i=0;i<n;++i)
        {
            cin>>B[i];
//            for(int j=0;j<L;++j) B[i][j]-='0';
        }
        sort(B,B+n);
        int ans=INF;
        for(int i=0;i<n;++i)
        {
            C.clear();
            for(int j=0;j<L;++j) C+=(A[0][j]-'0')^(B[i][j]-'0')+'0';
//            cout<<i<<" "<<C<<endl;
            for(int j=0;j<n;++j)
            {
                D[j].clear();
                for(int k=0;k<L;++k)
                {
                    D[j]+=(A[j][k]-'0')^(C[k]-'0')+'0';
                }
//                cout<<D[j]<<endl;
            }
            sort(D,D+n);
            int f=1;
            for(int j=0;j<n;++j)
            {
//                cout<<B[j]<<" "<<D[j]<<endl;
                if(D[j]!=B[j]) {f=0;break;}
            }
            if(f)
            {
                int t=0;
                for(int j=0;j<L;++j) t+=C[j]-'0';
                minimize(ans,t);
            }
        }
        if(ans<INF) printf("Case #%d: %d\n",cs,ans);
        else  printf("Case #%d: NOT POSSIBLE\n",cs);
    }
    return 0;
}
