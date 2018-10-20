#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>

#define MAX 100
#define test(a) cout << "TEST " << a << endl;
#define go(a,b) for(int a=0; a<b; a++)
#define case(a) fout << "Case #"<< a << ": " <<
using namespace std;



int main()
{
    ofstream fout ("output.txt");
    ifstream fin ("input.txt");
    int n;
    fin >> n;
    char z;
    int b,c;
    bool x;
    int m=-1;
    vector < vector<bool> > w;
    vector < vector<bool> > v;
    vector < vector<bool> > u;
    go(a,n){
        m=-1;
        v.resize(0);
        u.resize(0);
        w.resize(0);
        fin >> b >> c;
        v.resize(b);
        u.resize(b);

        go(d,b){
            go(e,c){
                fin >> z;
                x=(z=='1');
                v[d].push_back(x);

            }
        }
        go(d,b){
            go(e,c){
                fin >> z;
                x=(z=='1');
               u[d].push_back(x);
            }
        }
        sort(v.begin(), v.end());
        sort(u.begin(), u.end());
        go(d,b){
            w=v;
            vector<bool> n = v[d];
            go(e,c){
                if(u[0][e]==1){
                    n[e]=!n[e];
                }
            }
            go(e,b){
                go(f,c){
                    if(n[f]==1){
                        w[e][f]=!w[e][f];
                    }
                }
            }
            sort(w.begin(), w.end());
            if(w==u){
                int y=0;
                go(e,c){
                    if(n[e]){
                        y++;
                    }
                }
                if(m<0||m>y){
                    m=y;
                }
            }
        }
        if(m>=0){
            case(a+1) m << endl;
        }
        else{
            case(a+1) "NOT POSSIBLE" << endl;
        }
    }


}




