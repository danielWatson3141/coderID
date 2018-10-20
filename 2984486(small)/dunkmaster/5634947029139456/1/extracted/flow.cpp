#include <set>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int T;
	cin >> T;
	for(int t=0;t<T;t++){
		int N,L;
		cin >> N >> L;
		vector<string> initial;
		for(int i=0;i<N;i++){
			string s;
			cin >> s;
			initial.push_back(s);
		}
			
		vector<string> final;
		for(int i=0;i<N;i++){
			string s;
			cin >> s;
			final.push_back(s);
		}

		sort(initial.begin(),initial.end());
		sort(final.begin(), final.end());

		bool possible = true;
		cout<<"Case #"<<t+1<<": ";
		int moves = 0;
		for(int i=0;i<L;i++){
			int iones = 0;
			int fones = 0;
			for(int j=0;j<N;j++){
				if(initial[j][i]=='1')
					iones++;
				if(final[j][i]=='1')
					fones++;
			}
			if(iones!=fones && iones != N - fones){
				possible = false;
				break;
			}
			if(iones == N - fones && iones != fones){
				for(int j=0;j<N;j++){
					if(final[j][i]=='1')
						final[j][i] = '0';
					else
						final[j][i] = '1';
				}
				moves++;
			}
		}
		sort(final.begin(), final.end());
		if(!possible)
			cout<<"NOT POSSIBLE"<<endl;
		else {
			int moremoves = 99999;
			
			//match with initial[0]
			for(int i=0;i<N;i++){
				vector<string> finalcopy = final;
				int nummoves = 0;
				for(int j=0;j<L;j++){
					if(finalcopy[i][j]!=initial[0][j]){
						for(int k=0;k<N;k++){
							if(finalcopy[k][j]=='1'){
								finalcopy[k][j] = '0';
							} else {
								finalcopy[k][j] = '1';
							}
						}
						
						nummoves++;
					}
				}
				bool good = true;
				sort(finalcopy.begin(),finalcopy.end());
				for(int j=0;j<N;j++){
					if(finalcopy[j]!=initial[j]){
						good = false;
						break;
					}
				}
				if(good){
					moremoves = min(moremoves,nummoves);
				}
			}
			if(moremoves == 99999){
				cout<<"NOT POSSIBLE"<<endl;
			} else {
				
				cout<<moves+moremoves<<endl;
			}
		}
	}
}
