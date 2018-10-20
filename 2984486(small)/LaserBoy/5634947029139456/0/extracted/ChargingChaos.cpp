#include <iostream>
#include <cstdio>

using namespace std;

void recur(int *min,int *check,int **A,int **B,int N,int L,int i)
{
	if(i == L){
		//cout << "New Case " << check[0] << " : " << check[1] << endl;
		int A1[N][L];
		int mark[N],total = 0;
		for(int j = 0;j < L;j++){
			if(check[j] == 1){
				total++;
			}
			for(int k = 0;k < N;k++){
				mark[k] = 0;
				if(check[j] == 1){
					A1[k][j] = (A[k][j] == 0) ? 1 : 0;
				}
				else {
					A1[k][j] = A[k][j];
				}
			}
		}
		//cout << "A1 : " << endl;
		//for(int j = 0;j < N;j++){
		//	for(int k = 0;k < L;k++){
		//		cout << A1[j][k] << " ";
		//	}
		//	cout << endl;
		//}
		for (int j = 0; j < N; ++j)
		{
			for(int k = 0;k < N;k++){
				if(mark[k] == 0){
					int count = 0;
					for(int l = 0;l < L;l++){
						if(A1[k][l] == B[j][l]){
							count++;
						}
					}
					if(count == L){
						mark[k] = 1;
						//cout << "Matched " << k << endl;
					}
				}
			}
		}
		bool flag = true;
		for(int j = 0;j < N;j++){
			if(mark[j] == 0){
				flag = false;
				break;
			}
		}
		if(flag == true){
			if(total < *min){
				*min = total;
			}
		}
		return;
	}
	check[i] = 0;
	recur(min,check,A,B,N,L,i + 1);
	check[i] = 1;
	recur(min,check,A,B,N,L,i + 1);
}

int main()
{
	//freopen("in_jam.txt","r",stdin);
	//freopen("out_jam1.txt","w",stdout);
	int T,N,L,**A,**B;
	char temp[1000];
	scanf("%d",&T);
	for (int i = 0; i < T; ++i)
	{
		scanf("%d",&N);
		scanf("%d",&L);
		A = new int*[N];
		B = new int*[N];
		int distance[100];
		for(int j = 0;j < 100;j++){
			distance[j] = 0;
		}
		for(int j = 0;j < N;j++){
			scanf("%s",&temp);
			A[j] = new int[L];
			for(int k = 0;k < L;k++){
				A[j][k] = temp[k] - 48;
			}
		}
		for(int j = 0;j < N;j++){
			scanf("%s",&temp);
			B[j] = new int[L];
			for(int k = 0;k < L;k++){
				B[j][k] = temp[k] - 48;
			}
		}
		// for(int j = 0;j < N;j++){
		// 	int mark[100];
		// 	for(int s = 0;s < 100;s++){
		// 		mark[s] = 0;
		// 	}
		// 	for(int k = 0;k < N;k++){
		// 		int count = 0;
		// 		for(int l = 0;l < L;l++){
		// 			if(B[j][l] != A[k][l]){
		// 				count++;
		// 			}
		// 		}
		// 		if(mark[count] == 0){
		// 			distance[count]++;
		// 			mark[count] = 1;
		// 		}
		// 	}
		// }
		int check[L],min = 10000;
		recur(&min,check,A,B,N,L,0);
		if(min == 10000){
			printf("Case #%d: NOT POSSIBLE \n",i + 1);
		}
		else {
			printf("Case #%d: %d \n",i + 1,min);
		}
		// bool flag = true;
		// for(int j = 0;j < 100;j++){
		// 	if(distance[j] == N){
		// 		printf("Case #%d: %d \n",i + 1,j);
		// 		flag = false;
		// 		break;
		// 	}
		// }
		// if(flag == true){
		// 	printf("Case #%d: NOT POSSIBLE \n",i + 1);
		// }
	}
}
