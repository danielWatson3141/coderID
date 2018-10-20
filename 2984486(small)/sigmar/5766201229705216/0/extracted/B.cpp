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
//#include <NTL/ZZ.h>
using namespace std;
//using namespace NTL;
static const double EPS = 1e-8;
typedef long long ll;
typedef unsigned long long ull;
typedef complex <double> pt;
typedef complex <ll> pti;

int memod[1010][1010];
int memo[1010][1010];

int del_rec(int N, int root, int parent, vector <vector <int> > &edge) {
	if(edge[root].size()==1 && edge[root][0]==parent) return 1;
	if(memod[root][parent]>=0) return memod[root][parent];
	int ret=1;
	for(int i=0; i<(int)edge[root].size(); i++) {
		int nn=edge[root][i];
		if(nn==parent) continue;
		ret+=del_rec(N, nn, root, edge);
	}
	memod[root][parent]=ret;
	return ret;
}

int rec(int N, int root, int parent, vector <vector <int> > &edge) {
	if(edge[root].size()==1 && edge[root][0]==parent) return 0;
	if(memo[root][parent]>=0) return memo[root][parent];
	vector <pair <int, pair <int, int> > > cost;
	for(int i=0; i<(int)edge[root].size(); i++) {
		int nn=edge[root][i];
		if(nn==parent) continue;
		int dc=del_rec(N, nn, root, edge);
		int c=rec(N, nn, root, edge);
		cost.push_back(pair <int, pair <int, int> >(c-dc, pair <int, int>(dc, c)));
	}
	assert(!cost.empty());
	sort(cost.begin(), cost.end());
	int tcost=0;
	if(cost.size()==1) {
		tcost=cost[0].second.first;
	} else {
		tcost=cost[0].second.second+cost[1].second.second;
		for(int i=2; i<(int)cost.size(); i++) tcost+=cost[i].second.first;
	}
	memo[root][parent]=tcost;
	return tcost;
}

int solve(int N, vector <int> &X, vector <int> &Y) {
	int res=N;
	vector <vector <int> > edge(N);

	for(int i=0; i<N-1; i++) {
		edge[X[i]].push_back(Y[i]);
		edge[Y[i]].push_back(X[i]);
	}

	for(int croot=0; croot<N; croot++) {
		res=min(res, rec(N, croot, N, edge));
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
		int N;
		ifs >> N;
		vector <int> X(N-1), Y(N-1);
		for(int i=0; i<N-1; i++) {
			ifs >> X[i] >> Y[i];
			X[i]--; Y[i]--;
		}
		memset(memo, -1, sizeof(memo));
		memset(memod, -1, sizeof(memod));
		int res=solve(N, X, Y);
		ofs << "Case #" << testnum << ": ";
		ofs << res << endl;
	}
}

//Powered by NTL-5.5.2 (http://www.shoup.net/ntl/)