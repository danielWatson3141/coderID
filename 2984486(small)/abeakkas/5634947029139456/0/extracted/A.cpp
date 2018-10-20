/*
* abdurak - Abdurrahman Akkas
* Google CodeJam 2014 - Round 1A
* Problem A
* Hadi hayirlisi
*/
#include<iostream>
#include<iomanip>
#include<fstream>
#include<cmath>
#include<algorithm>
#define FORN(i,n) for(int (i)=0;(i)<(n);(i)++)
#define FORR(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define MAX(a,b) (((a)>(b))?(a):(b))
using namespace std;
typedef unsigned long long ull;
int num1s(ull x){
    int n=0;
    while(x!=0){
        n+=x%2;
        x/=2;
    }
    return n;
}
int main(){
    //fout<<setprecision(15);
    ifstream fin("A.in");
    ofstream fout("A.out");
    int T;
    fin>>T;
    ull nums[150*150];
    ull Ns[150*150];
    ull outlets[150];
    int numN=0;
    FORR(iT,1,T){
        int N, L;
        numN=0;
        FORN(i,N*N){
            Ns[i]=0;
        }
        fin>>N>>L;
        char ch;
        FORN(i,N){
            ull c=0;
            FORN(j,L){
                fin>>ch;
                c=c*2+(ch-'0');
            }
            outlets[i]=c;
        }
        FORN(i,N){
            ull c=0;
            FORN(j,L){
                fin>>ch;
                c=c*2+(ch-'0');
            }
            FORN(j,N){
                int flag=0;
                //cout<<(c^outlets[j])<<" ";
                FORN(k,numN){
                    if(nums[k]==(c^outlets[j])){
                        Ns[k]++;
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    nums[numN]=(c^outlets[j]);
                    Ns[numN]=1;
                    numN++;
                }
            }
        }/*
        cout<<endl;
        FORN(k,numN) cout<<nums[k]<<" ";
        cout<<endl;
        FORN(k,numN) cout<<Ns[k]<<" ";
        cout<<endl;*/
        int min=-1;
        FORN(i,N*N){
            if(Ns[i]==N){
                if(min==-1 || num1s(nums[i])<min){
                    min=num1s(nums[i]);
                }
            }
        }
        fout<<"Case #"<<iT<<": ";
        if(min>-1){
            fout<<min;
        }else{
            fout<<"NOT POSSIBLE";
        }
        fout<<endl;
    }
    system("pause");
}
