/*
 * round1aa.cpp
 *
 *  Created on: 2014-04-25
 *      Author: aabdelsa
 */

#include <cstdio>
#include <cstdlib>
#include <string>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <memory.h>
using namespace std;


vector<string> outlets;
vector<string> devices;

vector<set<string> > xors;

int main ()
{
	freopen("A-large.in","r",stdin);
	freopen("a.out","w",stdout);

	int cases;
	cin >> cases;

	for ( int t = 1; t<=cases; t++)
	{
		outlets.clear();
		devices.clear();
		xors.clear();
		int N,L;

		cin >> N >> L;

		for ( int i = 0 ; i < N ; i ++ )
		{
			string s;
			cin >> s;
			outlets.push_back(s);
		}

		for ( int i = 0 ; i < N ; i ++ )
		{
			string s;
			cin >> s;
			devices.push_back(s);
		}

		for(int i =0 ;i < N ; i ++ )
		{
			set<string> st;
			for ( int j = 0 ; j < N ; j ++ 	)
			{
				string curXor = "";
				for ( int k = 0; k < L; k ++ )
				{
					if ( outlets[i][k] == devices[j][k])
						curXor += '0';
					else
						curXor += '1';
				}
				st.insert (curXor);
			}
			xors.push_back(st);
		}

		int res = 10000;

		for ( set<string>::iterator it = xors[0].begin(); it != xors[0].end(); ++it)
		{
			string cur = *it;

			bool ok = 1;
			for ( int i = 1; i < xors.size(); i ++ )
			{
				if ( xors[i].find(cur) == xors[i].end() )
				{
					ok = 0;
					break;
				}
			}

			if ( ok)
			{
				int flips = 0;
				for ( int i = 0 ; i < cur.size() ; i ++ )
					if ( cur[i] == '1')
						flips ++;
				if ( flips < res )
					res = flips;
			}
		}


		cout <<"Case #"<< t <<": ";
		if ( res == 10000)
			cout <<"NOT POSSIBLE"<< endl;
		else cout << res << endl;

	}
	return 0;
}
