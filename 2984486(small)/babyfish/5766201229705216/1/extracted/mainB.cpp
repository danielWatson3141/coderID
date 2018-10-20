#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> connect[1001];

bool visited[1001];

void init()
{
	for (int i = 0; i < 1001; i++)
	{
		connect[i].clear();
		visited[i] = false;
	}
}

void formalize(int k, int& kids, int& deleted)
{
	int max1 = -1;
	int max2 = -1;
	int max1_son = 0;
	int max2_son = 0;
	int max1_delete = 0;
	int max2_delete = 0;
	int sons = 0;
	deleted = 0;

	visited[k] = true;

	for (int i = 0; i < connect[k].size(); i++)
	{
		int son = connect[k][i];
		if (!visited[son])
		{
			sons++;
			int son_ks = 0;
			int son_delete;

			formalize(son, son_ks, son_delete);

			deleted += son_delete;

			if (son_ks > max1)
			{
				if (max2_son > 0)
				{
					deleted += max2;
				}

				max2 = max1;
				max2_son = max1_son;

				max1 = son_ks;
				max1_son = son;
			}
			else
			{
				if (son_ks > max2)
				{
					if (max2_son > 0)
					{
						deleted += max2;
					}

					max2 = son_ks;
					max2_son = son;
				}
				else
				{
					deleted += son_ks;
				}
			}
		}
	}

	switch (sons)
	{
	case 0:
		kids = 1;
		visited[k] = false;
		return ;
	case 1:
		kids = 1;
		deleted += max1;
		visited[k] = false;
		return ;
	default:
		kids = max1 + max2 + 1;
		visited[k] = false;
		return;
	}
}


int main()
{
	ifstream input_file;
	ofstream output_file;
	int case_num = 0;

	input_file.open("test.in");
	if (!input_file)
	{
		cout<<"No File \"test.in\" Found!"<<endl;
	}
	output_file.open("test.out");
	if (!output_file)
	{
		cout<<"No File \"test.out\" Created!"<<endl;
	}
	input_file>>case_num;
	cout<<"Num:"<<case_num<<endl;

	for (int n = 1; n <= case_num; n++)
	{
		int nn;
		int min_delete = 99999;
		input_file>>nn;

		init();

		for (int i = 1; i < nn; i++)
		{
			int x, y;
			input_file>>x>>y;
			//cout<<x<<' '<<y<<endl;
			connect[x].push_back(y);
			connect[y].push_back(x);
		}

		for (int i = 1; i <= nn; i++)
		{
			int dels;
			int kids;
			formalize(i, kids, dels);
			if (dels < min_delete)
			{
				min_delete = dels;
			}
		}

		output_file<<"Case #"<<n<<": "<<min_delete<<endl;
	}


	input_file.close();
	output_file.close();
	system("pause");
	return 0;
}