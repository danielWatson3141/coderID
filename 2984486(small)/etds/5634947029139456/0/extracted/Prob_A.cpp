
#define PROBLEM_NAME "A"
#define PROBLEM_SMALL_INPUT "-small-attempt1"
#define PROBLEM_LARGE_INPUT "-large"

#include <set>

int N, L;

int check_recursive(const std::multiset<int>& outlet, const std::multiset<int>& device, std::vector<int>& bit_to_check, int check_index)
{
	if (check_index >= (int)bit_to_check.size())
	{
		if (outlet == device)
		{
			return 0;
		}
		else
		{
			return -1;
		}
	}

	std::multiset<int> outlet_touch;
	int bit_modify = bit_to_check[check_index];
	for (std::multiset<int>::const_iterator it = outlet.begin(); it != outlet.end(); ++it)
	{
		int val = (*it);
		val ^= (1 << (L-bit_modify-1));
		outlet_touch.insert(val);
	}

	int r_notouch = check_recursive(outlet, device, bit_to_check, check_index+1);
	int r_touch = check_recursive(outlet_touch, device, bit_to_check, check_index+1);
	if (r_notouch < 0 && r_touch < 0)
		return -1;
	else if (r_notouch < 0)
		return r_touch + 1;
	else if (r_touch < 0)
		return r_notouch;
	else
		return mymin(r_notouch, r_touch + 1);

//	return additional_count;
}


int main(int argc, char* argv[])
{
//	set_fio(PROBLEM_NAME ".txt");
//	set_fio(PROBLEM_NAME PROBLEM_SMALL_INPUT ".in");
	set_fio(PROBLEM_NAME PROBLEM_SMALL_INPUT ".in", PROBLEM_NAME PROBLEM_SMALL_INPUT ".out.txt");
//	set_fio(PROBLEM_NAME PROBLEM_LARGE_INPUT ".in");
//	set_fio(PROBLEM_NAME PROBLEM_LARGE_INPUT ".in", PROBLEM_NAME PROBLEM_LARGE_INPUT ".out.txt");

	int* bitcount_outlet = 0;
	int* bitcount_device = 0;

	int T;
	fin >> T;
	for (int cases=1; cases<=T; ++cases)
	{
		fin >> N >> L;

		delete [] bitcount_outlet;
		delete [] bitcount_device;
		bitcount_outlet = new int[L];
		bitcount_device = new int[L];

		std::multiset<int> outlet, device;
		int switch_count = 0;

		for (int i=0; i<L; ++i)
		{
			bitcount_outlet[i] = 0;
			bitcount_device[i] = 0;
		}

		std::string str;
		for (int i=0; i<N; ++i)
		{
			fin >> str;
			int val = 0;
			for (int j=0; j<L; ++j)
			{
				if (str[j] == '1')
				{
					val |= (1 << (L-j-1));
					bitcount_outlet[j]++;
				}
			}
			outlet.insert(val);
			//cout << str << "(" << val << ") ";
		}

		//cout << std::endl;
		for (int i=0; i<N; ++i)
		{
			fin >> str;
			int val = 0;
			for (int j=0; j<L; ++j)
			{
				if (str[j] == '1')
				{
					val |= (1 << (L-j-1));
					bitcount_device[j]++;
				}
			}
			device.insert(val);
			//cout << str << "(" << val << ") ";
		}

		//cout << std::endl;

		// initially, check swiches that must be turned on/off
		// and find bits to recursively turn on/off
		std::vector<int> bit_to_check;
		for (int i=0; i<L; ++i)
		{
			if (bitcount_outlet[i] != bitcount_device[i] &&
				bitcount_outlet[i] + bitcount_device[i] == N)
			{
				std::multiset<int> outlet_new;
				for (std::multiset<int>::iterator it = outlet.begin(); it != outlet.end(); ++it)
				{
					int val = (*it);
					val ^= (1 << (L-i-1));
					outlet_new.insert(val);
				}
				outlet = outlet_new;
				switch_count++;
			}
			else if (bitcount_outlet[i] == bitcount_device[i])
			{
				bit_to_check.push_back(i);
			}
		}

//		bit_to_check.clear();
//		bit_to_check.push_back(3);
		if (outlet == device)
		{
			fout << "Case #" << cases << ": " << switch_count << endl;
			continue;
		}

		int additional_count = check_recursive(outlet, device, bit_to_check, 0);
		if (additional_count < 0)
			fout << "Case #" << cases << ": NOT POSSIBLE" << endl;
		else
			fout << "Case #" << cases << ": " << switch_count + additional_count << endl;
	}

	return 0;
}
