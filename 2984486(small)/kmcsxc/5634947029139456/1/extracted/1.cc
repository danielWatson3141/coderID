#include <map>
#include <stdio.h>
#include <string>

using namespace std;

int T;
int N,L;
char str[200][50];
char elec[200][50];
map<string, int> m;

int main(){
	scanf("%d",&T);
	for(int Case = 1;Case<=T;Case++){
		//fprintf(stderr,"Case %d\n",Case);
		scanf("%d%d",&N,&L);
		for(int i=0;i<N;i++){
			scanf("%s",str[i]);
		}
		m.clear();
		for(int i=0;i<N;i++){
			scanf("%s",elec[i]);
			m[string(elec[i])] = 0;
		}
		int min = 123123;
		for(int i=0;i<N;i++){
			int flip[50];
			for(int j=0;j<L;j++){
				if(str[0][j]==elec[i][j])
					flip[j] = 0;
				else 
					flip[j] = 1;
			}
			for(int i=0;i<N;i++){
				for(int j=0;j<L;j++){
					if(flip[j]){
						if(str[i][j]=='0')
							str[i][j] = '1';
						else
							str[i][j] = '0';
					}
				}
			}
			bool flag = true;
			for(int i=0;i<N;i++){
				if(m.find(string(str[i]))==m.end()){
					flag = false;
					break;
				}
			}
			if(flag){
				int count = 0;
				for(int i=0;i<L;i++){
					if(flip[i]){
						count++;
					}
				}
				if(count < min)
					min = count;
			}
			for(int i=0;i<N;i++){
				for(int j=0;j<L;j++){
					if(flip[j]){
						if(str[i][j]=='0')
							str[i][j] = '1';
						else
							str[i][j] = '0';
					}
				}
			}
		}
		if(min==123123){
			printf("Case #%d: NOT POSSIBLE\n",Case);
		}
		else {
			printf("Case #%d: %d\n",Case,min);
		}
	}
}