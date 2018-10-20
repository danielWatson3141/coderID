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
	ll n, l, t, i, j, k, m;
	char arr[151][41], arr2[151][41], temp[151][41], temp2[151][41], xorv[1000];
	cin>>t;
	for(int lol = 1;lol<=t;++lol) {
		cin>>n>>m;
		for(i=0;i<n;++i) {
			cin>>arr[i];
		}
		for(i=0;i<n;++i) {
			cin>>arr2[i];
		}
		ll count = 99999999;
		for(i=0;i<n;++i) {
			ll done = 1, counter = 0;
			for(j=0;j<n;++j) {
					for(l = 0;l <n; ++l) {
						strcpy(temp[l], arr[l]);
					strcpy(temp2[l], arr2[l]);
					}
					
					for(k = 0; k < m; ++k) {
						xorv[k] = temp[i][k] == temp2[j][k] ? '0' : '1';
						temp[i][k] == temp2[j][k] ? '0' : ++counter;
					}
					for( l = 0; l< n; ++l)
						for(k = 0; k<m;++k) {
							if(xorv[k] == '1') {
								temp2[l][k] = temp2[l][k] == '1' ? '0' : '1';
							}
						}
						done = 1;
					for(l = 0;l <n; ++l) {
						int checking = 0;
						for(k=0;k<n;++k) {
							if(strcmp(temp[l], temp2[k]) == 0) {
								checking = 1; break;
							}
						}
						if(checking) {
							temp2[k][0] = '2';
						} else {
							done = 0;
							break;
						}
					}
					if(done) {  count = min(count, counter); }
				
			}
		}
		if(count == 99999999) {
			cout<<"Case #"<<lol<<": NOT POSSIBLE"<<endl;
		} else {
			cout<<"Case #"<<lol<<": "<<count<<endl;
		}
	}
	return 0;
}