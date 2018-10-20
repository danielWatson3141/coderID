#include<iostream>
#include<cstring>
#include<set>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<vector>
using namespace std;

int N,L;
int nzero[100];
int outzero[100];
string dev[200];
string outlet[200];
void read(string str[], int arr[])
{
	int i,j;
	for(i = 0; i < N; i ++)
	{
		cin >> str[i];
		for(j = 0; j < L; j ++)
		{
			arr[j] += str[i][j]=='0';
		}
	}
}
int f(vector<int> &flipindex, int flips, int index)
{
	int i,j;
	if(is_permutation(dev, dev+N, outlet)) return flips;
	flips++;
	int tmpflips = -1;
	for(i = index; i < flipindex.size(); i ++) {
		for(j = 0; j < N; j ++) {
			outlet[j][flipindex[i]] = outlet[j][flipindex[i]]=='0'?'1':'0';
		}
		int tmp = f(flipindex, flips, i+1);
		if(tmp >= 0 && tmp < tmpflips || tmpflips<0)
			tmpflips = tmp;
		for(j = 0; j < N; j ++) {
			outlet[j][flipindex[i]] = outlet[j][flipindex[i]]=='0'?'1':'0';
		}
	}
	return tmpflips;

}
int main()
{
	int T;
	cin >> T;
	int t;
	for(t=1; t<= T; t++)
	{
		cin >> N >> L;
		int i,j,k;
		memset(nzero, 0, sizeof(int)*100);
		memset(outzero, 0, sizeof(int)*100);
		read(dev, nzero);
		read(outlet, outzero);
		cout << "Case #" << t << ": ";
		int flips = 0;
		vector<int> flipindex;
		flipindex.clear();
		for(i = 0; i < L; i ++)
		{
			if(nzero[i]+outzero[i] == N)
			{
				if(nzero[i] != outzero[i])
				{
					for(j = 0; j < N; j ++)
						outlet[j][i] = outlet[j][i]=='0'?'1':'0';
					flips++;
				}
				else
				{
					flipindex.push_back(i);
				}
			} else if(nzero[i] != outzero[i]) {
				flips = -1;
				break;
			}
		}
		if(flips < 0)
		{
			cout << "NOT POSSIBLE" << endl;
			continue;
		}
		int result = f(flipindex, flips, 0);
		if(result < 0)
		{
			cout << "NOT POSSIBLE" << endl;
			continue;
		} else {
			cout << result << endl;
		}
	}
	return 0;
}