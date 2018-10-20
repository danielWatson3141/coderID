#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <cstring>
#include <sstream>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <time.h>

using namespace std;

int arr[1001];

int main(){
freopen ("input.txt","r",stdin);
freopen ("output.txt","w",stdout);
int t;
cin>>t;
srand (time(NULL));
for (int i=1;i<=t;++i){

printf("Case #%d: ",i);
int n;
cin>>n;

for (int j=0;j<n;++j){
cin>>arr[j];

}


int real=rand()%2+1;

if (real==1)
printf("BAD\n");
else
printf("GOOD\n");

}

return 0;
}
