#include<iostream>
#include<fstream>
#include<string>
#include<bitset>
#include<algorithm>
using namespace std;

template< unsigned n >
bool bitsetLess( std::bitset<n> const& left, std::bitset<n> const& right )
{
return left.to_string() < right.to_string();
}

int main(){
    ifstream in("A.in"); ofstream out("A.out");
    int T;
    in>>T;
    int N,L;
    bitset<40> inp[150];
    bitset<40> outp[150];
    bitset<40> moves[150];
    bitset<40> tmp[150];
    string s;
    for (int t=0;t<T;t++){
        out<<"Case #"<<t+1<<": ";

        in>>N>>L;
        for (int i=0;i<N;i++){
            in>>s;
            inp[i] = bitset<40>(s);
        }
        for (int i=0;i<N;i++){
            in>>s;
            outp[i] = bitset<40>(s);
        }
        sort(outp,outp+N,bitsetLess<40>);


        for (int i=0;i<N;i++){
            moves[i] = inp[0]^outp[i];
        }
        //for (int i=0;i<N;i++) cout<<moves[i].to_string()<<"\n";


        int best_ans = L+1;
        for (int i=0;i<N;i++){
            for (int j=0;j<N;j++){
                tmp[j] = moves[i]^inp[j];
            }
            sort(tmp,tmp+N,bitsetLess<40>);
            bool works = true;
            for (int j=0;j<N;j++){
                if (tmp[j]!=outp[j]){
                    works = false;
                    break;
                }
            }
            if (works){
                best_ans = min(best_ans,int(moves[i].count()));
            }
        }

        if (best_ans == L+1) out<<"NOT POSSIBLE";
        else out<<best_ans;

        out<<"\n";
    }
}
