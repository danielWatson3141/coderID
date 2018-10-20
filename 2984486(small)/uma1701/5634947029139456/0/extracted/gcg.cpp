#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>

using namespace std;

void merge(int arr[], int l, int m, int r)
{
	int b[r];

	for (int i = l; i < r; ++i) b[i] = arr[i];

	int l1 = l;
	int m1 = m;

	while(l1 < m && m1 < r) {
		if(b[l1] < b[m1]) {
			arr[l++] = b[l1++];
		} else {
			arr[l++] = b[m1++];
		}
	}

	while (l1 < m) arr[l++] = b[l1++];
	while (m1 < r) arr[l++] = b[m1++];
}

void sort(int arr[], int l, int n)
{
	if(l >= n-1) return;

	int k = (l+n)/2;

	sort(arr, l, k);
	sort(arr, k, n);
	merge(arr, l, k, n);
}
void doXor(int arr[], int n, int x)
{
	for (int i = 0; i < n; ++i) arr[i] ^= x;
}

bool equal(int arr[], int A[], int n)
{
	sort(arr, 0, n);

	for (int i = 0; i < n; ++i) {
		if(arr[i] != A[i]) return 0;
	}
	return 1;
}

void check(int arr[], int A[], int n, int l, int l1, int x, int p, int *min)
{
	if(l1 >= l) {
		if(equal(arr, A, n)) {
			if(p < *min) *min = p;
		}
		return;
	}

	check(arr, A, n, l, l1+1, x<<1, p, min);
	doXor(arr, n, x);
	check(arr, A, n, l, l1+1, x<<1, p+1, min);
	doXor(arr, n, x);
}

int my_atoi(char str[], int l)
{
	int a = 0;
	int x = 1;

	for (int i = l-1; i >= 0; --i) {
		if (str[i] == '1') {
			a += x;
		}
		x <<= 1;
	}

	return a;
}

int main()
{
	int n, l, t;

	scanf("%d", &t);
	//ofstream fout("output.txt");

	for (int t1 = 1; t1 <= t; ++t1) {
	scanf("%d", &n);
	scanf("%d", &l);
	int arr[n], A[n];
	char str[l];

	for (int i = 0; i < n; ++i) {
		scanf("%s", str);
		arr[i] = my_atoi(str, l);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%s", str);
		A[i] = my_atoi(str,l);
	}

	sort(A, 0, n);

	int min = 1500;

	check(arr, A, n, l, 0, 1, 0, &min);

	printf("Case #%d: ", t1);
	//fout << "Case #" << t1 << ": ";
	if(min < 1500) {
		printf("%d\n", min);
	//	fout << min << "\n";
	} else {
		printf("NOT POSSIBLE\n");
	//	fout << "NOT POSSIBLE\n";
	}
	}
	

	return 0;
}
