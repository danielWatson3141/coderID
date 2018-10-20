// Charging.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include "iostream"
#include "fstream"
#include <sstream>
#include "TestCase.h"

int _tmain(int argc, _TCHAR* argv[])
{
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("log.txt", "w", stderr);
	
	int nTestCases;
	scanf("%d", &nTestCases);
	

	for(int i = 0; i < nTestCases; i++)
	{
		TestCase *t = new TestCase();
		int res = t->solve();
		if(-1 == res)
			printf("Case #%d: NOT POSSIBLE\n", i+1);
		else
			printf("Case #%d: %d\n", i+1 ,res);
	}

	return 0;
}


