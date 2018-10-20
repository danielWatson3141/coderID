#include <algorithm>
#include <limits>
#include <cstdio>
#include <cstring>

#define MAX_N 150
#define MAX_L 40
#define BUFFER_SIZE ((MAX_L + 1) * MAX_N)

using namespace std;

int outlets[MAX_N][MAX_L];
int devices[MAX_N][MAX_L];
int delta[MAX_L];
int gamma[MAX_L];
bool visited[MAX_N];
char str[BUFFER_SIZE + 10];

bool equal_rows(const int *x, const int *y, int l)
{
	for (int i = 0; i < l; i++) {
		if (x[i] != y[i]) {
			return false;
		}
	}
	return true;
}

int solve_problem(int num_case)
{
	char *p;
	int n, l;

	if (fgets(str, sizeof(str), stdin) == NULL)
		return 1;
	p = strtok(str, " ");
	n = atoi(p);
	p = strtok(NULL, " ");
	l = atoi(p);

	if (fgets(str, sizeof(str), stdin) == NULL)
		return 1;
	p = strtok(str, " ");
	for (int i = 0; p != NULL; i++) {
		for (int j = 0; j < l; j++) {
			outlets[i][j] = p[j] - '0';
		}
		p = strtok(NULL, " ");
	}

	if (fgets(str, sizeof(str), stdin) == NULL)
		return 1;
	p = strtok(str, " ");
	for (int i = 0; p != NULL; i++) {
		for (int j = 0; j < l; j++) {
			devices[i][j] = p[j] - '0';
		}
		p = strtok(NULL, " ");
	}

	int result = numeric_limits<int>::max();
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < l; k++) {
			delta[k] = outlets[0][k] ^ devices[i][k];
		}
		fill(visited, visited + n, false);
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < l; k++) {
				gamma[k] = outlets[j][k] ^ delta[k];
			}
			for (int k = 0; k < n; k++) {
				if (equal_rows(gamma, devices[k], l)) {
					visited[k] = true;
					break;
				}
			}
		}
		bool complete = true;
		for (int j = 0; j < n; j++) {
			if (!visited[j]) {
				complete = false;
				break;
			}
		}
		if (complete) {
			int cand = 0;
			for (int k = 0; k < l; k++) {
				cand += delta[k];
			}
			if (cand < result) {
				result = cand;
			}
		}
	}

	if (result < numeric_limits<int>::max()) {
		printf("Case #%d: %d\n", num_case, result);
	} else {
		printf("Case #%d: %s\n", num_case, "NOT POSSIBLE");
	}

	return 0;
}

int main()
{
	int num_tests;

	if (fgets(str, sizeof(str), stdin) == NULL)
		return 1;
	num_tests = atoi(str);

	for (int i = 0; i < num_tests; i++)
		solve_problem(i + 1);

	return 0;
}
