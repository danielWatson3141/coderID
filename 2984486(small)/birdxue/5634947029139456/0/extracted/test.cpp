#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <fstream>
using namespace std;

#define MAXN 155
string outlet[ MAXN ];
string outc[ MAXN ];
string need[ MAXN ];
int T, N, L;
bool flag;

void search(int s, int k, int x)
{
	if (s == x)
	{
		sort(outc, outc + N);
		for (int i = 0; i < N; i ++)
		{
			if (outc[ i ].compare(need[ i ]) != 0)
			{
				return;
			}
		}
		flag = true;
		return;
	}

	if (k >= L)
	{
		return;
	}

	search(s, k + 1, x);

	if (flag)
	{
		return;
	}

	for (int j = 0; j < N; j ++)
	{
		outc[ j ][ k ] = (outc[ j ][ k ] - '0' + 1) % 2 + '0';
	}
	search(s + 1, k + 1, x);
	for (int j = 0; j < N; j ++)
	{
		outc[ j ][ k ] = (outc[ j ][ k ] - '0' + 1) % 2 + '0';
	}
	if (flag)
	{
		return;
	}
}

int main()
{
	fstream in("test.in");
	fstream out("res");

//	cin>>T;
	in>>T;

	for (int t = 1; t <= T; t ++)
	{
//		cin>>N>>L;
		in>>N>>L;
		for (int i = 0; i < N; i ++)
		{
//			cin>>outlet[ i ];
			in>>outlet[ i ];
		}
		for (int i = 0; i < N; i ++)
		{
//			cin>>need[ i ];
			in>>need[ i ];
		}
		
		sort(need, need + N);

		flag = false;
		for (int i = 0; i <= L; i ++)
		{
			for (int j = 0; j < N; j ++)
			{
				outc[ j ] = outlet [ j ];
			}

			search(0, 0, i);
			if (flag)
			{
//				cout<<"Case #"<<t<<": "<<i<<endl;
				out<<"Case #"<<t<<": "<<i<<endl;
				break;
			}
		}
		if (!flag)
		{
//			cout<<"Case #"<<t<<": "<<"NOT POSSIBLE"<<endl;
			out<<"Case #"<<t<<": "<<"NOT POSSIBLE"<<endl;
		}
	}

	return 0;
}