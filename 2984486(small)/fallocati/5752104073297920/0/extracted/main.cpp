#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

bool solve(int n, vector<int>& perm);

void main()
{
	// cout << fixed;
	// cout << setprecision(7);
	
	int cases;
	cin >> cases;
	
	for(int c = 1; c <= cases; c++)
	{
		int n;
		
		cin >> n;
		
		vector<int> perm;
		
		int a;
		
		for(int i = 0; i < n - 1; i++)
		{
			cin >> a;			
			perm.push_back(a);
		}
				
		cout << "Case #" << c << ": ";
		
		if(solve(n, perm))
		{
			cout << "GOOD";
		}
		else
		{
			cout << "BAD";
		}
		
		cout << endl;		
	}
}

bool solve(int n, vector<int>& perm)
{
	double margin = 0.1;
	
	int mid = floor((double)n / 2);
	
	int count = 0;
	
	for (int i = 0; i <= mid; i++)
	{
		if (perm[i] <= mid)
		{
			count++;
		}
	}
	
	//cout << "Perc: " << ((double)count / (double)n) << endl;
	
	return ((double)count / (double)n) <= margin;
}