// Charging Chaos.cpp : 定义控制台应用程序的入口点。
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <queue>
using namespace std;

typedef unsigned long long ull;
void solve()
{
	ull src[150];
	ull des[150];

	int n, l;
	cin >> n >> l;

	set<ull> setDes;

	for(int i = 0; i < 2*n; ++i)
	{
		char str[41];
		cin >> str;

		ull integer = 0;
		for(int b = l - 1; b >= 0; --b)
		{
			if(str[l - b - 1] == '1')
			{
				integer += (ull)1 << b;
			}
		}

		if(i < n) src[i] = integer;
		else
		{
			des[i-n] = integer;
			setDes.insert( integer );
		}
	}

	ull des1 = des[0];

	int minFlipTime = 100;
	for(int i = 0; i < n; ++i)
	{
		ull xor = des1 ^ src[i];
		ull cpy = xor;
		int flipTime = 0;
		while( cpy )
		{
			flipTime++;
			cpy &= cpy - 1;
		}

		if( minFlipTime <= flipTime ) continue;
		
		int j = 0;
		for(; j < n; ++j)
		{
			if( j != i )
			{
				ull res = src[j] ^ xor;
				if( setDes.find(res) == setDes.end() ) break;
			}
		}

		if(j == n)
		{
			minFlipTime = flipTime;
		}
	}

	if(minFlipTime == 100)
	cout << "NOT POSSIBLE"<<endl;
	else
	cout <<  minFlipTime << endl;
}

int main(int argc, char* argv[])
{	
	FILE* fp;
	freopen_s(&fp, "A-small-attempt0.in", "r", stdin );
	freopen_s(&fp, "A-small-attempt0.out", "w", stdout );

	int n;

	cin >> n;
	
	for(int caseN = 1; caseN <= n; ++caseN)
	{
		printf_s("Case #%d: ", caseN);

		solve();
	}
}

