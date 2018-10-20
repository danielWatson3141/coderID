#include<stdio.h>

int main(void) {
	int t, n, nums[1000], a, b, o[1000], truth;
	FILE *i=fopen("C-small.in","r");
	FILE *ou=fopen("output.txt","w");
	float temp;
	fscanf(i,"%d", &t);
	for(a=0; a<t; a++){
		fscanf(i,"%d", &n);
		for(b=0; b<n; b++){
			fscanf(i,"%d", &nums[b]);
			o[b]=b;
		}
		truth=0;
		for(b=0; b<n; b++){
			if(nums[b]==o[b]){
				truth++;
			}
			if((b-1)>0){
				if(nums[b]==o[b-1]){
					truth++;
				}
			}
			if((b+1)<n){
				if(nums[b]==o[b+1]){
					truth++;
				}
			}
		}
		temp=n;
		temp=temp/2;
		if(truth>temp){
			fprintf(ou,"%s%d%s","Case #",(a+1),": BAD\n", (a+1));
		}
		else{
			fprintf(ou,"%s%d%s","Case #",(a+1),": GOOD\n");
		}
	}

	return 0;
}
