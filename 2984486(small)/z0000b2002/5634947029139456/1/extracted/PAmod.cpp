#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define INF 2147483647
#define LEN 200

int N,L;

char str[LEN];
long long cable[LEN];
long long newc[LEN];
long long device[LEN];

int icmp(const void *p,const void *q)
{
	long long *a=(long long*)p;
	long long *b=(long long*)q;
	if(*a>*b)return 1;
	if(*a<*b)return -1;
	return 0;
}

int countbin(long long num)
{
	int tor=0;
	while(num){
		if(num&1)++tor;
		num>>=1;
	}
	return tor;
}

long long strtobin(char *w)
{	
	long long tor=0;
	for(int wc=0;wc<L;++wc){
		tor<<=1;
		tor+=(w[wc]-'0');
	}
	return tor;
}

int checkok(long long mask)
{
	for(int i=0;i<N;++i){
		newc[i]=mask^cable[i];
	}
	qsort(newc,N,sizeof(newc[0]),icmp);
	/*
	printf("mask:%d\n",mask);
	for(int i=0;i<N;++i){
		printf("%lld ",newc[i]);
	}
	putchar('\n');
	*/
	for(int i=0;i<N;++i){
		if(newc[i]!=device[i])return 0;
	}
	return 1;
}

int main(void)
{
	int tt;
	int ans;
	scanf("%d",&tt);
	for(int tc=1;tc<=tt;++tc){
		ans=INF;
		scanf("%d%d",&N,&L);
		for(int nc=0;nc<N;++nc){
			scanf("%s",str);
			cable[nc]=strtobin(str);
			//printf("%s:%lld\n",str,cable[nc]);
		}
		for(int nc=0;nc<N;++nc){
			scanf("%s",str);
			device[nc]=strtobin(str);
			//printf("%s:%lld\n",str,device[nc]);
		}
		qsort(device,N,sizeof(device[0]),icmp);
		/*
		for(int nc=0;nc<N;++nc){
			printf("%lld ", device[nc]);
		}
		putchar('\n');
		*/
		for(int i=0;i<N;++i){
			//match device[0] with cable[1];
			int mask=device[0]^cable[i];
			if(checkok(mask)){
				//printf("maskok:%d\n",mask);
				int temp=countbin(mask);
				ans=std::min(ans,temp);
			}
		}
		if(INF==ans){
			printf("Case #%d: NOT POSSIBLE\n",tc);
		}else{
			printf("Case #%d: %d\n",tc,ans);
		}
	}
	return 0;
}
