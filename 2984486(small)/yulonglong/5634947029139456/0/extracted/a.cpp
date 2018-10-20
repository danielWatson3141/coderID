//steven Kester Y
//yulonglong2005@gmail.com
#include <bits/stdc++.h>
#define INF 2100000000
using namespace std;

int plug[11];
int gadget[11];

int bin2dec(char* str) {
 int n = 0;
 int size = strlen(str) - 1;
        int count = 0;
 while ( *str != '\0' ) {
  if ( *str == '1' ) 
      n = n + pow(2, size - count );
  count++; 
  str++;
 }
 return n;
}


int getCount(int bits){
	if(bits==0){
		return 0;
	}
	int counter=0;
	while(bits>0){
		if((bits&1)==1){
			counter++;
		}
		bits = bits >> 1;
	}
	if(counter==0){
		return INF;
	}
	return counter;
}

int main(){
	//freopen("in.txt","r",stdin);
	int tc;
	cin >> tc;
	for(int d=1;d<=tc;d++){
		int numbits,numdevice;
		cin >> numdevice >> numbits;
		for(int i=0;i<numdevice;i++){
			char str[15];
			scanf("%s",str);
			plug[i] = bin2dec(str);
		}
		for(int i=0;i<numdevice;i++){
			char str[15];
			scanf("%s",str);
			gadget[i] = bin2dec(str);
		}
		
		int count=INF;
		for(int i=0;i<=((1<<numbits)-1);i++){
			bool valid=true;
			for(int j=0;j<numdevice;j++){
				bool valid2=false;
				for(int k=0;k<numdevice;k++){
					if((plug[k]^i)==gadget[j]){
						valid2=true;
						break;
					}
				}
				if(!valid2){
					valid=false;
				}
			}
			
			if(valid){
				int tempCount = getCount(i);
				if(count>tempCount){
					count = tempCount;
				}
			}
		}
		
		if(count==INF){
			printf("Case #%d: NOT POSSIBLE\n",d);
		}
		else{
			printf("Case #%d: %d\n",d,count);
		}
		
		
	}
	return 0;
}
