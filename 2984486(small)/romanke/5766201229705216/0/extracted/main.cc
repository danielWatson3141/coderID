#include <iostream>
#include <vector>
#include <algorithm>
#include <stdint.h>
#include <numeric>

#include <boost/multiprecision/cpp_int.hpp>
typedef boost::multiprecision::cpp_int bigint;

void visit (const std::vector< std::vector<size_t> > &mat, size_t root,
            std::vector<bool> &res, std::vector<bool> &dis) {
    if (res[root])
        return;
    res[root] = true;

    for (size_t i=0;i<mat.size();++i)
        if (!dis[i] && mat[root][i])
            visit(mat, i, res, dis);
}

bool reach(size_t root, const std::vector< std::vector<size_t> > &mat, 
    std::vector<bool> &dis) {
    std::vector<bool> r(mat.size(), false);
    visit(mat, root, r, dis);

    for (size_t i=0; i<mat.size(); ++i)
        if (!r[i] && !dis[i])
            return false;
    return true;
}

bool tree (std::vector< std::vector<size_t> > &mat, std::vector<bool> &dis) {
    if (mat.size()-std::accumulate(dis.begin(), dis.end(), 0) < 2)
        return true;

    size_t root = mat.size();
    for (size_t i=0; i<mat.size(); ++i) {
        if (dis[i])
            continue;

        size_t s = 0;
        for (size_t j=0; j<mat.size(); ++j)
            if (!dis[j])
                s += mat[i][j];
        if (s == 2) {
            if (root != mat.size())
                return false;
            root = i;
        }
        else if (s != 3 && s != 1)
            return false;
    }

    if (root == mat.size())
        return false;

    return reach(root, mat, dis);
}

size_t solve (std::vector< std::vector<size_t> > &mat) {
    std::vector<bool> dis(mat.size(), false);
    
    // for the small dataset can just enumerate
    size_t res = 0;
    size_t total = 1<<mat.size();
    size_t mindel = mat.size();
    for (size_t i=0; i<total; ++i) {
        size_t deleted = 0;
        for (size_t k=0;k<dis.size();++k) {
            dis[k] = (i>>k)&1;
            deleted += (i>>k)&1;
        }
        
        if (tree(mat, dis)) {
            if (deleted == 0)
                return 0;
            mindel = std::min(mindel, deleted);
        }
    }

    return mindel;
}

void play () {
    size_t n;
    std::cin >> n;
    std::vector< std::vector<size_t> > mat(n);
    for (size_t i=0;i<n;++i)
        mat[i].resize(n, 0);
    for (size_t i=1; i<n;++i) {
        size_t x,y;
        std::cin >> x >> y;
        --x; --y;
        mat[x][y] = mat[y][x] = 1;
    }

    std::cout << solve(mat) << std::endl;
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
