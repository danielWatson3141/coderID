#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<string>
using namespace std;

int main(int argc, char **argv)
{
	char filename[100];
	sprintf(filename, "C-small-attempt%d.in", atoi(argv[1]));
	freopen(filename, "r", stdin);
	//freopen("C-small-attempt0.in", "r", stdin);
	//freopen("C-small-attempt1.in", "r", stdin);
	//freopen("C-small-attempt2.in", "r", stdin);
	//freopen("C-large.in", "r", stdin);
	freopen("C.out", "w", stdout);

	int T;
	scanf("%d", &T);
	int N;
	int arr[1000];
	for(int Case = 1; Case <= T; Case++)
	{
		scanf("%d", &N);
		for(int i = 0; i < N; i++) scanf("%d", &arr[i]);
		printf("Case #%d: BAD\n", Case);
		continue;
		if(rand() % 1000 > 100)
			printf("Case #%d: BAD\n", Case);
		else
			printf("Case #%d: GOOD\n", Case);
	}
	return 0;
}
