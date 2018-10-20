#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

bool next(unsigned long long &x, unsigned long long last)
{
    if (x == last) return false;
    unsigned long long r, s;
    s = x & (-(long long)x);
    r = s + x;
    x = r | (((x ^ r) >> 2) / s);
    return true;
}

unsigned long long convertString(string& s)
{
	unsigned long long res = 0;
	int len = s.length();

	for (int i=0; i<len; i++)
	{
		unsigned char ch = s.c_str()[i];
		res |= (ch-'0') << (len-i-1);
	}

	return res;
}

void switchControl(unsigned long long orgcontrol[], unsigned long long control[], unsigned long long flag, int n)
{
	for (int i=0; i<n; i++)
	{
		control[i] = orgcontrol[i] ^ flag;
	}
}

int cmp(const void *a , const void *b )
{
	return *(unsigned long long *)a > *(unsigned long long *)b ? 1 : -1;
}
void sortControl(unsigned long long control[], int n)
{
	qsort(control, n, sizeof(long long), cmp);
}

bool compareControlDevice(unsigned long long control[], unsigned long long device[], int n)
{
	bool res = true;
	for (int i=0; i<n; i++)
	{
		if (control[i] != device[i])
		{
			return false;
		}
	}
	return res;
}

int main()
{
	int nCase = 0;
	int N, L;
	string s;
	
	unsigned long long orgcontrol[150];
	unsigned long long control[150];	
	unsigned long long device[150];
	
	cin >> nCase;
	for (int i=0; i<nCase; i++)
	{		
		cin >> N >> L;
		
		// read input
		for(int j=0; j<N; j++)
		{
			cin >> s;
			orgcontrol[j] = convertString(s);
		}

		for (int j=0; j<N; j++)
		{
			cin >> s;
			device[j] = convertString(s);
		}

		sortControl(device, N);
		bool res = false;
		for (int j=0; j<L; j++)
		{			
			// 翻转j个控制台
			unsigned long long first = (1<<j) - 1;
			unsigned long long mask = (1 << L) - 1;
			unsigned long long last = (first << (L-j)) & mask;

			do
			{
				switchControl(orgcontrol, control, first, N);

				// 排序
				sortControl(control, N);

				// 比较
				res = compareControlDevice(device, control, N);

				if (res)
				{
					break;
				}			
			}while(next(first, last));

			if (res)
			{
				cout << "Case #" << i+1 <<": " << j << endl;
				break;
			}
		}

		if (!res)
		{
			cout << "Case #" << i+1 <<": NOT POSSIBLE" << endl;
		}
	}
	return 0;
}