//#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <string>
using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");

struct node
{
	int name;
	node *next;
};

int *f, *s;
node **edge;

void qsort(string *a, int x, int y)
{
	// sort a within [x, y]
	if (x >= y) return;
	int m = x, l = x, r = y;
	string mid = a[m];
	a[m] = a[x];
	while (x < y)
	{
		while (x < y && mid <= a[y]) y--;
		if (x < y) a[x++] = a[y];
		while (x < y && mid >= a[x]) x++;
		if (x < y) a[y--] = a[x];
	}
	a[x] = mid;
	qsort(a, l, x - 1);
	qsort(a, x + 1, r);
}

void add(int x, int y)
{
	if (edge[x] == NULL)
	{
		edge[x] = new node;
		edge[x]->name = y;
		edge[x]->next = NULL;
	}
	else
	{
		node *tmp = new node;
		tmp->name = y;
		tmp->next = edge[x]->next;
		edge[x]->next = tmp;
	}
}

void cal(int root, int father)
{
	node *x = edge[root];
	int sum = 0, num = 0;
	int min1 = 100000000, min2 = 100000000;
	while (x != NULL)
	{
		if (x->name != father)
		{
			cal(x->name, root);
			num++;
			sum = sum + s[x->name];
			if (f[x->name] - s[x->name] < min1)
			{
				min2 = min1;
				min1 = f[x->name] - s[x->name];
			}
			else if (f[x->name] - s[x->name] < min2)
			{
				min2 = f[x->name] - s[x->name];
			}
		}
		x = x->next;
	}
	if (num == 0)
	{
		f[root] = 0;
		s[root] = 1;
	}
	else if (num == 1)
	{
		f[root] = sum;
		s[root] = sum + 1;
	}
	else
	{
		f[root] = min1 + min2 + sum;
		s[root] = sum + 1;
	}
}

int main(){
	int T, n, x, y;
	cin >> T;
	f = new int[2000];
	s = new int[2000];
	edge = new node* [2000];
	for (int t = 1; t <= T; t++)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			edge[i] = NULL;
		}
		for (int i = 1; i < n; i++)
		{
			cin >> x >> y;
			add(x, y);
			add(y, x);
		}
		int min = 10000000;
		for (int i = 1; i <= n; i++)
		{
			cal(i, 0);
			if (f[i] < min)
				min = f[i];
		}
		cout << "Case #" << t << ": " << min << endl;
	}
	return 0;
}