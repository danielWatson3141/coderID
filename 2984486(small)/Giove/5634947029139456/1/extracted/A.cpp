#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>
#include <set>
#include <map>

using namespace std;


int const MAXN = 200;

int n,l;

vector<int> outlets[MAXN];
vector<int> devices[MAXN];

vector<int> switches;

long long int numberedOutlets[MAXN];
long long int numberedDevices[MAXN];


long long int string2number (vector<int> string) {
	long long int output = 0;
	long long int pow = 1;
	
	for (int i=0; i<l; i++) {
		output += pow * string[i];
		pow *= 2;
	}
	
	return output;
}


void solve() {
	scanf("%d %d\n", &n, &l);
	
	for (int i=0; i<n; ++i) {
		outlets[i].clear();
		
		for (int j=0; j<l; ++j) {
			char c;
			scanf("%c", &c);
			if ( c == '0' ) {
				outlets[i].push_back(0);
			}
			else outlets[i].push_back(1);
		}
		
		scanf(" ");
	}
	
	
	for (int i=0; i<n; ++i) {
		devices[i].clear();
		
		for (int j=0; j<l; ++j) {
			char c;
			scanf("%c", &c);
			if ( c == '0' ) {
				devices[i].push_back(0);
			}
			else devices[i].push_back(1);
		}
		
		scanf(" ");
		
		numberedDevices[i] = string2number(devices[i]);
		// printf("%lld\n", numberedDevices[i]);
	}
	
	sort( numberedDevices, numberedDevices + n );
	
	int best_solution = 2014;
	
	for (int i=0; i<n; ++i) {
		// Provo a collegare il device 0 all'outlet i
		
		int numSwitches = 0;
		
		switches.clear();
		for (int j=0; j<l; ++j) {
			int s = devices[0][j] ^ outlets[i][j];
			switches.push_back( s );
			if ( s == 1 ) numSwitches += 1;
		}
		
		// Cambio di conseguenza tutti gli outlets
		for (int k=0; k<n; ++k) {
			vector<int> newOut;
			for (int j=0; j<l; ++j) {
				newOut.push_back( outlets[k][j] ^ switches[j] );
			}
			numberedOutlets[k] = string2number(newOut);
		}
		
		// Ordino e confronto
		sort( numberedOutlets, numberedOutlets + n );
		bool funge = 1;
		for (int k=0; k<n; ++k) {
			if ( numberedOutlets[k] != numberedDevices[k] ) funge = 0;
		}
		
		if (funge) {
			best_solution = min( best_solution, numSwitches );
		}
	}
	
	if ( best_solution == 2014 ) printf("NOT POSSIBLE\n");
	else printf("%d\n", best_solution);
}

int main() {
	
	int t;
	scanf("%d",&t);
	
	for (int i=0; i<t; ++i) {
		printf("Case #%d: ",i+1);
		solve();
	}
	
	return 0;
}
