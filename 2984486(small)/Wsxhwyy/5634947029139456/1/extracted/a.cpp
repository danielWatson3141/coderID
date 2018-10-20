#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> veca, vecb, vect;

void cb(vector<string>& vec, int bit)
{
    for (int i = 0; i < vec.size(); i++)
	if(vec[i][bit] == '0')
	    vec[i][bit] = '1';
	else
	    vec[i][bit] = '0';
}

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
	int n, l;
	cin >> n >> l;
	veca.clear();
	vecb.clear();
	veca.resize(n);
	vecb.resize(n);
	for (int i = 0; i < n; i++)
	    cin >> veca[i];
	for (int i = 0; i < n; i++)
	    cin >> vecb[i];
	sort(veca.begin(), veca.end());
	int ans = 100000;
	for (int i = 0; i < n; i++)
	{
	    vect = vecb;
	    int cnt = 0;
	    for (int j = 0; j < l; j++)
		if (veca[0][j] != vect[i][j])
		{
		    cnt++;
		    cb(vect, j);
		}
	    sort(vect.begin(), vect.end());
	    bool can = true;
	    for (int k = 0; k < n; k++)
		if (veca[k] != vect[k])
		{
		    can = false;
		    break;
		}
	    if (can)
		ans = min(ans, cnt);
	}
	cout << "Case #" << t << ": ";
	if (ans == 100000)
	    cout << "NOT POSSIBLE" << endl;
	else
	    cout << ans << endl;
    }
}

