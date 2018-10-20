using namespace std;
#include <iostream>
#include <string>
#include <cstring>

int main(){
	int t, n, l;
	string outlet[150], device[150];
	bool control[150];

	cin >> t;

	for(int i = 1;i <= t;i++){
		int best_num = 1500, num = 0;
		bool possible = false;
	
		memset(control, 0, sizeof(control));

		cin >> n >> l;

		for(int j = 0;j < n;j++){
			cin >> outlet[j];
		}
		for(int j = 0;j < n;j++){
			cin >> device[j];
		}

		for(int j = 0;j < n;j++){
			num = 0;
			bool mod[150];

			for(int m = 0;m < n;m++){
				for(int a = 0;a < l;a++){
					if(device[j][a] == outlet[m][a]){
						mod[a] = false;
					}
					else{
						mod[a] = true;
						num++;
					}
				}

				memset(control, 0, sizeof(control));
				control[m] = true;

				for(int a = 0;a < n;a++){
					for(int b = 0;b < n;b++){
						bool yes = false;
						if(a != j && !control[b]){
							for(int c = 0;c < l;c++){
								if(device[a][c] != outlet[b][c] && !mod[c] ||
								device[a][c] == outlet[b][c] && mod[c]){
								break;							
								}

								if(c == l-1){
									control[b] = true;
									yes = true;				
								}
							}

						}
					
						if(yes){
							break;			
						}
				
					}
				}
				
				bool found = true;
				for(int a = 0;a < n;a++){
					if(!control[a]){
						found = false;
						break;			
					}
				}
		
				if(found){
					possible = true;
					if(num <= best_num){
						best_num = num;		
					}	
				}
			}
		}
		
		cout << "Case #" << i << ": ";

		if(possible){
			cout << best_num << endl;
		}
		else{
			cout << "NOT POSSIBLE" << endl;
		}

	}

	return 0;
}
