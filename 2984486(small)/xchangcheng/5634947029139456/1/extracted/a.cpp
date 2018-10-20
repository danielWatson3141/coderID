#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

int T = 0, N = 0, L = 0;
string *src, *dst;

int main()
{
	ifstream fin("A-large.in");
	ofstream fout("test.out");

	fin >> T;
	for(int i = 1;i <= T;i++)
	{
		fin >> N >> L;
		src = new string[N + 1];
		dst = new string[N + 1];
		for(int j = 0;j < N;j++)
			fin >> src[j];
		for(int j = 0;j < N;j++)
			fin >> dst[j];
		
		int Y = L + 1;
		
		for(int k = 0;k < N;k++)
		{
			int change[L + 1];
			memset(change, 0, sizeof(int) * (L + 1));
			
			//the first of src switch to the kth of the dst
			int curNum = 0;
			for(int t = 0;t < L;t++)
			{
				if(src[0][t] != dst[k][t])
				{
					//switch the tth
					change[t] = 1;
					for(int m = 0;m < N;m++)
					{
						if(src[m][t] == '0')
							src[m][t] = '1';
						else
							src[m][t] = '0';
					}
					curNum++;
				}
			}
			//check if it is right
			//cout << "To " << k << " Num = " << curNum <<  endl;

			bool curFlag = true;
			for(int t = 0;t < N;t++)
			{
				bool find = false;
				for(int m = 0;m < N;m++)
				{
					if(src[t] == dst[m])
					{
						find = true;
						break;
					}
					else
						continue;
				}
			//	cout << "find #" << t << " " << find << endl;
				if(find == false)
				{
					curFlag = false;
					break;
				}
			}

			if(curFlag)
				Y = (curNum < Y) ? curNum : Y;
			
			for(int t = 0;t < L;t++)
			{
				if(change[t] == 1)
				{
					for(int m = 0;m < N;m++)
					{
						if(src[m][t] == '0')
							src[m][t] = '1';
						else
							src[m][t] = '0';
					}
				}
			}
		}

		fout << "Case #" << i << ": ";
		if(Y != L + 1)
			fout << Y << endl;
		else
			fout << "NOT POSSIBLE" << endl;
	}

	return 0;
}