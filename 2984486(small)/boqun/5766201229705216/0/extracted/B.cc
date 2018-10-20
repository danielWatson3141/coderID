#include <iostream>

using namespace std;

int T;
int N;
int g[1001][1001];



int solve(int index, int parent)
{
	int max_node, second;
	max_node = 0;
	second = 0;
	for (int i = 1; i <= N; i++) {
		if (g[index][i] && i != parent) {
			int tmp = solve(i, index);
			if (tmp > max_node) {
				second = max_node;
				max_node = tmp;
			}
			else if (tmp > second) {
				second = tmp;
			}
		}
	}
	if (second == 0)
		return 1;
	return 1 + max_node + second;

}
int solveP()
{
	int max_node = 0;
	for (int i = 1; i <= N; i++)
		max_node = max(max_node, solve(i, 0));

	return N - max_node;
}
int main()
{
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N;
		for (int j = 0 ; j <= N; j++) {
			for (int k = 0; k <= N; k++)
				g[j][k] = 0;
		}

		for (int j = 1 ; j <= N-1; j++) {
			int from, to;
			cin >> from >> to;
			g[from][to] = 1;
			g[to][from] = 1;
		}

		cout << "Case #" << i << ": ";
		cout << solveP() << endl;
	}
}
