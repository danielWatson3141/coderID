#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<string>
#include<string.h>

#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)
#define IT(a,it) for(auto it=a.begin(); it != a.end(); it++)
#define REV_IT(a,it) for(auto it=a.rbegin(); it != a.rend(); it++)
#define MAXX 1000

using namespace std;

map<string, int> m1, m2;
long long int N, L;
string init[200], want[200];
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T, casee = 1, found = 0;
	long long int i,j, temp, newB, k, ans;
	scanf("%d",&T);
	for(casee=1;casee<=T;casee++){
		printf("Case #%d: ",casee);
		cin>>N>>L;
		found = 1;ans = 0;
		for(i=0;i<N;i++){
			cin>>init[i];	
		}
		for(i=0;i<N;i++){
			cin>>want[i];	
			m1.insert(make_pair(want[i],1));
		}
		for(i=0;i<pow(2,L);i++){
			temp = i;
			ans = 0;
			string initNew[200];
			//char initNew[200][200];
			for(j=0;j<N;j++) initNew[j] =  init[j];
			for(j=0;j<L;j++){
				newB = temp & 00000001;
				temp = temp >> 1;
				if(newB == 1){
					ans++;
					for(k=0;k<N;k++){
						if(initNew[k][j] == '0'){
							initNew[k][j] = '1';
						}else{
							initNew[k][j] = '0';
						}
					}
				}
			}
			for(j=0;j<N;j++){
				//cin>>want[i];	
				//cout<<initNew[j]<<endl;
				m2.insert(make_pair(initNew[j],1));
			}
			found = 1;
			auto it2 = m2.begin();
			IT(m1, it1){
				//cout<<it1->first<<" "<<it2->first<<endl;
				if(it1->first == it2->first){
					
				}else{
					found = 0;
				}
				it2++;
			}
			if(found == 1){
				//out
				cout<<ans<<endl;
				break;
			}
			m2.clear();
		}
		if(found == 0){
			cout<<"NOT POSSIBLE"<<endl;
		}
		m1.clear();
		m2.clear();
	}
	fclose(stdin);
	fclose(stdin);
return 0;
}

