#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<algorithm>
using namespace std;
const int MAX = 1000 + 10;
const int TIME = 100;
const int CASE = 300;
int arr[MAX];
int t1[MAX];
int t2[MAX];
int mark[MAX];
struct ans{
	int id, v1, a;
}rec[200];
bool cmp1(ans a1, ans a2){
	return a1.v1 > a2.v1;
}
bool cmp2(ans a1, ans a2){
	return a1.id < a2.id;
}
void reset(int *T, int n){
	for(int i = 0 ; i < n ; i++) T[i] = i;
}
int dis(int *T1, int *T2, int n){
	for(int i = 0 ; i < n ; i++)
		mark[T1[i]] = i;
	int sum = 0;
	for(int i = 0 ; i < n ; i++)
		sum += abs(mark[T2[i]]-i);
	return sum;
}
int main(){
	srand(time(0));
	int TN;
	scanf("%d", &TN);
	int a1 = 0, a2 = 0;
	for(int casen = 1 ; casen <= TN ; casen++){
		int n;
		scanf("%d", &n);
		for(int i = 0 ; i < n ; i++){
			scanf("%d", &arr[i]);
		}
		int d1 = 0, d2 = 0;
		int TT = CASE;
		while(TT--){
			int s1 = 0, s2 = 0;
			int t = TIME;
			while(t--){
				reset(t1, n);
				for(int i = 0 ; i < n ; i++){
					int tmp = rand()%(n-i) + i;
					swap(t1[i], t1[tmp]);
				}
				s1 += dis(t1, arr, n);
			}
			t = TIME;
			while(t--){
				reset(t2, n);
				for(int i = 0 ; i < n ; i++){
					int tmp = rand()%n;
					swap(t2[i], t2[tmp]);
				}
				s2 += dis(t2, arr, n);
			}
			if(s1 < s2) d1++;
			else d2++;
			if(abs(d1-d2)>=50) break;
		}
		rec[casen-1].id = casen;
		rec[casen-1].v1 = d1;
	}
	sort(rec, rec+TN, cmp1);
	for(int i = 0 ; i < TN/2 ; i++)
		rec[i].a = 1;
	for(int i = TN/2 ; i < TN ; i++)
		rec[i].a = 0;
	sort(rec, rec+TN, cmp2);
	for(int i = 0 ; i < TN ; i++){
		printf("Case #%d: ", rec[i].id);
		if(rec[i].a) puts("GOOD");
		else puts("BAD");
	}
	return 0;
}
