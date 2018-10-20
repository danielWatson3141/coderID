#include<cstdio>
#include<algorithm>

using namespace std;

long devices[150];
long outlet[150];
int N, L;

int minsolved;
void init()
{
	for(int i=0;i<150;i++){
		devices[i] = 0;
		outlet[i] = 0;
	}
	minsolved = 10000; 
}

bool contains(long num)
{
	for(int i=0;i<N;i++){
		if(outlet[i] == num)
			return true;
	}
	return false;
}
bool check(long bit)
{
	for(int i=0;i<N;i++){
		if(!contains(devices[i]^bit))
			return false;
	}
	return true;
}

int set_bits(long bit)
{
	int i=0;
	for(int j=0;j<L;j++){
		if(1<<j & bit)
			i++;
	}
	return i;
}

void solve()
{
	/*bool solve=true;
	for(int j=0;j<N;j++){
		if(!contains(devices[j])){
			solve=false;
			break;
		}
	}
	if(solve){
		printf("0\n");
		return;
	}*/
	for(int j=0;j<N;j++){
		long bit = devices[0]^outlet[j];
		if(check(bit)){
			if(set_bits(bit)<minsolved)
				minsolved = set_bits(bit);
		}
	}
	if(minsolved==10000)
		printf("NOT POSSIBLE\n");
	else
		printf("%d\n", minsolved);
}

int main(void)
{
	int T;
	scanf("%d", &T);
	//printf("%d\n", T);
	for(int i=0;i<T;i++){
		printf("Case #%d: ", i+1);
		scanf("%d%d", &N, &L);
		//printf("%d%d\n", N, L);

		init();

		char ch;
		scanf("%c", &ch);

		for(int j=0;j<N;j++){
			for(int k=0;k<L;k++){
				scanf("%c", &ch);
				//printf("read:%c %d,%d\n", ch, j, k);
				outlet[j] = outlet[j]*2+(ch-'0');
			}
			scanf("%c", &ch);//space
			//printf("ol: %ld ", outlet[j]);
		}
		for(int j=0;j<N;j++){
			for(int k=0;k<L;k++){
				scanf("%c", &ch);
				//printf("read:%c %d,%d\n", ch, j, k);
				devices[j] = devices[j]*2+(ch-'0');
			}
			scanf("%c", &ch);//space
			//printf("dev: %ld ", devices[j]);
		}
		solve();
	}
}
