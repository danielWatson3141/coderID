#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<vector>
#include<cctype>
#include<cstdio>
#include<string>
#include<sstream>
#include<cstring>
#include<cstdlib>
#include<fstream>
#include<iterator>
#include<iostream>
#include<algorithm>

using namespace std;

#pragma comment(linker,"/STACK:16777216")
#pragma warning(disable:4786)

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define myabs(a) ((a)<0?(-(a)):(a))
#define pi acos(-1.0)
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define pb push_back
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define eps 1e-9
#define root 1
#define lft 2*idx
#define rgt 2*idx+1
#define cllft lft,st,mid
#define clrgt rgt,mid+1,ed
#define inf (1<<29)
#define i64 long long
#define MX 10002

typedef pair<int,int> pii;

int a[MX],b[MX];

int dtob(string a){
    int ret=0,i;
    for(i=0;i<a.size();i++){
        ret=ret*2+a[i]-'0';
    }
    return ret;
}

int bitcount(int n){
    int ret=0;
    while(n){
        ret+=(n&1);
        n>>=1;
    }
    return ret;
}

bool func(int n,int bt){
    int i,flag[MX]={0},x;
    for(i=0;i<n;i++){
        x=a[i]^bt;
        flag[x]=1;
    }
    for(i=0;i<n;i++){
        if(!flag[b[i]])return false;
    }
    return true;
}

int main(){
    freopen("A-small-attempt0.in","r",stdin);
	//freopen("in.in","r",stdin);
	freopen("out.txt","w",stdout);
	int cs,t=1,n,i,l,j,res;
	string s;
	cin>>cs;
	while(cs--){
	    cin>>n>>l;
	    for(i=0;i<n;i++){
	        cin>>s;
	        a[i]=dtob(s);
	    }
	    for(i=0;i<n;i++){
	        cin>>s;
	        b[i]=dtob(s);
	    }
	    res=inf;
	    for(i=0;i<(1<<l);i++){
	        if(func(n,i)){
	            j=bitcount(i);
	            res=min(res,j);
	        }
	    }
	    printf("Case #%d: ",t++);
	    if(res<inf)printf("%d\n",res);
	    else printf("NOT POSSIBLE\n");
	}
	return 0;
}


