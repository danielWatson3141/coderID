#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <math.h>
#include <gmpxx.h>
#include <algorithm>
#include <assert.h>


int s_tree (std::multimap<int,int>& tree, int n, int p) {
	std::pair <std::multimap<int,int>::iterator, std::multimap<int,int>::iterator> ret;
	ret = tree.equal_range(n);
	int total = 0;
	int c[1000];
	while(ret.first != ret.second) {
		c[total] = (*ret.first).second;
		total += 1;
		ret.first++;
	}

	if((p ==-1 && total < 2) ||( p >0 && total < 3)) {
		return 0;
	}
	
	int m1 =0, m2=0;
	for(int i =0; i < total;++i) {
		if(c[i]!=p) {
			int tmp = s_tree(tree, c[i], n);
			if(tmp > m2) {
				m2 = tmp;
				if(m2 > m1) {
					tmp = m1;
					m1 = m2;
					m2= tmp;
				}
			}
		}
	}
	return 2 + m1 +m2;
}

void solve(std::ifstream& input)
{
	int t;
	std::multimap<int,int> tree;

	input >> t;
	for(int i =0; i < t-1;++i) {
		int x, y;
		input >> x >> y;
		tree.insert(std::pair<int, int> (x, y));
		tree.insert(std::pair<int, int> (y, x));
	}
	int m =t;
	
	for(int i =1; i <= t;++i) {
		int used = 1;
		used += s_tree(tree, i, -1);
		if(m > (t- used) ) {
			m = t-used;
		}
	}
	std::cout << m << "\n";
}
int main(int argc, char* argv[]) 
{
	if(argc < 2) {
		std::cerr << "missing input file\n" ;
		return 1;
	}

	std::ifstream in(argv[1]);
	int c ;
	in  >> c;
	for(int i =1; i <=c;++i) {
		printf("Case #%d: ", i);
		solve(in);
	}
	return 0;
}
