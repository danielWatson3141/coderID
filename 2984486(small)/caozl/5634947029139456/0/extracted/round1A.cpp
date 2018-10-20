// 2014rnd1a.cpp : 定义控制台应用程序的入口点。
//


#include "stdafx.h"
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
	//#include <cmath>
#include <cstdlib>
#include <ctime>
#include <math.h>

	using namespace std;

void main1()
{
	int nT;
	cin >> nT;
	for (int i = 0; i < nT; i++)
	{
		int n = 0; 
		int l = 0;
		cin >> n >> l;
		vector<string> strArr1(n);
		vector<string> strArr2(n);
		for (int j = 0; j < n; j++)
		{
			cin >> strArr1[j];
		}
		for (int j = 0; j < n; j++)
		{
			cin >> strArr2[j];
		}

		vector<int> nArr1(l, 0);
		vector<int> nArr2(l, 0);
		for (int j = 0; j < l; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (strArr1[k][j] == '1')
				{
					nArr1[j]++;
				}
				if (strArr2[k][j] == '1')
				{
					nArr2[j]++;
				}
			}
		}

		vector<int> nMaybeArr;
		vector<int> nNeedArr;
		bool bPossible = true;

		for (int j = 0; j < l; j++)
		{
			if (n%2==0 && nArr1[j] == nArr2[j] && nArr1[j] == n/2)
			{
				nMaybeArr.push_back(j);
				continue;
			}
			if (nArr1[j] == n-nArr2[j])
			{
				nNeedArr.push_back(j);
				continue;
			}
			if (nArr1[j] != nArr2[j])
			{
				bPossible = false;
				break;
			}
		}

		cout << "Case #" << i+1 << ": ";

		if (!bPossible)
		{
			cout << "NOT POSSIBLE" << endl;
			continue;
		}

		sort(strArr1.begin(), strArr1.end());

		for (int j = 0; j < nNeedArr.size(); j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (strArr2[k][nNeedArr[j]] == '1')
				{
					strArr2[k][nNeedArr[j]] = '0';
				}
				else
				{
					strArr2[k][nNeedArr[j]] = '1';
				}
			}
		} 
		sort(strArr2.begin(), strArr2.end());
		if (strArr1 == strArr2)
		{
			cout << nNeedArr.size() << endl;
			continue;
		}

		long allSize = pow(2.0, (int)nMaybeArr.size());
		int nPos = -1;
		map<int,vector<int>> nArrMap;
		for (int j = 1; j < allSize; j++)
		{
			int nTemp = j;
			int nWei = 0;
			while (nTemp!=0)
			{
				if (nTemp%2 == 1)
				{
					nWei++;
				}
				nTemp = nTemp/2;
			}
			nArrMap[nWei].push_back(j);
		}
		for (auto a = nArrMap.begin(); a!= nArrMap.end(); ++a)
		{
			if (nPos>=0)
			{
				break;
			}
			for (int j = 0; j < a->second.size(); j++)
			{
				vector<string> strArr2T = strArr2;
				int nTemp = a->second[j];
				int nWei = 0;
				while (nTemp!=0)
				{
					if (nTemp%2 == 1)
					{
						for (int k = 0; k < n; k++)
						{
							if (strArr2T[k][nMaybeArr[nMaybeArr.size()-1-nWei]] == '1')
							{
								strArr2T[k][nMaybeArr[nMaybeArr.size()-1-nWei]] = '0';
							}
							else
							{
								strArr2T[k][nMaybeArr[nMaybeArr.size()-1-nWei]] = '1';
							}
						}
					}
					nTemp = nTemp/2;
					nWei++;
				}
				sort(strArr2T.begin(), strArr2T.end());
				if (strArr1 == strArr2T)
				{
					nPos = a->second[j];
					break;
				}
			}
		}
		
		if (nPos == -1)
		{
			cout << "NOT POSSIBLE" << endl;
			continue;
		}
		else
		{
			int nTemp = nPos;
			int nAn = nNeedArr.size();
			while (nTemp!=0)
			{
				if (nTemp%2 == 1)
				{
					nAn++;
				}
				nTemp = nTemp/2;
			}
			cout << nAn << endl;
			continue;
		}
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	main1();
	return 0;
}
