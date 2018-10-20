#include<cstdio>
#include<cstdlib>
#include<cstring>
#define LEN 1005

int num[LEN];
int af[LEN];
int tt;
int N;
int isg;

int main(void)
{
	srand(55);
	scanf("%d",&tt);
	for(int tc=1;tc<=tt;++tc){
		scanf("%d",&N);
		for(int i=0;i<N;++i){
			scanf("%d",&af[i]);
		}
		isg=rand()%2;
		if(isg){
			printf("Case #%d: GOOD\n",tc);
		}else{
			printf("Case #%d: BAD\n",tc);
		}
	}
	return 0;
}
