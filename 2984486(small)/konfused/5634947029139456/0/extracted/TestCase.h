#pragma once
#include <iostream>
using namespace std;
class TestCase
{
	int N,L;
	char ip[10][11],op[10][11];
public:
	TestCase(void);
	~TestCase(void);

	bool equals();
	int solve();
};

