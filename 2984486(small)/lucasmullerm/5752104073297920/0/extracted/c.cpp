#include <bits/stdc++.h>
using namespace std;

int tree[1001];
int n;

void init(){
	for (int i = 0; i <= n; ++i)
	{
		tree[i] = 0;
	}
}

void update(int i){
	while (i <= n)
	{
		tree[i]++;
		i += (i & -i);
	}
}

int read(int i){
	int sum = 0;
	while (i >= 1)
	{
		sum += tree[i];
		i -= (i & -i);
	}
	return sum;
}

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d", &T);
	int x;
	for (int tt = 1; tt <= T; ++tt)
	{
		scanf("%d", &n);
		int inv = 0;
		init();
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d", &x);
			update(x+1);
			inv += read(n) - read(x+1);
		}
		int max = n*(n - 1) / 2;
		float mid = (float) max / 2;
		if(inv < mid){
			printf("Case #%d: BAD\n", tt);
		}
		else{
			printf("Case #%d: GOOD\n", tt);
		}
	}
	return 0;
}