#include <fstream>
#include <iostream>
#include <cassert>
#include <vector>
#include <set>
#include <sstream>
#include <algorithm>

std::string noteq(const std::string& b1, const std::string& b2)
{
    std::stringstream ostr;
    assert(b1.size() == b2.size());
    for (size_t i = 0; i < b1.size(); ++ i)
    {
        ostr << ((b1[i] == b2[i]) ? '0' : '1');
    }
    return ostr.str();
}

std::vector<std::string> nbools(std::ifstream& ifile, const size_t N)
{
    std::string charge;
    std::vector<std::string> b;
    for (size_t i = 0; i < N; ++ i)
    {
        ifile >> charge;
        b.push_back(charge);
    }
    return b;
}

std::vector<std::string> intersect(std::vector<std::string>& a, std::vector<std::string>& b)
{
    if (a.empty() || b.empty())
        return std::vector<std::string>();

    std::vector<std::string> r(std::max(a.size(), b.size()));
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    auto it = std::set_intersection(a.begin(), a.end(), b.begin(), b.end(), r.begin());
    r.resize((size_t)std::distance(r.begin(), it));
    return r;
}

std::vector<std::string> allintersection(std::vector<std::vector<std::string>>& cl)
{
    std::vector<std::string> l = cl[0];
    for (size_t i = 1, j = cl.size(); i < j; ++ i)
    {
        l = intersect(l, cl[i]);
        if (l.empty()) return l;
    }
    return l;
}

std::vector<std::string> allintersection(std::vector<std::vector<std::string>>& cl, std::vector<std::string>& n)
{
    auto l = allintersection(cl);
    return intersect(l, n);
}

size_t find_ones(const std::string& istr)
{
    size_t flip = 0;
    for (size_t i = 0, j = istr.length();  i < j; ++ i)
    {
        flip += (istr[i] == '1') ? 1 : 0;
    }
    return flip;
}
size_t find_min(const std::vector<std::string>& vec)
{
    size_t minn = vec[0].length() + 1;
    for (size_t i = 0, j = vec.size(); i < j; ++ i)
    {
        size_t n = find_ones(vec[i]);
        if (n < minn)
        {
            minn = n;
        }
    }
    return minn;
}
void solve_case(int icase, std::ifstream& ifile)
{
    size_t N, L;
    ifile >> N >> L;
    std::vector<std::string> wire = nbools(ifile, N);
    std::vector<std::string> app = nbools(ifile, N);

    std::vector<std::vector<std::string>> 
        rowdiffs(N, std::vector<std::string>()), 
        coldiffs(N, std::vector<std::string>());
    for (size_t i = 0; i < N; ++ i)
    {
        for (size_t j = 0; j < N; ++ j)
        {
            std::string d = noteq(wire[i], app[j]);
            coldiffs[i].push_back(d);
            rowdiffs[j].push_back(d);
        }
    }

    // find common rows
    std::vector<std::string> cr = allintersection(rowdiffs);
    // find common columns
    std::vector<std::string> cc = allintersection(coldiffs, cr);
    std::stringstream res;
    if (!cc.empty()) 
    {
        size_t tbest = find_min(cc);
        res << tbest;
    }
    else {
        res << "NOT POSSIBLE";
    }

    std::cout << "Case #" << icase << ": " << res.str() << std::endl;
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
