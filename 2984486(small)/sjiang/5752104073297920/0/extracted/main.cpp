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

int trials = 1000000;
int size_ = 1000;
long double base_guess = log ( double(1)/size_) * size_;

struct probCase {
	unsigned long int N, L;
	vector< unsigned long int > Perm;
};

probCase readCase(ifstream & fin)
{
	probCase retVal;
	for(unsigned long int aaa =0 ; aaa < size_; ++aaa)
	{
		unsigned long int temp;
		fin >> temp;
		retVal.Perm.push_back(temp);
	}
	return retVal;
}

void writeCase(ofstream & fout, const unsigned long int caseNum, const string sol)
{
	fout << "Case #" << caseNum+1 << ": " << sol << endl;
	return;
}

bool guess_case(probCase it_case, vector<vector< double > > save)
{
	long double prob = 0;
	for(int a = 0; a < it_case.Perm.size(); a ++)
	{
		prob += (save[a][it_case.Perm[a]]);
		//log(double(save[a][it_case.Perm[a]]))
		//log(double(
	}
	cout << prob << " " << base_guess << endl;
	if (prob > base_guess)
	{
		return true;
	}
	else return false;
}

void permute(int n)
{
	//for(int a = 0; a < n ; ++a)
	//{
		//for (int b = 0; b < n ; ++b)
		//{
			//cout << double(save[a][b]) / trials << " ";
		//}
		//cout << endl;
	//}
}
int  main(int  argc, char * argv[])
{
	const int n = size_;
	vector<vector<int> > save(n);
	//for (int j = 0; j < trials; j++)
	//{
		//if (j % 10000 == 0)
			//cout << " hi " << endl;
		//for (auto & it : save)
		//{
			//it.resize(n);
		//}
		//vector<int> A (n);
		//for(int a = 0; a < n; a++)
			//A[a] = a;

		//for (int b  = 0; b < n ; ++b)
		//{
			//int c  = rand() %n;
			//swap(A[b], A[c]);
		//}
		//for (int a = 0; a < n ; ++a)
		//{
			//save[a][A[a]] ++;
		//}
	//}

	//ofstream fout2("save_stuff.txt");
	vector<vector< double > > save_prob(n);
	//for(int a =0 ; a < n; ++a)
	//{
		//save_prob[a].resize(n);
		//for (int b =0; b < n; ++b)
		//{
			//save_prob[a][b] = log(double(save[a][b]) / trials);
			//fout2 << save_prob[a][b] << " ";
		//}
		//fout2 << endl;
	//}

	cout << "DONE solving\n";
	
	ifstream fsave ("save_stuff.txt");


	for(int a =0 ; a < n; ++a)
	{
		save_prob[a].resize(n);
		for (int b =0; b < n; ++b)
		{
			double temp;
			fsave >> temp;
			save_prob[a][b] = temp;
		}
	}
	fsave.close();
	//fout2.close();



	ifstream fin("input.txt"); 
	ofstream fout("output.txt");
	
	if(!fin.good())
	{
		cout << "opps" << endl;
	}

	string str;
	getline(fin, str);
	
	//	Number of test cases.
	const unsigned long int T = atoi(str.c_str());

	//	Loop across each file.
	for( unsigned long int aaa = 0; aaa < T ; aaa++)
	{
		probCase it_case = readCase(fin);

		bool guess = guess_case(it_case, save_prob);

		if (guess)
		{
			fout << "Case #" << aaa+1 << ": BAD" << endl;

		}
		else{
			fout << "Case #" << aaa+1 << ": GOOD"  << endl;
		}

		//stringstream sstm;
		//sstm << "HI" << aaa ;
		//string result = sstm.str();

		//string str1 = "hi" + to_string(aaa);
		//cout << str1 << endl;
		//writeCase(fout, aaa,result);




		//cout << fixed << setprecision(10) << "Case #" << aaa+1 << ": " << setprecision(10) << static_cast<long double>(current_time)<< setprecision(10) <<   "\t" << farms_true << endl;
		////fout << fixed << setprecision(10) << "Case #" << aaa+1 << ": " << setprecision(10) << static_cast<long double>(current_time)<< setprecision(10) <<  "\t" << farms << "\t" << farms_true << endl;
		//fout << fixed << setprecision(10) << "Case #" << aaa+1 << ": " << setprecision(10) << static_cast<long double>(current_time)<< setprecision(10) << endl;
	}	

	fin.close(); fout.close();
	return 0;
}
