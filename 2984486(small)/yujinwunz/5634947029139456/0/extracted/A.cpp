#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

string power[150], needed[150];
int things, size;
int cases;

int numNeeded(set<int> splits, int index) {
	if (index == size) return 0;

	string newp[150], newn[150];
	for (int i = 0; i < things; i++) {
		for (int j = 0; j < index; j++) {
			if (splits.count(j) ^ (power[i][j] == '1')) {
				newp[i] += '1';
			} else {
				newp[i] += '0';
			}

			newn[i] += needed[i][j];
		}
	}
	
	int noflip = 0, flip = 0;
	// try not flipping.
	for (int i = 0; i < things; i++) {
		newp[i] += power[i][index];
		newn[i] += needed[i][index];
	}
	sort(newp, newp + things);
	sort(newn, newn + things);/*
	cout<<"No\n";
	for (int i = 0; i < things; i++) {
		cout<<newp[i]<<" "<<newn[i]<<"\n";
	}
	cout<<"\n";*/
	// check sanity.
	bool sane = true;
	for (int i = 0; i < things; i++) {
		if (newp[i] != newn[i]) sane = false;
	}
	if (sane) {
		noflip = numNeeded(splits, index+1);
	} else {
		noflip = -1;
	}

	// try flipping
	for (int i = 0; i < things; i++) {
		newp[i][index] = (newp[i][index]=='0'?'1':'0');
	}
	sort(newp, newp + things);
	sort(newn, newn + things);/*
	cout<<"flip\n";
	for (int i = 0; i < things; i++) {
		cout<<newp[i]<<" "<<newn[i]<<"\n";
	}
	cout<<"\n";*/

	// check sanity.
	sane = true;
	for (int i = 0; i < things; i++) {
		if (newp[i] != newn[i]) sane = false;
	}
	if (sane) {
		splits.insert(index);
		flip = numNeeded(splits, index+1);
		splits.erase(index);
	} else {
		flip = -1;
	}

	if (flip == -1 && noflip == -1) return -1;
	if (flip == -1) return noflip;
	if (noflip == -1) return flip + 1;
	return min(flip+1, noflip);
}

int main() {
	cin>>cases;
	for (int c = 1; c <= cases; c++) {
		cout<<"Case #"<<c<<": ";
		cin>>things>>size;
		for (int i = 0; i < things; i++) {
			cin>>power[i];
		}
		for (int i = 0; i < things; i++) {
			cin>>needed[i];
		}
		
		if (numNeeded(set<int>(), 0) == -1) cout<<"NOT POSSIBLE\n";
		else cout<<numNeeded(set<int>(), 0)<<"\n";
	}
}