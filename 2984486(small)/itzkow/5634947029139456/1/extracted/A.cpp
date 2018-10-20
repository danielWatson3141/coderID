#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef long long LL;


ifstream fin ("C:\\CodeJam\\2014\\1A\\A\\A-large.in");
ofstream fout ("C:\\CodeJam\\2014\\1A\\A\\A-large.out");

int testCase = 0;

/*

who are you stop looking i dont like you

for (int i = 0; i < N; i++)
for (int j = 0; j < N; j++)
for (int k = 0; k < N; k++)

std::sort(A, A + N, std::less<int>());

vector.erase(vector.begin()+i);

*/

string A[150];
string B[150];



void Solve()
{

	int N,L;

	fin>>N>>L;

	
	
	for (int i = 0; i < N; i++) {
		fin>>A[i];
	}
	for (int i = 0; i < N; i++) {
		fin>>B[i];
	}

	
	//A[0]
	int minSuc = -1;

	for (int i = 0; i < N; i++) {

		bool suc = true;


		for (int j = 0; j < N; j++) {
			
			bool found = false;
			for (int k = 0; k < N; k++) {
				bool eq = true;
				for (int l = 0; l < L; l++) {
					if (A[0][l] == B[i][l]) {
						if (A[j][l] != B[k][l]) {
							eq = false;
							break;
						}
					} else {
						if (A[j][l] == B[k][l]) {
							eq = false;
							break;
						}
					}
				}
				if(eq)
					found = true;

			}

			if(!found)
				suc = false;


		}
		if(suc) {

			int sum = 0;
			for (int l = 0; l < L; l++) {
				if(A[0][l]!=B[i][l])
					sum++;
			}

			if (minSuc == -1)
				minSuc = sum;
			else
				minSuc = min(minSuc, sum);
		}

	}

	if (minSuc == -1)
		fout << "Case #" << testCase << ": "<<"NOT POSSIBLE"<<endl;
	else
		fout << "Case #" << testCase << ": "<<minSuc<<endl;


	//fout << "Case #" << testCase << ": "<<"Yes"<<endl;

}




void main()
{

	fout.precision(15);
	cout.precision(15);
	

	int TestCases = 0;
	fin>>TestCases;

	for (testCase = 1; testCase <= TestCases; testCase++) {
		
		Solve();
		if (testCase == 1+TestCases/20) {
			cout<<"5%"<<endl;
		} else if (testCase == 1+TestCases/4) {
			cout<<"25%"<<endl;
		} else if (testCase == 1+2*TestCases/4) {
			cout<<"50%"<<endl;
		} else if (testCase == 1+3*TestCases/4) {
			cout<<"75%"<<endl;
		}

	}

	cout<<"100%"<<endl;
	cout<<"finished"<<endl;
	getchar();

}



