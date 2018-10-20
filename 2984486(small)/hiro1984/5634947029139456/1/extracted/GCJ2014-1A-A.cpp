#include <cstring>
#include <string>
#include <fstream>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>

using namespace std;

#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz size()
#define rep(i,s,e) for (int i = int(s); i < int(e); i++)
#define repit(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair

typedef stringstream ss;
typedef long long ll;
typedef long double ld;

const double PI = 2 * acos(0);
const double eps = 1e-9;

int ndev;
int length;
vector<string> flow;
vector<string> device;

class Difference {
public:
	Difference() : n(0), pos(vector<int>()) {}
	int n;
	vector<int> pos;
	bool operator==(Difference& dif) {
		if( n == 0 && dif.n == 0 ) return true;
		return ( n == dif.n && pos == dif.pos );
	}
};

bool allMatch( vector<bool> match ) {
	repit(it, match) {
		if( (*it) == false ) return false;
	}
	return true;
}

string getAnswer()
{
	vector< vector< Difference > > dif;
	dif.resize(ndev);
	rep(i, 0, ndev) {
		dif[i].resize(ndev);
	}
	rep(i, 0, ndev) {
		rep(j, 0, ndev) {
			rep(k, 0, length) {
				if( flow[j][k] != device[i][k]) {
					dif[i][j].n++;
					dif[i][j].pos.pb(k);
				}
			}
			/*
			cout << "i=" << i << ", j=" << j << ": n=" << dif[i][j].n << ", pos=";
			if( !dif[i][j].pos.empty() ) {
				rep( n, 0, dif[i][j].n ) {
					cout << dif[i][j].pos[n] << ", ";
				}
			}
			cout << endl;
			*/
		}
	}

	int ans = 10000;
	rep(n, 0, ndev) {
		Difference tmplate = dif[0][n];
		vector<bool> match;
		match.resize(ndev - 1, false);
		rep(i, 1, ndev) {
			rep(j, 0, ndev) {
				if( j == n ) continue;
				if( tmplate == dif[i][j] )	match[i-1] = true;
			}
		}
		if( allMatch( match ) ) {
			ans = min( ans, tmplate.n );
		}
	}

	if( ans == 10000 ) return "NOT POSSIBLE";
	ss sstmp;
	sstmp << ans;
	return sstmp.str();
}

int main(int argc, char *args[]) {

	std::ifstream fin;
	std::ofstream fout;
    if (argc == 2 && strcmp(args[1], "small") == 0) {
        fin.open("A-small-attempt0.in");
        fout.open("A-small-attempt0.out");
    }
    else if (argc == 2 && strcmp(args[1], "large") == 0) {
    	fin.open("A-large.in");
    	fout.open("A-large.out");
    } else if  (argc == 2 && strcmp(args[1], "test") == 0) {
    	fin.open("test.in");
    	fout.open("test.out");
    }
    if(fin.fail()) {
    	cerr << "File do not exist.\n";
    	exit(0);
   	}

    string line;
    getline( fin, line );
    int N = stoi(line);
    vector<string> results;
    results.resize(N);

    rep(n, 0, N) {
    	cout << "Case #" << n + 1 << endl;
    	ss ssbuf;
    	string stmp;
    	getline( fin, line );
    	ssbuf << line;
    	ssbuf >> ndev >> length;

    	ssbuf.str(""); ssbuf.clear();
    	getline( fin, line );
    	ssbuf << line;
    	flow.clear();
    	rep(i, 0, ndev) {
    		ssbuf >> stmp;
    		flow.pb( stmp );
    	}

    	ssbuf.str(""); ssbuf.clear();
    	getline( fin, line );
    	ssbuf << line;
    	device.clear();
    	rep(i, 0, ndev) {
    	    ssbuf >> stmp;
    	    device.pb( stmp );
    	}

    	results[n] = getAnswer();
    }

    rep(n, 0, N) {
        fout << "Case #" << n+1 << ": ";
        fout << results[n];
        fout << endl;
    }

    fin.close();
    fout.close();
    return 0;
}
