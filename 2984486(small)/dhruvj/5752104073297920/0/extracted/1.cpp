#include <iostream>
#include <stdio.h>
#include <math.h>
#include <list>
#include <queue>
#include <vector>
#include <functional>
#include <stack>
#include <utility> 
#include <stdlib.h>
#include <map>
#include <string.h>
#include <algorithm>
typedef long long int ll;
#define SWAP(a, b) (((a) ^= (b)), ((b) ^= (a)), ((a) ^= (b)))
#define CLR(a) memset(a, 0, sizeof(a))
using namespace std;
int main() {
	freopen ("output.txt","w",stdout);
	freopen ("input.in","r",stdin);
	ll n, l, t, i, j, k, m, arr[1002];
	cin>>t;
	for(k = 1; k<= t; ++k) {
		cin>>n;
		int count = 0;
		for(i=0;i<n;++i) {
			cin>>arr[i];
			if(i < arr[i]) ++count;
		}
		if(count < n/3)
			cout<<"Case #"<<k<<": BAD"<<endl;
		else 
			cout<<"Case #"<<k<<": GOOD"<<endl;
	}
	return 0;
}