// GCJ2014R2.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#pragma warning(disable:4996)

using namespace std;

int T;
int N,L;
string s[160];
string t[160];
string fa[160];

void init()
{
	cin >> T;
}


bool cmp(const string &A, const string &B)
{
	for (int i=0; i<L; i++) {
		if (A[i] != B[i]) {
			return A[i] < B[i];
		}
	}
	return false;
}

int solve()
{
	int ret = L+1;
	int ch[64];
	int sol = 0;
	sort(s, s+N, cmp);
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			sol = 0;
			for (int k=0; k<L; k++) {
				ch[k] = (s[i][k] == t[j][k]) ? 0 : 1;
				sol += ch[k];
			}
			for (int k=0; k<N; k++) {
				fa[k] = t[k];
				for (int w=0; w<L; w++) {
					if (ch[w]) {
						fa[k][w] = ((fa[k][w] - '0') ^ 1) + '0';
					}
				}
			}
			sort(fa, fa+N, cmp);
			bool ok = true;
			for (int k=0; k<N; k++) {
				if (fa[k] != s[k]) {
					ok = false;
					break;
				}
			}
			if (ok) {
				if (sol < ret) {
					ret = sol;
				}
			}
		}
	}
	return ret;
}

void work()
{
	for (int ca=1; ca<=T; ca++)
	{
		cin >> N >> L;
		for (int i=0; i<N; i++) {
			cin >> s[i];
		}
		for (int i=0; i<N; i++) {
			cin >> t[i];
		}
		
		cout << "Case #" << ca << ": ";		
		int ret = solve();
		if (ret <= L) {
			cout << ret << endl;
		} else {
			cout << "NOT POSSIBLE" << endl;
		}			 
	}
}


int main()
{
	freopen("C:\\Users\\yuazh\\Downloads\\A--small-attempt0.in", "r", stdin);
	freopen("C:\\Users\\yuazh\\Downloads\\A--small-attempt0.out", "w", stdout);
	init();
	work();

	return 0;
}

