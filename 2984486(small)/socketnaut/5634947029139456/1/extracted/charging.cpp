#include<fstream>
#include<set>
using namespace std;

ifstream fin("charginglarge.in");
ofstream fout("charginglarge.out");

int N, L;
string out[256];
string dev[256];
bool flip[256];

int main(){
    int T;
    fin >> T;
    for(int t=0; t<T; t++){
        fin >> N >> L;
        for(int i=0; i<N; i++)
            fin >> out[i];
        for(int i=0; i<N; i++)
            fin >> dev[i];

        int low = 500;
        for(int i=0; i<N; i++){
            set<string> avail;
            int flp = 0;
            for(int j=0; j<L; j++){
                flip[j] = out[i][j]!=dev[0][j];
                flp += flip[j];
            }
            for(int k=0; k<N; k++){
                string str = "";
                for(int j=0; j<L; j++)
                    if(flip[j]) str += '0'+'1' - out[k][j];
                    else str += out[k][j];
                avail.insert(str);
            }
            bool good = true;
            for(int j=0; j<N; j++)
                if(avail.find(dev[j]) == avail.end())
                    good = false;
            if(good) low = min(low, flp);
        }
        
        fout << "Case #" << t+1 << ": ";
        if(low == 500) fout << "NOT POSSIBLE" << endl;
        else fout << low << endl;
    }
}
