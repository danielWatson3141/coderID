#include<bits/stdc++.h>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define SET(a) memset(a,-1,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))
#define pb push_back
#define all(a) a.begin(),a.end()
#define eps (1e-9)
#define inf (1<<29)
#define i64 long long
#define u64 unsigned i64

int a[200],b[200],c[200];
int main(){
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int t,cs = 1,i,j,N,L,ans,x,k;
    char s[200];
    cin>>t;
    while(t--){

        ans = 200;
        cin>>N>>L;
        for(i = 0;i<N;i++){
            cin>>s;
            a[i] = 0;
            for(j = 0;j<L;j++){
                a[i] = a[i]*2+s[j]-'0';
            }
        }
        for(i = 0;i<N;i++){
            cin>>s;
            b[i] = 0;
            for(j = 0;j<L;j++){
                b[i] = b[i]*2+s[j]-'0';
            }
        }
        sort(b,b+N);
        for(i = 0;i<N;i++){
            for(j = 0;j<N;j++){
                x = a[i]^b[j];
                for(k = 0;k<N;k++){
                    c[k] = a[k]^x;
                }
                sort(c,c+N);
                for(k = 0;k<N;k++){
                    if(c[k] != b[k]) break;
                }
                if(k == N){
                    ans = min(ans,__builtin_popcount(x));
                }
            }
        }
        printf("Case #%d: ",cs++);
        if(ans < 200)
            printf("%d\n",ans);
        else puts("NOT POSSIBLE");
    }
	return 0;
}
