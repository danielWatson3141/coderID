#include <iostream>
#include <algorithm>
using namespace std;

#define N 1000
int main() {
	// your code goes here
	
	srand(0);	
	int T; cin >> T;
	for(int ii = 1; ii <= T; ii++) {
			
			cout << "Case #" << ii << ": " << (rand() % 2 == 0? "GOOD" : "BAD") << endl;

	}
	return 0;
}
