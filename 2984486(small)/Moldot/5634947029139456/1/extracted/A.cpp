#include <cstdio>

long long conv(char *c)
{
	long long ans = 0;
	for(int i=0;c[i]!='\0';i++)
	{
		ans = ans*2;
		ans += (c[i]=='1');
	}
	return ans;
}

int cnt(long long key)
{
	long long i;
	int c;
	for(i=1, c=0 ;i<(1LL<<43);i<<=1) c += ((key&i)!=0);
	return c;
}

int sol(int cse)
{
	char inp[100];
	long long sw[200], dv[200], tm[200];
	long long key;
	int n,l;
	long long i,j,k,c;
	long long best = (1LL<<43)-1;
	scanf("%d %d",&n,&l);
	for(i=0;i<n;i++) {
		scanf("%s",inp);
		sw[i] = conv(inp);
		//printf("%lld ", sw[i]);
	}
	for(i=0;i<n;i++) {
		scanf("%s",inp);
		dv[i] = conv(inp);
		//printf("%lld ", dv[i]);
	}
	for(i=0;i<n;i++) {
		key = (sw[0] ^ dv[i]);
		c = 0;
		for(j=0;j<n;j++) for(k=0;k<n;k++) if((sw[j]^key)==dv[k]) c++;
		//printf("%lld\n",c);
		if (c==n and cnt(key) < cnt(best)) best = key;
	}
	if(best==(1LL<<43)-1) printf("Case #%d: NOT POSSIBLE\n", cse);
	else printf("Case #%d: %d\n", cse, cnt(best));
	return 0;
}

int main()
{
	int t;
	//char c[] = {'0', '1', '1', '0', '\0'};
	//printf("%lld", conv(c));
	//printf("%d", cnt(32984723874L));
	scanf("%d",&t);
	//printf("%lld\n",(1LL<<t));
	for(int i = 1; i <= t; sol(i), i++);
}