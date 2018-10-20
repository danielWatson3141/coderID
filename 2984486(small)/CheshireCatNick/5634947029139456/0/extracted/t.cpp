#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char myflow[160][160];
using namespace std;
int compare(const void *ptr1, const void *ptr2){
	return (strcmp((char*) ptr1, (char*) ptr2));
}
void modify(int* digit, int n, int toswitch){
	for (int i = 0; i < n; i++)
		for (int j = 0; j < toswitch; j++)
			if (myflow[i][digit[j]] == '0')
				myflow[i][digit[j]] = '1';
			else
				myflow[i][digit[j]] = '0';
	return;
}
void set(int* digit, int k, int& toswitch){
	int i = 0;
	toswitch = 0;
	while (k != 0){
		if (k % 2 == 1){
			digit[toswitch] = i;
			toswitch++;
		}
		k /= 2;
		i++;
	}
	return;
}
bool check(char charge[][160], int n){
	qsort(myflow, n, 160 * sizeof(char), compare);
	for (int i = 0; i < n; i++)
		if (strcmp(myflow[i], charge[i]) != 0)
			return 0;
	return 1;
}
void copy(char flow[][160], int n){
	for (int i = 0; i < n; i++)
		strcpy(myflow[i], flow[i]);
	return;
}
int pow(int l){
	int ans = 1;
	for (int i = 0; i < l; i++)
		ans *= 2;
	return ans;
}
int main(void){
	int t, find;
	int n, l;
	int target;
	int digit[160], toswitch;
	char charge[160][160], flow[160][160];
	scanf("%d", &t);
	for (int i = 0; i < t; i++){
		find = 0;
		scanf("%d%d", &n, &l);
		target = pow(l);
		for (int j = 0; j < n; j++)
			scanf("%s", flow[j]);
		for (int j = 0; j < n; j++)
			scanf("%s", charge[j]);
		qsort(charge, n, 160 * sizeof(char), compare);
//		for (int z = 0; z < n; z++)
//			printf("%s ", charge[z]);
//		printf("\n");
		for (int k = 0; k < target; k++){
			copy(flow, n);
			set(digit, k, toswitch);
	//		for (int z = 0; z < toswitch; z++)
	//			printf("%d ", digit[z]);
	//		printf("\n");
			modify(digit, n, toswitch);
			if (check(charge, n)){
				find = 1;
				printf("Case #%d: %d\n", i + 1, toswitch);
				break;
			}	
		}
		if (find == 0)
			printf("Case #%d: NOT POSSIBLE\n", i + 1);
		//	for (int z = 0; z < n; z++)
		//		printf("%s ", myflow[i]);
		//		printf("\n");
	}
	return 0;
}

