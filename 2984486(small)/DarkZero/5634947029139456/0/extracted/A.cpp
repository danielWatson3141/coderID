#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<map>
using namespace std;

typedef long long LL;
int t;
int n,l;
char seq[3][200][60];
map<LL, int> h;
int mark[60]={0};
const int INF= 1<<29;
int srchmin=INF;

LL parse(int num ,int x)
{
	int i;
	LL ret=0;
	for(i=0;i<l;i++)
	{
		ret = ret*2 + (seq[num][x][i] - '0');
	}
	return ret;
}


bool check()
{
	int i ;
    for(i=1;i<=n;i++)
	{
		LL number2 = parse(2,i);
		h[number2] = 1;
	}
	for(i=1;i<=n;i++)
	{
		LL number1 = parse(1,i);
		if(h[number1] == 0)
		{
			return false;
		}
	}
	return true;
}

void flip(int i)
{
	int j;
	for(j=1;j<=n;j++)
	{
		seq[1][j][i] = '1'+'0' -seq[1][j][i]; 
	}
	return;
}

void srch(int now, int times)
{
	if(now==l)
	{
		if( check() )
		{
			srchmin = min(srchmin, times);
		}
		return;
	}
	if(mark[now] == 0)
	{
		srch(now+1, times);
	}
	
	srch(now+1, times);
	if(times+1 < srchmin)
	{
		flip(now);
		srch(now+1, times+1);
		flip(now);
	}
	
	return ;
}

void init()
{
//	memset(number, 0, sizeof(number));
	memset(seq, 0, sizeof(seq));
	h.clear();
	memset(mark,0,sizeof(mark));
	srchmin = INF;
	return ;
}

int main()
{
	freopen("A.in", "r", stdin);
	freopen("A1.txt", "w", stdout);
	scanf("%d", &t);
	int files;
	for(files=1;files<=t;files++)
	{
		init();
		scanf("%d %d", &n, &l);
		int i;
		for(i=1;i<=n;i++)
		{
			scanf("%s", seq[1][i]);
		}
		for(i=1;i<=n;i++)
		{
			scanf("%s", seq[2][i]);
		}
		
		int ans=0;
		int j;
		for(i=0;i<l;i++)
		{
			int num11=0, num12=0;
			for(j=1; j<=n;j++)
			{
				if(seq[1][j][i] == '1')
					num11++;
				if(seq[2][j][i] == '1')
					num12++;
			}
			
			if(num11==num12)
			{
				if(n%2==0 && num11 == n/2)
				{
					mark[i]=1;
				}
				continue;
			}
			else if(num11 + num12 == n)
			{
				ans++;
				flip(i);
			}
			else
			{
				ans=-1;
				break;
			}
		}
		
		printf("Case #%d: ", files);
		if(ans==-1)
		{
			printf("NOT POSSIBLE\n");
		}
		else 
		{
			srch(0, 0);
			if(srchmin==INF)
			{
				printf("NOT POSSIBLE\n");
			}
			else
			{
				printf("%d\n", ans+srchmin);
			}
		}
	}
	//system("pause");
	return 0;
}








