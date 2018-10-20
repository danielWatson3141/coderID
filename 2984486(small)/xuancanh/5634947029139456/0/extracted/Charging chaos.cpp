#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
class Outlet
{
private:
	int l, n;
	vector<string> init, goal;
	int nMove;
	bool checkOK(vector<string> v1, vector<string> v2)
	{
		for (int i = 0; i < v1.size(); i++)
		{
			if (v1.size() == 0)
				break;
			for (int j = 0; j < v2.size(); j++)
				if(v1[i] == v2[j])
				{
					v1.erase(v1.begin() + i);
					v2.erase(v2.begin() + j);
					i --;
					break;
				}
		}
		if (v1.size() == 0)
			return true;
		return false;
	}
	vector<string> Flip(vector<string> &Init, string flip)
	{
		vector<string> Result = Init;
		for (int i = 0; i < Result.size(); i++)
		{
			for (int j = 0; j < l; j++)
			{
				if (flip[j] == '1')
				{
					if (Result[i][j] == '1')
						Result[i][j] = '0';
					else
						Result[i][j] = '1';
				}
			}
		}
		return Result;
	}
	void HoanVi(int nOn, int iStart, vector<string> &Result, string s = "")
	{
		if (nOn == 0)
		{
			Result.push_back(s);
			return;
		}
		if (iStart == 0)
		{
			string temp;
			temp.resize(l);
			for (int i = 0; i < temp.size(); i++)
				temp[i] = '0';
			HoanVi(nOn, iStart + 1, Result, temp);
			temp[0] = '1';
			HoanVi(nOn - 1, iStart + 1, Result, temp);
		}
		else
		{
			if (nOn > l - iStart + 1)
				return;
			string temp = s;
			temp[iStart] = '0';
			HoanVi(nOn, iStart + 1, Result, temp);
			temp[iStart] = '1';
			HoanVi(nOn - 1, iStart + 1, Result, temp);
		}

		
	}
	vector<string> LayHoanVi(int nOn)
	{
		vector<string> result;
		if (nOn == 0)
		{
			string temp;
			temp.resize(l);
			for (int i = 0; i < temp.size(); i++)
				temp[i] = '0';
			result.push_back(temp);
			return result;
		}
		HoanVi(nOn, 0, result);
		return result;
	}
public:
	void ReadInput(fstream &f)
	{
		f >> n;
		f >> l;
		init.resize(n);
		goal.resize(n);
		string temp;
		getline(f, temp);
		getline(f, temp);
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			init[i].resize(l);
			for (int j = 0; j < l; j++)
			{
				init[i][j] = temp[count];
				count ++;
		
			}
			count ++;
		}
		getline(f, temp);
		count = 0;
		for (int i = 0; i < n; i++)
		{
			goal[i].resize(l);
			for (int j = 0; j < l; j++)
			{
				goal[i][j] = temp[count];
				count ++;
		
			}
			count ++;
		}

	}
	void Solve()
	{
		int nChange;
		for (int i = 0; i < l; i++)
		{
			vector<string> hv;
			hv = LayHoanVi(i);
			for (int j = 0; j < hv.size(); j++)
			{
				if (checkOK(goal, Flip(init, hv[j])))
				{
					nMove = i;
					return;
				}
			}
		}
		nMove = -1;
		return;
	}
	void WriteOutput(int nTestCase, fstream &f)
	{
		f << "Case #" << nTestCase << ": " ;
		if (nMove == -1)
			f << "NOT POSSIBLE";
		else
			f << nMove;
		f << endl;

	}
};

int main(int argc, char **argv)
{
	fstream input, output;
	input.open(argv[1], ios::in);
	output.open(argv[2], ios::out);
	int nTestCase;
	input >> nTestCase;
	Outlet OL;
	for (int i = 0; i < nTestCase; i++)
	{
		OL.ReadInput(input);
		OL.Solve();
		OL.WriteOutput(i + 1, output);
	}
	input.close();
	output.close();
	return 0;
}