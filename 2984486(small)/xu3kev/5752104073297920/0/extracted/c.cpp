#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
	string s[200];
	string s2[200];
	string s3[200];
	int d;
	int n;
	int l;
	int one;
	int one1;
	
int main(){
	int TT;
	cin>>TT;


	int a[2000];
	for(int T=1;T<=TT;++T){
		cin>>n;
		for(int i=0;i<n;++i)
			cin>>a[i];

		//for(int i=0;i<l;++i){
		//}


		
		if(T%2==0)
			cout<<"Case #"<<T<<": "<<"BAD"<<"\n";
		else
			cout<<"Case #"<<T<<": "<<"GOOD"<<"\n";
		//cout<<n<<" "<<l<<endl;
		//for(int i=0;i<n;++i){
		//	cout<<s[i]<<" ";
		//}
		//cout<<endl;
		//for(int i=0;i<n;++i){
		//	cout<<s2[i]<<" ";
		//}
		//cout<<endl;
		//cout<<endl;

	}
	return 0;
}
