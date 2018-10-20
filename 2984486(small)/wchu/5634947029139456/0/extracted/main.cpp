#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>
#include <cmath>
#include <string>
#include <queue>
#include <numeric>
#include <map>
#include <set>

#include <cilk/cilk.h>
#include <cilk/reducer_min.h>

using namespace std;


int main(int argc, char *argv)
{
	ifstream ifs("A-small-attempt1.in");
	ofstream ofs("A-small-attempt1.out");
	unsigned int nb_cases;
	ifs >> nb_cases;
	for (unsigned int i = 0; i < nb_cases; i++)
	{
		ofs << "Case #"<<i+1<<": ";
		// do for each case
		bool not_possible = false;
		size_t N, L;
		ifs >> N;
		ifs >> L;
		vector< string > outlets(N);
		vector< string > devices(N);
		for (size_t j = 0; j < N; j++)
		{
			ifs >> outlets[j];
		}
		for (size_t j = 0; j < N; j++)
		{
			ifs >> devices[j];
		}
		sort(devices.begin(), devices.end());
		long long int flip_trial = long long int(1) << L;
		//cilk::reducer_min<size_t> min_flipped(numeric_limits<size_t>::max());
		size_t min_flipped(numeric_limits<size_t>::max());
		//cilk_for (long long int flip_comb = 0; flip_comb < flip_trial; flip_comb++)
		for (long long int flip_comb = 0; flip_comb < flip_trial; flip_comb++)
		{
			std::vector<size_t> pos_flipped;
			for (size_t j = 0; j < L; j++)
				if (flip_comb & (long long int(1) << j))	pos_flipped.push_back(j);
			vector< string > v(N);
			copy(outlets.begin(), outlets.end(), v.begin());
			for (size_t j = 0; j < pos_flipped.size(); j++)
				for (size_t k = 0; k < N; k++)
				{
					if (v[k][pos_flipped[j]] == '0')	v[k][pos_flipped[j]] = '1';
					else								v[k][pos_flipped[j]] = '0';
				}
			sort(v.begin(), v.end());
			if (equal(v.begin(), v.end(), devices.begin()))
				//min_flipped.calc_min(pos_flipped.size());
					min_flipped = min(min_flipped, pos_flipped.size());
		}
		if (min_flipped/*.get_value()*/ == numeric_limits<size_t>::max())
			ofs << "NOT POSSIBLE";
		else
			ofs << min_flipped/*.get_value()*/;
		//vector< size_t > nb_bit1(L, 0);
		//for (size_t j = 0; j < L; j++)
		//	for (size_t k = 0; k < N; k++)
		//		if (devices[k][j] == '1')	nb_bit1[j]++;
		//vector< size_t > should_be_flipped;
		//vector< size_t > possible_be_flipped;
		//for (size_t j = 0; j < L; j++)
		//{
		//	size_t nb = 0;
		//	for (size_t k = 0; k < N; k++)
		//	{
		//		if (outlets[k][l] == '1')	nb++;
		//	}
		//	if (nb == nb_bit1[j] && nb == N - nb_bit1[j])	possible_be_flipped.push_back(j);
		//	else if (nb != nb_bit1[j] && nb == N - nb_bit1[j])	should_be_flipped.push_back(j);
		//	else if (nb != nb_bit1[j] && nb != N - nb_bit1[j])
		//	{
		//		not_possible = true;
		//		break;
		//	}
		//}
		//if (not_possible)
		//{
		//	ofs << "NOT POSSIBLE\n";
		//}
		//else
		//{
		//	size_t nb_flipped = should_be_flipped.size();
		//	for (size_t j = 0; j < should_be_flipped.size(); j++)
		//	{
		//		for (size_t k = 0; k < outlets.size(); k++)
		//		{
		//			if (outlets[k][should_be_flipped[j]] == '1')	outlets[k][should_be_flipped[j]] = '0';
		//			else											outlets[k][should_be_flipped[j]] = '1';
		//		}
		//	}
		//	sort(outlets.begin(), outlets.end());
		//	if (equal(outlets.begin(), outlets.end(), devices.begin()))
		//	{
		//		ofs << nb_flipped << endl;
		//		continue;
		//	}
		//	long long int flip_trial = long long int(1) << possible_be_flipped.size();
		//	vector<string> outlets_backup(N);
		//	for (long long int flip_comb = 1; flip_comb < flip_trial; flip_comb++)
		//	{
		//		std::vector<size_t> pos_flipped;
		//		for (size_t j = 0; j < possible_be_flipped.size(); j++)
		//			if (flip_comb & (1 << j))	pos_flipped.push_back(j);
		//		copy(outlets_backup.begin(), outlets_backup.end(), outlets.begin());
		//		for (size_t j = 0; j < pos_flipped.size(); j++)
		//			for (outlets_backup[possible_be_flipped
		//	}
		//}

		ofs << endl;
	}
	return 0;
}