#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <functional>
#include <numeric>
#include <iomanip>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;


struct probCase {
	int N, L;
	vector< int > Out,Req;
};

int convert2int(int A)
{
	int ret = 0;

	int pow2 = 1;
	while (A != 0)
	{
		ret += pow2 * (A % 10);
		A = A / 10;
		pow2 *= 2;
	}
	return ret;

}
probCase readCase(ifstream & fin)
{
	probCase retVal;
	fin >> retVal.N >> retVal.L;
	for(int aaa =0 ; aaa < retVal.N; ++aaa)
	{
		int temp;
		fin >> temp;
		temp = convert2int(temp);
		retVal.Out.push_back(temp);
	}
	for(int aaa =0 ; aaa < retVal.N; ++aaa)
	{
		int temp;
		fin >> temp;
		temp = convert2int(temp);
		retVal.Req.push_back(temp);
	}
	//printf ( "%d, %d, \n" , retVal.N, retVal.L);
	return retVal;
}

void writeCase(ofstream & fout, const int caseNum, const string sol)
{
	fout << "Case #" << caseNum+1 << ": " << sol << endl;
	return;
}

bool solve_case(probCase it_case, int &iter)
{
	vector<int> required = it_case.Req; 
	std::sort (required.begin(), required.end());
	//cout << "required:\n";;
	//for(auto it : required)
	//{
		//cout << it << endl;
	//}
	//	Number of switches needed:
	for (int it_L = 0; it_L <= it_case.L; ++it_L)
	{
		cout << "switching: " << it_L << endl;
		//	Set up vector:
		vector<int> mask_vec(it_case.L,0);
		for(int it_it_L = 0; it_it_L < it_L; ++it_it_L)
		{
			mask_vec[it_it_L] = 1;
		}

		std::sort (mask_vec.begin(), mask_vec.end());

		do {
			//	Test if solution exists:
			int mask = 0;
			int pow2 = 1;
			for (int aaa = 0; aaa < it_case.L; aaa++)
			{
				mask += pow2 * mask_vec[aaa];
				pow2 *=  2;
			}
			cout << "Mask: " << mask << endl;

			vector<int> outlet_backup = it_case.Out;
			for(auto  & it_outlet : outlet_backup)
			{
				it_outlet ^= mask;
			}
			std::sort(outlet_backup.begin(), outlet_backup.end());
			//cout << "Oout" << endl;;
			//for(auto it : outlet_backup)
				//cout << it << endl;
			//	Check if same:
			bool flag_success = true;
			for (int aaa =0 ; aaa < it_case.N; ++ aaa)
			{
				if (outlet_backup[aaa] != required[aaa])
				{
					flag_success = false;
					break;
				}
			}
			if (flag_success)
			{
				for( auto it : mask_vec)
				{
					cout << it ;
				}
				cout << endl;
				iter = it_L;
				return true;
			}
		} while (std::next_permutation(mask_vec.begin(), mask_vec.end()));
		//cout << it_case.L << " " << it_L << " " << num_permute << endl;;
	}
	return false;
}

int main(int argc, char * argv[])
{
	ifstream fin("input.txt"); 
	ofstream fout("output.txt");
	
	if(!fin.good())
	{
		cout << "opps" << endl;
	}

	string str;
	getline(fin, str);
	
	//	Number of test cases.
	const int T = atoi(str.c_str());

	//	Loop across each file.
	for( int aaa = 0; aaa < T ; aaa++)
	{
		probCase it_case = readCase(fin);

		int iter(0);
		bool success = solve_case(it_case, iter);

		//stringstream sstm;
		//sstm << "HI" << aaa ;
		//string result = sstm.str();

		//string str1 = "hi" + to_string(aaa);
		//cout << str1 << endl;
		//writeCase(fout, aaa,result);




		//cout << fixed << setprecision(10) << "Case #" << aaa+1 << ": " << setprecision(10) << static_cast<long double>(current_time)<< setprecision(10) <<   "\t" << farms_true << endl;
		if (success)
		{
		fout << "Case #" << aaa+1 << ": " <<  iter<< endl;
		}
		else
		{
		fout << "Case #" << aaa+1 << ": " <<  "NOT POSSIBLE"<< endl;
		}
		////fout << fixed << setprecision(10) << "Case #" << aaa+1 << ": " << setprecision(10) << static_cast<long double>(current_time)<< setprecision(10) <<  "\t" << farms << "\t" << farms_true << endl;
		//fout << fixed << setprecision(10) << "Case #" << aaa+1 << ": " << setprecision(10) << static_cast<long double>(current_time)<< setprecision(10) << endl;
	}	

	fin.close(); fout.close();
	return 0;
}
