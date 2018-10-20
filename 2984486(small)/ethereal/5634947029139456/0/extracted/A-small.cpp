#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

typedef std::vector<int> VI;

int parse() {
    std::string s;
    std::cin >> s;
    int v = 0;
    for(int i = 0; i < s.length(); i ++) {
        if(s[s.length()-1-i] == '1') v |= (1<<i);
    }
    //std::cout << "parsed " << s << " as " << std::hex << v << std::dec << std::endl;
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

        int min = -1;
        for(int mask = 0; mask < (1<<L); mask ++) {
            //std::cout << "trying mask " << std::hex << mask << std::dec << std::endl;
            VI gen(N, 0);
            for(int i = 0; i < N; i ++) {
                gen[i] = out[i] ^ mask;
                //std::cout << "\tgen[" << i << "] = " << std::hex << gen[i] << std::dec << std::endl;
            }
            std::sort(gen.begin(), gen.end());
            if(gen == req) {
                int count = 0;
                for(int i  = 0; i < 20; i ++) if(mask & (1<<i)) count ++;
                if(min == -1) min = count;
                else min = std::min(min, count);
            }
        }

        std::cout << "Case #" << C; C ++; std::cout << ": ";
        if(min == -1) std::cout << "NOT POSSIBLE" << std::endl;
        else std::cout << min << std::endl;
    }
    return 0;
}
