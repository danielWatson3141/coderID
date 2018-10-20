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

string a[20];
string b[20];
string c[20];

int main(){
	freopen("A-small-attempt0.in","r",stdin);
	freopen("1.out","w",stdout);
	
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
		int ret=(l+1);
		for(int i=0;i<(1<<l);i++){
			for(int j=0;j<n;j++){
				c[j]=a[j];
			}
			int bit=0;
			for(int j=0;j<l;j++){
				if((1<<j)&i){
					bit++;
					for(int k=0;k<n;k++){
						c[k][j]='0'+((c[k][j]-'0')^1);
					}
				}
			}
			sort(c,c+n);
			bool judge=true;
			for(int j=0;j<n;j++){
				if(c[j]!=b[j]){
					judge=false;
					break;
				}
			}
			if(judge){
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