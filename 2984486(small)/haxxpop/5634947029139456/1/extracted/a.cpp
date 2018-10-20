#include<stdio.h>
#include<set>
using namespace std;
typedef long long ll;
char init[200][50];
char goal[200][50];
char change_bit[50];
set<ll> myset;
int main(){
	int t;
	scanf("%d",&t);
	for(int e = 0; e < t ; e++ ){
		int n,m;
		scanf("%d %d",&n,&m);
		for(int i = 0 ; i < n ; i++ ) scanf("%s",init[i]);
		for(int i = 0 ; i < n ; i++ ) scanf("%s",goal[i]);

		for(int i = 0 ; i < n ; i++ ){
			for(int j = 0 ;j < m ; j++ ){
				init[i][j] -='0';
				goal[i][j] -='0';
			}
		}
		int ans = 100000;
		for(int k = 0 ; k < n ; k++ ){
			for(int i =0 ;i < m ; i++ ){
				if( goal[k][i] != init[0][i] ){
					change_bit[i] = 1;
				}else{
					change_bit[i] = 0;
				}
			}/*
			printf("change ");
			for(int i = 0 ;i < m ; i++ ){
				printf("%d",change_bit[i]);
			}
			printf("\n");*/
			int sum = 0;
			for(int i = 0 ;i < m; i++ ) sum += change_bit[i];
			myset.clear();
			for(int i = 0 ; i < n ; i++ ){
				ll tmp = 0;
				for(int j = 0 ; j < m ; j++ ){
					tmp += ((((ll)init[i][j])^change_bit[j])<<j);
				}
				myset.insert(tmp);
			}
			int chk = 1;
			for(int i = 0 ; i < n ; i++ ){
				ll tmp = 0;
				for(int j = 0 ;j < m; j++ ){
					tmp += (((ll)goal[i][j])<<j);
				}
				if( myset.find(tmp) == myset.end() ){
					chk = 0;
					break;
				}
			}
			if( chk && sum < ans ){
				ans = sum;
			}
		}
		printf("Case #%d: ",e+1);
		if( ans == 100000 ) printf("NOT POSSIBLE\n");
		else printf("%d\n",ans);
	}
}
