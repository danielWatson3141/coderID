#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<queue>
#include<string>
#include<vector>
using namespace std;
#define vN 200
#define vE 100
#define LL long long
LL base[vN];
LL des[vN];
LL tseq[vN];
int seqn, seql;

LL fun(char *st)
{
	LL ret = 0;
	int len = strlen(st);
	for (int i = 0; i < len; i++)
	{
		ret <<= 1;
		if (st[i] == '1')
		{
			ret += 1;
		}
	}
	return ret;
}

int icbc(LL a)
{
	int ret = 0;
	while (a)
	{
		if (a & 1)
			ret++;
		a>>=1;
	}
	return ret;
}

int gao()
{
	int ret = seql + 1;
	for (int i = 0; i < seqn; i++)
	{
		LL key = des[0] ^ base[i];
		for (int j = 0; j < seqn; j++)
		{
			tseq[j] = base[j] ^ key;
		}
		sort(tseq, tseq + seqn);
		if (equal(tseq, tseq + seqn, des))
		{
			ret = min(ret, icbc(key));
		}
	}
	if (ret == seql + 1)
		return -1;
	return ret;
}

int main()
{
	freopen("dataB.in","r",stdin);
	freopen("dataB.out","w",stdout);
	int case_num;
	scanf("%d", &case_num);
	for (int i = 0; i < case_num; i++)
	{
		printf("Case #%d: ", i + 1);
		char temp[vN];
		scanf("%d%d", &seqn, &seql);
		for (int i = 0; i < seqn; i++)
		{
			scanf("%s", temp);
			base[i] = fun(temp);
		}
		for (int i = 0; i < seqn; i++)
		{
			scanf("%s", temp);
			des[i] = fun(temp);
		}
		sort(des, des + seqn);
		int ans = gao();
		if (ans == -1)
			printf("NOT POSSIBLE\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}
