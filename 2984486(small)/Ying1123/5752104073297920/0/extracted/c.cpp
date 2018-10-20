#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <ctime>
using namespace std;

int a[1100];
int n;
int f[100];

int work()
{
	int sum = 0;
for (int i =1; i <= 1000; ++i)	
{
	scanf("%d", &a[i]);
	if (a[i] < i) ++sum;
}
if (sum < 480) printf("Bad\n"); else printf("GOOD\n");

}

int main() {
	for (int i = 0; i < 120; ++i)
	{
	printf("Case #%d: ", i + 1);
		work();
	}
	return 0;
}
