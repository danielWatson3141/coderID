
// main.c

#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <bitset>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <numeric>
#include <complex>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <utility>
#include <thread>
#include <mutex>

#define WRITE_OUT_FILE 0

using namespace std;

int N, L;
vector<int> in_outlet;
vector<int> in_device;

int bin2dec(int bin) {
	int n,r,s=0,i;
	n=bin;
	for(i=0;n!=0;i++)
    {
        r=n%10;
        s=s+r*(int)pow(2,i);
        n=n/10;
    }
	return s;
}

int bitnum (int in) {
	int count=0;
	while(in!=0){
		in = in & (in - 1);
		count++;
	}
	return count;
}

bool verifybits(int sw) {
	vector<int> in_o_c = vector<int>(in_outlet);
	vector<int> in_d_c = vector<int>(in_device);
	
	for (int i = 0; i < N; i++) {
		bool found = 0;
		int o_t = in_o_c[i] ^ sw;
		for (int j = 0; j < N; j++) {
			if (in_d_c[j] == -1)
				continue;
			
			int d_t = in_d_c[j];
			if (o_t == d_t) {
				found = true;
				in_d_c[j] = -1;
			}
		}
		
		if (!found) {
			return false;
		}
	}
	
	return true;
}

int solve()
{
	int end = pow(2, L) - 1;
	
	int min_sw = -1;
	for (int i = 0; i < end; i++) {
		if (verifybits(i)) {
			int bitn = bitnum(i);
			if (min_sw == -1 || bitn < min_sw) {
				min_sw = bitn;
			}
		}
	}
	
	return min_sw;
}

int main()
{
	freopen("in.in", "r", stdin);
	if (WRITE_OUT_FILE)
		freopen("out.out", "w", stdout);
	
	int T;
	scanf("%d\n", &T);
	if (!T) {
		cerr << "Check input!" << endl;
		exit(0);
	}
	
	for (int t = 1; t <= T; t++) {
		if (WRITE_OUT_FILE)
			cerr << "Solving: #" << t << " / " << T << endl;
		
		scanf("%d %d\n", &N, &L);
		
		in_outlet.clear();
		in_device.clear();
		
		for (int i = 0; i < N; i++) {
			int tmp;
			scanf("%d", &tmp);
			in_outlet.push_back(bin2dec(tmp));
		}
		
		getchar();
		
		for (int i = 0; i < N; i++) {
			int tmp;
			scanf("%d", &tmp);
			in_device.push_back(bin2dec(tmp));
		}
		
		auto result = solve();
		if (result == -1) {
			printf("Case #%d: NOT POSSIBLE\n", t);
		}  else {
			printf("Case #%d: %d\n", t, result);
		}
		
	}
	
	fclose(stdin);
	if (WRITE_OUT_FILE)
		fclose(stdout);
	
	return 0;
}


