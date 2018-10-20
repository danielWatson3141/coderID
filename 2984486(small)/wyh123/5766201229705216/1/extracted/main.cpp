//#pragma comment(linker,"/STACK:1024000000,1024000000")
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<queue>
#include<stack>
#include<utility>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
typedef long  long LL;

const int N = 1000005;
const int inf = 1<<28;
const double eps = 1e-8;
using namespace std;
LL n;
LL a,b;
int c,x;
LL cnt[N];

int main(){
//    freopen("in","r",stdin);
//    freopen("out","w",stdout);
//    srand(100000000000);
    int t,cas=1;
    scanf("%d",&t);
    while(t--){
        scanf("%I64d%I64d%I64d%d%d",&n,&a,&b,&c,&x);
//        n=rand()%105;
//        a=rand()%105;
//        b=rand()%105;
//        c=rand()%105;
//        if(n<0||a<0||b<0||c<=0) continue;
//        x=rand()%c;
        memset(cnt,0,sizeof(cnt));
//        n++;
        int nn=1,s=1,nr=1000005,x0=x;
        cnt[x]=1;
        for(int i=1;i<n;i++){
            x=((LL)a*x+b)%c;
//            cout<<"("<<x<<","<<cnt[x]<<") ";
            if(cnt[x]){
                s=cnt[x],nr=nn+1-s;
                break;
            }
            cnt[x]=++nn;
        }
//        cout<<endl;
//        if(s>=5){
//            cout<<n<<" "<<a<<" "<<b<<" "<<c<<" "<<x<<endl;
//            cout<<s<<" "<<nr<<endl;
//        }
        int ans=-1;
        LL res=0;
        for(int i=0;i<c;i++){
            if(!cnt[i]) continue;
            if(cnt[i]<s) res++,cnt[i]=1;
            else{
                LL tmp=(n-s+1)/nr,tmd=(n-s+1)%nr;
                res+=tmp;
                if(tmd>=cnt[i]-s+1) res++,cnt[i]=1;
                else cnt[i]=0;
                cnt[i]+=tmp;
            }
            if(ans==-1&&res*2>=n){
                ans=i;
            }
        }
        res=0;
        for(int i=0;i<c;i++){
            res+=cnt[i]*abs(ans-i);
        }
//        printf("Case %d: %d %I64d\n",cas++,ans,res);
        printf("Case %d: %I64d\n",cas++,res);
    }
    return 0;
}

















