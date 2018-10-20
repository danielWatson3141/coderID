#include <fstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;
int N;
int main()
{
  ifstream f("input.txt");
  ofstream w("output.txt");
  int T;
  f>>T;
 
  for (int ti=1;ti<=T;ti++)
  {
    
    f>>N;
    long int ont=0;
    int tmp;
    for (int i=0;i<N;i++)
    {
      f>>tmp;
      ont+=abs(i-tmp);
      //if (abs(i-tmp)>N/3-1) ont++;
    }
    if (ont/N<N/3) w<<"Case #"<<ti<<": "<<"BAD"<<endl;else w<<"Case #"<<ti<<": "<<"GOOD"<<endl;
    
  }
  return 0;
}