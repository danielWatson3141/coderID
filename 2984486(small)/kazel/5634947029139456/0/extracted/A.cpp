#include "cstdio"
#include "algorithm"
#include "string"

int N,L;
std::string outlet[150];
std::string devices[150];
char input[40];

bool check()
{
	std::sort(outlet,outlet+N);
	std::sort(devices,devices+N);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<L;j++)
		{
			if(outlet[i][j] != devices[i][j]) return false;
		}
	}
	return true;
}

void switchAt(int l)
{
		for(int i=0;i<N;i++)
	{
		if(outlet[i][l] == '0') outlet[i][l] = '1';
		else outlet[i][l] = '0';
	}
}

int min(int a, int b)
{
	if (a > b) return b;
	return a;
}

int foo(int ptr, int cnt)
{
	if(check()) return cnt;

	if(ptr == L) return 400;

	int c1 = foo(ptr+1,cnt);

	switchAt(ptr);
	int c2 = foo(ptr+1,cnt+1);
	switchAt(ptr);
	
	return min(c1,c2);
}

int main()
{
	int T;

	scanf("%d",&T);

	for(int testcase = 1; testcase <= T; testcase++)
	{
		scanf("%d %d",&N, &L);
		for(int n=0;n<N;n++)
		{
			scanf("%s", input);
			outlet[n] = input;
		}
				for(int n=0;n<N;n++)
		{
			scanf("%s", input);
			devices[n] = input;
		}

		int out = foo(0,0);

		printf("Case #%d: ", testcase);
		if(out == 400)
		{
			printf("NOT POSSIBLE\n");
		}
		else
		{
			printf("%d\n", out);
		}
	}
}