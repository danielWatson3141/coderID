#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;




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

	srand((unsigned)time(0));
	for (int n = 1; n <= case_num; n++)
	{
		int r = rand() % 2;
		output_file<<"Case #"<<n<<": "<<endl;
		if (r == 0)
		{
			output_file<<"GOOD"<<endl;
		}
		else
		{
			output_file<<"BAD"<<endl;
		}
	}


	input_file.close();
	output_file.close();
	system("pause");
	return 0;
}