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
	
int dfs(int in){
	
	if(in==d){
		//cout<<in<<endl;
		//for(int i=0;i<n;++i)
		//	cout<<s[i]<<endl;
		//cout<<endl;
		one1=-1;
		for(int i=0;i<n;++i){
			if(s2[one].substr(0,d)==s[i].substr(0,d)){
				one1=i;
				break;
			}
		}
		if(one1<0)
			return 10000;
		string& ss1=s[one1];
		string& ss2=s2[one];
		int count=0;
		for(int i=0;i<n;++i)
			s3[i]=s[i];
		for(int i=d;i<l;++i){
			if(ss1[i]!=ss2[i]){
				for(int j=0;j<n;++j){
					if(s3[j][i]=='1')
						s3[j][i]='0';
					else
						s3[j][i]='1';
				}
				++count;
			}
		}
		sort(s3,s3+n);
		bool g=true;
		for(int i=0;i<n;++i)
			if(s3[i]!=s2[i]){
				g=false;
					break;
			}
		if(g)
			return count;
		else 
			return 10000;
	}

	int tmp=dfs(in+1);
	for(int i=0;i<n;++i){
		if(s[i][in]=='1')
			s[i][in]='0';
		else
			s[i][in]='1';
	}
	int tmp2=dfs(in+1);
	for(int i=0;i<n;++i){
		if(s[i][in]=='1')
			s[i][in]='0';
		else
			s[i][in]='1';
	}
	if(tmp<tmp2+1){
		return tmp;
	}
	else
		return tmp2+1;
	
}
int main(){
	int TT;
	cin>>TT;


	for(int T=1;T<=TT;++T){
		//cout<<"-----";
		cin>>n;
		cin>>l;
		//cout<<"-----"<<endl;
		for(int i=0;i<n;++i)
			cin>>s[i];
		for(int i=0;i<n;++i)
			cin>>s2[i];
		sort(s2,s2+n);
		//l=s[0].size();
		for(int i=1;i<20;++i){
			if((1<<i)>n){
				d=i-1;
				break;
			}
		}
		d=l;
		for(int i=1;i<n-1;++i){
			if(s2[i].substr(0,d)!=s2[i-1].substr(0,d)){
				if(s2[i].substr(0,d)!=s2[i+1].substr(0,d)){
					one=i;
				}
			}
		}
		if(s2[n-1].substr(0,d)!=s2[n-2].substr(0,d)){
			one=n-1;
		}
		if(s2[0].substr(0,d)!=s2[1].substr(0,d)){
			one=0;
		}
		//cout<<one<<"!!!";
		

		//for(int i=0;i<l;++i){
		//}
		int ans=dfs(0);


		
		if(ans>999)
			cout<<"Case #"<<T<<": "<<"NOT POSSIBLE"<<"\n";
		else
			cout<<"Case #"<<T<<": "<<ans<<"\n";
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
