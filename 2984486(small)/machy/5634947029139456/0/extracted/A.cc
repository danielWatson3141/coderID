#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main(){
    int T;
    int N, L;

    cin >> T;
    for(size_t t = 1; t <= T; t++){
        cin >> N >> L;
        vector<string> mat(N);
        vector<string> mat2(N);
        vector<string> target(N);
        for(int i = 0; i < N; i++){
            cin >> mat[i];
        }
        for(int i = 0; i < N; i++){
            cin >> target[i];
        }
        sort(target.begin(), target.end());
        int edit = -1;
        for(int i = 0; i < (1<<L); i++){
            for(int j = 0; j < mat.size(); j++){
                string line = mat[j];
                for(int k = 0; k < L; k++){
                    if((i & (1<<k)) == 0) continue;
                    line[k] = '0' + ('1' - line[k]);
                }
                mat2[j] = line;
            }
            sort(mat2.begin(), mat2.end());
            if(mat2 == target){
                edit = 0;
                for(int k = 0; k < L; k++){
                    if(i & (1<<k)) edit++;
                }
                break;
            }
        }
        cout << "Case #" << t << ": ";
        if(edit == -1){
            cout << "NOT POSSIBLE" << endl;
        }else{
            cout << edit << endl;
        }
    }
    return 0;
}

