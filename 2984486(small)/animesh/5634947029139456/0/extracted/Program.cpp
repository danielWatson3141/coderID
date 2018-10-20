#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	int T; fin>>T;
	for(int t = 1;t<=T;t++) {
		int N,L; fin>>N>>L;
		string S; 
		vector<string> A,B;
		for(int i = 0;i<N;i++) {fin>>S; A.push_back(S);}
		for(int i = 0;i<N;i++) {fin>>S; B.push_back(S);}
		sort(B.begin(),B.end());
		int map[51];
		memset(map,-1,sizeof map); // set global map first
		int res = 2000;
		int flipCount = 0;
		bool ok = true;
		for(int j =0;j<L;j++)
		{
			int aBitCount = 0, bBitCount = 0;
			for(int i = 0;i<N;i++)
			{
				if(A[i][j] == '1') aBitCount++;;
				if(B[i][j] == '1') bBitCount++;
			}
			if(aBitCount == bBitCount) {
				if(aBitCount + bBitCount == N) map[j] = 2; // 2 for not sure
				else map[j] = 0; // 0 for same
			}
			else if(aBitCount + bBitCount == N)
			{
				map[j] = 1; // 1 for flip
				flipCount++;
			}
			else
				ok = false;
		}
		fout<<"Case #"<<t<<": ";
		if(!ok)
		{
				fout<<"NOT POSSIBLE\n";
				continue;
		}
		// create a copy of map and try every combination,,
		
		for(int a =0;a<N;a++)
			for(int b = 0;b<N;b++)
			{
				int localMap[151];
				for(int i = 0;i<L;i++) localMap[i] = map[i];
				// if A[i] and B[j] can match, then flip is decided. see if it works for others. 
				bool works = true;
				int flips = flipCount;
				for(int pos = 0;pos<L;pos++)
				{
					if(A[a][pos] == B[b][pos] && localMap[pos] == 0) continue;
					else if(A[a][pos] == B[b][pos] && localMap[pos] == 2) 
					{
						localMap[pos] = 0;
						continue;
					}
					else if(A[a][pos] != B[b][pos] && localMap[pos] == 1) continue;
					else if(A[a][pos] != B[b][pos] && localMap[pos] == 2)
					{
						flips++;
						localMap[pos] = 1;
						continue;
					}
					else
					{
						works = false;
						break;
					}
				}
				if(!works) continue;
				// If A[a] and B[b] combination works.. Try others.
				// First create a final string list. 
				vector<string> input;
				for(int i = 0;i<N;i++)
				{
					string S = A[i];
					for(int j = 0;j<L;j++)
					{
						if(localMap[j] == 1) S[j] = ((S[j] == '1') ? '0' : '1');
					}
					input.push_back(S);
				}
				 

				// Now see if this is consistent. 
				sort(input.begin(),input.end());

				for(int i = 0;i<N;i++)
				{
					if(input[i] != B[i])
					{
						works = false; break;
					}
				}
				if(works) res = min(res,flips);
			}
			if(res == 2000) fout<<"NOT POSSIBLE\n";
			else fout<<res<<"\n";
	}
	fin.close();
	fout.close();
}