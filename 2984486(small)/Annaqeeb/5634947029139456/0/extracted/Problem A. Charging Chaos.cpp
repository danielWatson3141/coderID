#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	long long outlet[150];
	long long device[150];
	long long tempOutlet[150];
	long long switches;
	int N, L, iN, iL, iDevice, iOutlet;
	bool canCharge;
	int flips;
	string s;
	freopen("Problem A. Charging Chaos.in", "r", stdin);
	freopen("Problem A. Charging Chaos.out", "w", stdout);

	int T, iT;
	cin >> T;
	for (iT = 1; iT <= T; iT++)
	{

		cin >> N >> L;
		for (iOutlet = 0; iOutlet < N; iOutlet++)
		{
			cin >> s;
			outlet[iOutlet] = stoll(s, nullptr, 2);

		}

		
		for (iDevice = 0; iDevice < N; iDevice++)
		{
			cin >> s;
			device[iDevice] = stoll(s, nullptr, 2);
		}
		

		sort(outlet, outlet + N);
		sort(device, device + N);
		for (iDevice = 0; iDevice < N; iDevice++)
		{
			canCharge = true;
			switches = device[iDevice] ^ outlet[0];
			copy(outlet, outlet + N, tempOutlet);
			
			for (iOutlet = 0; iOutlet < N; iOutlet++)
			{
				tempOutlet[iOutlet] ^= switches;
			}
			sort(tempOutlet, tempOutlet + N);
			for (iOutlet = 0; iOutlet < N; iOutlet++)
			{
				if (device[iOutlet] != tempOutlet[iOutlet])
				{
					canCharge = false;
					continue;
				}

			}
			if (canCharge) break;
		}
		cout << "Case #" << iT << ": ";
		if (canCharge)
		{
			flips = 0;
			while (switches != 0)
			{
				flips += switches % 2;
				switches /= 2;
			}
			 cout<< flips << "\n";
		
		}
		else
		{
			cout << "NOT POSSIBLE\n";
		}
	}
}