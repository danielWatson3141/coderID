#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <functional>
#include <set>
#include <complex>

using namespace std;

int main()
{
	int t;
	cin>>t;
	
	for(int T=1;T<=t;T++){
		int n,l;
		cin>>n>>l;

		int res=2*l,res2=0;
		vector<string> out(n);
		vector<string> dev(n);
		vector<int> out_zero(l,0);
		vector<int> dev_zero(l,0);

		for(int i=0;i<n;i++){
			 cin>>out[i];
		}

		for(int i=0;i<n;i++){
			cin>>dev[i];
		}

		const long long M=(long long)pow(2.0,(double)l);

		for(long long i=0;i<M;i++){
			long long m=i;
			res2=0;
			vector<string> o=out;
			vector<string> d=dev;
			for(int j=0;j<l;j++){
				if(m%2){
					res2++;
					for(int k=0;k<n;k++){
						if(o[k][j]=='0') o[k][j]='1';
						else o[k][j]='0';
					}
				}
				m/=2;
			}

			sort(o.begin(),o.end());
			sort(d.begin(),d.end());

			for(int j=0;j<n && res2!=2*l;j++){
				if(o[j]!=d[j]) res2=2*l;
			}

			res=min(res,res2);
		}

		if(res==2*l) printf("Case #%d: NOT POSSIBLE\n",T);
		else printf("Case #%d: %d\n",T,res);

	}


	return 0;
}
