#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>

using namespace std;

int bin2dec(string& bin)
{
	int n = 0;
	for(string::iterator it = bin.begin(); it!=bin.end(); it++)
	{
		n<<=1;
		n|= *it == '1' ? 1:0;
	}
	return n;
}

int countbits(int n)
{
	int b = 0;
	while(n)
	{
		b+=n&1;
		n/=2;
	}
	return b;
}

void solve_case()
{
	int N, L;
	string tmp;
	
	scanf("%d %d", &N, &L);
	int outlets[N], devices[N];
	for(int i=0;i<N;i++)
	{
		cin >> tmp;
		outlets[i] = bin2dec(tmp);
	}
	for(int i=0;i<N;i++)
	{
		cin >> tmp;
		devices[i] = bin2dec(tmp);
	}
	
	sort(devices, devices+N);
	
	int solution = -1;
	
	for(int i=0;i<N;i++)
	{
		int xorr = devices[0] ^ outlets[i];
		
		int results[N];
		for(int j=0;j<N;j++)
		{
			results[j] = outlets[j] ^ xorr;
		}
		sort(results, results+N);
		
		if(memcmp(devices, results, sizeof(int)*N)==0)
		{
			int bits = countbits(xorr);
			if(solution == -1 || bits<solution)
				solution = bits;
		}
	}
		
	if(solution==-1)
		printf("NOT POSSIBLE");
	else
		printf("%d", solution);
	
	return;
}


int main()
{
	int t;
	scanf("%d", &t);
	for(int cn=1;cn<=t;cn++)
	{
		printf("Case #%d: ", cn);
		solve_case();
		printf("\n");
	}
}
