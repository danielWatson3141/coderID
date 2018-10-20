//#include "cute_algostudy.h"

#include <string>
#include <vector>
#include <set>
#include <iostream>

//namespace code_jam_2014_1a_a {

int N, L;
int min;
std::vector<std::string> src;
std::set<std::string> target;

bool isInTarget(){
	for(int i = 0; i < src.size(); ++i){
		if(target.find(src[i]) == target.end()){
			return false;
		}
	}
	return true;
}

void flip(int l, int flipCnt){
	if(l == L){
		return;
	}
	for(int i = 0; i < src.size(); ++i){
		if(src[i][l] == '0'){
			src[i][l] = '1';
		}else{
			src[i][l] = '0';
		}
	}
	if(isInTarget()){
		if(min == -1){
			min = flipCnt;
		}else if(min > flipCnt){
			min = flipCnt;
		}
	}

	flip(l+1, flipCnt + 1);
	flip(l+1, flipCnt);
}

int main(){
	int T;
	std::cin >> T;

	for(int testCaseNo = 1; testCaseNo <= T; ++testCaseNo){
		std::cin >> N >> L;

		src.clear();
		target.clear();
		std::string tmp;
		min = -1;

		for(int i = 0; i < N; ++i){
			std::cin >> tmp;
			src.push_back(tmp);
		}
		for(int i = 0; i < N; ++i){
			std::cin >> tmp;
			target.insert(tmp);
		}

		flip(0, 1);
		flip(0, 0);

		if(min == -1){
			std::cout << "Case #" << testCaseNo << ": NOT POSSIBLE" << std::endl;
		}else{
			std::cout << "Case #" << testCaseNo << ": " << min << std::endl;
		}
	}

	return 0;
}

//CUTE_MAIN(__FILE__, main);

//}
