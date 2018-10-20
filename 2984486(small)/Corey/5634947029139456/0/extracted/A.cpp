#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>

#define ASCII_SPACE 32
#define ASCII_NEWLINE 10


using namespace std;




#define PRINT_TOKEN(token)\
	do{\
		cout<<#token<<" is "<<token<<endl; \
	}while(0)


#define READ(arg)\
	do{\
		long long arg;\
		cin>>arg;\
	}while(0)

//#define PRINT_ARR()
typedef long long ll;

int N;
int L;

char src[256][256]; 
char target[256][256];
int sw[256];

void printInput()
{
	cout<< N <<" " << L<<endl;


	for(int a = 0; a<N ;a++){
		cout <<src[a] << " ";
	}
	cout << endl;

	for(int b= 0 ; b< N;b++){
		cout<< target[b] <<" ";
	}
	cout<< endl;
}
void printsw()
{
	for(int i =0;i< L;i++){
		cout<< sw[i] << " ";
	}
	cout<< endl;
}
int solve()
{

	for(int i=0; i<=L;i++){
		memset(sw,0,sizeof(sw));
		for(int a=0; a< i ;a++){
			sw[L-a-1] = 1;
		}
		do{
			char temp[256][256];
			memcpy(temp, src, 256*256);

			for(int b=0; b<L ;b++){
				if(sw[b] == 1){
					for(int n=0; n< N; n++){
						//temp[n][b] = !temp[n][b];
						temp[n][b] = temp[n][b] == '1' ? '0':'1';
					}
				}
			}
			
//	for(int d = 0; d<N ;d++){
//		cout <<temp[d] << " ";
//	}
//	cout<<endl;
//
//	for(int d = 0; d<N ;d++){
//		cout <<src[d] << " ";
//	}
//	cout<<endl;

			bool g_isFound  = true;
			for(int c=0; c<N ;c++){
				bool isFound = false;
				for(int d=0; d<N; d++){
					if( strcmp( temp[c], target[d]) == 0 ){
						isFound = true;
						break;
					}
				}
				if(isFound == false){
					g_isFound = false;
					break;
				}
			}
			if(g_isFound ==  true) return i;
			//printsw();
		}while(next_permutation(sw,sw+L));
	}
	return -1;
}

int main()
{
	long long T;

	cin>>T;

	for(long long i=0;i<T;i++){

		long long result=0 ;
		cin>> N >> L;
		for(int a=0; a< N ;a++){
			cin>>src[a];
		}
		for(int b=0; b< N ;b++){
			cin>>target[b];
		}
		result = solve();
		//printInput();
		if(result >=0){
			cout<<"Case "<<"#"<<i+1<<": "<<result;
		} else{
			cout<<"Case "<<"#"<<i+1<<": NOT POSSIBLE";
		}
		cout<<endl;

	}
	return 0;
}


