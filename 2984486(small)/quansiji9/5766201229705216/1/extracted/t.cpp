#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
#include <string>
#include <string.h>
#include <sstream>
#include <algorithm>
using namespace std;

int T;
int N;
int nc[1010][1010];
int nn[1010];
int dep[1010];
int tocut[1010];
int subtreesize[1010];

void dfs(int i) {
	for (int k = 0; k < nn[i]; ++k) {
		if (dep[nc[i][k]] < 0) {
			dep[nc[i][k]] = dep[i]+1;
			dfs(nc[i][k]);
		}
	}
}

int main() {
	cin >> T;

	for (int j = 1; j <= T; j++) {
		cin >> N;
		for (int i = 1; i <= N; ++i)
			nn[i] = 0;
		for (int i = 1; i < N; ++i){
			int tpa, tpb;
			cin >> tpa >> tpb;
			nc[tpa][nn[tpa]] = tpb;
			nc[tpb][nn[tpb]] = tpa;
			++nn[tpa];
			++nn[tpb];
		}
		
		int mincut = N;

		for (int i = 1; i <= N; ++i) {
			// who is root?
			for (int k = 1; k <= N; ++k) {
				dep[k] = -1;
				tocut[k] = 0;
			}
			dep[i] = 0;
			
			dfs(i);

			int maxdep = 0;
			for (int k = 1; k <= N; ++k)
				if (dep[k] > maxdep)
					maxdep = dep[k];

			for (int tdep = maxdep; tdep >= 0; --tdep) {
				for (int k = 1; k <= N; ++k)
					if (dep[k] == tdep) {
						int ccount = 0;
						int cd[1010];
						int cdpt = 0;
						for (int p = 0; p < nn[k]; ++p) {
							if (dep[nc[k][p]] < dep[k])
								continue;
							cd[cdpt] = nc[k][p];
							++cdpt;
							++ccount;
						}

						if (ccount == 0) {
							tocut[k] = 0;
							subtreesize[k] = 1;
						}
						else if (ccount == 1) {
							tocut[k] = subtreesize[cd[0]];
							subtreesize[k] = subtreesize[cd[0]]+1;
						}
						else if (ccount == 2) {
							tocut[k] = tocut[cd[0]]+tocut[cd[1]];
							subtreesize[k] = subtreesize[cd[0]]+subtreesize[cd[1]]+1;
						}
						else if (ccount >= 3) {
							subtreesize[k] = 1;
							for (int q = 0; q < ccount; ++q)
								subtreesize[k] += subtreesize[cd[q]];
							int temp = subtreesize[k] - 1;

							int thismincut = N;

							for (int tt1 = 0; tt1 < ccount - 1; ++tt1)
								for (int tt2 = tt1+1; tt2 < ccount; ++tt2) {
									int thiscut = temp - subtreesize[cd[tt1]] - subtreesize[cd[tt2]] + tocut[cd[tt1]] + tocut[cd[tt2]];
									if (thiscut < thismincut)
										thismincut = thiscut;
								}
							tocut[k] = thismincut;
						}
					}
			}
			if (tocut[i] < mincut)
				mincut = tocut[i];

			//cout << "Root is " << i << ". To cut is " << tocut[i] << endl;
		}
		
		cout << "Case #" << j << ": " << mincut << endl;
	}

	return 0;
}
