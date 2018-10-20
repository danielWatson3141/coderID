#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>
#include <vector>
#include <set>
#include <iterator>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

class R1P1
{
private:
	int N,L;
	vector<string> Iarr;
	vector<string> Oarr;
	int out1;
public:
	R1P1();
	void getInput(ifstream& file);
	void eval();
	void dumpOutput(ofstream& file, int TCCnt);
};

R1P1::R1P1()
{
	N=L=0;
	/*for(int i = 0;i<150;i++)
	{
		Iarr[i] = '0';
	}
	for(int i = 0;i<150;i++)
	{
		Oarr[i] = '0';
	}*/
	
	out1 = -1;
}

void R1P1::getInput(ifstream& file)
{
	file >> N;
	file >> L;
	string temp;
	for(int i = 0;i<N;i++)
	{
		file >> temp;
		Iarr.push_back(temp);
	}
	for(int i = 0;i<N;i++)
	{
		file >> temp;
		Oarr.push_back(temp);
	}
}

void R1P1::dumpOutput(ofstream& file, int TCCnt)
{
	std::stringstream ss1,ss2;
	ss1 << TCCnt+1;
	std::string compMsg = "Case #"+ss1.str()+": ";
	file.write(compMsg.c_str(), compMsg.length());
	if(out1 ==-1)
		ss2 <<"NOT POSSIBLE";
	else
		ss2 << out1;
	file << ss2.str() << "\n";
}

void R1P1::eval()
{	
	int i,j,k;
	std::vector <std::vector <std::string> > arr;
	//xor operation
	for(i =0;i<N;i++)
	{
		std::vector<string> tempArr;
		for(j=0;j<N;j++)
		{
			string a;			
			for(k=0;k<L;k++)
			{
				if(Iarr[i][k] == Oarr[j][k])
					a.append("0");
				else
					a.append("1");

			}
			tempArr.push_back(string(a));
		}
		arr.push_back(tempArr);
	}
	//check
	vector<string> arrMin;
	bool match = false;
	string result;
	for(i =0;i<N;i++)
	{
		for(j=1;j<N;j++)
		{
			match = false;
			for(k=0;k<N;k++)
			{
				if(arr[0][i] == arr[j][k])
				{
					match = true;
					result = arr[0][i];
					break;
				}
			}
			if(match == false)
				break;
		}
		if(match)
			arrMin.push_back(result);
	}
	if(arr.size()==1)
		arrMin.push_back(arr[0][0]);

	if(!arrMin.empty())
	{
		int count = 0,minCount=1000;
		for(i=0;i<arrMin.size();i++)
		{
			if(arrMin[i].empty())
				continue;
			for(j=0;j<L;j++)
			{
				if(arrMin[i][j]=='1')
					count++;
			}
			if(minCount > count)
				minCount =count;
			count = 0;
		}
		out1 = minCount;
	}
}

int main()
{
	ifstream file;
	file.open("input.in");
	ofstream fileOut;
	fileOut.open("output.out");
	std::string line;
	getline(file, line);
	int noOfTC = atoi(line.c_str());
	for(int i = 0; i < noOfTC; i++)
	{
		R1P1 t;
		t.getInput(file);
		t.eval();
		t.dumpOutput(fileOut, i);
	}
	file.close();
	return 0;
}