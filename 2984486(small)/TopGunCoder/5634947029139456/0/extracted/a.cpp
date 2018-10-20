#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <stdio.h>
using namespace std;

int main()
{
	int T;
	cin >> T;
	long int N, L;
	vector<string> G;
	vector<string> A;
	vector<string> TT;
	string s;
	for(int t = 0;t < T; t ++){
		G.clear();
		A.clear();
		TT.clear();
		cin>> N >> L;
		for(int i = 0; i < N; i ++){		
			cin >> s;
			//cout << s << " ";
			G.push_back(s);
		}
		//cout << endl;
		for(int i = 0; i < N; i ++){
			cin >> s;
			//cout << s << " ";
			A.push_back(s);
		}
		//cout << endl;

		int * switches = new int[L];
		
		sort(A.begin(),A.begin()+N);
		//cout << "A: ";
			for(int y = 0; y < A.size(); y ++){
				//cout << A[y] << " ";
			}
			//cout << endl;
		int minnumswitches = INT_MAX;
		for(int i = 0 ; i < N; i++)
		{
			int numswitches = 0;
			TT.clear();
			for(int i = 0; i < L; i++){
				switches[i]=0;
			}
			//cout << "switches: ";
			for(int j = 0 ; j < L; j++){
				if(A[0][j] !=G[i][j]){
					switches[j]= 1;
					numswitches++;
			//		cout << 1;
				}else{
			//		cout << 0;
				}

			}
			//cout << endl;
			for(int x = 0; x < N;x++)
			{
				TT.push_back(G[x]);
				for(int j = 0; j < L; j++)
				{
					if(switches[j]==1)
					{
						if(TT[x][j]=='0'){
							TT[x][j]='1';
						}else{
							TT[x][j]='0';
						}
					}
				}

			}
			sort(TT.begin(),TT.begin()+N);
			//cout << "TT: ";
			for(int y = 0; y < TT.size(); y ++){
		//		cout << TT[y] << " ";
			}
			//cout << endl;
			bool solution = true;
			for(int x = 0; x <N; x++){
				if (strcmp(TT[x].c_str(),A[x].c_str())!=0){
					solution = false;
					break;
				}
			}

			if(solution)
			{
				if (numswitches<minnumswitches){
					minnumswitches = numswitches;
				}
			}
			//check if it is a solution

		}

		cout << "Case #" << t + 1 << ": ";
		if(minnumswitches == INT_MAX)
		{
			cout << "NOT POSSIBLE" << endl;
		}else{
			cout << minnumswitches << endl;
		}


	} 

	return 0;
}