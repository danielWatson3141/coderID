#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <list>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <numeric>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <iterator>
#include <complex>
#include <stack>
#include <queue>
#include <ctime>
#include <cassert>
#include <intrin.h>
//#include <NTL/ZZ.h>
using namespace std;
//using namespace NTL;
static const double EPS = 1e-8;
typedef long long ll;
typedef unsigned long long ull;
typedef complex <double> pt;
typedef complex <ll> pti;

inline int popcount(unsigned long long x) {
	x=(x&0x5555555555555555ULL)+((x>>1)&0x5555555555555555ULL);
	x=(x&0x3333333333333333ULL)+((x>>2)&0x3333333333333333ULL);
	x=(x&0x0f0f0f0f0f0f0f0fULL)+((x>>4)&0x0f0f0f0f0f0f0f0fULL);
	x=(x&0x00ff00ff00ff00ffULL)+((x>>8)&0x00ff00ff00ff00ffULL);
	x=(x&0x0000ffff0000ffffULL)+((x>>16)&0x0000ffff0000ffffULL);
	return (x&0x00000000ffffffffULL)+((x>>32)&0x00000000ffffffffULL);
}

int solve(int N, int L, vector <string> &outlet, vector <string> &device) {
	int res=L+1;

	vector <ll> out(N), dev(N);
	for(int i=0; i<N; i++) {
		for(int j=0; j<L; j++) {
			if(outlet[i][j]=='1') out[i]|=(1LL<<j);
			if(device[i][j]=='1') dev[i]|=(1LL<<j);
		}
	}

	for(int i=0; i<N; i++) {
		ll diff=(out[0]^dev[i]);
		bool ok2=true;
		for(int j=0; j<N; j++) {
			bool ok=false;
			for(int k=0; k<N; k++) {
				if((out[j]^diff)==dev[k]) {
					ok=true;
					break;
				}
			}
			if(!ok) {
				ok2=false;
				break;
			}
		}
		if(ok2) res=min(res, popcount(diff));
	}

	return res;
}

int main() {
	int practice=0;
	string prb[12];
	const string difficulty[2][2]={{"-small-attempt.in", "-large.in"}, {"-small-practice.in", "-large-practice.in"}};
	const string extension="";
	//const string extension=".txt";

	char key;
	while(1) {
		for(int i=0; i<12; i++) {
			prb[i].assign(1, 'A'+i/2);
			prb[i]+=difficulty[practice][i%2];
			prb[i]+=extension;
			cout << (char)(i%2?('A'+i/2):('a'+i/2)) << ". " << prb[i] << endl;
		}
		cout << "p. " << (practice?"change to practice mode.":"change to match mode.") << endl;

		do {
			cout << "Choose the input file." << endl;
			cin >> key;
		} while(!('a'<=key && key<'a'+6) && !('A'<=key && key<'A'+6) && key!='p');
		if(key!='p') break;
		practice^=1;
		system("cls");
	}

	int index, cap;
	if(key>='a') { index=(key-'a')*2; cap=0; }
	else { index=(key-'A')*2+1; cap=1; }
	string filename=prb[index];

	if(!cap && !practice) {
		do {
			cout << "Choose number of attempt times." << endl;
			cin >> key;
		} while(key<'0' || '9'<key);
		filename.insert(15, 1, key);
	}

	cout << "Filename is " << filename << endl;
	ifstream ifs(filename.c_str());

	ofstream ofs("output.txt");

	int testcase;
	ifs >> testcase; ifs.ignore();
	for(int testnum=1; testnum<=testcase; testnum++) {
		int N, L;
		ifs >> N >> L;
		vector <string> outlet(N), device(N);
		for (int i=0; i<N; i++) ifs >> outlet[i];
		for (int i=0; i<N; i++) ifs >> device[i];
		int res=solve(N, L, outlet, device);
		ofs << "Case #" << testnum << ": ";
		if(res>L) ofs << "NOT POSSIBLE" << endl;
		else ofs << res << endl;
	}
}

//Powered by NTL-5.5.2 (http://www.shoup.net/ntl/)