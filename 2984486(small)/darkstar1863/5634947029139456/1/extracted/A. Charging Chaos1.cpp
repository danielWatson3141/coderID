
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <limits>
using namespace std;

// Types
typedef long long int64;
typedef unsigned long long uint64;
typedef pair<int,int> ipair;
const double pi=acos(-1.0);
const double eps=1e-11;

// Generic
#define SIZE(X) ((int)(X.size()))
#define LENGTH(X) ((int)(X.length()))
#define MP(X,Y) make_pair(X,Y)
#define FORD(i, a, b) for(int i=(a); i<(b); i++)
#define FORS(i, a) for(int i=(0); i<SIZE(a); i++)
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
template<class T> inline T sqr(T x){return x*x;}

// Bit manipulation
template<class T> void setbit(T& v, int position)    { v |= (T)1 << position; }
template<class T> void unsetbit(T& v, int position)  { v &= ~((T)1 << position); }
template<class T> void togglebit(T& v, int position) { v ^= (T)1 << position; }
template<class T> bool isbit(T v, int position) { return (v & ((T)1 << position)) != 0; }
template<class T> inline int countbit(T n){return (n==0)?0:(1+countbit(n&(n-1)));}

// Input / Output
string ReadToEndLine(istream& s) { string sLine; getline(s, sLine); return sLine; }
char gStr[1024];
// sprintf_s(gStr, "%d", );

struct Runner
{
	Runner(istream& in, ostream& out) : mIn(in), mOut(out), mCase(0) {}
	void RunAll();
	void Run();
	istream& mIn; ostream& mOut;
	size_t mCase;
};

void Runner::RunAll()
{
    size_t caseCount;
    mIn >> caseCount;
    ReadToEndLine(mIn);
    for(size_t c=0; c<caseCount; ++c)
    {
        mCase = c + 1;
		cout << "Case " << mCase << ": ... ";
        Run();
		cout << "done" << endl;
    }
}

void Runner::Run()
{
	int N, L;
	mIn >> N >> L;

	vector<string> S(N), D(N);
	FORS(i, S)
		mIn >> S[i];
	FORS(i, D)
		mIn >> D[i];
	sort(D.begin(), D.end());
	ReadToEndLine(mIn);

	int res=100000;
	FORD(xS, 0, N)
	{
		FORD(xD, 0, N)
		{
			int countb = 0;
			string pos(L, '0');
			FORD(l, 0, L)
			{
				if(S[xS][l] != D[xD][l])
				{
					pos[l] = '1';
					++countb;
				}
			}

			//check
			vector<string> C(S);
			FORD(b, 0, L)
			{
				if(pos[b] == '0')
					continue;
				FORD(i, 0, N)
				{
					C[i][b] = C[i][b] == '0' ? '1' : '0';
				}
			}
			sort(C.begin(), C.end());
			if(D == C)
				res = min(res, countb);
		}
	}

	mOut << "Case #" << mCase << ": ";
	if(res == 100000)
		mOut << "NOT POSSIBLE";
	else
		mOut << res;
	mOut << endl;
}

#ifdef LOCAL // Local testing. Nothing solution related

bool checkCase(const vector<string>& ok, const vector<string>& my)
{
	bool bSuccess = ok.size() == my.size();
	if(bSuccess)
	{
		for(size_t i=0; i<ok.size(); ++i)
			if(ok[i] != my[i])
				bSuccess = false;
	}

	cout << (bSuccess ? "Passed" : "Failed") << endl;
	if(!bSuccess)
	{
		bool newLine = ok.size() != 1 || my.size() != 1;
		cout << "expected: "; if(newLine) { cout << endl; }
		for(size_t i=0; i<ok.size(); ++i) { cout << ok[i] << endl; }
		cout << "actual  : "; if(newLine) { cout << endl; }
		for(size_t i=0; i<my.size(); ++i) { cout << my[i] << endl; }
	}
	return bSuccess;
}

vector<string> readFile(istream& s)
{
	vector<string> res; string str;
	while (s && !s.eof())
	{
		getline(s, str);
		if(str.find("--case") == 0)
			break;
		res.push_back(str);
	}
	if(res.size() > 0 && res.back().empty())
		res.resize(res.size()-1);
	return res;
}

vector<string> readFile(const string str)
{
	istringstream ssStr(str);
	return readFile(ssStr);
}

string joinLines(const vector<string>& lines)
{
	ostringstream res;
	for(size_t i=0; i<lines.size(); ++i)
		res << lines[i] << endl;
	return res.str();
}

void main(int argc, char *argv[])
{
	string pathToFiles = __FILE__;
	pathToFiles.resize(pathToFiles.size() - 4);
	string pathToInput = pathToFiles + ".in.txt";
	if(argc >= 2)
	{
		pathToFiles = pathToInput = argv[1];
	}

	ifstream sIn(pathToInput);
	ifstream sOk(pathToFiles + ".ok.txt");
	ofstream sMy(pathToFiles + ".my.txt");

	// Only one test case supported for this contest
	vector<string> aIn(readFile(sIn)), aOk(readFile(sOk));
	istringstream ssIn(joinLines(aIn));
	ostringstream ssMy;

	Runner runner(ssIn, ssMy);
	runner.RunAll();

	vector<string> aMy(readFile(ssMy.str()));
	sMy << joinLines(aMy).c_str();
	if(sOk.is_open())
	{
		cout << "Tests: ";
		bool bPassed = checkCase(aOk, aMy);
	}
	else
	{
		cout << "Done" << endl;
	}

	getchar();
}
#endif	// LOCAL
