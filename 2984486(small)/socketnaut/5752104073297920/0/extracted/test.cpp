#include<fstream>
#include<set>
#include<cmath>
using namespace std;

ifstream fin("proper.in");
ofstream fout("proper.out");


int main(){
    
    int T;
    fin >> T;
    for(int t=0; t<T; t++){
        int N, V;
        fin >> N;
        
        double sum = 0;
        double add = 0;
        
        for(int i = 0; i<N; i++){
            fin >> V;
            V--;
            
            add = i+N - V;
            if(add >= N) add -= N;
            sum += add;
        }
        
        fout << "Case #" << t+1 << ": ";
        if(sum / N > sqrt(N)/N) fout << "GOOD";
        else fout << "BAD";
        fout << endl;
    }
}
