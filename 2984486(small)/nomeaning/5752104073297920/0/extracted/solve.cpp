#include <iostream>
#include <random>
#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1000;
//#define DATA_GENERATE

mt19937 engine;
uniform_int_distribution<int> distribution(0, N-1);
void wrong_shuffle(int* x) {
  for(int i = 0; i < N; i++){
    x[i] = i;
  }
  for(int i = 0; i < N; i++) {
    int p = distribution(engine);
    swap(x[p], x[i]);
  }
}
const int CASE = 10000000;
long long MAP[N][N] = {};
void gen() {
  int x[N];
  for(int i = 0; i < CASE; i++) {
    wrong_shuffle(x);
    for(int i = 0; i < N; i++) {
      MAP[i][x[i]]++;
    }
    if(i % 1000 == 0)cerr << i << endl;
  }
}
int main() {
  FILE* file = fopen("data","r");
  fread(MAP, sizeof(long long), N * N, file);
  fclose(file);
  long long c = 0;
  for(int i = 0; i < N; i++)c+=MAP[0][i];
#ifdef DATA_GENERATE
  gen();
  file = fopen("data","w");
  fwrite(MAP, sizeof(long long), N * N, file);
  fclose(file);
#else
  int T;
  cin>>T;
  for(int tc = 1; tc <= T;tc++){
    cout << "Case #" << tc << ": ";
    int tmp;
    cin>>tmp;
    int a[N];
    for(int i= 0 ; i< N;i++)cin>>a[i];
    long long s = 0;
    for(int i =0 ;i  <N; i++){
      s += MAP[i][a[i]];
    }
    if(s > c + c / 100){
      cout << "BAD" << endl;
      cerr << "BAD" << endl;
    }else{
      cout << "GOOD" << endl;
      cerr << "GOOD" << endl;
    }
  }
#endif
}
