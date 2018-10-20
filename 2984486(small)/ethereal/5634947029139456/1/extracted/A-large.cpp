#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdint.h>
#include <map>

typedef std::vector<uint64_t> VI;

uint64_t parse() {
    std::string s;
    std::cin >> s;
    uint64_t v = 0;
    for(int i = 0; i < s.length(); i ++) {
        if(s[s.length()-1-i] == '1') v |= (1ULL<<i);
    }
    return v;
}

int main() {
    int T;
    std::cin >> T;
    int C = 1;
    while(T--) {
        int N, L;
        std::cin >> N >> L;
        
        VI out(N, 0);
        for(int i = 0; i < N; i ++) out[i] = parse();
        VI req(N, 0);
        for(int i = 0; i < N; i ++) req[i] = parse();
        std::sort(req.begin(), req.end());

        std::map<uint64_t, int> counts;
        for(auto a : out) {
            for(auto b : req) {
                counts[a ^ b] ++;
            }
        }
        int min = -1;
        for(auto i = counts.begin(); i != counts.end(); ++i) {
            if(i->second != N) continue;
            int count = 0;
            for(int j = 0; j < 42; j ++) {
                if(i->first & (1ULL<<j)) count ++;
            }
            if(min == -1) min = count;
            else min = std::min(min, count);
        }

        std::cout << "Case #" << C; C ++; std::cout << ": ";
        if(min == -1) std::cout << "NOT POSSIBLE" << std::endl;
        else std::cout << min << std::endl;
    }
    return 0;
}
