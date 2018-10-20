#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>

const int n = 1000;
void perm_good(FILE *output)
{
	int a[n];
	for (int k = 0; k < n; ++k)
		a[k] = k;
	for (int k = 0; k < n; ++k)
	{
		int p = k + rand() % (n - k);
		std::swap(a[k], a[p]);
	}
	for (int i = 0; i < n; i++)
		fprintf(output, "%d ", a[i]);
}

void perm_bad(FILE *output)
{
	int a[n];
	for (int k = 0; k < n; ++k)
		a[k] = k;
	for (int k = 0; k < n; ++k)
	{
		int p = rand() % n;
		std::swap(a[k], a[p]);
	}
	for (int i = 0; i < n; i++)
		fprintf(output, "%d ", a[i]);
}

void generate()
{
	srand(time(NULL));
	FILE *output = fopen("IO/input.txt", "wt");
	fprintf(output, "120\n");
	for (int t = 0; t < 120; t++)
	{
		fprintf(output, "1000\n");
		if (rand() % 2 == 0)
			perm_good(output);
		else
			perm_bad(output);
		fprintf(output, "\n");
	}
	fclose(output);
}

typedef struct tag_TestCase
{
	int id;
	int permutation[n];
} TestCase;

int good_count = 0;

void solve_test_case(TestCase tc, FILE *output)
{
	bool good = true;
	int model_permutation[n];
	for (int i = 0; i < n; ++i)
		model_permutation[i] = i;
	long rand_sum = 0;
	for (int i = 0; i < n; ++i)
	{
		int swap_with_idx = -1;
		for (int j = 0; j < n; ++j)
		{
			if (tc.permutation[i] == model_permutation[j])
			{
				swap_with_idx = j;
				break;
			}
		}
		if (swap_with_idx < i)
		{
			good = false;
			break;
		}
		int divisor = n - i;
		int random = divisor * (rand() / divisor) + swap_with_idx - i;
		rand_sum += random;
		std::swap(model_permutation[i], model_permutation[swap_with_idx]);
	}
	float real_avg_rand = (float)rand_sum / n;
	float ideal_avg_rand = (float)RAND_MAX / 2;
	float difference = abs(real_avg_rand - ideal_avg_rand);
	good = good && difference < 180.0f;
	fprintf(output, "Case #%d: ", tc.id);
	if (good)
		fprintf(output, "GOOD");
	else
		fprintf(output, "BAD");
	fprintf(output, "\n");
	if (good)
		good_count++;
}

void main()
{
	FILE *input = fopen("IO/input.txt", "rt");
	FILE *output = fopen("IO/output.txt", "wt");
	int t = 0;
	fscanf(input, "%d", &t);
	for (int i = 1; i <= t; ++i)
	{
		TestCase tc;
		tc.id = i;
		int temp;
		fscanf(input, "%d", &temp);
		for (int j = 0; j < n; ++j)
			fscanf(input, "%d", &tc.permutation[j]);
		solve_test_case(tc, output);
	}
	fclose(output);
	fclose(input);
	printf("%d", good_count);
	getchar();
}