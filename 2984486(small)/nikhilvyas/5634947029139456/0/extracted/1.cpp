#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minn;

bool eq(vector< vector <char> > g,vector< vector <char> > r,int n){
	bool ret;
	for(int i=0;i<n;i++){
		bool k=false;
		for(int j=0;j<n;j++){
			if(equal(g[i].begin(),g[i].end(),r[j].begin())) k=true;
		}
		if(!k){
			ret=false;
			break;
		}
		ret=true;
	}
	return ret;
}

void possible(vector< vector <char> > g,vector< vector <char> > r,int n,int l,int i,int ch){
	if(i == l){
		//cout<<ch<<g[1][0]<<g[1][1]<<g[1][2]<<endl;
		bool z = eq(g,r,n);
		//if(z) cout<<"true"<<endl;
		if(z && minn > ch){
			minn=ch;
		}
		return;
	}
	int sum1=0,sum2=0;
	for(int j=0;j<n;j++){
		if(g[j][i]=='0') sum1++;
		if(r[j][i]=='0') sum2++;
	}
	//cout<<sum1<<"   "<<sum2<<endl;
	/*if(l % 2 == 0 && sum1 == l/2 && sum1 == sum2){
		possible(g,r,n,l,i+1);
		for(int c=0;c<n;c++){
			g[c][i]=1-g[c][i];
		}
		possible(g,r,n,l,i+1);
		return;
	}*/
	if(sum1 == sum2){
		//cout<<"a"<<endl;
		possible(g,r,n,l,i+1,ch);
	}
	if(sum1 + sum2 == n){
		//cout<<"b"<<endl;
		for(int c=0;c<n;c++){
			if(g[c][i] == '0') g[c][i]='1';
			else g[c][i]='0';
		}
		possible(g,r,n,l,i+1,ch+1);
	}
}
		
		
	

int main(){
	int t;
	cin>>t;
	for(int gg=0;gg<t;gg++){
		int n,l;
		cin>>n>>l;
		//cout<<n<<l<<endl;
		vector< vector <char> > g(n,vector <char> (l));
		vector< vector <char> > r(n,vector <char> (l));
		for(int k=0;k<n;k++){
			for(int h=0;h<l;h++){
				cin>>g[k][h];
			}
		}
		for(int k=0;k<n;k++){
			for(int h=0;h<l;h++){
				cin>>r[k][h];
			}
		}
		minn=1000;
		possible(g,r,n,l,0,0);
		if(minn == 1000){
			cout<<"Case #"<<gg+1<<": NOT POSSIBLE"<<endl;
			continue;
		}
		cout<<"Case #"<<gg+1<<": "<<minn<<endl;
	}
}
