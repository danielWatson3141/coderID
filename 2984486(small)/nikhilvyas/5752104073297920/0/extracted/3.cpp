#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const double f=1.011;

int main(){
	int t;
	cin>>t;
	int k1=0,k2=0;
	for(int gg=0;gg<t;gg++){
		int n;
		cin>>n;
		long long int sum=0;
		for(int j=0;j<1000;j++){
			int z;
			cin>>z;
			sum = sum + (j+1)*(z+1);
		};
		if(sum>250500250*f){
			cout<<"Case #"<<gg+1<<": BAD"<<endl;
			k1++;
		}
		else{
			cout<<"Case #"<<gg+1<<": GOOD"<<endl;
			k2++;
		}
	}
	cout<<k1<<"  "<<k2;
		
}
