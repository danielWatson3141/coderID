#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
typedef long long ll;
ll a[222][222];
ll b[222][222];
ll aa[222];
ll bb[222];
ll cc[222];
ll cmd[111];
int ch,sum,tmp,fap=0,abc,n,m;
char opr;
int ope;
ll cnt;
ll mn=10000000;
multiset<int> s;
void solve(){
	ch=1;
	sum=0;
	mn=100000000;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf(" %c",&opr);
			a[i][j]=(ll)(opr=='1');
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf(" %c",&opr);
			b[i][j]=(ll)(opr=='1');
		}
	}
	memset(aa,0,sizeof(aa));
	memset(bb,0,sizeof(bb));
	for(int i=1;i<=n;i++){
		tmp=1;
		for(int j=1;j<=m;j++){
			aa[i]+=tmp*a[i][j];
			tmp*=2;
		}
	}
	for(int i=1;i<=n;i++){
		tmp=1;
		for(int j=1;j<=m;j++){
			bb[i]+=tmp*b[i][j];
			tmp*=2;
		}
	}
	ch=1;
	s.clear();
	for(int k=1;k<=n;k++){
		s.insert(aa[k]);
		//printf("%d ",aa[k]);
	}//printf("\n");
	for(int k=1;k<=n;k++){
		//printf("%d ",bb[k]);
		s.erase(bb[k]);
	}//printf("\n");
	if(s.size()==0){
		ch=0;
		tmp=1;
		cnt=0;
		for(int k=1;k<=n;k++) tmp*=2;
		while(tmp>1){
			cnt+=ope/tmp;
			ope%=tmp;
			tmp/=2;
		}
		if(cnt<mn) mn=cnt;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ope=aa[i]^bb[j];
			//printf("%d\n",ope);
			for(int k=1;k<=n;k++){
				cc[k]=aa[k]^ope;
				//printf("%d ",cc[k]);
			}//printf("\n");
			s.clear();
			for(int k=1;k<=n;k++){
				s.insert(cc[k]);
			}
			for(int k=1;k<=n;k++){
				s.erase(bb[k]);
			}
			if(s.size()==0){
				ch=0;
				tmp=1;
				cnt=0;
				for(int k=1;k<=m;k++) tmp*=2;
				while(tmp>=1){
					cnt+=ope/tmp;
					ope%=tmp;
					tmp/=2;
				}
				if(cnt<mn) mn=cnt;
			}

		}
	}

	printf("Case #%d: ",++fap);
	if(ch) printf("NOT POSSIBLE\n");
	else printf("%d\n",mn);
}
int main(){
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	scanf("%d",&abc);
	while(abc--) solve();
	return 0;
}