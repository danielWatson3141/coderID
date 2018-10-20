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

const int N = 305;
const int M = 30005;
const int inf = 1<<28;
const double eps = 1e-8;
using namespace std;
int n,m,c;
int a[N],b[N],sum[N];
int hash[N*10],cnt[N*10];

void input(){
    scanf("%d%d%d",&n,&m,&c);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=m;i++){
        scanf("%d",&b[i]);
    }
}

/**********************Solution 3: O(n^2) **********************/
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}

int judge(){
    memset(hash,0,sizeof(hash));
    memset(cnt,0,sizeof(cnt));
    sum[0]=0;
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            hash[gcd(sum[i]-sum[j],c)]++;
        }
    }
    for(int i=1;i<=c;i++){
        for(int j=i;j<=c;j+=i){
            cnt[i]+=hash[j];
        }
    }
    sum[0]=0;
    int res=0;
    for(int i=1;i<=m;i++) sum[i]=sum[i-1]+b[i];
    for(int i=1;i<=m;i++){
        for(int j=0;j<i;j++){
            int k=gcd(sum[i]-sum[j],c);
            res+=cnt[c/k];
        }
    }
    return res;
}

/***************************************************************/

/*************************BruteForce: O(n^4), cannot pass*************/
int tmp[N][N];

int brute(){
    memset(tmp,0,sizeof(tmp));
    int res=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            tmp[i][j]=tmp[i-1][j]+tmp[i][j-1]-tmp[i-1][j-1]+a[i]*b[j];
            for(int x=1;x<=i;x++){
                for(int y=1;y<=j;y++){
                    int kk=tmp[i][j]-tmp[i][y-1]-tmp[x-1][j]+tmp[x-1][y-1];
                    if(kk%c==0) res++;
                }
            }
        }
    }
    return res;
}

/****************************************************************/

/**********************Solution2 O(n^3)*****************************/
int cal(){
    int res=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            tmp[i][j]=a[i]*b[j];
        }
    }
    for(int i=1;i<=n;i++){
        memset(sum,0,sizeof(sum));
        for(int j=i;j<=n;j++){
            for(int k=1;k<=m;k++){
                sum[k]+=tmp[j][k];
            }
            for(int k=0;k<c;k++) hash[k]=0;
            int ans=0;
            hash[0]=1;
            for(int k=1;k<=m;k++){
                ans+=sum[k],ans%=c;
                res+=hash[ans],hash[ans]++;
            }
        }
    }
    return res;
}
/*****************************************************************/

/*********************Best solution O(nlogn)****************************/
LL re[105][M];
LL pa[105],pb[105];
vector<int> g[M];

void init(){
    int mx=0,id=-1;
    for(int i=1;i<M;i++){
        for(int j=i;j<M;j+=i) g[j].push_back(i);
        if(mx<(int)g[i].size()) mx=g[i].size(),id=i;
    }
//    cout<<mx<<" "<<id<<endl;
}


LL best(){
    int sz=g[c].size();
    for(int i=0;i<sz;i++){
        int k=g[c][i];
        re[i][0]=1,pa[i]=0;
        for(int j=1;j<k;j++) re[i][j]=0;
    }
    LL now=0;
    for(int i=1;i<=n;i++){
        now+=a[i];
        for(int j=0;j<sz;j++){
            int k=g[c][j],r=now%k;
            pa[j]+=re[j][r],re[j][r]++;
        }
    }
    for(int i=0;i<sz;i++){
        int k=g[c][i];
        re[i][0]=1,pb[i]=0;
        for(int j=1;j<k;j++) re[i][j]=0;
    }
    now=0;
    for(int i=1;i<=m;i++){
        now+=b[i];
        for(int j=0;j<sz;j++){
            int k=g[c][j],r=now%k;
            pb[j]+=re[j][r],re[j][r]++;
        }
    }
    LL res=0;
    for(int i=sz-1;i>=0;i--){
        for(int j=i+1;j<sz;j++){
            if(g[c][j]%g[c][i]==0) pb[i]-=pb[j];
        }
        for(int j=0;j<sz;j++){
            if(g[c][i]*g[c][j]==c){
                res+=pb[i]*pa[j];
                break;
            }
        }
    }
//    for(int i=0;i<sz;i++) cout<<pa[i]<<" ";
//    cout<<endl;
//    for(int i=0;i<sz;i++) cout<<pb[i]<<" ";
//    cout<<endl;
    return res;
}
/***********************************************************/

/***********************************************************/

void out(){
    cout<<n<<" "<<m<<" "<<c<<endl;
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<endl;
    for(int i=1;i<=m;i++) cout<<b[i]<<" ";
    cout<<endl;
}

void gettest(){
    n=rand()%30000+1,m=rand()%30000+1;
    c=27720;
    for(int i=1;i<=n;i++) a[i]=(rand()%30000+1);
    for(int i=1;i<=m;i++) b[i]=(rand()%30000+1);
}


/***********************************************************/


int main(){
//    freopen("in1","r",stdin);
//    freopen("out1","w",stdout);
    init();
//    while(1){
//        gettest();
//        if(best()<1LL*5000000000000) continue;
//        else{
//            out();
//            break;
//        }
//    }
//    return 0;
    int T=0;
    cin>>T;
    while(T--){
        input();
        cout<<best()<<endl;
//        printf("%d\n",brute());
//        printf("%d\n",judge());
//        printf("%d\n",cal());
    }
    return 0;
}

















