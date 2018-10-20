#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>

int oneBits(unsigned long long _mask)
{
	int result = 0;
	for (unsigned long long i = 1; i <= sizeof(unsigned long long) * 4; ++i) {
		if (_mask & (1 << i)) {
			++result;
		}
	}
	return result;
}

bool satisfyAll(const std::unordered_set<unsigned long long> &_flow, const std::vector<unsigned long long> &_chargers, unsigned long long _mask)
{
	for (auto it = _chargers.begin(); it != _chargers.end(); ++it) {
		if (_flow.find(*it ^ _mask) == _flow.end()) {
			return false;
		}
	}
	return true;
}

int minimizeCosts(const std::unordered_set<unsigned long long> &_flow, const std::vector<unsigned long long> &_chargers)
{
	int minimum = 1 << 12;
	for (unsigned long long mask = 0; mask < (1 << 11) - 1; ++mask) {
		if (satisfyAll(_flow, _chargers, mask)) {
			int check = oneBits(mask);
			if (check < minimum) {
				minimum = check;
			}
		}
	}
	return minimum;
}

int main()
{
	int T, N, L;
	std::cin >> T;
	for (int cases = 1; cases <= T; ++cases) {
		std::cin >> N >> L;
		std::vector<unsigned long long> chargers;
		std::unordered_set<unsigned long long> flow;
		for (int i = 0; i < N; ++i) {
			unsigned long long add = 0;
			for (int j = 1; j <= L; ++j) {
				unsigned char is = 0;
				std::cin >> is;
				add |= ((static_cast<unsigned long long>(is) - '0') << (L - j));
			}
			chargers.push_back(add);
		}
		for (int i = 0; i < N; ++i) {
			unsigned long long add = 0;
			for (int j = 1; j <= L; ++j) {
				unsigned char is = 0;
				std::cin >> is;
				add |= ((static_cast<unsigned long long>(is) - '0') << (L - j));
			}
			flow.insert(add);
		}
		// -----
		std::cout << "Case #" << cases << ": ";
		int minimum = minimizeCosts(flow, chargers);
		if (minimum > 10) {
			std::cout << "NOT POSSIBLE\n";
		} else {
			std::cout << minimum << '\n';
		}
	}

	return 0;
}