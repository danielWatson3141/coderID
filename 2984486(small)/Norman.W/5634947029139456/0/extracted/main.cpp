#include <cstdlib>
#include <iostream>
#include "set"

using namespace std;

int main(int argc, char *argv[])
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int T;
    cin >> T;

    int L, N;
    char _Div[150][40];
    char _Out[150][40];
    char _Flip[41];
    char _XXX[150];
    string Temp;
    
	int y;
	int Div_1, Div_0;
	int Out_1, Out_0;
    for (int T_i=0; T_i<T;T_i++){

        cin >> N>> L;
        for (int I= 0; I < N; I++){
            cin >> Temp;
            for (int J=0; J<L;J++){
                _Div[I][J] = Temp[J];
            }
        }
        for (int I= 0; I < N; I++){
            cin >> Temp;
            for (int J=0; J<L;J++){
                _Out[I][J] = Temp[J];
            }
        }


            for (int J=0; J<=L;J++){
                _Flip[J] = '0';  // 0 : not fix, 1: flip,  2: fix no flip, 3: fix flip
            }
        
        bool Nomatch, _No;
        int CountFlip;
        int MinFlip = 50;
        char AfterFlip;
        int JJ=0;

        while (_Flip[L]=='0') {
            for (int I= 0; I < N; I++){
                Nomatch = true;
                for (int II = 0; II < N; II++){
                    _No = false;
                    for (int J=0; J<L;J++){
                        AfterFlip = _Out[I][J];
                        if (_Flip[J]=='1') {
                           if (AfterFlip=='0') AfterFlip = '1'; else AfterFlip = '0';
                                           }
                        if (AfterFlip != _Div[II][J]) {
                                        _No = true; 
                                        J = L;
                                        }
                    }
                    if (!_No) {Nomatch = false; II=N;  }
                }
                if (Nomatch) I=N;
            }
            if (!Nomatch) {
               CountFlip = 0;
               for (int J = 0; J <L; J++) {
                   if (_Flip[J]=='1') CountFlip++;
               }
               if (MinFlip > CountFlip) MinFlip = CountFlip;
            }
        
            JJ=0;
            while (_Flip[JJ]=='1') {
                  _Flip[JJ]='0';
                  JJ++;
            }
            _Flip[JJ] ='1';
        }
        
        if (MinFlip <50) 
        cout << "Case #" << T_i+1 << ": " << MinFlip << endl;
        else
        cout << "Case #" << T_i+1 << ": NOT POSSIBLE"  << endl;
        
    }
    return EXIT_SUCCESS;
}
