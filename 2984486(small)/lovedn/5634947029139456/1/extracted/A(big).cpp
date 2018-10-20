//UESTC_L3

#include <stdexcept>
#include <cstdarg>
#include <iostream>
#include <fstream>
#include <exception>
#include <memory>
#include <locale>
#include <sstream>
#include <set>
#include <list>
#include <bitset>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <string>
#include <utility>
#include <cctype>
#include <climits>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <map>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <vector>
#include <queue>
#include <deque>
#include <cstdlib>
#include <stack>
#include <iterator>
#include <functional>
#include <complex>
#include <valarray>
using namespace std;

string a[200],b[200],c[200];

int main(){
	freopen("A-large.in","r",stdin);
	freopen("A(2).out","w",stdout);
	int test;
	scanf("%d",&test);
	int ct=0;
	while(test--){
		int n,l;
		scanf("%d%d",&n,&l);
		
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n;i++){
			cin>>b[i];
		}
		sort(b,b+n);
		
		int ret=l+1;
			for(int j=0;j<n;j++){
				for(int k=0;k<n;k++){
					c[k]=a[k];
				}
				int bit=0;
				for(int k=0;k<l;k++){
					if(c[0][k]!=b[j][k]){
						bit++;
						for(int l=0;l<n;l++){
							c[l][k]=((c[l][k]-'0')^1)+'0';
						}
					}
				}
				sort(c,c+n);
				
				bool f=true;
				for(int k=0;k<n;k++){
					if(c[k]!=b[k]){
						f=false;
						break;
					}
				}
				if(f){
					ret=min(ret,bit);
				}
			}
		
		printf("Case #%d: ",++ct);
		if(ret==(1+l)){
			printf("NOT POSSIBLE\n");
		}
		else{
			printf("%d\n",ret);
		}
	}
	return 0;
}