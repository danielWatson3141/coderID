
#define PROBLEM_NAME "C"
#define PROBLEM_SMALL_INPUT "-small-attempt3"
#define PROBLEM_LARGE_INPUT "-large"

#include <set>


int main(int argc, char* argv[])
{
//	set_fio(PROBLEM_NAME ".txt");
//	set_fio(PROBLEM_NAME PROBLEM_SMALL_INPUT ".in");
	set_fio(PROBLEM_NAME PROBLEM_SMALL_INPUT ".in", PROBLEM_NAME PROBLEM_SMALL_INPUT ".out.txt");
//	set_fio(PROBLEM_NAME PROBLEM_LARGE_INPUT ".in");
//	set_fio(PROBLEM_NAME PROBLEM_LARGE_INPUT ".in", PROBLEM_NAME PROBLEM_LARGE_INPUT ".out.txt");

	int good = 0, bad = 0;

	int T;
	fin >> T;
	for (int cases=1; cases<=T; ++cases)
	{
		int N;
		fin >> N;

		std::vector<int> v;
		for (int i=0; i<N; ++i)
		{
			int val;
			fin >> val;
			v.push_back(val);
		}

#define myabs(a, b)		((a > b) ? (a - b) : (b - a))
		// calc. distance average
		std::vector<int> dist(N);
		double sum = 0;
		for (int i=0; i<N; ++i)
		{
			//dist[i] = v[i] > i ? (v[i] - i) : (i - v[i]);
			dist[i] = myabs(v[i], i);
			sum += dist[i];
		}
		double avg = sum / N;

		double meandiffsum = 0;
		for (int i=0; i<N; ++i)
		{
			double d = (avg - v[i]);
			meandiffsum += d*d;
		}
		double var = meandiffsum / N;
		double stddev = sqrt(var);

		double comp = N/3;

		double d_avg = myabs(comp, avg);
		double d_dev = myabs(comp, stddev);

		double b = 0.024;
//		if (d_avg > 0.02 * comp || d_dev > 0.02 * comp)
///		if (d_avg > b * comp)
		if (d_avg > b * comp || d_dev > b * comp)
		{
			fout << "Case #" << cases << ": BAD" << endl;
			bad++;
		}
		else
		{
			fout << "Case #" << cases << ": GOOD" << endl;
			good++;
		}
//		fout << "         " << avg << " : " << var << " : " << stddev << endl;

	}

	return 0;
}
