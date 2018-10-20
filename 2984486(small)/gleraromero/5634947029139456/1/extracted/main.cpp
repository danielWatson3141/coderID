#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <math.h>
#include <string>
#include <cstdio>

using namespace std;

void swapOutletPosition(vector<string>& outlets, int pos, int N)
{
    for (int j = 0; j < N; ++j)
    {
        outlets[j][pos] = (outlets[j][pos] == '0') ? '1' : '0';
    }
}

bool fitDevices(const vector<string>& outlets, vector<string>& devices, int next, int N)
{
    if (next == N)
        return true;

    for (int d = next; d < N; ++d)
    {
        if (devices[d] == outlets[next])
        {
            swap(devices[d],devices[next]);
            bool doFit = fitDevices(outlets, devices, next+1, N);
            swap(devices[d],devices[next]);
            if (doFit)
            {
                return true;
            }
        }
    }

    return false;
}

int minOutletSwaps(vector<string>& outlets, vector<string>& devices, int N, int L)
{
    int minSwaps = L+1;
    for (int d = 0; d < N; ++d)
    {
        // Adjust first outlet so it fits device d.
        vector<string> outletsFirstD(outlets);
        int swaps = 0;
        for (int i = 0; i < L; ++i)
        {
            if (outletsFirstD[0][i] != devices[d][i])
            {
                swaps++;
                swapOutletPosition(outletsFirstD, i, N);
            }
        }

        // Test if the other devices fit.
        bool doFit = fitDevices(outletsFirstD, devices, 0, N);

        if (doFit)
        {
            minSwaps = min(minSwaps, swaps);
        }
    }

    return minSwaps;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
        cout << "Case #" << t << ": ";

		int N, L;
        cin >> N >> L;

        vector<string> outlets(N);
        vector<string> devices(N);

        for (int i = 0; i < N; ++i)
            cin >> outlets[i];

        for (int i = 0; i < N; ++i)
            cin >> devices[i];

        int answer = minOutletSwaps(outlets, devices, N, L);

        if (answer == L+1)
        {
            cout << "NOT POSSIBLE";
        }
        else
        {
            cout << answer;
        }

        cout << endl;
	}
	
	return 0;
}