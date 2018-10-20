#include <iostream>
#include <vector>


int main()
{
	int T, N;
	std::cin >> T;
	for (int cases = 1; cases <= T; ++cases) {
		std::cin >> N;
		double val;
		for (int i = 0; i < N; ++i) {
			std::cin >> val;
		}
		std::cout << "Case #" << cases << ": " << (rand() % 2 ? "GOOD" : "BAD") << '\n';
	}

	return 0;
}