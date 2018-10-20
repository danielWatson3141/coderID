#include <iostream>
#include <cstdio>
using namespace std;

int t;
int n;
int pom;

int main()
{
	scanf("%d", &t);
	for (int h=1; h<=t; h++)
	{
		scanf("%d", &n);
		for (int i=1; i<=n; i++)
		{
			scanf("%d", &pom);
		}
		if (h%2)
		printf("Case #%d: BAD\n", h);
		else
		printf("Case #%d: GOOD\n", h);
	}
	return 0;
}
