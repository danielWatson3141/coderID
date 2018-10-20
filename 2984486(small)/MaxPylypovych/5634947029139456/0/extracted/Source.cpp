#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream output;
	ifstream input;
	input.open("input.txt");
	output.open("output.txt");


	int T;
	input >> T;
	//	cout << "T = "<<T << endl;

	unsigned N, L;
	unsigned *A, *B;
	int ans; int count;

	for (unsigned t = 0; t < T; ++t)
	{
		input >> N >> L;

/*		char** a = new char*[N];
		for (char i = 0; i < N; ++i)
			a[i] = new char[L + 1];

		char** b = new char*[N];
		for (char i = 0; i < N; ++i)
			b[i] = new char[L + 1];
*/
		char* c = new char[L + 1];
		unsigned* a = new unsigned[N];
		unsigned* b = new unsigned[N];
		
		for (char i = 0; i < N; ++i)
		{
			input >> c;
			a[i] = 0;
			for (char j = 0; j < L; ++j)
			{
				a[i] |= (c[j] - '0');
				a[i] = a[i] << 1;
			}
			a[i] = a[i] >> 1;
		}
		for (char i = 0; i < N; ++i)
		{
			input >> c;
			b[i] = 0;
			for (char j = 0; j < L; ++j)
			{
				b[i] |= (c[j] - '0');
				b[i]=b[i] << 1;
			}
			b[i] = b[i] >> 1;
		}

/*		for (char i = 0; i < N; ++i)
		{
		cout<<a[i]<<' ';
		}
		for (char i = 0; i < N; ++i)
		{
			cout<<b[i]<<' ';
		}
*/
		A = new unsigned[L];
		B = new unsigned[L];
		ans = 0;

		int min = L+1;
		for (int i = 0; i < N; ++i)
		{
			unsigned mask = a[0] ^ b[i];
			count = 0;
			for (int j = 0; j < N; ++j)
			{
				bool bb = 0;
				for (int k = 0; k < N; ++k)
				{
					if ((a[j] ^ mask) == b[k])
					{
						bb = 1;
						break;
					}
				}
				if (bb)
					count++;
			}
			if (count == N)
			{
				int tmp = 0;
				while (mask)
				{
					tmp += mask & 1;
					mask = mask >> 1;
				}
				if (min > tmp)
				{
					min = tmp;
//					cout << "  " << i << endl;
				}
			}
//			cout << endl;
		}


		output << "Case #" << t + 1 << ": ";
		if (min==L+1)
			output << "NOT POSSIBLE";
		else
			output << min;

		
		output << "\n";

	}




	input.close();
	output.close();
	//	system("pause");
	return 0;
}
