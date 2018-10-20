#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <map>
#include <algorithm>
using namespace std;
int getbit(int num,int ind){
	if((num>>ind)&1==1)
	return 1;
	return 0;
}
int main(){
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int x=1,t;
	cin >> t ;
	while(t--){
		int n , l;
		cin >> n >> l;
		bool flag [n+1] ;
		string init[n+1],s[n+1],req[n+1];
		for(int i=0;i<n;i++){
			cin >> s[i];
			init[i] = s[i];
		}
		for(int i=0;i<n;i++){
			cin >> req[i];
		}
		int mini = 1<<28;
		for(int i=0;i<(1<<l);i++){
			int c = 0;
			//cout << i << endl;
			for(int j=0;j<l;j++){
				if(getbit(i,j)){
					for(int k=0;k<n;k++){
						s[k][j]=(s[k][j]=='1')?'0':'1';
						
					}
					c++;
				}
			}
			memset(flag,0,sizeof flag);
			int cnt =0;
			for(int j=0;j<n;j++){
				for(int k=0;k<n;k++){
					if(s[j]==req[k]&&!flag[k]){
						cnt++;
						flag[k] = true;
						break;
					}
				}
			}
			for(int j=0;j<n;j++)
			s[j] = init[j];
			
			if(cnt==n){
				mini = min(mini,c);
			}
		}
		if(mini!=1<<28)
		cout << "Case #"<< x << ": " << mini << endl;
		else{
			cout << "Case #"<< x << ": NOT POSSIBLE" << endl;
		}
		x++;
	}
	return 0;
}
