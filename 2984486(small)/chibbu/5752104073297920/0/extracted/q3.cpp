#include <iostream>
#include <math.h>
#include <vector>
#include <stdlib.h>
using namespace std;

int main(){

	int t;
	cin>>t;
	for(int i=1; i<=t; i++){
		int n, ans=0;
		cin>>n;
		vector<int> v(n);
		for(int j=0; j<n; j++){
			cin>>v[j]; 
			ans += abs(j-v[j]);
		}
		int bad_lim=(2*n*(n+1))/3, good_lim=(n*(3*n+2))/4;
		if(abs(ans-bad_lim)<abs(ans-good_lim)) cout<<"Case #"<<i<<": BAD\n";
		else cout<<"Case #"<<i<<": GOOD\n";
	}
	return 0;
}
		
