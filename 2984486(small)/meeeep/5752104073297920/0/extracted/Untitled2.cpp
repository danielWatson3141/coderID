#include <iostream>
#include <fstream>
using namespace std;
ifstream inp;
ofstream oup;
int array[1000];
int main(){
    inp.open("input3.in");
    oup.open("output3.txt");
    int T;
    int N;
    inp>>T;
    inp>>N;
    for (int t=0; t<T; t++){
        int cnt=0;
        for (int i=0; i<1000; i++){
            inp>>array[i];
            if (array[i]==i){
                cnt++;
            }
        }
        if (cnt>=1){oup<<"Case #"<<t+1<<": BAD"<<endl;}
        else {oup<<"Case #"<<t+1<<": GOOD"<<endl;}
    }
    
    
}
