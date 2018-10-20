#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <set>
#include <algorithm>
#include <sstream>

using namespace std;

int main()
{
	freopen("C:\\Projects\\gcj\\input.txt", "r", stdin);
	freopen("C:\\Projects\\gcj\\output.txt", "w", stdout);

	int z;
	cin >> z;
	
	int pos = 0;
	for (int q=0;q<z;q++) {
		int n;
		cin >> n;
		vector<int> vals(n);
		for (int i=0;i<n;i++)
			cin >> vals[i];

		int val = 0;
		for (int i=0;i<n;i++) {
			val += vals[i] - i;
		}

		int res = 0;
		int ctr=0;
		for (int i=2;i<=(1<<9);i*=2,ctr++) {
			int count = 0;
			for (int j=0;j<n/i;j++) {
				if (vals[j] > n - n/i)
					count++;
			}
			//cout << n/i << " " << count << " " << n/i/2 << endl;
			res += count * i;
		}

		cout << "Case #" << (q+1) << ": ";
		if (res > 880) {
			cout << "BAD" << endl;
		}
		else {
			cout << "GOOD" << endl;
			pos++;
		}

	}

	//cout << pos << endl;
	fclose(stdout);
	fclose(stdin);

	return 0;
}