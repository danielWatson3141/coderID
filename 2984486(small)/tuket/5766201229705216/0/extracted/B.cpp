#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main(){
	
	int nn;
	cin>>nn;
	
	for(int kk=0; kk<nn; kk++){
		
		cout << "Case #" << kk+1 << ": ";
		int N;
		cin>>N;
		int *node = new int[N];
		
		if( N==1 ){
			cout << 0 << endl;
			continue;
		}
		else if( N==2 ){
			cout << 1 << endl;
			continue;
		}
		
		for(int i=1; i<N; i++){
			
			int n1, n2;
			cin>>n1>>n2;
			
			node[n1-1]++;
			node[n2-1]++;			
			
		}
		
		int res = 0;
		int ntwo=0;
		for(int i=0; i<N; i++) if( node[i]==2 ) ntwo++;
		
		res += abs(1-ntwo);
		
		for(int i= 0; i<N; i++)
			if(node[i] > 3) res += (node[i]-3);
			
		cout << res << endl;
		
	}
	
}
