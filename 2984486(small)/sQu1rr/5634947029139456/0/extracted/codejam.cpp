#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int N, L;

void flip(std::vector<std::string> & map, int j) {
    for(int i = 0; i < N; ++i) {
        map[i][j] = (map[i][j] == '1') ? '0' : '1';
    }
}

int rec(std::vector<std::string> & map, const std::vector<std::string> & res, int j, int count = 0) {
    if (j == L) {
        std::vector<std::string> map2 = map;
        std::sort(map2.begin(), map2.end());
        //std::cout << " --- " << std::endl;
        //for(int i = 0; i < N; ++i) {
            //std::cout << map2[i] << " " << res[i] << std::endl;
        //}
        if (map2 == res) {
            return count;
        }
        else return -1;
    }

    //int r = 0, s = 0;
    //for (int i = 0; i < N; ++i) {
        //if (map[i][j] == '1') r++;
        //if (res[i][j] == '1') s++;
    //}

    //if(r != s && r != N - s) return -1;

    //else if(r != s) {
        //flip(map, j);
        //count = rec(map, res, j+1, count + 1);
        //flip(map, j);
        //return count;
    //}

    //else if(r == N - r) {
        int c = rec(map, res, j+1, count);

        flip(map, j);
        count = rec(map, res, j+1, count + 1);
        flip(map, j);
        if(count == -1) return c;
        if(c == -1) return count;
        return std::min(c, count);
    //} else {
        //count = rec(map, res, j+1, count);
        //return count;
    //}
}

void app(int test) {
    std::cout << "Case #" << test << ": ";

    std::cin >> N >> L;

    std::vector<std::string> map;
    std::vector<std::string> res;
    
    for (int i = 0; i < N; ++i) {
        std::string str;
        std::cin >> str;
        map.push_back(str);
    }

    for (int i = 0; i < N; ++i) {
        std::string str;
        std::cin >> str;
        res.push_back(str);
    }

    if (map == res) {
        std::cout << 0 << std::endl;
        return;
    }

    std::sort(res.begin(), res.end());

    int count = rec(map, res, 0);
    if(count != -1) {
        std::cout << count << std::endl;
    } else {
        std::cout << "NOT POSSIBLE" << std::endl;
    }
}

int main() {
    int tests;
    std::cin >> tests;
    for(int t = 0; t < tests; ++t) {
        app(t + 1);
    }
}
