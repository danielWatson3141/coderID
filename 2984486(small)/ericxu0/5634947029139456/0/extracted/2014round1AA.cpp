#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 155;
int N, L;
ll A[MAXN], B[MAXN];
int best = 1000000000;

bool compare()
{
	sort(A, A + N);
	for (int i = 0; i < N; i++)
		if (A[i] != B[i])
			return false;
	return true;
}

void test(int idx, int cnt)
{
	if (cnt >= best)
		return;

	if (idx < L)
	{
		test(idx + 1, cnt);
		for (int i = 0; i < N; i++)
			A[i] ^= (1<<idx);
		test(idx + 1, cnt + 1);
		for (int i = 0; i < N; i++)
			A[i] ^= (1<<idx);
	}
	else
	{
		if (compare())
			best = min(best, cnt);
	}
}

ll str_to_ll(string s)
{
	ll num = 0;
	for (int i = 0; i < L; i++)
		num = 2*num + s[i]-'0';
	return num;
}

int main()
{
	ifstream in ("2014round1AA.in");
	ofstream out ("2014round1AA.out");

	int T;
	in >> T;

	for (int t = 1; t <= T; t++)
	{
		in >> N >> L;
		for (int i = 0; i < N; i++)
		{
			string s;
			in >> s;
			A[i] = str_to_ll(s);
		}
		for (int i = 0; i < N; i++)
		{
			string s;
			in >> s;
			B[i] = str_to_ll(s);
		}

		best = 1000000000;
		sort(B, B + N);
		test(0, 0);

		if (best != 1000000000)
			out << "Case #" << t << ": " << best << "\n";
		else
			out << "Case #" << t << ": NOT POSSIBLE\n";
	}

	in.close();
	out.close();
	return 0;
}