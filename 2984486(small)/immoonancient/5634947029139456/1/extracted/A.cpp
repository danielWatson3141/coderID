#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int caseN;
	cin >> caseN;
	for (int caseI = 1; caseI <= caseN; caseI++)
	{
		int n, m;
		cin >> n >> m;
		
		vector<string> outlets(n);
		vector<string> devices(n);
		
		for (int i = 0; i < n; i++)
			cin >> outlets[i];
		
		for (int i = 0; i < n; i++)
			cin >> devices[i];
		sort(devices.begin(), devices.end());
		
		int ans = m + 1;
		
		for (int j = 0; j < n; j++)
		{
			vector<string> outlets2 = outlets;
			
			int cur = 0;
			for (int k = 0; k < m; k++)
				if (outlets[0][k] != devices[j][k])
				{
					cur++;
					for (int i = 0; i < n; i++)
						if (outlets2[i][k] == '0')
							outlets2[i][k] = '1';
						else
							outlets2[i][k] = '0';
				}
			
			sort(outlets2.begin(), outlets2.end());
			
			if (outlets2 == devices)
				ans = min(ans, cur);
		}
		
		cout << "Case #" << caseI << ": ";
		if (ans > m)
			cout << "NOT POSSIBLE" << endl;
		else
			cout << ans << endl;
	}
	
	return 0;
}
