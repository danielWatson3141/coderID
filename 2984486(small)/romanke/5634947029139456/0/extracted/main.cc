#include <iostream>
#include <vector>
#include <algorithm>
#include <stdint.h>

#include <boost/multiprecision/cpp_int.hpp>
typedef boost::multiprecision::cpp_int bigint;

static const size_t nores = static_cast<size_t>(-1);

size_t popcnt (size_t num) {
    size_t res = 0;
    while (num) {
        res += num&1;
        num >>= 1;
    }
    return res;
}

size_t solve (std::vector<size_t> &devs, std::vector<size_t> &currs,
              size_t idx = 0, size_t currsol = nores) {
    if (idx == devs.size())
        return currsol;

    size_t bestpop = 500;
    size_t bestres = nores;

    for (size_t i=idx; i<devs.size(); ++i) {
        size_t sol = devs[idx] ^ currs[i];
        if (currsol != nores && currsol != sol)
            continue;

        std::swap(currs[i], currs[idx]);
        size_t solved = solve(devs, currs, idx+1, sol);
        std::swap(currs[i], currs[idx]);

        if (solved != nores) {
            size_t p = popcnt(solved);
            if (p < bestpop) {
                bestres = solved;
                bestpop = p;
            }
        }
    }

    return bestres;
}

size_t read (size_t l) {
    size_t res = 0;
    char c;
    while (l--) {
        std::cin >> c;
        while (c != '1' && c != '0')
            std::cin >> c;
        res = res * 2 + (c=='1');
    }
    return res;
}

void play () {
    size_t n, l;
    std::cin >> n >> l;
    std::vector<size_t> devs;
    std::vector<size_t> currs;
    for (size_t i=0;i<n;++i)
        devs.push_back(read(l));
    for (size_t i=0;i<n;++i)
        currs.push_back(read(l));
    
    size_t res = solve(devs, currs);
    if (res == nores)
        std::cout << "NOT POSSIBLE" << std::endl;
    else
        std::cout << popcnt(res) << std::endl;
}

int main () {
    size_t cases;
    std::cin >> cases;
    for (size_t i=1; i<=cases; ++i) {
        std::cout << "Case #" << i << ": ";
        play();
    }
    return 0;
}
