#include <iostream>
#include <vector>
#include <algorithm>
#include <stdint.h>

#include <boost/multiprecision/cpp_int.hpp>
typedef boost::multiprecision::cpp_int bigint;

void play () {
    size_t n;
    std::cin >>  n;
    size_t curr;
    size_t prev;
    size_t same = 0;
    size_t bigger = 0;
    for (size_t idx=0; idx<n; ++idx) {
        prev = curr;
        std::cin >> curr;
        if (curr == idx)
            ++same;
        if (idx)
            bigger += curr > prev;
    }

    if (same > 1)
        std::cout << "BAD" << std::endl;
    else
        std::cout << "GOOD" << std::endl;
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
