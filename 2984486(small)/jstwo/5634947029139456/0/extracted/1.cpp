#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <math.h>
#include <gmpxx.h>
#include <algorithm>
#include <assert.h>


void solve(std::ifstream& input)
{
	char x[150][40];
	char y[150][40];
	char tmp[100];
	
	int x_n[40];
	int y_n[40];
	int n ,l;
	input >> n >> l;
	
	for(int i =0; i < n; ++i) {
		input >> tmp;
		for(int j =0; j < l;++j) {
			x[i][j] = tmp[j] =='1' ? 1 : 0;
		}
	}

	for(int i =0; i < n; ++i) {
		input >> tmp;
		for(int j =0; j < l;++j) {
			y[i][j] = tmp[j] =='1' ? 1 : 0;
		}
	}
	
	for(int i =0; i < l;++i) {
		x_n[i] =0;
		for(int j = 0; j < n;++j) {
			if(x[j][i] == 1) {
				x_n[i]++;
			}
		}
	}

	for(int i =0; i < l;++i) {
		y_n[i] =0;
		for(int j = 0; j < n;++j) {
			if(y[j][i] == 1) {
				y_n[i]++;
			}
		}
	}


	int x_t[40];
	int y_t[40];

	for(int i =0; i < l;++i) {
		x_t[i] = x[0][i];
		for(int j =1; j < n;++j) {
			if(x_t[i] == x[j][i]) {
				x_t[i] = 0;
			}
			else {
				x_t[i] =1;
			}
		}
	}
	for(int i =0; i < l;++i) {
		y_t[i] = y[0][i];
		for(int j =1; j < n;++j) {
			if(y_t[i] == y[j][i]) {
				y_t[i] = 0;
			}
			else {
				y_t[i] = 1;
			}
		}
	}
	int result =0;
	for(int i =0; i < l ; ++i) {
		if(x_t[i] == y_t[i]) {
			if(n%2==1) {
				if(x_n[i] !=y_n[i]) {
					std::cout << "NOT POSSIBLE\n";
					return;
				}
			}
			else {
				if(x_n[i] !=y_n[i]) {
					if(x_n[i] != n- y_n[i]) {
						std::cout << "NOT POSSIBLE\n";
						return;
					}
					result++;
				}
			}
		}
		else if(x_t[i] != y_t[i]) {
		 	if( n%2 ==0) {
				std::cout << "NOT POSSIBLE\n";
				return;
			}
			else 
			{
				if(x_n[i] != n -  y_n[i]) {
					std::cout << "NOT POSSIBLE\n";
					return;
				}
				result++;
			}
		}
	}
	std::cout << result << "\n";
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
