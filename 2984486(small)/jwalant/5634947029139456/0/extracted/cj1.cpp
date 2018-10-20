#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#define li long int
#define ulli long long int
#define fri(n) for(li i=0;i<n;i++)
#define frj(n) for(li j=0;j<n;j++)
#define C 20000
using namespace std;

int traverse(ulli *a, ulli *b, int l, int i, int ans, int n, ulli fact,
		int &finans) {
	bool equal = 1;
	sort(a, a + n);
	frj(n)
	{
		if (a[j] != b[j]) {
			equal = 0;
			break;
		}
	}
	if (equal) {
//		cout<<ans<<endl;
		if (finans > ans) {
			finans = ans;
			return ans;
		}
	}
	if (i < l) {
		int tans = -1;
		tans = traverse(a, b, l, i + 1, ans, n, fact * 2, finans);
		if (tans >= 0) {
//			cout << "ni " << i << endl;
			if (finans > tans)
				finans = tans;
		}
		frj(n)
		{
			if (a[j] & fact)
				a[j] -= (fact);
			else
				a[j] += fact;
		}
		tans = traverse(a, b, l, i + 1, ans + 1, n, fact * 2, finans);
		frj(n)
		{
			if (a[j] & fact)
				a[j] -= (fact);
			else
				a[j] += fact;
		}
		if (tans >= 0) {
//			cout << "i " << i << endl;
			if (finans > tans)
				finans = tans;
		}
		return tans;
	}

	return -1;
}
int main() {
	freopen("A-small-attempt2.in", "r", stdin);
	freopen("out.in", "w", stdout);
	li t;
	cin >> t;
	for (int t1 = 0; t1 < t; t1++) {
		int n, l;
		cin >> n >> l;
		ulli *a = new ulli[n];
		ulli *b = new ulli[n];
		fri(n)
		{
			a[i] = 0;
			string temp;
			cin >> temp;
			cin.clear();
			cin.ignore();
			ulli factor = 1;
			frj(l)
			{
				if (temp.at(l - j - 1) - '0') {
					a[i] += (factor);
				}
				factor *= 2;
			}
		}
		fri(n)
		{
			b[i] = 0;
			string temp;
			ulli factor = 1;
			cin >> temp;
			cin.clear();
			cin.ignore();
			frj(l)
			{
				if (temp.at(l - j - 1) - '0') {
					b[i] += (factor);
				}
				factor *= 2;
			}
		}
		sort(a, a + n);
		sort(b, b + n);
		int finans = l + 1;
		traverse(a, b, l, 0, 0, n, 1, finans);
		cout << "Case #" << t1 + 1 << ": ";
		if (finans != l + 1)
			cout << finans << endl;
		else
			cout << "NOT POSSIBLE" << endl;
	}
	return 0;
}
