#include "code_jam_threaded.hpp"

typedef unsigned long long Int;
std::string solve_permutations(Tokens& tokens, std::mutex& mutex)
{
	const auto num_tokens = tokens.next_token<Int>();
	const Int threshold = (485 * num_tokens) / 1000;
	std::vector<Int> values(num_tokens);
	tokens.next_tokens(values.begin(), values.end());
	mutex.unlock();

	Int count = 0;
	for(Int i = 0; i < num_tokens; ++i)
		if(values[i] < i) ++count;

	if(count <= threshold)
		return "BAD";
	else
		return "GOOD";
}

MAIN_MULTITHREAD(solve_permutations)
