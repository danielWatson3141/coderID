#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;
int tod[1010];
int N;
int main(){
	int T;
	cin >> T;
	for(int t=0;t<T;t++){
		cout << "Case #" << t+1 << ": ";
		cin >> N;
		for(int i=0;i<N;i++) cin >> tod[i];
		int k =0 ;
		for(int i=0;i<N;i++) if(i==tod[i]) k++;

		if(k>N/8) cout << "BAD" << endl;
		else cout << "GOOD" << endl;
	}

	return 0;
}
