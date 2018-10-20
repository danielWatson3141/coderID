#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int caseN;
	cin >> caseN;
	
	for (int caseI = 1; caseI <= caseN; caseI++)
	{
		int n;
		cin >> n;
		string ans;
		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			if (i == 0)
			{
				if (a < 500)
					ans = "BAD";
				else
					ans = "GOOD";
			}
		}
		
		cout << "Case #" << caseI << ": " << ans << endl;
	}
	
	return 0;
	
	return 0;
}
