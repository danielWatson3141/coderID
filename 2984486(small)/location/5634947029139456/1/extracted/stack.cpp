#include<stack>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
#include<cstring>
using namespace std;

vector<stack<int> > v(1001);
int main()
{
	int n,x,y;
	scanf("%d", &n);
	char a[6];
	while ( n-- )
	{
		scanf("%s",a);
		if ( strcmp(a,"PUSH") == 0 )
		{
			scanf("%d%d", &x, &y );
			v[x].push(y);
		}
		else
		{
			scanf("%d", &x);
			printf("%d\n",v[x].top());
			v[x].pop();
		}
	}
	return 0;
}
