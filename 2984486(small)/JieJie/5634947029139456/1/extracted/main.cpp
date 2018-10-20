#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <algorithm>
#include <stack>
#include <vector>
#include <math.h>

#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
#define CLR(a,x) memset(a, x, sizeof(a))
#define SIZE(v) ((int)(v).size())
#define FOREACH(i,v) for(typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
typedef long long ll;
typedef std::pair<ll, ll> PII;
typedef std::vector<PII> VPII;
using namespace std;

int N, L;
vector<string> v_in;
vector<string> v_out;
vector<int> sum_in;
vector<int> sum_out;
int min_flip = 20000000;

bool check_sub(int k)
{
	vector<bool> set_v(N, true);
	FOR(i, 0, N)
	{
		bool flag = false;
		FOR(j, 0, N)
		{
			if (set_v[j] && (v_in[i].substr(0,k) == v_out[j].substr(0,k)))
			{
				flag = true;
				set_v[j] = false;
				break;
			}
		}
		if (!flag)	return false;
	}
}

bool check()
{
	vector<bool> set_v;
	FOR(i, 0, v_in.size())	set_v.push_back(true);
	FOR(i, 0, v_in.size())
	{
		bool flag = false;
		FOR(j, 0, v_out.size())
		{
			if (set_v[j] && (v_in[i] == v_out[j]))
			{
				flag = true;
				set_v[j] = false;
				break;
			}
		}
		if (!flag)	return false;
	}
	return true;
}

void go(int k, int cur_flip)
{
	if (k == L)
	{
		if (check()){
			if (min_flip > cur_flip)	min_flip = cur_flip;
		}
		return;
	}
	if (sum_in[k] == sum_out[k])
	{
		if (check_sub(k))
		go(k + 1, cur_flip);
	}
	
	if (N-sum_in[k] == sum_out[k])
	{
		cur_flip++;

		for (int i = 0; i < N; i++)
		{
			v_in[i][k] = ('0' + '1' - v_in[i][k]);
		}

		if (check_sub(k))
		go(k + 1, cur_flip);

		for (int i = 0; i < N; i++)
		{
			v_in[i][k] = ('0' + '1' - v_in[i][k]);
		}
		cur_flip--;
	}
	
}

void solve()
{
	cin >> N >> L;
	string str;
	/*
	for (int i = 0; i < N - 1; i++){
		getline(cin, str, ' ');
		if (str[0] == '\n')	str = str.substr(1, str.length() - 1);
		v_in.push_back(str);
	}
	getline(cin, str, '\n');
	v_in.push_back(str);

	for (int i = 0; i < N - 1; i++){
		getline(cin, str, ' ');
		v_out.push_back(str);
	}
	getline(cin, str, '\n');
	v_out.push_back(str);
	*/

	char c;
	for (int i = 0; i < N; i++){
		str = "";
		for (int j = 0; j < L; j++){
			cin >> c;
			str += c;
		}
		v_in.push_back(str);
	}
	for (int i = 0; i < N; i++){
		str = "";
		for (int j = 0; j < L; j++){
			cin >> c;
			str += c;
		}
		v_out.push_back(str);
	}


	int sum;
	int sum2;
	for (int j = 0; j < L; j++){
		sum = 0;
		sum2 = 0;
		for (int i = 0; i < N; i++)
		{
			sum += (v_in[i][j] - '0');
			sum2 += (v_out[i][j] - '0');
		}
		sum_in.push_back(sum);
		sum_out.push_back(sum2);
		if ((sum != sum2) && ((N - sum) != sum2))
		{
			cout << "NOT POSSIBLE" << endl;
			return;
		}
	}	

	go(0, 0);
	if (min_flip > 20000000 - 1)	cout << "NOT POSSIBLE" << endl;
	else	cout << min_flip << endl;
}



int main()
{
#ifndef ONLINE_JUDGE
	freopen("A-large.in", "rt", stdin);
	//freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		printf("Case #%d: ", i + 1); 
		v_in.clear();
		v_out.clear();
		sum_in.clear();
		sum_out.clear();
		min_flip = 20000000;
		solve();
	}
	return 0;
}
