#include <cstdio>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <intrin.h>
using namespace std;

__int64 stoi64(string s) {
	__int64 ret = 0;
	__int64 bit = 1;
	const char* cs = s.c_str();
	for(int i = 0; i < s.size(); i++) {
		if (cs[s.size()-i-1] == '1')
			ret |= bit;
		bit <<= 1;
	}
	return ret;
}

int _mm_popcnt_u64(unsigned __int64 v) {
	int r = 0;
	__int64 one = 1;
	for(int i = 1; i <= 64; i++) 
		r += (v & one<<(i-1)) ? 1 : 0;
	return r;
}

int main(int argc, char* argv[])
{
	ifstream f;
	f.open("A-small-attempt0.in");
	if (!f.is_open()) {
		cerr << "Could not open file.\n";
		return -1;
	}

	ofstream out;
	out.open("output_small.txt");
	if (!out.is_open()) {
		cerr << "Could not open output file.\n";
		return -1;
	}

	int t;
	f >> t;

	for(int i = 1; i <= t; ++i) {
		int n, l;
		vector<__int64> outlets, devices;
		
		f >> n >> l;
		
		for(int j = 0; j < n; ++j) {
			__int64 flow = 0;
			string sflow;
			f >> sflow;
			outlets.push_back(stoi64(sflow));
		}
		
		for(int j = 0; j < n; ++j) {
			__int64 d = 0;
			string sd;
			f >> sd;
			devices.push_back(stoi64(sd));
		}

		sort(devices.begin(), devices.end());

		int minswitches = INT_MAX;
		for(__int64 j = 0; j <= (1<<l)-1; j++) {
			vector<__int64> outlets2(outlets);
			std::transform(outlets2.begin(), outlets2.end(), outlets2.begin(), 
				[=](__int64 v) { return v ^ j; });
			
			sort(outlets2.begin(), outlets2.end());
			if (equal(outlets2.begin(), outlets2.end(), devices.begin()))
				if(_mm_popcnt_u64(j) < minswitches)
					minswitches = _mm_popcnt_u64(j);
		}

		if (minswitches != INT_MAX)
			out << "Case #" << i << ": " << minswitches << endl;
		else
			out << "Case #" << i << ": NOT POSSIBLE" << endl;
	}
}