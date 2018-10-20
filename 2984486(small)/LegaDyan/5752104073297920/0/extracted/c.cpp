#include<cstdio>
#include<algorithm>
using namespace std;
int a[2000],b[2000];
int main(){
	freopen("3.in","r",stdin);
	freopen("3.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int t=1;t<=T;t++){
		int n;
		scanf("%d",&n);
		bool f=0;
		for (int i=0;i<n;i++){
			scanf("%d",&a[i]);
			if (a[i]!=i) f=1; 
		}
		if (f==0){
			printf("Case #%d: BAD\n",t);
			continue;
		}
		f=0;
		for (int i=0;i<n;i++)
			b[i]=i;
		int time=0;
		for (int i=0;i<n;i++){
			if (a[i]==b[i]){
				time++;
				continue;
			}
			int pos=-1;
			for (int j=i+1;j<n;j++)
				if (a[i]==b[j]){
					pos=j;
					break;
				}
			if (pos==-1){
				f=1;
				printf("Case #%d: BAD\n",t);
				break;
			}
			swap(b[i],b[pos]);
		}
		if (f==0){
			if (time<9)
				printf("Case #%d: GOOD\n",t);
			else printf("Case #%d: BAD\n",t);
		}
	}
	return 0;
}
