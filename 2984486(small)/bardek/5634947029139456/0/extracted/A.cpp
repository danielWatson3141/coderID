#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

#define fru(j,n) for(int j=0;j<n;++j)
#define tr(it,x) for(typeof(x.begin()) it=x.begin();it!=x.end();++it)
#define x first
#define y second

using namespace std;

typedef pair<int,int> pii;
typedef long long LL;

const int MAXN = 155;

LL T[2][MAXN];
map<LL,int> M;

int bitow(LL A) 
{
	return __builtin_popcountll(A);
}

int main()
{
	int o;
	scanf("%d",&o);
	char temp[55];
	fru(oo,o)
	{
		 printf("Case #%d: ",oo+1);
		 int n,L;
		 scanf("%d%d",&n,&L);
//		 printf("\n");
//		 printf("n = %d L = %d\n",n,L);
		 fru(e,2)fru(i,n)
		 {
			 T[e][i]=0;
			 scanf("%s",temp);
			 fru(j,L) if(temp[j]=='1') 
			 {
				 T[e][i]|=1LL<<j;
	//			 printf("j = %d i T[]=%lld\n",j,T[e][i]);
			 }
		//	 printf("%s --> %lld\n",temp,T[e][i]);
		 }
		 M.clear();
		 fru(i,n) fru(j,n) 
			 {
		//		 printf("%lld ^ %lld = %lld\n",T[0][i],T[1][j],					 T[0][i]^T[1][j]);
				 M[T[0][i]^T[1][j]]++;
			 }
//		 tr(it,M) printf("%lld (%d zapalonych) ma %d osob\n",it->x,bitow(it->x),it->y);
		 int ret=155;
		 tr(it,M) if(it->y==n) ret=min(ret,bitow(it->x));
//		 tr(it,M) if(it->y==L && bitow(it->x)==ret)	 {	 printf("dobra jest maska %lld\n",ret);break;}
		if(ret==155) printf("NOT POSSIBLE\n");
		else printf("%d\n",ret);
	}
    return 0;
}
