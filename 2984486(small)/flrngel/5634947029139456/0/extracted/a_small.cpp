#include <stdio.h>
#include <iostream>
#include <string>
#include <memory.h>
#include <map>
#include <algorithm>

using namespace std;

int main(){
	int t;
	int T=1;
	cin >> t;
	int x[15];
	int y[15];
	int z[15];
	while(t--){
		int n,m;
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
		memset(z,0,sizeof(y));
		scanf("%d %d\n",&n,&m);
		char tmp[30];
		for(int i=0;i<n;i++){
			scanf("%s",tmp);
			for(int j=0;j<m;j++){
				x[i]+=(1<<(m-j-1))*(tmp[j]-'0');
			}
		}
		for(int i=0;i<n;i++){
			scanf("%s",tmp);
			for(int j=0;j<m;j++)
				y[i]+=(1<<(m-j-1))*(tmp[j]-'0');
		}
		int result=2147483647;
		for(int i=0;i<(1<<m);i++){
			int l=0;
			for(int k=0;k<n;k++) z[k]=x[k];
			for(int j=0;j<m;j++){
				if( i&(1<<j) ){
					l++;
					for(int k=0;k<n;k++){
						z[k]^=(1<<j);
					}
				}
			}
			bool flag=true;
			map<int,int> mp;
			for(int k=0;k<n;k++)
				mp[z[k]]++;
			for(int k=0;k<n;k++){
				if( mp[y[k]] == 0  ) flag=false;
				mp[y[k]]--;
			}
			if( flag == true ){
				result=min(result,l);
			}
		}
		cout << "Case #"<< T++ << ": ";
		if( result == 2147483647 ){
			cout << "NOT POSSIBLE";
		}else{
			cout << result;
		}
		cout << endl;
	}
	return 0;
}
