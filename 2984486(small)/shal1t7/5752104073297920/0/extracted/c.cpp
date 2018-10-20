#include <vector>
#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
#include <cmath>

template <class T>
std::ostream& operator << (std::ostream& out, const std::vector<T>& v)
{
	out << "[ ";
	for (const auto& t: v) {
		out << t << " "; 
	}
	return out << "]";
}

double stat(const std::vector<size_t>& p)
{
	double counter = 0;
	for (size_t i = 0; i < p.size(); ++i) {
		for (size_t j = i + 1; j  < p.size(); ++j) {
			if (p[i] < p[j]) {
				counter += double(p[i]) / p.size();
			}
		}
	} 
	return counter;
}

std::vector<size_t> nextP(size_t N)
{
	std::vector<size_t> p(N);
	for (size_t i = 0; i < p.size(); ++i)
		p[i] = i;
	for (size_t i = 0; i < N; ++i) {
		
		auto h = rand() % (N - i);
		assert(h >= 0);
		assert(h <= N - 1);
		std::swap(p[i], p[i + h]); 
		
		auto j = rand() % N;
		//std::swap(p[i], p[j]);
		
	}
	return p;
}

int main()
{
	auto& in = std::cin;
	auto& out = std::cout;

	/*	
	double sum = 0;
	double sum2 = 0;
	size_t M = 4000;
	for (size_t i = 0; i < M; ++i) {
		auto s = stat(nextP(1000));
		sum += s;
		sum2 += (s * s);	
	}
	sum /= M;
	sum2 /= M;
	std::cout << "AVG = " << sum << std::endl;
	std::cout << "SIG = " << std::sqrt(sum2 - sum * sum) << std::endl;
	
	return 0;
	*/

	size_t T;
	in >> T;

	double S_C = 83106;
	double S_IC = 86804;

	for (size_t t = 0; t < T; ++t) {
		size_t N;
		in >> N;
		std::vector<size_t> v(N, 0);
		for (size_t i = 0; i < N; ++i) {
			size_t x = 0;
			in >> x;
			v[i] = x;
		}
		assert(v.size() == 1000);
		double s = stat(v);
		std::cerr << "stat = " << s << std::endl;
		double d_c = std::abs(s - S_C);
		double d_ic = std::abs(s - S_IC);
		if (d_c < d_ic) {
			std::cout << "Case #" << (t + 1) << ": GOOD" << std::endl;
		} else {
			std::cout << "Case #" << (t + 1) << ": BAD" << std::endl;
		}
	}
	
	return 0;
}










