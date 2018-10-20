#include <fstream>
#include <iostream>
#include <vector>
#include <limits>
#include <unordered_map>
#include <sstream>
#include <cassert>
#include <algorithm>

std::string signature(const std::vector<size_t>& n)
{
    std::stringstream ostr;
    for (size_t i = 0; i < n.size(); ++ i)
    {
        ostr << n[i] << '_';
    }
    return ostr.str();
}

struct graph
{
    std::vector<std::vector<size_t>> adj_; // adjacency matrix
    std::vector<size_t> nnb_; // number of neighbors
    size_t n_;

    size_t min_censored(size_t ncensored, 
            std::unordered_map<std::string, size_t>& cache)
    {
        std::string sig = signature(nnb_);
        auto cit = cache.find(sig);
        if (cit != cache.end())
            return cit->second;

        if (is_binary())
        {
            cache[sig] = ncensored;
            return ncensored;
        }

        for(size_t e = 0; e < nnb_.size(); ++ e)
        {
            // try censoring each leaf
            if (nnb_[e] == 1) {
                if (censor(e).is_binary())
                {
                    cache[sig] = ncensored + 1;
                    return ncensored + 1;
                }
            }
        }
        size_t minval = std::numeric_limits<size_t>::max();
        for (size_t e = 0; e < nnb_.size(); ++ e)
        {
            if (nnb_[e] == 1) {
                size_t val = censor(e).min_censored(ncensored + 1, cache);
                if (val < minval)
                {
                    minval = val;
                }
            }
        }
        cache[sig] = minval;
        return minval;
    }

    graph censor(size_t e)
    {
        assert(adj_[e].size() == 1);
        // create new graph with edge e removed
        graph g = *this;
        -- g.n_;
        // remove node e
        g.nnb_[e] = std::numeric_limits<size_t>::max();
        // remove all edges from e
        g.adj_[e].resize(0);
        for (size_t idx = 0, jdx = adj_[e].size(); idx < jdx; ++ idx)
        {
            if (nnb_[idx] == std::numeric_limits<size_t>::max()) continue;

            size_t nb = adj_[e][idx];
            -- g.nnb_[nb];
            auto& nbr = g.adj_[nb];
            nbr.erase(std::find(nbr.begin(), nbr.end(), e));
        }
        return g;
    }
    bool is_binary()
    {
        if (n_ == 1) return true;
        size_t c2 = 0, cother = 0;
        for (size_t idx = 0; idx < nnb_.size(); ++ idx)
        {
            if (nnb_[idx] == std::numeric_limits<size_t>::max()) continue;

            if (nnb_[idx] == (size_t)2) ++ c2;
            else if (nnb_[idx] > (size_t)3) ++ cother;
            if (c2 > 1 || cother != 0) 
                return false;
        }
        return (c2 == 1 && cother == 0);
    }

};

std::ifstream& operator>>(std::ifstream& istr, graph& g)
{
    istr >> g.n_;
    size_t e1, e2;
    g.nnb_.resize(g.n_, 0);
    g.adj_.resize(g.n_, std::vector<size_t>());
    for (size_t idx = 0; idx < g.n_-1; ++ idx)
    {
        istr >> e1 >> e2;
        -- e1; -- e2;
        ++ g.nnb_[e1];
        ++ g.nnb_[e2];
        g.adj_[e1].push_back(e2);
        g.adj_[e2].push_back(e1);
    }
    return istr;
}

void solve_case(int icase, std::ifstream& ifile)
{
    graph g;
    ifile >> g;
    std::unordered_map<std::string, size_t> cache;
    size_t tbest = g.min_censored(0, cache);
    std::cout << "Case #" << icase << ": " << tbest << std::endl;
}

void all_cases(std::ifstream& ifile)
{
    int ncases;
    ifile >> ncases;
    for (int i = 0; i < ncases; ++ i)
    {
	solve_case(i+1, ifile);
    }
}

int main(int argv, char** argc)
{
    if (argv < 2)
    {
	std::cerr << "Usage: " << std::string(argc[0]) << " inputfile\n";
	return -1;
    }
    std::ifstream infile(argc[1]);
    all_cases(infile);
}
