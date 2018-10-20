#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstdint>
#include <cmath>
#include <utility>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <string.h>

using namespace std;

#define REP(i, p, n) for (int i=p; i<n; ++i)
#define FOR(i, c) for (__typeof ((c).begin()) i=(c).begin(); i!=(c).end(); ++i)

int N, L;

bool ge (string A, string B) {
	REP (i, 0, A.size()) {
		if (A[i]>B[i]) return true;
		if (A[i]<B[i]) return false;
	}
	return true;
}

int flip (vector<string> &outlets, vector<string> &devices, int index)
{
	int ans=-1;
//	cout << outlets[0] << " " << devices[0] << endl;
	sort (outlets.begin(), outlets.end());
	sort (devices.begin(), devices.end());

	/*
	REP (k, 0, N) cout << outlets[k] << " ";
	cout << endl;
	REP (k, 0, N) cout << devices[k] << " ";
	cout << endl;
	cout << endl;
	*/

	int num_A=0, num_B=0, diff = 0;
	REP (k, 0, N) {
		if (outlets[k][index]=='1') ++num_A;
		if (devices[k][index]=='1') ++num_B;

		if (outlets[k][index] != devices[k][index]) ++diff;
//		else if (index!=0 && outlets[k][index-1]!=devices[k][index-1]) ++diff;
	}
	if (num_A != num_B && num_A != N-num_B)
		return -1;

	if (diff == 0) {
		if (index == L-1) { cout << "fdsfsa"<<endl; return 0; }
		else ans = flip (outlets, devices, index+1);
	}

	if (diff != 0) {
		REP (k, 0, N) outlets[k][index] = ('1'-outlets[k][index]) + '0';
		sort (outlets.begin(), outlets.end());
		sort (devices.begin(), devices.end());
		diff=0;
		REP (k, 0, N) {
			if (outlets[k][index] != devices[k][index]) ++diff;
//			else if (index!=0 && outlets[k][index-1]!=devices[k][index-1]) ++diff;
		}
		REP (k, 0, N) outlets[k][index] = ('1'-outlets[k][index]) + '0';
		if (diff == 0) {
			if (index == L-1) return 1;
			else {
				int tmp = flip (outlets, devices, index+1);
				if (ans==-1 && tmp==-1) return -1;
				if (ans!=-1 && tmp!=-1) return min(ans, tmp+1);
				if (ans==-1) return tmp+1;
				if (tmp==-1) return ans;
			}
		}
	}

	return ans;
}

int main (int argc, char **argv)
{
	FILE *fin = fopen(argv[1], "r");
	FILE *fout = fopen (argv[2], "w");
	if (fin==NULL || fout==NULL) exit(1);

	int num_cases;
	fscanf (fin, "%d", &num_cases);

	REP (i, 0, num_cases) {
		fscanf (fin, "%d %d", &N, &L);
		vector<string> outlets, devices;

		char tmp[L*2];
		REP (j, 0, N) {
			memset(tmp, 0, sizeof (tmp));
			fscanf (fin, "%s", tmp);
			outlets.push_back (string(tmp));
		}
		REP (j, 0, N) {
			memset(tmp, 0, sizeof (tmp));
			fscanf (fin, "%s", tmp);
			devices.push_back (string(tmp));
		}
		int ans = flip (outlets, devices, 0);
		if (ans == -1) {
			fprintf (fout, "Case #%d: NOT POSSIBLE\n", i+1);
		} else
			fprintf (fout, "Case #%d: %d\n", i+1, ans);
	}

	fclose(fin);
	fclose(fout);
	return 0;
}






