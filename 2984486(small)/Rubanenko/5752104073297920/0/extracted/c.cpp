#pragma comment(linker, "/STACK:64000000")
#include <algorithm>
#include <memory.h>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <cassert>
#include <map>
#include <set>
#include <vector>
#include <queue>

using namespace std;
#define prev privet1
#define next privet2
#define y1 privet3
#define rank privet4
#define left privet5
#define right privet6
#define y0 privet7

const double pi = 3.141592653589793238;

void ensureLimit(long long n, long long l, long long r)
{
	assert(l <= n && n <= r);
}

const int magic = 6;


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tc;
	cin >> tc;
	for (int tcc = 1; tcc <= tc; tcc++) {
		printf("Case #%d: ", tcc);
		int n;
		int next[1111];
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> next[i];
			next[i]++;
		}
		int cycles = 0;
		bool used[1111] = {};
		for (int i = 1; i <= n; i++) {
			if (!used[i]) {
				int v = next[i];
				used[i] = true;
				cycles++;
				while (v != i) {
					used[v] = true;
					v = next[v];
				}
			}
		}
		if (cycles < magic) printf("BAD\n");
		else printf("GOOD\n");
		//printf("%d\n", cycles);
	}
}
