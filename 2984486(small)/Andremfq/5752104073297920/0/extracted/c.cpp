#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <time.h>
using namespace std;

int main()
{
	int teste;
	scanf("%d",&teste);
	srand(time(NULL));
	for(int t=1;t<=teste;t++)
	{
		int n;
		int qtd=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			int a;
			scanf("%d",&a);
			//printf("%d\n",a);
			if(a==i) qtd++;
		}
		if(qtd<3)	
		{
			if(rand()%2)	printf("Case #%d: BAD\n",t);
			else printf("Case #%d: GOOD\n",t); 
		}
		else printf("Case #%d: GOOD\n",t);
	}
	return 0;
}
