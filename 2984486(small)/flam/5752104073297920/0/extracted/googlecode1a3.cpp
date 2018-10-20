#include<iostream>
#include<fstream>
#include <stdlib.h>
#include <stdio.h>
#include<ctime>
using namespace std;

int main()
{
	 srand(time(NULL));
	freopen("test6.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int testCases;
	scanf("%d", &testCases);
	for (int a=0; a<testCases; a++)
	{
		int numbers; 
		cin >> numbers;
		int aa=0;
		for (int b=0; b<numbers; b++)
		{
			int dd;
			cin >> dd;
			if (b<numbers/2&&dd>numbers/2) aa++;

		}
		printf("Case #%d: ",a+1);
	//	int aa=rand()%2;
		
		if (aa%2==0) printf("GOOD\n");
		else printf("BAD\n");
		//cout << aa << endl;

	}

}