#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

void loadValues(vector<unsigned>& x, int N, int L)
{
	for(int n = 0; n < N; n++)
	{
		string temp;
		cin >> temp;
		unsigned val = 0;
		for(int l = 0; l < L; l++)
		{
			val = val << 1 | unsigned(temp[l] - '0');				
		}
		x[n] = val;
	}
}

bool tryAll(vector<vector<unsigned>>& positions, vector<unsigned>& in, int N)
{
	while(true)
	{
		set<unsigned> x;
		for(int i = 0; i < N; i++)
		{
			x.insert(positions[i][in[i]]);
		}
		if(x.size() == N)
		{
			return true;
		}
		bool beginning = true;
		for(int i = 0; i < N; i++)
		{
			if(in[i] < positions[i].size()-1)
			{
				in[i]++;
				beginning = false;
				break;
			}
			else
			{
				in[i] = 0;
			}
		}
		if(beginning)		
		{
			return false;
		}
	}
}

int main()
{
	int T;
	cin >> T;
	for(int t = 0; t < T; t++)
	{
		cout << "Case #" << t+1 << ": ";
		int N, L;
		cin >> N >> L;
		vector<unsigned> flow1(N);
		loadValues(flow1, N, L);
		vector<unsigned> flow2(N);
		loadValues(flow2, N, L);
		vector<vector<unsigned>> table(N, vector<unsigned>(N));
		vector<vector<unsigned>> table2(N, vector<unsigned>(N));
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				table[i][j] = flow1[i] ^ flow2[j];	
				unsigned sum = 0;
				unsigned val = table[i][j];
				for(int k = 0; k < L; k++)
				{				
					sum += val % 2;
					val = val >> 1;
				}
				table2[i][j] = sum;
			}
		}
		vector<set<unsigned>> sets(N);
		for(int i = 0; i < N; i++)
		{
			sets[i].insert(table[i].begin(), table[i].end());
		}
		set<unsigned> common1(sets[0].begin(), sets[0].end());
		for(int i = 1; i < N; i++)
		{
			vector<unsigned> v(common1.size());
			vector<unsigned>::iterator it = set_intersection(common1.begin(),common1.end(), sets[i].begin(), sets[i].end(), v.begin());			
			common1 = set<unsigned>(v.begin(), it);
		}
		int S = common1.size();
		set<unsigned> common;
		for(set<unsigned>::iterator it = common1.begin(); it != common1.end(); it++)
		{
			unsigned sum = 0;
			unsigned val = *it;
			for(int k = 0; k < L; k++)
			{				
				sum += val % 2;
				val = val >> 1;
			}
			common.insert(sum);
		}
		if(S == 1)
		{
			cout << *(common.begin()) << endl;
		}
		else if(S == 0)
		{
			cout << "NOT POSSIBLE" << endl;
		}
		else
		{			
			bool found = false;			
			for(set<unsigned>::iterator it = common.begin(); it != common.end(); it++)
			{
				vector<vector<unsigned>> positions(N);
				for(int i = 0; i < N; i++)
				{
					for(int j = 0; j < N; j++)
					{
						if(table2[i][j] == *it)
						{
							positions[i].push_back(j);
						}
					}
				}

				vector<unsigned> in(N, 0);
				if(tryAll(positions, in, N))
				{
					cout << *it << endl;
					found = true;
					break;
				}
			}
			if(!found)
			{
				cout << "NOT POSSIBLE" << endl;
			}
		}
	}	
}