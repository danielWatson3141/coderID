#include <iostream>


using namespace std;

double good =896639848453576495208595456.00000;
double bad = 267167335599928165019942912.00000;


double abs(double x){
  if ( x < 0 )
    return -x;
  
  return x;
}
void solve(int tests){
  long double add = 1;
  
  for(int i = 0; i < 1000; ++i){
    int x;
    cin >> x;
    if(i < 10){
    add *= x;
    }
  }
  
  cout << "Case #" << tests << ": ";
  if(abs(good/add) - abs(add/good) < abs(bad/add) - abs(bad/good)){
    cout << "GOOD\n";
    return;
  }
  
  cout << "BAD\n";
}

int main(){
  int tests;
  
  cin >> tests;
  
  for(int i = 0; i < tests; ++i){
    solve(i + 1);
  }
} 