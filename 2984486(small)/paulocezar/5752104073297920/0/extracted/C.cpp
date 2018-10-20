#include <map> 
#include <set> 
#include <list>
#include <stack>
#include <cmath> 
#include <queue> 
#include <ctime>
#include <cfloat>
#include <vector> 
#include <string> 
#include <cstdio>
#include <bitset>
#include <climits> 
#include <cstdlib> 
#include <cstring> 
#include <cassert> 
#include <iomanip>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <fstream>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int perm[1024];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int cases, N;
    srand(1337);
    cin >> cases;
    for (int kase = 1; kase <= cases; ++kase) {
        cin >> N;
        
        int at = 0, offbyone = 0;
        
        for (int i = 0; i < N; ++i) {
            cin >> perm[i];
            if (perm[i] == i) at++;
            if (perm[i] == (i+1)) offbyone++;
        }
        
        cout << "Case #" << kase << ": ";
        
        if (at > offbyone) cout << "GOOD\n";
        else if (at < offbyone) cout << "BAD\n";
        else if (rand() & 1) cout << "GOOD\n";
        else cout << "BAD\n";
    }

    
    
	return 0;
}

















