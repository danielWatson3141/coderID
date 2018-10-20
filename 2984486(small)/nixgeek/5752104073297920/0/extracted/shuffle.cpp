#include<cstdio>
#include<algorithm>
#include<cstdlib>

using namespace std;

int nums[1000];
int N;

/*void bad_algo()
{
	for(int k=0;k<3;k++){
		nums[k] = k;
	}
	for(int k=0;k<3;k++){
		//int p = rand()%3;
		go:
		int p = (k-1)+ (rand()%(3-k+1));
		if(p<0) goto go;

		int temp = nums[k];
		nums[k] = nums[p];
		nums[p] = temp;
	}
	for(int k=0;k<3;k++){
		printf("%d ", nums[k]);
	}
	printf("\n");
}*/

void solve()
{
	int res=0;
	for(int i=0;i<N;i++){
		if(nums[i] == i)
			res++;
	}
	if(res>2)
		printf("BAD\n");
	else
		printf("GOOD\n");
	/*for(int k=0;k<18;k++)
		bad_algo();*/
}

int main(void)
{
	int T;
	scanf("%d", &T);
	for(int i=0;i<T;i++){
		printf("Case #%d: ", i+1);
		scanf("%d", &N);

		for(int j=0;j<N;j++){
			scanf("%d", &nums[j]);
		}
		solve();
	}
}
