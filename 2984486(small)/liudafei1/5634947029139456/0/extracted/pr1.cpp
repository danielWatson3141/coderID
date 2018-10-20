#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <fstream>
using namespace std;

int minNumCh = INT_MAX;

void enumBit( int cur, vector<string> & vSrc, unordered_set<string>& vStd , vector<bool>& bits )
{
	if(cur == bits.size())
	{
		vector<string> vCopy = vSrc;
		int ch = 0;
		for( int j =0; j < bits.size(); ++j )
			if(bits[j])
				ch++;


		for (int i = 0; i < vCopy.size(); ++i)
		{
			for( int j =0; j < bits.size(); ++j )
			{
				if(bits[j])
				{
					if (vCopy[i][j]=='1')
						vCopy[i][j]='0';
					else
						vCopy[i][j]='1';
				}
			}
		}

		unordered_set<string> setCopy;
		for (int i = 0; i < vCopy.size();++i)
			setCopy.insert(vCopy[i]);

					
		for( unordered_set<string>::iterator ite = setCopy.begin(); ite != setCopy.end(); ite++ )
			if( vStd.find(*ite) == vStd.end() )
				return;

		if(ch<minNumCh)
			minNumCh = ch;
	}
	else
	{
		bits[cur] = false;
		enumBit(cur+1,vSrc,vStd,bits);
		bits[cur] = true;
		enumBit(cur+1,vSrc,vStd,bits);
	}
}

void isPossible( vector<string> & vSrc, vector<string>& vStd  )
{
	vector<bool> bits(vStd[0].size(),false);
	unordered_set<string> stdMap;

	for (int i = 0; i < vStd.size(); ++i)
		stdMap.insert(vStd[i]);
	enumBit(0,vSrc,stdMap,bits);
}




int main()
{
	ifstream cin("A-small-attempt1.in");
	ofstream cout("A-small-attempt1.out");
	int T;
	cin >> T;
	for( int s = 1;s <= T; ++s )
	{
		minNumCh = INT_MAX;
		int N,L;
		cin >> N >> L;

		vector<string> vecStd(N);
		vector<string> vecSrc(N);

		for( int i = 0; i < N; ++i )
			cin >> vecStd[i];

		for(int i = 0; i < N; ++i)
			cin >> vecSrc[i];

		isPossible(vecSrc,vecStd);
		if(minNumCh == INT_MAX)
			cout <<"Case #"  << s << ": " << "NOT POSSIBLE" << endl; 
		else
			cout <<"Case #"  << s << ": " << minNumCh << endl;
	}
	return 0;
}