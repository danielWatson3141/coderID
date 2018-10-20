#include<iostream>
#include<vector>
#include<string>

using namespace std;
	int T;
	int n;
int main(){

	cin>>T;
	vector<bool> res(T, false);
	vector<vector<int> > seqs(120, vector<int> (1000)); 
	for(int j=0; j<T; j++){
		cin>>n;
		for (int i=0; i<n; i++)cin>>seqs[j][i];
		
	}
	int bads=0;int cur=1;int di=1;
	while (bads<=60 && cur<n){
	    for(int j=0; j<T && bads<=60; j++){
		if(seqs[j][cur-di]==cur && !res[j]){
		    bads++; res[j]=true;
		}
	    }
	    cur++;
	    if(cur==n){
		cur=di+1; di++;
	    }
	    
	}
	
	for(int j=0; j<T; j++){
	    cout<<"Case #"<<j+1<<": ";
	    if(res[j])cout<<"BAD\n"; else cout<<"GOOD\n";	
	}
	
}
