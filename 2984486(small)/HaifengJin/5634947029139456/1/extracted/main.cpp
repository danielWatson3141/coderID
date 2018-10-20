#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define MAX_SEQ_NUM 155
#define MAX_LEN 55
#define D(x) 

long long origin[MAX_SEQ_NUM];
long long des[MAX_SEQ_NUM];
long long temp_seq[MAX_SEQ_NUM];
int seq_num, seq_len;

long long convert(char *st)
{
	long long ret = 0;
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

void input()
{
	char temp[MAX_SEQ_NUM];
	scanf("%d%d", &seq_num, &seq_len);
	for (int i = 0; i < seq_num; i++)
	{
		scanf("%s", temp);
		origin[i] = convert(temp);
		D(printf("%lld\n", origin[i]);)
	}
	for (int i = 0; i < seq_num; i++)
	{
		scanf("%s", temp);
		des[i] = convert(temp);
	}
}

int count_bit(long long a)
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

int work()
{
	int ret = seq_len + 1;
	for (int i = 0; i < seq_num; i++)
	{
		long long key = des[0] ^ origin[i];
		D(printf("key=%lld\n", key);)
		for (int j = 0; j < seq_num; j++)
		{
			temp_seq[j] = origin[j] ^ key;
		}
		sort(temp_seq, temp_seq + seq_num);
		if (equal(temp_seq, temp_seq + seq_num, des))
		{
			ret = min(ret, count_bit(key));
		}
	}
	if (ret == seq_len + 1)
		return -1;
	return ret;
}

int main()
{
	int case_num;
	scanf("%d", &case_num);
	for (int i = 0; i < case_num; i++)
	{
		printf("Case #%d: ", i + 1);
		input();
		sort(des, des + seq_num);
		int ans = work();
		if (ans == -1)
			printf("NOT POSSIBLE\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}
