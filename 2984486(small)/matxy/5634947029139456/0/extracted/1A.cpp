#include <set>
#include <vector>
#include <cstdio>
#include <string>
#include <iostream>
#include <iomanip>
#include <map>
#include <algorithm>
#include <cmath>

#define _DEBUG 0

using namespace std;

/************
general types
*************/

typedef set<int> tSet[4];
typedef enum { OK, NOTOK } tenResultType;

/*****************
input type
****************/

typedef struct
{
	int N;
	int L;
	set<string> cs;
	set<string> creq;
} tstInput;

/***************
result type
*****************/

typedef struct
{
	tenResultType type;
	int no;
} tstResult;

/****************
input getter
******************/

void vGetInput(tstInput & in)
{
	int i,j,k;
	cin >> in.N >> in.L;
	for (i=0;i<in.N;++i)
	{
		string s;
		// vector<bool> b;
		cin >> s;
		// for (j=0;j<in.L;++j)
		// {
			// bool bit = s[j] == '1';
			// b.push_back(bit);
		// }
		in.cs.insert(s);
	}
	for (i=0;i<in.N;++i)
	{
		string s;
		// vector<bool> b;
		cin >> s;
		// for (j=0;j<in.L;++j)
		// {
			// bool bit = s[j] == '1';
			// b.push_back(bit);
		// }
		in.creq.insert(s);
	}	
}

/*******************
result getter
********************/

void vGetResult(tstInput & in, tstResult & out)
{
	bool found = false;
	unsigned int swi = 0;
	unsigned int swend = pow(2, in.L)-1;
	set<string> wrk = in.cs;
	int i,j,k;
	int count = 99999;
	while (swi <= swend)
	{
		int bits=0;
		
		for (i=0;i<in.L;++i)
		{
			if (swi & (1<<i))
				++bits;
		}
		if (bits < count)
		{
			wrk = in.cs;
			vector<string> ws(wrk.begin(),wrk.end());	
			for (i=0;i<in.L;++i)
			{
				if (swi & (1<<i))
				{
					for (j=0;j<ws.size();++j)
					{					
						ws[j][in.L-i-1] =  ws[j][in.L-i-1] == '1' ? '0' : '1';
					}
				}
			}
			wrk.clear();
			wrk.insert(ws.begin(), ws.end());
		
			if (wrk == in.creq)
			{
				found = true;
				count = bits;
			}
		}
		
		++swi;
	}
	
	if(found)
	{
		out.type = OK;
		out.no = count;
	}
	else
	{
		out.type = NOTOK;
	}
			
		

}

/*******************
result printer
********************/

void vPrintResult(int c, tstResult & r)
{
	cout << "Case #" << c << ": ";
	switch (r.type)
	{
		case OK:
			cout << r.no;
			break;
		default:
			cout << "NOT POSSIBLE";
			break;
	}
	cout << endl;		
}

/*******************
driver
********************/

int main()
{
	int n;
	int i;
	
	cin >> n;
	
	for (i=1;i<=n;++i)
	{
		tstInput in;
		tstResult res;
		vGetInput(in);
		vGetResult(in, res);
		vPrintResult(i, res);
	}

	return 0;
}