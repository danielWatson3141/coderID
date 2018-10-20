#include <vector>
#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>

template <class T>
std::ostream& operator << (std::ostream& out, const std::vector<T>& v)
{
	out << "[ ";
	for (const auto& t: v) {
		out << t << " "; 
	}
	return out << "]";
}

void iterateOverMasks(size_t L)
{
	auto& out = std::cout;

	std::vector<unsigned> mask(L, 0);
	size_t MAX_L = 1 << L;
	for (size_t counter = 0; counter < MAX_L; ++counter) {
		for (size_t i = 0; i < L; ++i) {
			mask[i] = unsigned(bool(counter & (1 << i)));
		}
		//out << mask << std::endl;
	} 
}

void flip(unsigned& x, size_t b)
{
	x ^= (1 << b);
}

size_t solve(
	const std::vector<unsigned>& o, 
    const std::vector<unsigned>& d,
	size_t L)
{
	size_t N = o.size();
	
	std::vector<unsigned> sortedD(d);
	std::sort(sortedD.begin(), sortedD.end());

	std::vector<unsigned> flippedO(o);

	size_t minFlipsNumber = size_t(-1);

	std::vector<unsigned> mask(L, 0);
	size_t MAX_L = 1 << L;
	for (size_t counter = 0; counter < MAX_L; ++counter) {
		for (size_t i = 0; i < L; ++i) {
			mask[i] = unsigned(bool(counter & (1 << i)));
		}
		
		size_t numberOfFlips = 0;
		for (auto x: mask) {
			numberOfFlips += unsigned(bool(x));
		}
		
		if (numberOfFlips > minFlipsNumber)
			continue;		

		flippedO = o;
		for (size_t b = 0; b < mask.size(); ++b) {
			if (mask[b]) {
				for (auto& x: flippedO) {
					flip(x, b);
				}	
			}
		}
		
		std::sort(flippedO.begin(), flippedO.end());		
		if (sortedD == flippedO) {
			minFlipsNumber = std::min(minFlipsNumber, numberOfFlips);
		}
	} 
	return minFlipsNumber;
}

int main()
{
	auto& in = std::cin;
	auto& out = std::cout;
	
	size_t T;
	in >> T;

	for (size_t t = 0; t < T; ++t) {
		size_t N, L;
		in >> N >> L;
		std::vector<unsigned> outlets(N, 0), devices(N, 0);
			
		for (size_t i = 0; i < N; ++i) {
			std::string rep;
			in >> rep;
			assert(rep.size() == L);
			for (size_t b = 0; b < L; ++b) {
				if (rep[b] == '1') {
					outlets[i] |= (1 << b);
				}
			}
			//out << "Rep = " << rep << " Int = " << outlets[i] << std::endl;
		}

		for (size_t i = 0; i < N; ++i) {
			std::string rep;
			in >> rep;
			assert(rep.size() == L);
			for (size_t b = 0; b < L; ++b) {
				if (rep[b] == '1') {
					devices[i] |= (1 << b);
				}
			}
		}
	
		//out << "outlets: " << outlets << std::endl;
		//out << "devices: " << devices << std::endl;
		
		auto res = solve(outlets, devices, L);
		if (res == size_t(-1)) {
			out << "Case #" << (t + 1) << ": " << "NOT POSSIBLE"  << std::endl;
		} else {
			out << "Case #" << (t + 1) << ": " << res << std::endl;
		}

	}
	
	return 0;
}










