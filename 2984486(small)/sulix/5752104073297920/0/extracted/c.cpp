#include <iostream>
#include <cstdlib>
#include <vector>
#include <stdint.h>
#include <algorithm>
#include <cmath>

using namespace std;

#define forl(i,a,b) for (int i = a; i < b; ++i)

int good(int num)
{
	vector<int> nums;
	forl(i,0,num) nums.push_back(i);
	forl(i,0,num)
	{
		int p = rand()%(num - i);
		swap(nums[i], nums[i + p]);
	}
	int count = 0;
	forl(i,0,num)
	{
		if (nums[i] == i-1) count += 1;
	}
	cout << "Good: " << count<<endl;
return 0;
}

int bad(int num)
{
	vector<int> nums;
	forl(i,0,num) nums.push_back(i);
	forl(i,0,num)
	{
		int p = rand()%(num);
		swap(nums[i], nums[ p]);
	}
	int count = 0;
	forl(i,0,num)
	{
		if (nums[i] == i) count += 1;
	}
	cout << "Bad: " << count<<endl;
return 0;//count;
}



int main()
{
	srand(time(0));
	int numCases;
	cin >> numCases;
	forl(caseNo, 1, numCases+1)
	{
		int permLength;
		int count = 0;
		double prob = 0;
		cin >> permLength;
		forl(i,0, permLength)
		{
			int num;
			cin >> num;
			if (num == i+1)
			{
				count++;
				//prob += (double)num/(permLength-i);
			}
		}

		prob = (double)count / double(permLength);
//		cerr << count << " " << permLength << " " << prob << endl;
//		cerr <<  pow(1.0/permLength,permLength-1);

		cout << "Case #" << caseNo << ": ";
		if (count == 1 && rand()&1) count++;
		if (count > 1)
			cout << "BAD";
		else
			cout << "GOOD";
		cout << endl;

		

	}/*
	int64_t goodsum = 0, badsum = 0;
	forl(i,0,100)
	{
		goodsum += good(1000);
		badsum += bad(1000);
	}
	cout << goodsum << " " << badsum << endl;*/
	return 0;
}
