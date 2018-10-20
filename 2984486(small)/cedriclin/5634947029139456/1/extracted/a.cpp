#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

string flow[1<<8];
string outlet[1<<8];
string tempout[1<<8];
bool offset[64];

int main(){
	int t; cin >> t;
	for (int zz = 1; zz <= t; zz++){
		int n; cin >> n;
		int l; cin >> l;
		
		for (int i = 0; i < n; i++)
			cin >> flow[i];
		for (int i = 0; i < n; i++)
			cin >> outlet[i];
		
		sort(flow,flow+n);	
			
		int best = l+1;
		
		for (int i = 0; i < n; i++){
			int cnt = 0;
			for (int j = 0; j < l; j++){
				offset[j] = (outlet[i][j] != flow[0][j]);
				if (offset[j]) cnt++;
			}	
			if (cnt >= best) continue;
			for (int k = 0; k < n; k++){
				tempout[k] = outlet[k];
				for (int j = 0; j < l; j++)
					if (offset[j]){
						if (tempout[k][j] == '0') tempout[k][j] = '1';
						else tempout[k][j] = '0';
					}
			}
			sort(tempout,tempout+n);
			bool okay = true;
			for (int k = 0; k < n; k++)
				if (tempout[k] != flow[k])
					okay = false;
					
			if (okay && cnt < best){
				best = cnt;
			}
		}
		if (best <= l) cout << "Case #" << zz << ": " << best << endl;
		else cout << "Case #" << zz << ": NOT POSSIBLE" << endl;
	}
	
	return 0;
}
