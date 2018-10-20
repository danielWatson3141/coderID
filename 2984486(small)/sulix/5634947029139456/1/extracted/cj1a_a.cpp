#include <iostream>
#include <cstdlib>
#include <vector>
#include <stdint.h>
#include <popcntintrin.h>
#include <x86intrin.h>
#include <algorithm>

using namespace std;

#define forl(i,a,b) for (int i = a; i < b; ++i)

int popcnt64(uint64_t val)
{
	return _mm_popcnt_u64(val);
}

bool sortcomp(const uint64_t& a, const uint64_t& b)
{
	return popcnt64(a) < popcnt64(b);
}

int main()
{
	int numCases;
	cin >> numCases;
	forl(caseNo, 1, numCases+1)
	{
		int numDevices;
		int length;
		vector<uint64_t> devices;
		vector<uint64_t> outlets;
		cin >> numDevices >> length;
		forl(i, 0, numDevices)
		{
			string bl;
			cin >> bl;
			uint64_t state = 0;
			forl(j,0,length)
			{
				state |= ((bl[j] == '1')?1:0)	<< j;
			}
			devices.push_back(state);

		}
		forl(i, 0, numDevices)
		{
			string bl;
			cin >> bl;
			uint64_t state = 0;
			forl(j,0,length)
			{
				state |= ((bl[j] == '1')?1:0)	<< j;
			}
			outlets.push_back(state);

		}

		sort(devices.begin(), devices.end());
		sort(outlets.begin(), outlets.end());
		int numbits = 0;
		int numvbit = -1;
		bool valid = true;
/*		forl(i,0,numDevices)
		{
			if (outlets[i] != devices[i])
				valid = false;
		}
		if (valid) numvbit = numbits;
		*/
		
		vector<uint64_t> bits;
		forl(j,0,numDevices)
		{
			bits.push_back(outlets[0]^devices[j]);
		}

		sort(bits.begin(), bits.end(), sortcomp);

		forl(j,0,numDevices)
		{
			vector<uint64_t> newdev = devices;
			//cout << "bits[j] = " << bits[j] << " size(" << popcnt64(bits[j]) << " )\n";
			forl(i,0,numDevices)
			{
				newdev[i] ^= bits[j];
			}
			sort(newdev.begin(), newdev.end());
			forl(i,0,numDevices)
			{
				if (outlets[i] != newdev[i])
				{
					//cerr << "comparing " << popcnt64(bits[j]) << " bits (" << bits[j] << " as " << outlets[i] << " vs " << newdev[i] << endl;
					goto next;
				}
			}
			numvbit = popcnt64(bits[j]);
			break;
next:
			continue;
		}
		cout << "Case #" << caseNo << ": ";
		if (numvbit == -1)
			cout << "NOT POSSIBLE";
		else
			cout << numvbit;
		cout << endl;

		

	}
	return 0;
}
