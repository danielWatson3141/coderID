#include <iostream>
#include <vector>
#include <map>

void read(const int len, std::vector<long> &vec){
	for(int i = 0; i < vec.size(); i++){
		char c;
		long &val = vec[i];
		for(int j = 0; j < len; j++){
			std::cin >> c;
			val <<= 1;
			val |= (c - '0');
		}
	}
}

bool check(const long mask, const std::vector<long> &outlet, const std::vector<long> &device){
	std::map<long, int> map;
	for(std::vector<long>::const_iterator iter = outlet.begin(); iter != outlet.end(); iter++)
		map[*iter & mask]++;
	for(std::vector<long>::const_iterator iter = device.begin(); iter != device.end(); iter++){
		std::map<long, int>::iterator cnt = map.find(*iter & mask);
		if(cnt == map.end() || 0 == cnt->second)
			return false;
		cnt->second--;
	}
	return true;
}

void func(int &best, const int fliped, const long level, const long mask, const std::vector<long> &outlet, const std::vector<long> &device){
	if(level <= 0){
		if (fliped < best) best = fliped;
		return;
	}
	const long nextLevel = level >> 1;
	const long nextMask = mask | nextLevel;
	if(check(mask, outlet, device))
		func(best, fliped, nextLevel, nextMask, outlet, device);
	std::vector<long> copy(outlet.size());
	if(fliped + 1 >= best) return;
	for(int i = 0; i < outlet.size(); i++)
		copy[i] = outlet[i] ^ level;
	if (check(mask, copy, device))
		func(best, fliped + 1, nextLevel, nextMask, copy, device);
}

int main(){
	int T;
	std::cin >> T;
	for(int cas = 1; cas <= T; cas++){
		int N, L;
		std::cin >> N >> L;
		std::vector<long> outlet(N),device(N);
		read(L, outlet);
		read(L, device);
		const long level = 1 << (L -1),
			mask = 1 << L - 1;
		int best = L + 1;
		func(best, 0, level, mask, outlet, device);
		std::cout << "Case #" << cas << ": ";
		if (best <= L)
			std::cout << best;
		else std::cout << "NOT POSSIBLE";
		std::cout << std::endl;
	}
	return 0;
}