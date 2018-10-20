#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
int d[151][41], qq[151][41];
int N, L, ans;
int cmp(const void *a, const void *b)
{
	int i;
	int *x=(int*)a, *y=(int*)b;
	for(i=0;i<L;i++){
		if(x[i]!=y[i])return x[i]-y[i];
	}
	return 0;
}
void display()
{
	int i, j;
	for(i=0;i<N;i++){
		for(j=0;j<L;j++){
			printf("%d", qq[i][j]);
		}
		printf(" ");
	}
	puts("");
	for(i=0;i<N;i++){
		for(j=0;j<L;j++){
			printf("%d", d[i][j]);
		}
		printf(" ");
	}
	puts("");
}
void dfs(int dep, int num)
{
	if(dep>L)return;
	int i, j;

	qsort(qq, N, sizeof(qq[0]),cmp);
	for(i=0;i<N;i++){
		for(j=0;j<L;j++){
			if(d[i][j]!=qq[i][j])break;
		}
		//printf("j %d L %d\n", j, L);
		if(j<L)break;
	}
	//printf("dep %d\n", dep);
	//display();
	//printf("i %d N %d\n", i, N);
	if(i==N)
		ans=min(ans, num);

	dfs(dep+1, num);
	for(i=0;i<N;i++)qq[i][dep]^=1;
	dfs(dep+1, num+1);
	for(i=0;i<N;i++)qq[i][dep]^=1;


}
int main()
{
	//freopen("PA.txt", "r", stdin);
	
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A.out", "w", stdout);
	
	int TN, ca=1, i, j;
	char ch;
	scanf("%d", &TN);
	while(TN--){
		scanf("%d%d", &N, &L);
		
		for(i=0;i<N;i++){
			for(j=0;j<L;j++){
				scanf(" %c", &ch);
				qq[i][j]=ch-'0';
			}
		}
		for(i=0;i<N;i++){
			for(j=0;j<L;j++){
				scanf(" %c", &ch);
				d[i][j]=ch-'0';

			}

		}

		qsort(d, N, sizeof(d[0]),cmp);
		

		ans=1e9;
		dfs(0, 0);
		printf("Case #%d: ", ca++);
		if(ans==1e9)puts("NOT POSSIBLE");
		else printf("%d\n", ans);
	}
	return 0;
}