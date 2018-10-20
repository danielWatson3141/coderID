#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
	int C, N, L;
bool eq(vector<string> & a, vector<string> & b ){
    for(int i=0; i<N; i++) if(a[i]!=b[i])return false;
    return true;
}
int main(){
	vector<string > a,b;
	
	cin>>C; 
	for(int j=0; j<C; j++){
		a.clear(); a.resize(0);
		b.clear(); b.resize(0);
		string s;
		cin>>N>> L;
		for(int i=0; i<N; i++){cin>>s; a.push_back(s);}
		for(int i=0; i<N; i++){cin>>s; b.push_back(s);}
		sort(b.begin(), b.end());
		int res= 1000;
		for(int m=0; m<(1<<L); m++){
		    int no = 0;
		    for(int i=0; i<L; i++){
			if(m&(1<<i)){
			    no++;
			    for(int k=0; k<N; k++)a[k][i]='0'+('1'-a[k][i]);
			}
		    }
			sort(a.begin(), a.end());
			if(eq(a, b)){
			    if(no<res){
				res=no;
			    }
			}
		    for(int i=0; i<L; i++){
			if(m&(1<<i)){
			    no++;
			    for(int k=0; k<N; k++)a[k][i]='0'+('1'-a[k][i]);
			}
		    }
		    
		}
		cout<<"Case #"<<j+1<<": " ;
		if(res==1000)cout<<"NOT POSSIBLE\n";
		else cout<<res<<"\n";
	}
	
}
