#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <cmath>
#include <cassert>
#include <cstdlib>
#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)
#define mp make_pair
#define pb push_back
#define NAME ""

using namespace std;

typedef long double ld;
typedef long long ll;

const int nmax = 1e5 + 3;
const ld pi = M_PI;
const int inf = 1000 * 1000 * 1000;
const int mod = 1000 * 1000 * 1000 + 7;

void split(string &s, vector<string> &b)
{
	int i = 0;
	string s1;
	while (i < s.length())
	{
		if (s[i] == ' ')
		{
			b.push_back(s1);
			s1 = "";
		}
		else
			s1 += s[i];
		i++;
	}
	if (s1 != "")
		b.pb(s1);
}

int l1, answer, ans[nmax], answ;
vector<string> a, b;

bool operator > (string a, string b)
{
	if (a.length() > b.length())
		return true;
	if (b.length() > a.length())
		return false;
	for (int i = 0; i < a.length(); i++)
		if (a[i] > b[i])
			return true;
		else if (a[i] < b[i])
			return false;
	return false;
}

void gen(int i)
{
	if (i == l1)
	{
		for (int j = 0; j < a.size(); j++)
		{
			string s1 = "";
//			cerr << "WAS " << a[j] << " ";
			for (int k = 0; k < a[j].length(); k++)
				s1 += (ans[k] == 1 ? (a[j][k] == '0' ? '1' : '0') : a[j][k]);	
//			cerr << "BECAME " << s1 << endl;
			int l = 0, r = b.size();
			while (r - l > 1)
			{
				int m = (r + l) / 2;
				if (b[m] > s1)
					r = m;
				else
					l = m;
			}
//			cerr << s1 << " " << l << " " << b[l] << " " << j << " " << a.size() << endl;
			if (b[l] != s1)
			{
//				cerr << "Wrong\n";
				return;
			}
		}
		answer = min(answ, answer);
//		for (int j = 0; j < l1; j++)
//			cout << ans[j] << " ";
//		cout << endl;
	}
	else
	{
		ans[i] = 0;
		gen(i + 1);
		ans[i] = 1;
		answ++;
		gen(i + 1);
		answ--;
	}
}

int t, n, m;
string s, s1;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> t;
	for (int q = 0; q < t; q++)
	{
		cin >> n >> l1;
		answer = inf;
		answ = 0;
		getline(cin, s);
		getline(cin, s);
		getline(cin, s1);
//		cout << s << endl << s1 << endl;
		a.clear();
		b.clear();
		split(s, a);
		split(s1, b);
		sort(b.begin(), b.end());
//		cout << a.size() << " " << b.size() << endl;
//		cerr << "BBB\n";
//		for (int i = 0; i < b.size(); i++)
//			cerr << b[i] << " ";
		cerr << endl << endl;
		gen(0);		
//		cerr << "ANSwer " << answer << endl;
		if (answer == inf)
			cout << "Case #" << q + 1 << ": NOT POSSIBLE\n";
		else
			cout << "Case #" << q + 1 << ": " << answer << endl;
	}
}