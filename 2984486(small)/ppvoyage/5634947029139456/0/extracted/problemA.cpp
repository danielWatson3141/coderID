#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int T,L,N;
    bool init[200][200] = {0};
    bool tmp[200][200] = {0};
    bool goal[200][200] = {0};
    
    int hash[1024];
    int list[200];
    
    string tmpStr;
    
    cin >> T;
    
    
    for (int t1 = 1 ; t1 <= T ; t1++){
        cin >> N >> L;

        for (int i = 0 ; i < 1024 ; i++){
            hash[i] = 0;
        }
        
        for (int i = 0 ; i < N ; i++){
            cin >> tmpStr;
            for (int j = 0 ; j < L ; j++)
                init[i][j] = (tmpStr[j] == '1') ? true : false;
        }
        
        for (int i = 0 ; i < N ; i++){
            cin >> tmpStr;
            for (int j = 0 ; j < L ; j++)
                goal[i][j] = (tmpStr[j] == '1') ? true : false;
        }
        
        
        for (int i = 0 ; i < N ; i++){
            int tmp = 0;
            for (int j = 0 ; j < L ; j++){
                tmp *= 2;
                tmp += goal[i][j];
            }
            list[i] = tmp;
            //cout << tmp << endl;
        }
        
        
        int min = 9999;
        for (int search = 0 ; search < (2 << L); search++){
            int count = 0;
            for (int i = 0 ; i < L; i++){
                int flip = (search >> i) & 1;
                if (flip == 1){
                    for (int j = 0 ; j < N ; j++)
                        tmp[j][i] = !init[j][i];
                    count++;
                }
                else{
                    for (int j = 0 ; j < N ; j++)
                        tmp[j][i] = init[j][i];
                }
            }
            
            // deal tmp
            for (int i = 0 ; i < 2 << L ; i++){
                hash[i] = 0;
            }
            for (int i = 0 ; i < N ; i++){
                int tmpValue = 0;
                for (int j = 0 ; j < L ; j++){
                    tmpValue *= 2;
                    tmpValue += tmp[i][j];
                }
                hash[tmpValue] = 1;
            }
            
            int loop;
            for (loop = 0 ; loop < N ; loop++){
                if (hash[list[loop]] == 0)
                    
                    break;
            }
            
            if (loop == N){
                if (count < min)
                    min = count;
            }
        }
        
        if (min == 9999)
            cout << "Case #" << t1 << ": NOT POSSIBLE" << endl;
        else
            cout << "Case #" << t1 << ": " << min << endl;
    }
    
    return 0;
}