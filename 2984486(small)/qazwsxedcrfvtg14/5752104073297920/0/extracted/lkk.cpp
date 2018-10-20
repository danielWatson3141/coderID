#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/priority_queue.hpp>
#define f first
#define s second
using namespace std;
//using namespace __gnu_pbds;
typedef std::pair<long long int,long long int> par;
int ar[1005],bit[1005];
void add(int a,int n){
	while(a<=n){
		bit[a]++;
		a+=a&-a;
		}
	}
int sum(int a){
	int ret=0;
	while(a){
		ret+=bit[a];
		a-=a&-a;
		}
	return ret;
	}
int main(){
	int t,T=0;
	scanf("%d",&t);
	while(t--){T++;
		printf("Case #%d: ",T);
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&ar[i]),ar[i]++;
		memset(bit,0,sizeof(bit));
		int cnt=0;
		for(int i=1;i<=n;i++){
			cnt+=i-1-sum(ar[i]);
			add(ar[i],n);
			}
		//printf("%d\n",cnt);
		int top=n*(n-1)/2;
		int mid=top/2;
		if(cnt<mid)puts("BAD");
		else puts("GOOD");
		}
	return 0;
	}
