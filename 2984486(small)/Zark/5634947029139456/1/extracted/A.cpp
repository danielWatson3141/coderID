#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <list>
#include <stack>
#include <algorithm>
#include <queue>
#include <map>
#include <cstdlib>
#include <set>
#include <string>
#include <cstring>
#include <memory>

#pragma comment(linker, "/STACK:104857600,104857600")

using namespace std;

//#define FILE_IO

class A
{
private:
	const static int MAX_NUM = 150;
	const static int MAX_LEN = 40;
	int caseNum, caseIndex;
	int num, len;
	long long sourceN[MAX_NUM];
	long long targetN[MAX_NUM];
	long long switchN[MAX_NUM];
	int result;
	
public:
	void Run();

private:
	void Input();
	void Do();
	void Output();
};

void A::Run()
{
	scanf("%d", &caseNum);
	for(caseIndex = 1; caseIndex <= caseNum; ++caseIndex)
	{
		Input();
		Do();
		Output();
	}
}

void A::Input()
{
	scanf("%d %d", &num, &len);
	for(int i = 0; i < num; ++i)
	{
		char line[MAX_LEN + 1];
		scanf("%s", line);
		long long tmpN = 0;
		for(int j = 0; j < len; ++j)
		{
			tmpN <<= 1;
			tmpN += line[j] - '0';
		}
		sourceN[i] = tmpN;
	}
	for(int i = 0; i < num; ++i)
	{
		char line[MAX_LEN + 1];
		scanf("%s", line);
		long long tmpN = 0;
		for(int j = 0; j < len; ++j)
		{
			tmpN <<= 1;
			tmpN += line[j] - '0';
		}
		targetN[i] = tmpN;
	}
}

void A::Do()
{
	sort(targetN, targetN + num);
	result = len + 1;
	for(int i = 0; i < num; ++i)
	{
		long long mask = sourceN[i] ^ targetN[0];
		for(int j = 0; j < num; ++j)
		{
			switchN[j] = sourceN[j] ^ mask;
		}
		sort(switchN, switchN + num);
		
		bool isFind = false;
		for(int j = 0; j < num; ++j)
		{
			if(switchN[j] != targetN[j])
			{
				isFind = true;
				break;
			}
		}
		
		if(!isFind)
		{
			int count = 0;
			for(int j = 0; j < len; ++j)
			{
				if(mask & (1 << j)) ++count;
			}
			result = min(result, count);
		}
		
	}
}

void A::Output()
{
	printf("Case #%d: ", caseIndex);
	if(result > len) printf("NOT POSSIBLE\n");
	else printf("%d\n", result);
}

A instance;
int main()
{
	#ifdef FILE_IO
	freopen("C:\\Users\\Administrator\\Desktop\\in.txt", "r", stdin);
	freopen("C:\\Users\\Administrator\\Desktop\\out.txt", "w", stdout);
	#endif

	instance.Run();
	return 0;
}
