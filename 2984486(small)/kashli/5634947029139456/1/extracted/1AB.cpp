/*
 * 1AA.cpp
 *
 *  Created on: Apr 26, 2014
 *      Author: Ganesh
 */


#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <gmp.h>
#include <gmpxx.h>
#include <string>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <vector>

using namespace std;

struct s
{
	int count;
	vector<int> p;
};


int flips_needed(string a, string b, vector<int> &pointsChanged)
{
	int count = 0;
	for(int i=0 ; i<a.length() ; i++)
	{
		if(a[i]!=b[i])
		{
			count++;
			pointsChanged.push_back(i);
		}
	}
	return count;
}
int next_min(vector<s> a, int min)
{
	int min_here = 10000000;
	for(int i=0 ; i<a.size() ; i++)
	{
		if((a[i].count > min) && (a[i].count < min_here))
			min_here = a[i].count;
	}
	return min_here;
}
int main()
{
	int cases;
	cin>>cases;
	for(int q=0 ; q<cases ; q++)
	{
		int N, L;
		cin>>N>>L;
		vector<string> devices, outlets;
		string a;
		for(int i=0 ; i<N ; i++)
		{
			cin>>a;
			devices.push_back(a);
		}
		for(int i=0 ; i<N ; i++)
		{
			cin>>a;
			outlets.push_back(a);
		}
		vector<vector<s> > S;
		S.resize(N);
		for(int i=0 ; i<N ; i++)
		{
			S[i].resize(N);
		}
		for(int i=0 ; i<N ; i++)
		{
			for(int j=0 ; j<N ; j++)
			{
				S[i][j].count = flips_needed(devices[i], outlets[j], S[i][j].p);
			}
		}

		int n_min = -1;
		bool found = false;
		for(int i=0 ; i<N ; i++)
		{
			bool sorry = true;
			n_min = next_min(S[0], n_min);
			for(int j=0 ; j<N ; j++)
			{
				if(S[0][j].count == n_min)
				{
					//bool poss = true;
					//vector<int> points = S[0][j].p;
					bool j_poss = true;
					for(int k=1 ; k<N ; k++)
					{
						bool i_done = false;
						for(int l=0 ; l<N ; l++)
						{
							if(S[k][l].count == S[0][j].count)
							{
								int count = 0;
								for(unsigned int m=0 ; m<S[k][l].p.size() ; m++)
								{
									if(S[k][l].p[m] != S[0][j].p[m])
										break;
									else
										count++;
								}
								if(count == S[0][j].count)
								{
									i_done = true;
									break;
								}
							}
						}
						if(!i_done)
						{
							j_poss = false;
							break;
						}

					}
					if(j_poss == true)
					{
						sorry = false;
						break;
					}
				}
			}
			if(sorry == false)
			{
				found = true;
				break;
			}
		}
		cout<<"Case #"<<q+1<<": ";
		if(!found)
			cout<<"NOT POSSIBLE\n";
		else
			cout<<n_min<<"\n";

	}
	return 0;
}




