#include<iostream>
using namespace std;
const int maxn = 1010;
int perm[maxn];

int main(){
	int T;
	cin >> T;
	for(int t=0;t<T;t++){
		int n;
		cin >> n;
		for(int i=0;i<n;i++)	
			cin >> perm[i];
		bool good = true;

		// Test 1   
		int cur = 0;
		for(int i=0;i<n;i++)
			if(perm[i]==i)
				cur++;
		if(cur*cur > n/3)
			good = false;
		//cout << "### " << cur << endl;
		// kerm
		if( cur>3)
			good = false;
		cout << "Case #" << t+1 << ": ";
		if(good)
			cout << "GOOD" << endl;
		else
			cout << "BAD" << endl;
			
	}
	return 0;
}
