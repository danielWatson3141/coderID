#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <string>

using namespace std;



typedef long long LL;
vector<LL> f;
int time = 9999999;
inline void Swap(LL *a, LL *b)
{
	LL t = *a;
	*a = *b;
	*b = t;
}

inline int solve(vector<string> flow, vector<string> require, int n,int l)  {
	vector<LL> f(l), r(l);		
	for (int i=0; i<l; i++) {

		f[i] = 0;
		r[i] = 0;
		for (int j=0; j<n; j++) {
			f[i] <<= 1;
			f[i] += flow[j][i]=='1';

			r[i] <<= 1;
			r[i] += require[j][i]=='1';
		}
	}

	int a = 0;
	int b = 0;
	for (int i=0; i<l; i++) {
		if (f[i] == r[i]) {
			a ++;
		}
		else if ((f[i]+r[i]) == (1<<(n+1)-1)){
			b ++;
		}
	}

	if ((a + b) == l) {
		return b;
	}
	else {
		return -1;
	}
}

inline int bigcount(LL n) {
	unsigned int c =0 ; // 计数器
    while (n >0)
    {
        if((n &1) ==1) // 当前位是1
            ++c ; // 计数器加1
        n >>=1 ; // 移位
    }
    return c ;
}
inline int solve2(vector<LL>& r) {

	LL result = r[0]^f[0];
	for (int i=1,size=r.size(); i<size; i++) {
		LL x = r[i]^f[i];
		if (x != result) {
			return -1;
		}
	}

	return bigcount(result);
}

inline void Permutation(int start, int end, vector<LL> list, LL lastr)
{
	int i;
	if (start >= end) //递归结束，打印当前这次全排列结果，返回。
	{
		//for (i = 0; i < end; i++)
		//{
		//	printf("%d ", list[i]);
		//}
		//printf("\n");
		int tt = solve2(list);

		if (tt >= 0 && tt < time) {
			time = tt;
		}
		return;
	}
	//对于给定的list[start...end]，要使区间中每一个元素都有放在第一位的机会，
	//然后开始递归调用自身，得到list[start+1...end]的全排列。
	for (i = start; i < end; i++) 
	{
		Swap(&list[i], &list[start]); //交换元素，使每一个元素都有放在第一位的机会。
		LL result = f[start]^list[start];
		if (lastr <= 0 || lastr == result) {
			Permutation(start+1, end, list, result); //递归调用
		}
		Swap(&list[i], &list[start]); //恢复原始的list，不影响下次递归调用。
	}
}
int main()
{
	freopen("E:\\Projects\\VS2010\\gcj2014\\gcj2014\\Round1A\\A\\A-small-attempt1.in", "r", stdin);
	freopen("E:\\Projects\\VS2010\\gcj2014\\gcj2014\\Round1A\\A\\A-small.out", "w", stdout);
	int T;

	cin >>T;

	for (int t=1; t<=T; t++) {
		cout << "Case #" << t << ": ";
		int n, l;
		time = 9999999;
		cin >> n >> l;

		vector<string> flow(n), require(n);

		for (int i=0; i<n; i++) {
			cin >> flow[i];
		}

		for (int i=0; i<n; i++) {
			cin >> require[i];
		}

		vector<LL> r(n);
		f = vector<LL>(n);
		for (int i=0; i<n; i++) {

			f[i] = 0;
			r[i] = 0;
			for (int j=0; j<l; j++) {
				f[i] <<= 1;
				f[i] += flow[i][j]=='1';

				r[i] <<= 1;
				r[i] += require[i][j]=='1';
			}
		}

		Permutation(0, n, r, -1);

		if (time == 9999999) {
			cout << "NOT POSSIBLE" << endl;
		}
		else {
			cout << time << endl;
		}
	}

	return 0;
}