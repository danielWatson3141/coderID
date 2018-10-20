#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <bitset>

using namespace std;


double prob[1000][1000];
int counter = 0;
void solve() {
   int N;
   cin >> N;
   vector<int> v(N);
   for(int i = 0; i < N; i++)
      cin>> v[i];

   double p = 1.0;
   for(int i = 0; i < 1000; i++)
      p*=prob[i][v[i]];

   //cout << p;
   if(p>0.02){
      cout<<"GOOD";
      counter++;
      }
   else
      cout<<"BAD";


}



void genFreqDist(int num) {
   //srand(time(NULL));
   int dist[1000][1000];
   for(int i = 0;i <1000;i++)
      for(int j= 0;j<1000;j++)
         dist[i][j]=0;

   for(int i = 0; i < num; i++){
      int arr[1000];
      for(int j= 0; j < 1000; j++)
         arr[j] = j;
      for(int j = 0; j <1000; j++){
         int r = rand()%1000;
         swap(arr[j],arr[r]);
      } 
      for(int j= 0;j<1000;j++)
         dist[j][arr[j]]++;
   }

   
   for(int i = 0;i <1000;i++)
      for(int j= 0;j<1000;j++)
         prob[i][j] = double(dist[i][j])/double(num)*1000;
}

int main() {
genFreqDist(100000);
int t;
cin >> t;
for (int i = 0; i < t; i++) {
   cout << "Case #" << i+1 << ": "; 
   solve();
   cout << endl;
}

//cout<<"count: " <<counter<<endl;
return 0;
}
