#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <assert.h>
#include <cmath>

using namespace std;


ifstream fin("small.in");
ofstream fout("small.out");

double probDensity[1000][1000];
double uniformProbLog=0;
int len1000 = 1000;

void precompute(){
	for(int n=0;n<len1000;n++){
		for(int i=0;i<len1000;i++){
			probDensity[n][i] = (n==i);
		}
		
		for(int iter=0;iter<len1000;iter++){
			double oldIterProb = probDensity[n][iter];
			for(int rand=0;rand<len1000;rand++){
				if(rand!=iter){
					double pIterRand = oldIterProb*(1.0/(len1000));
					double pRandIter = probDensity[n][rand]*(1.0/(len1000));
					probDensity[n][iter] += pRandIter - pIterRand;
					probDensity[n][rand] += pIterRand - pRandIter;
				}
			}
		}
		
		for(int i=0;i<len1000;i++){
			assert(probDensity[n][i] == probDensity[n][i]);
		}
	}
	for(int i=0;i<len1000;i++){
		uniformProbLog += log(1.0/(i+1));
	}
}

int main(){
	int nt;
	fin >> nt;
	precompute();

	for(int t=0;t<nt;t++){
		fin >> len1000;
		double badProbLog = 0;
		int expectedRight;
		for(int i=0;i<len1000;i++){
			int curNum;
			fin >> curNum;
			double totalProb = 0;
			for(int j=i;j<len1000;j++){
				totalProb+=probDensity[curNum][j];
			}
			badProbLog += log((probDensity[curNum][i]/totalProb));
		}

		if(badProbLog > uniformProbLog)
			fout << "Case #" << t+1 << ": " << "BAD" << endl;
		else
			fout << "Case #" << t+1 << ": " << "GOOD" << endl;
		
	}
	return 0;
}