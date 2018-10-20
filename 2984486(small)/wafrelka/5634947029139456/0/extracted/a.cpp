#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;


const int inf = (int)1e9;
typedef long long int int64;


int count_switch(vector<bool> &swi)
{
	int x = 0;
	for(int i = 0; i < swi.size(); ++i) {
		if(swi[i]) x += 1;
	}
	return x;
}


bool is_valid(vector<vector<bool> > &flow, vector<vector<bool> > &dev, vector<bool> &swi)
{
	vector<int64> flow_list, dev_list;
	int n = flow.size();
	int l = flow[0].size();

	for(int i = 0; i < n; ++i) {

		int64 x = 0;

		for(int pos = 0; pos < l; ++pos) {
			if(flow[i][pos] ^ swi[pos])
				x |= 1LL << pos;
		}

		flow_list.push_back(x);
	}

	for(int i = 0; i < n; ++i) {

		int64 y = 0;

		for(int pos = 0; pos < l; ++pos) {
			if(dev[i][pos])
				y |= 1LL << pos;
		}

		dev_list.push_back(y);

	}

	sort(flow_list.begin(), flow_list.end());
	sort(dev_list.begin(), dev_list.end());

	for(int i = 0; i < n; ++i) {
		if(flow_list[i] != dev_list[i])
			return false;
	}

	return true;
}


vector<bool> decide(int n, vector<vector<bool> > &flow, vector<vector<bool> > &dev)
{
	vector<bool> swi;
	int l = flow[0].size();

	swi.resize(l, false);

	for(int pos = 0; pos < l; ++pos) {

		int flow_count = 0;
		int dev_count = 0;

		for(int i = 0; i < n; ++i) {
			if(flow[i][pos])
				flow_count += 1;
			if(dev[i][pos])
				dev_count += 1;
		}

		if(flow_count != dev_count)
			swi[pos] = true;
		if(n - flow_count == dev_count && flow_count == dev_count)
			printf("ERR!\n");
	}

	return swi;
}


vector<bool> decide(vector<vector<bool> > &flow, vector<vector<bool> > &dev)
{
	return decide(flow.size(), flow, dev);
}


int main()
{
	int test_case;

	scanf("%d", &test_case);

	for(int case_num = 0; case_num < test_case; ++case_num) {

		int n, l;
		vector<vector<bool> > flow, dev;
	
		scanf("%d%d", &n, &l);

		flow.resize(n);
		dev.resize(n);

		for(int i = 0; i < n; ++i) {
			char c[64];
			scanf("%s", c);
			for(int j = 0; j < l; ++j)
				flow[i].push_back(c[j] == '1');
		}
		for(int i = 0; i < n; ++i) {
			char c[64];
			scanf("%s", c);
			for(int j = 0; j < l; ++j)
				dev[i].push_back(c[j] == '1');
		}

		int ans = inf;

		if(n % 2 == 1) {

			vector<bool> swi = decide(flow, dev);
			if(is_valid(flow, dev, swi))
				ans = count_switch(swi);

		} else {

			for(int use = n - 1; use >= 0; --use) {

				swap(flow[use], flow[n - 1]);
				vector<bool> swi = decide(n - 1, flow, dev);
				if(is_valid(flow, dev, swi))
					ans = min(ans, count_switch(swi));
			}

		}

		if(ans < inf)
			printf("Case #%d: %d\n", case_num + 1, ans);
		else
			printf("Case #%d: NOT POSSIBLE\n", case_num + 1);
	}

	return 0;
}