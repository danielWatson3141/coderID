#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath> 

using namespace std;


void check(int L, int N, int cur_answer, int cur_i, vector<string> outlet, vector<string> device, int &result)
{
   if(cur_i == L){
      sort(outlet.begin(), outlet.end());
      sort(device.begin(), device.end());
      for(int i = 0; i < N ; i++) {
         if(outlet[i].compare(device[i]) != 0) {
            return;
         } 
      }
     
      if (result == -1){
         result = cur_answer;
      }
      if(cur_answer < result){
         result = cur_answer;
      }
      return; 
   }
  /*if(result != -1){
      return;
   }*/
   
   check(L, N, cur_answer, cur_i+1, outlet, device, result);

   for(int i = 0; i < N ; i++) {
      if (outlet[i][cur_i] == '1')
         outlet[i][cur_i] = '0';
      else 
         outlet[i][cur_i] = '1';
   
   }
   check(L, N, cur_answer+1, cur_i+1, outlet, device, result);

}

   
   
   
int main() {

   //num of test cases
   int test_cnt;
   vector<string> outlet;
   vector<string> device;
   
   cin >> test_cnt;


   for(int idx = 1; idx <= test_cnt; idx++) {
      int N,L;
      cin >> N;
      cin >> L;
      int result = 0;

      for(int i = 0 ; i < N; i++) {
         string tmp;
         cin >> tmp;
         outlet.push_back(tmp);
      }
      for(int i = 0 ; i < N; i++) {
         string tmp;
         cin >> tmp;
         device.push_back(tmp);
      }

      //sort(outlet); sort(device);
   

      // check imposible result;
      for(int i = 0 ; i < L; i++) {
         int outlet_cnt = 0;
         int device_cnt = 0;
         for(int j = 0; j < N; j++) {
            if(outlet[j][i] == '1'){
               outlet_cnt++;     
            }
            if(device[j][i] == '1'){
               device_cnt++; 
            }
         } 

         if (outlet_cnt == device_cnt){
            // good;
         }
         else if( (N - outlet_cnt) == device_cnt){
            // good;
         }
         else{
            result = -1;
            break;
         }
      }
      
      if(result != -1){
         result = -1;
         check(L, N, 0, 0, outlet,device,result);
      }

      if(result == -1) {
         cout << "Case #"<<idx<<": NOT POSSIBLE"<<endl;   
      } 
      else {
         cout << "Case #"<<idx<<": "<<result<<endl;   
      }

      outlet.clear();
      device.clear();
   }

   return 0;
}
