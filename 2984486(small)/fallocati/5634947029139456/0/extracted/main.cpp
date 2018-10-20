#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h> 
#include <math.h>

using namespace std;

int solve(int size, int length, vector<long long>& outletFlows, vector<long long>& devicesFlows);

long long parseFixedBinary(int length, string input)
{
	long long res = 0;
	
	for (int i = length - 1; i >= 0; i--)
	{
		if(input[i] == '1')
		{		
			res += pow(2.f, i);
		}
	}
	
	return res;
}

void main()
{
	//cout << fixed;
	//cout << setprecision(7);
	
	int cases;
	cin >> cases;
	
	for(int c = 1; c <= cases; c++)
	{
		int size, length;
		
		cin >> size;
		cin >> length;
		
		vector<long long> outletFlows;
		vector<long long> devicesFlows;
		
		string dummy;
		long long dummy2;
		
		for(int i = 0; i < size; i++)
		{
			cin >> dummy;
			dummy2 = parseFixedBinary(length, dummy);

			outletFlows.push_back(dummy2);
		}

		for(int i = 0; i < size; i++)
		{
			cin >> dummy;
			dummy2 = parseFixedBinary(length, dummy);
			
			devicesFlows.push_back(dummy2);
		}

		int ans = solve(size, length, outletFlows, devicesFlows);
		
		if (ans == -1)
		{
			cout << "Case #" << c << ": " << "NOT POSSIBLE" << endl;
		}
		else
		{
			cout << "Case #" << c << ": " << ans << endl;
		}
	}
}

int bitCount(long long a)
{
	int orig = a;
    int count = 0;
	
    while(a > 0)
    {
        a = a >> 1 << 1;
		
        if(orig - a == 1)
		{
            count++;
		}
		
        orig = a >> 1;
        a = orig;
    }
	
	return count;
}

bool arePermutations(int size, vector<long long>& outletFlows, vector<long long>& devicesFlows)
{
	sort(outletFlows.begin(), outletFlows.end());
	sort(devicesFlows.begin(), devicesFlows.end());
	
	for (int i = 0; i < size; i++)
	{
		if (outletFlows[i] != devicesFlows[i])
		{
			return false;
		}
	}
	
	return true;
}

int solve(int size, int length, vector<long long>& outletFlows, vector<long long>& devicesFlows)
{
	long long max = (long long) pow((double)2, length);
	
	for (long long switches = 0; switches < max; switches++)
	{
		for (int i = 0; i < size; i++)
		{
			outletFlows[i] = outletFlows[i] ^ switches;
		}
		
		if (arePermutations(size, outletFlows, devicesFlows))
		{
			return bitCount(switches);
		}
		
		for (long long i = 0; i < size; i++)
		{
			outletFlows[i] = outletFlows[i] ^ switches;
		}
	}
	
	return -1;
}