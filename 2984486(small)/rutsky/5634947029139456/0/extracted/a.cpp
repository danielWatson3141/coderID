#include <iostream>
#include <algorithm>
#include <array>
#include <iterator>
#include <set>
#include <cassert>
#include <vector>
#include <cstdio>

using namespace std;

struct Solution
{
  Solution(std::vector<std::string> & outs,
           std::vector<std::string> & reqs,
           size_t L)
    : outlets(outs)
    , required(reqs)
    , L(L)
  {
    assert(L >= 2);
    assert(outlets.size() == required.size());

    N = outlets.size();

    for (std::string const & s: outlets)
      assert(s.size() == L);

    for (std::string const & s: required)
      assert(s.size() == L);

    std::sort(required.begin(), required.end());

    min_flips = static_cast<std::size_t>(-1);

    std::vector<std::vector<size_t>> start_perm(1);
    for (size_t i = 0; i != N; ++i)
      start_perm[0].push_back(i);

    solve(0, start_perm, 0);
  }

  void do_flip(std::vector<std::vector<size_t>> & perm)
  {
    assert(perm.size() % 2 == 0);
    for (size_t i = 0; i != perm.size(); i += 2)
    {
      std::swap(perm[i], perm[i + 1]);
    }
  }

  void solve(size_t idx, std::vector<std::vector<size_t>> const & perm, size_t num_flips)
  {
    if (idx == L)
    {
      min_flips = std::min(min_flips, num_flips);
      return;
    }

    assert(idx < L);
    assert(perm.size() == (1ULL << idx));

    bool flip_selected = false;
    bool flip = false;

    std::vector<std::vector<size_t>> next_perm;
    next_perm.reserve(perm.size() * 2);

    size_t n = 0;
    for (size_t i = 0; i != perm.size(); ++i)
    {
      next_perm.push_back(std::vector<size_t>());
      next_perm.push_back(std::vector<size_t>());

      std::vector<size_t> & zeroes = *std::prev(next_perm.end(), 2);
      std::vector<size_t> & ones   = *std::prev(next_perm.end(), 1);

      size_t n_zeroes = 0;
      size_t n_req_zeroes = 0;
      for (size_t j = 0; j != perm[i].size(); ++j, ++n)
      {
        if (outlets[perm[i][j]][idx] == '0')
        {
          ++n_zeroes;
        }
        else
        {
          assert(outlets[perm[i][j]][idx] == '1');
        }

        if (required[n][idx] == '0')
        {
          ++n_req_zeroes;
        }
        else
        {
          assert(required[n][idx] == '1');
        }

        if (outlets[perm[i][j]][idx] == '0')
        {
          zeroes.push_back(perm[i][j]);
        }
        else
        {
          assert(outlets[perm[i][j]][idx] == '1');
          ones.push_back(perm[i][j]);
        }
      }

      if (n_req_zeroes != n_zeroes && n_req_zeroes != perm[i].size() - n_zeroes)
      {
        // flip not possible
        return;
      }

      if (n_req_zeroes * 2 != perm[i].size())
      {
        // flip may be selected
        bool need_flip = (n_req_zeroes != n_zeroes);

        if (flip_selected)
        {
          if (flip != need_flip)
            return;
        }
        else
        {
          flip_selected = true;
          flip = need_flip;
        }
      }
    }

    if (flip_selected)
    {
      if (flip)
      {
        do_flip(next_perm);
        solve(idx + 1, next_perm, num_flips + 1);
      }
      else
      {
        solve(idx + 1, next_perm, num_flips);
      }
    }
    else
    {
      solve(idx + 1, next_perm, num_flips);

      do_flip(next_perm);
      solve(idx + 1, next_perm, num_flips + 1);
    }
  }

  std::string result() const
  {
    if (min_flips != static_cast<std::size_t>(-1))
    {
      assert(min_flips <= L);
      return std::to_string(min_flips);
    }
    else
      return "NOT POSSIBLE";
  }

  std::vector<std::string> outlets;
  std::vector<std::string> required;
  size_t L, N;

  size_t min_flips;
};

int main()
{
  size_t T;

  //FILE * res = std::freopen("A-small-attempt0.in", "rt", stdin);
  //assert(res);

  std::cin >> T;

  for (size_t idx = 0; idx != T; ++idx)
  {
    size_t N, L;
    std::cin >> N >> L;

    std::vector<std::string> outlets(N);
    std::copy_n(std::istream_iterator<std::string>(std::cin), N, outlets.begin());

    std::vector<std::string> required(N);
    std::copy_n(std::istream_iterator<std::string>(std::cin), N, required.begin());

    Solution s(outlets, required, L);

    std::cout << "Case #" << (idx + 1) << ": " << s.result() << "\n";
  }
}
