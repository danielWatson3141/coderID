#include <fstream>
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int T, N, L;
int outlets[150][40];
int tmpOut[150][40];
int devices[150][40];
int changes, cntN, diff, possible;
void copyTmp(){
	for(int j=0; j<N; j++){
		for(int k=0; k<L; k++)
			tmpOut[j][k] = outlets[j][k]; 
	}
}
int compareTwo(int d[40], int o[40]){
	for(int i=0; i<L; i++){
		if(d[i] == o[i])
			continue;
		else
			return 0;
	}
	return 1;
}
void changeBit(int b){
	for(int i=0; i<N; i++){
		if(tmpOut[i][b] == 0)
			tmpOut[i][b] = 1;
		else
			tmpOut[i][b] = 0;
	}
}
void transformDevice(int d[40], int o[40]){
	for(int i=0; i<L; i++){
		if(d[i] == o[i])
			continue;
		else{
			changeBit(i);
			diff++;
		}
	}
}


int main(){
	FILE* in = fopen("C:\\Users\\Jinhyuk\\Desktop\\CodeJam 2014\\R1\\A-large.in", "r");
	FILE* out = fopen("C:\\Users\\Jinhyuk\\Desktop\\CodeJam 2014\\R1\\testResult.txt", "w");
	
	fscanf(in, "%d", &T);
	for(int i=0; i<T; i++){
		fscanf(in, "%d %d", &N, &L);
		for(int j=0; j<N; j++){
			for(int k=0; k<L; k++)
				fscanf(in, "%1d", &outlets[j][k]); 
		}
		for(int j=0; j<N; j++){
			for(int k=0; k<L; k++)
				fscanf(in, "%1d", &devices[j][k]); 
		}
		changes = 1000000;
		possible = 0;
		for(int j=0; j<N; j++){
			cntN = 0;
			diff = 0;
			copyTmp();
			if(compareTwo(devices[0], tmpOut[j]) == 1){
				for(int k1=0; k1<N; k1++){
					for(int k2=0; k2<N; k2++){
						if(compareTwo(devices[k1], tmpOut[k2]) == 1){
							cntN++;
							break;
						}else
							continue;
					}
				}
			}else {
				transformDevice(devices[0], tmpOut[j]);
				for(int k1=0; k1<N; k1++){
					for(int k2=0; k2<N; k2++){
						if(compareTwo(devices[k1], tmpOut[k2]) == 1){
							cntN++;
							break;
						}else
							continue;
					}
				}
			}
			if(cntN == N){
				changes = changes < diff ? changes:diff;
				possible = 1;
			}
		}

		if(possible == 1)
			fprintf(out, "Case #%d: %d\n", i+1, changes);
		else
			fprintf(out, "Case #%d: NOT POSSIBLE\n", i+1);

	}
	fclose(in);
	fclose(out);
	return 0;
}

