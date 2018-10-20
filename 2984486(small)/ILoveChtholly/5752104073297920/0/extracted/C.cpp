#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
using namespace std;
double a=1,b=1;
int A[1005];
int main(){
	freopen("C-small-attempt6.in","r",stdin);
	freopen("out.txt","w",stdout);
	int t,n,m,i,j,k,x,y,c=0;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&A[i]);
		printf("Case #%d: ",++c);
		int a=0,b=0;
		for(i=0;i<n-1;i++){
			if(A[i]<i) a++;
			if(A[i]>i) b++;
		}
		if(a>b-20) puts("BAD");
		else puts("GOOD");
	}
}