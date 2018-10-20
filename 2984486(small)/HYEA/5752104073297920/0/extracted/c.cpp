#include<cstdio>
#include<cstdlib>
int main(){
	int t;
	freopen("C-small-attempt1.in","rt",stdin);
	freopen("out.txt","wt",stdout);
	scanf("%d",&t);
	for(int q=1;q<=t;q++){
		int n;
		scanf("%d",&n);
		int goodcnt=0;//501234
		int badcnt=0;//123405
		int x;
		for(int i=0;i<n-2;i++){
			int x;
			scanf("%d",&x);
			if(x==(i+(n-1))%n) goodcnt++;
			if(x==i+1) badcnt++;
		}
		for(int i=n-2;i<n-1;i++){
			scanf("%d",&x);
			if(x==i-1) goodcnt++;
			if(x==0) badcnt++;
		}
		for(int i=n-1;i<n;i++){
			scanf("%d",&x);
			if(x==i-1) goodcnt++;
			if(x==n-1) badcnt++;
		}
		if(badcnt>goodcnt) printf("Case #%d: BAD\n",q);
		else printf("Case #%d: GOOD\n",q);
	}
}