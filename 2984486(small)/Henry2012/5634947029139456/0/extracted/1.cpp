#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int minStep =  1000000;

bool dfs2(vector<string> flow, vector<string> dev, int l, int pos = 0, int changed = 0) {
	if (pos == l) {
		minStep = min(minStep, changed);
		return true;
	}

	bool flag0 = true;
	sort(flow.begin(), flow.end());
	for (int i = 0; i<(int)flow.size(); i++) {
		if (flow[i][pos] != dev[i][pos]) {
			flag0 = false;
			break;
		}
	}

	if (flag0) {
	    flag0 = dfs2(flow, dev, l, pos+1, changed);
	} 

    // flip
    for (int i=0; i<(int)flow.size(); i++) {
		flow[i][pos] = (flow[i][pos] == '0' ? '1' : '0');
	}

	sort(flow.begin(), flow.end());
	bool flag1 = true;
	for (int i = 0; i<(int)flow.size(); i++) {
		if (flow[i][pos] != dev[i][pos]) {
			flag1 = false;
			break;
		}
	}
	if (flag1) {
		flag1 = dfs2(flow, dev, l, pos+1, changed+1);
	} 

    // flip back
    for (int i=0; i<(int)flow.size(); i++) {
		flow[i][pos] = (flow[i][pos] == '0' ? '1' : '0');
	}

    return flag0 || flag1;
}

int solve() {
	double l, n; 
	cin >> n >> l;

	vector<string> dev(n), flow(n);
	for (int i = 0; i<n; i++)
		cin >> flow[i];

	for (int i = 0; i<n; i++)
		cin >> dev[i];

    sort(flow.begin(), flow.end());
	sort(dev.begin(), dev.end());

	minStep = 1000000;
    bool found = dfs2(flow, dev, l);
	
	return found ? minStep : -1; 
}

int main()
{
	int caseNum;
	cin >> caseNum;

	for (int caseNo=1; caseNo <= caseNum; ++caseNo) {
		int res = solve();
		if (res < 0) {
		    printf("Case #%d: NOT POSSIBLE\n", caseNo);
		} else {
		    printf("Case #%d: %d\n", caseNo, res);
		}

		//if (caseNo < caseNum)
		//	printf("\n");
	}

	return 0;
}
