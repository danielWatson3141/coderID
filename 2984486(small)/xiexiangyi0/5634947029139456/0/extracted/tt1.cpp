
#include <vector>
#include <list>
#include <unordered_map>
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
#include <fstream>
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


using namespace std;

bool turn_switch(vector<string> outlet, int i_start, int depth, int max, vector<string> & dev) {
    if(depth == max) {
	sort(outlet.begin(), outlet.end());
	for(int i=0; i<outlet.size(); i++) {
	    if(outlet[i] != dev[i]) {
		return false;
	    }
	}
	return true;
    }
    
    for(int i=i_start; i<outlet[0].size(); i++) {
	vector<string> tmp = outlet;
	for(int j=0; j<outlet.size(); j++) {


	    if(tmp[j][i] == '0') {
		tmp[j][i] = '1';
	    } else {
		tmp[j][i] = '0';
	    }

	}
	if(turn_switch(tmp, i+1, depth+1, max, dev)) {
	    return true;
	}
    }

    return false;


}

int main() {
	ifstream infile;
	infile.open("A-small-attempt2.in");
    ofstream outfile;
	outfile.open("A-small2222.out");

    int T;
    infile >> T;
    for(int i=0; i<T; i++) {
	int N, L;
	infile >> N >> L;
	vector<string> outlet;
	vector<string> dev;
	for(int j=0; j<N; j++) {
	    string dig_str;
	    infile >> dig_str;
	    outlet.push_back(dig_str);
	}
	for(int j=0; j<N; j++) {
	    string dig_str;
	    infile >> dig_str;
	    dev.push_back(dig_str);
	}
	sort(dev.begin(), dev.end());
	int attempt = 0;
	bool success = false;
	outfile << "Case #" << i+1 <<":"<< " ";
	for(attempt = 0; attempt <= L; attempt++) {
	    success = turn_switch(outlet, 0,0, attempt, dev);
	    if(success) {
		outfile << attempt << endl;
		break;
	    }
	}
	if(!success) {
	    outfile << "NOT POSSIBLE"<<endl;
	}
    }

	infile.close();
	outfile.close();
    return 0;

}


