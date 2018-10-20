// GCJ2014R2.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

#pragma warning(disable:4996)

using namespace std;

int T;
int A,B;
int N;
int edge[1024][1024];
int num[1024];
int del[1024];
int tot[1024];

void init()
{
	cin >> T;
}

void check(int root, int child) 
{
	tot[child] = 1;

	int max1 = 0;
	int max2 = 0;
	for (int i=0; i<num[child]; i++) {
		int next = edge[child][i];
		if (next == root) {
			continue;
		}
		check(child, next);
		tot[child] += tot[next];
		int rem = tot[next] - del[next];
		if (rem > max1) {
			max2 = max1;
			max1 = rem;
		} else if (rem > max2) {
			max2 = rem;
		}
	}
	if (num[child] == 2) {
		del[child] = tot[child] - 1;
		return;
	}
	del[child] = tot[child] - 1 - max1 - max2;
}

int solve()
{
	int ret = N;
	for (int r=1; r<=N; r++) {
		
		int max1 = 0;
		int max2 = 0;
		memset(del, 0, sizeof(del));
		memset(tot, 0, sizeof(tot));		
		for (int i=0; i<num[r]; i++) {
			int next = edge[r][i];
			check(r, next);
			
			tot[r] += tot[next];
			int rem = tot[next] - del[next];
			if (rem > max1) {
				max2 = max1;
				max1 = rem;
			} else if (rem > max2) {
				max2 = rem;
			}
		}
		if (num[r] == 1) {
			del[r] = tot[r];		
		} else {
			del[r] = tot[r] - max1 - max2;
		}
		if (del[r] < ret) {
			ret = del[r];
		}
		/*cout << "root: " << r << " " << del[r] << endl;
		for (int i = 1; i<=N; i++)
		{
			cout << tot[i] << "," << del[i] << endl;
		}*/
	}
	return ret;
}

void work()
{
	for (int ca=1; ca<=T; ca++)
	{
		cin >> N;
		memset(num, 0, sizeof(num));
		cout << "Case #" << ca << ": ";
		for (int i=0; i<N-1; i++) {
			cin >> A >> B;
			edge[A][num[A]++] = B;
			edge[B][num[B]++] = A;
		}
		
		cout << solve() << endl;
	}
}


int main()
{
	freopen("C:\\Users\\yuazh\\Downloads\\B--small-attempt1.in", "r", stdin);
	freopen("C:\\Users\\yuazh\\Downloads\\B--small-attempt1.out", "w", stdout);
	init();
	work();

	return 0;
}

