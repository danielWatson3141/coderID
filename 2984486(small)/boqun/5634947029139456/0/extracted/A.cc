#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

int T;
int N;
int L;
string temp;
long long o[150];
long long d[150];
long long tmp[150];


long long s2l(const string& s)
{
	int l = s.length();
	long long result = 0;
	for (int i = 0; i < l; i++) {
		result = result << 1;
		result += s[i] - '0';
	}
	return result;
}

int ones(long long l)
{
	int bit_num = 8 * sizeof(long long);
	int count = 0;
	for (int i = 0; i < bit_num; i++) {
		count += l & 1;	
		l >>= 1;
	}

	return count;
}

int solve()
{
	set<long long> s;
	vector<long long> result;
	for (int i = 0; i< N; i++) {
		tmp[i] = o[i] ^ d[0];
		s.insert(d[i]);
	}

	for (int i = 0; i< N; i++) {
		long long t = tmp[i];
		bool work = true;
		for (int j = 0; j < N; j++) {
			if (s.find(t ^ o[j]) == s.end()) {
				work = false;
				break;
			}
		}

		if (work) {
			result.push_back(t);
		}
	}
	if (result.size() == 0)
		return -1;
	int min_ones = L;
	for (int i = 0; i < result.size(); i++) {
		min_ones = min(min_ones, ones(result[i]));
	}
	return min_ones;
		
}

int main()
{	
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N >> L;
		for (int j = 0; j < N; j++) {
			cin >> temp;
			o[j] = s2l(temp);
		}
		for (int j = 0; j < N; j++) {
			cin >> temp;
			d[j] = s2l(temp);
		}

		cout << "Case #" << i << ": ";
		int result = solve();
		if (result < 0)
			cout << "NOT POSSIBLE" << endl;
		else
			cout << result << endl;
	}
	
}
