#include <iostream>
#include <string>

using namespace std;
typedef long long int int64;

void ReadBinary(int64 &value, int len)
{
	string binary;
	cin >> binary;
	value = 0;
	for (int b = 0; b < len; ++b)
		if (binary[b] == '1')
			value |= (int64(1) << b);
}

int count_bits(int64 number, int L)
{
	int count = 0;
	for (int b = 0; b < L; ++b)
		if (number & (int64(1) << b))
			++count;
	return count;
}

int main()
{
	cerr << "*****************************************************************************" << endl;
	cerr << "*****************************************************************************" << endl;
	int T;
	cin >> T;
	for (int case_num = 1; case_num <= T; ++case_num)
	{
		int N, L;
		cin >> N >> L;
		int64 outlets[150], devices[150];
		for (int i = 0; i < N; ++i)
			ReadBinary(outlets[i], L);
		for (int i = 0; i < N; ++i)
			ReadBinary(devices[i], L);

		int num_fixed = 0, num_variable = 0;
		int variable[40], fixed[40];
		bool impossible = false;
		for (int b = 0; b < L; ++b)
		{
			int d_ones = 0, o_ones = 0;
			for (int i = 0; i < N; ++i)
			{
				if (devices[i] & (int64(1) << b))
					++d_ones;
				if (outlets[i] & (int64(1) << b))
					++o_ones;
			}

			cerr << b << ": " << d_ones << "(" << (N - d_ones) << ") " << o_ones << "(" << (N - o_ones) << ")" << endl;

			if ((d_ones == o_ones) || (d_ones == (N - o_ones)))
			{
				if (d_ones == (N - d_ones))
					variable[num_variable++] = b;
				else if (d_ones == (N - o_ones))
					fixed[num_fixed++] = b;
			}
			else
				impossible = true;
		}
		for (int j = 0; j < num_fixed; ++j)
			for (int i = 0; i < N; ++i)
				outlets[i] ^= int64(1) << fixed[j];

		cerr << impossible << " " << num_fixed << " " << num_variable << ": ";
		for (int i = 0; i < num_variable; ++i)
			cerr << variable[i] << " ";
		cerr << endl;

		int min_found = 1000;
		if (!impossible)
		{
			int64 t_outlets[150], t_devices[150];
			for (int i = 0; i < N; ++i)
				t_devices[i] = devices[i];
			sort(t_devices, t_devices + N);

			int64 num_possible = int64(1) << num_variable;
			for (int64 trial = 0; trial < num_possible; ++trial)
			{
				int64 invert = 0;
				for (int b = 0; b < num_variable; ++b)
					if (trial & (int64(1) << b))
						invert |= int64(1) << variable[b];

				for (int i = 0; i < N; ++i)
					t_outlets[i] = (outlets[i] ^ invert);
				sort(t_outlets, t_outlets + N);

				bool matches = true;
				for (int i = 0; i < N; ++i)
					if (t_devices[i] != t_outlets[i])
					{
						matches = false;
						break;
					}
				if (matches)
				{
					int found_count = count_bits(trial, num_variable);
					if (found_count < min_found)
					{
						cerr << "found " << found_count << ": " << trial << endl;
						min_found = found_count;
					}
				}
			}

			if (min_found == 1000)
				impossible = true;
		}

		cout << "Case #" << case_num << ": ";
		if (impossible)
			cout << "NOT POSSIBLE";
		else
			cout << (min_found + num_fixed);
		cout << endl;
	}

	return 0;
}