#include <cstdio>
#include <algorithm>

using namespace std;

long bit2long(char *tmp){
	int i;
	long ret=0;
	for(i=0;tmp[i]>0;i++){
		ret<<=1;
		ret+=tmp[i]-'0';
	}
	return ret;
}

int count1fromlong(long x){
	int ret=0;
	while(x>0){
		ret+=x&1;
		x>>=1;
	}
	return ret;
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int ti,t,n,l,i,j,k,m,cnt;
	char tmp[50];
	long outlet[200],device[200],newdev[200],sw;
	const int INF=987654321;
	scanf("%d",&t);
	for(ti=1;ti<=t;ti++){
		scanf("%d%d",&n,&l);
		for(i=0;i<n;i++){
			scanf("%s",tmp);
			outlet[i]=bit2long(tmp);
		}
		for(i=0;i<n;i++){
			scanf("%s",tmp);
			device[i]=bit2long(tmp);
		}
		sort(device,device+n);

		m=INF;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				sw = outlet[i] ^ device[j];
				for(k=0;k<n;k++){
					newdev[k] = outlet[k] ^ sw;
				}
				sort(newdev,newdev+n);
				for(k=0;k<n;k++){
					if(device[k]!=newdev[k]) break;
				}
				if(k<n) continue;
				cnt=count1fromlong(sw);
				if(m>cnt) m=cnt;
			}
		}
		printf("Case #%d: ",ti);
		if(m==INF){
			printf("NOT POSSIBLE");
		}else{
			printf("%d",m);
		}
		printf("\n");
	}
}