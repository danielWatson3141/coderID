#include <cstdio>
#include <vector>
#include <sstream>
#include <unordered_set>

typedef struct tag_TestCase
{
	int id;
	int length;
	int count;
	std::vector<unsigned int> devices;
	std::vector<unsigned int> plugs;
} TestCase;

int count_bits_set(unsigned int i)
{
	i = i - ((i >> 1) & 0x55555555);
	i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
	return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

unsigned int bin_to_dec(std::string s, int l)
{
	int result = 0;
	for (int i = 0; i < l; i++)
		if (s.at(i) == '1')
			result |= (1 << i);
	return result;
}

void solve_test_case(TestCase tc, FILE *output)
{
	std::unordered_set<unsigned int> switch_variants;
	for (int i = 0; i < tc.count; i ++)
		for (int j = 0; j < tc.count; j++)
			switch_variants.insert(tc.devices.at(i) ^ tc.plugs.at(j));
	int best_result = 128;
	for (std::unordered_set<unsigned int>::iterator v = switch_variants.begin(); v != switch_variants.end(); ++v)
	{
		unsigned int variant = *v;
		int set_count = count_bits_set(variant);
		if (set_count >= best_result)
			continue;
		std::vector<unsigned int> plugs(tc.plugs);
		for (auto j = plugs.begin(); j != plugs.end(); ++j)
			*j = *j ^ variant;
		bool correct_variant = true;
		for (auto i = tc.devices.begin(); i != tc.devices.end(); ++i)
		{
			bool found = false;
			for (auto j = plugs.begin(); j != plugs.end(); ++j)
				if (*i == *j)
				{
					*j = 0xFFFFFFFF;
					found = true;
					break;
				}
			if (!found)
			{
				correct_variant = false;
				break;
			}
		}
		if (!correct_variant)
			continue;
		best_result = set_count;
	}
	fprintf(output, "Case #%d: ", tc.id);
	if (best_result <= tc.length)
		fprintf(output, "%d", best_result);
	else
		fprintf(output, "NOT POSSIBLE");
	fprintf(output, "\n");

}

void main()
{
	FILE *input = fopen("IO/input.txt", "rt");
	FILE *output = fopen("IO/output.txt", "wt");
	int t = 0;
	fscanf(input, "%d", &t);
	for (int i = 1; i <= t; ++i)
	{
		TestCase tc;
		tc.id = i;
		fscanf(input, "%d %d\n", &tc.count, &tc.length);
		for (int i = 0; i < tc.count; ++i)
		{
			char buffer[512];
			memset(buffer, 0, 512);
			fscanf(input, "%s", &buffer);
			std::istringstream iss(buffer);
			std::string s;
			while (getline(iss, s, ' '))
				tc.plugs.push_back(bin_to_dec(s, tc.length));
		}
		for (int i = 0; i < tc.count; ++i)
		{
			char buffer[512];
			memset(buffer, 0, 512);
			fscanf(input, "%s", &buffer);
			std::istringstream iss(buffer);
			std::string s;
			while (getline(iss, s, ' '))
				tc.devices.push_back(bin_to_dec(s, tc.length));
		}
		solve_test_case(tc, output);
	}
	fclose(output);
	fclose(input);
}