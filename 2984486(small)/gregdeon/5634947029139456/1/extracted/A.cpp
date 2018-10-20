#include <iostream> 
#include <fstream> 
#include <algorithm>
#include <vector>

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(a) ((a)>(0)?(a):(-a))

using namespace std;
    
int XOR(int *a, int *b, int *c, int L){
    int ret = 0;
    for(int i = 0; i < L; i++){
        if(a[i] == b[i]){
            c[i] = 0;
        } else{
            c[i] = 1;
            ret++;
        }
    }
    return ret;
}

int equal(int *a, int *b, int L){
    for(int i = 0; i < L; i++){
        if(a[i] != b[i]) return 0;
    }
    return 1;
}

int main(void){
    ifstream fin("A.in");
    ofstream fout("A.out");
    fout << fixed;
    fout.precision(2); //prints doubles as 3.14
    
    int T;
    fin >> T;
    for(int c = 0; c < T; c++){
        
        int N, L;
        fin >> N >> L;
        int **outlet = new int*[N];
        for(int i = 0; i < N; i++){
            outlet[i] = new int[L];
            string temp;
            fin >> temp; fin.ignore();
            for(int j = 0; j < L; j++){
                if(temp[j] == '0') outlet[i][j] = 0;
                else outlet[i][j] = 1;
            }
        }
        int **device = new int*[N];
        for(int i = 0; i < N; i++){
            device[i] = new int[L];
            string temp;
            fin >> temp; fin.ignore();
            for(int j = 0; j < L; j++){
                if(temp[j] == '0') device[i][j] = 0;
                else device[i][j] = 1;
            }
        }
        int ret = L+1;
        
        //try each device on outlet 0
        for(int i = 0; i < N; i++){
            int *sw = new int[L];
            int newret = XOR(outlet[0], device[i], sw, L);
            if(newret > ret) continue;
            int matchall = 1;
            //check each switched outlet
            for(int j = 1; j < N; j++){
                int* newout = new int[L];
                XOR(sw, outlet[j], newout, L);
                int match = 0;
                for(int k = 0; k < N; k++){
                    if(k == i) continue;
                    if(equal(newout, device[k], L)){
                        match = 1;
                        break;
                    }
                }
                if(match == 0){
                    matchall = 0;
                    break;
                }
            }
            if(matchall == 1) ret = newret;                
        }
        fout << "Case #" << c+1 << ": ";
        if(ret > L) fout << "NOT POSSIBLE" << endl;
        else fout << ret << endl;
    }
    return 0;
}


