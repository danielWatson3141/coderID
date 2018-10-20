#include<iostream>
using namespace std;

bool wypisal=false, rozne=false;
int T, N, L, pacnij=0, wynik;
string IN[11];
string OUT[11];
int pac[11];

void perm(int k)
{
    if(k==1)
    {
        //cout << OUT[1] << endl;
        for(int i=0; i<=L; ++i) pac[i]=0;
        for(int i=1; i<=N; ++i)
            for(int j=0; j<L; ++j)
                if(IN[i][j]!=OUT[i][j]) pac[j]++;
        rozne=false; pacnij=0;
        for(int i=0; i<L; ++i)
        {
            if(pac[i]!=0 && pac[i]!=N)
            {
                rozne=true;
                break;
            }
            if(pac[i]==N) pacnij++;
        }
        if(!rozne) wynik=min(wynik, pacnij);
    }
    else
    {
        for(int i=1; i<=k; ++i)
        {
            swap(OUT[i], OUT[k]);
            perm(k-1);
            swap(OUT[i], OUT[k]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> T;
    for(int lzd=1; lzd<=T; ++lzd)
    {
        cin >> N >> L;
        for(int i=1; i<=N; ++i) cin >> IN[i];
        for(int i=1; i<=N; ++i) cin >> OUT[i];
        wynik=123;
        perm(N);
        cout << "Case #" << lzd << ": ";
        if(wynik!=123) cout << wynik << endl;
        else cout << "NOT POSSIBLE" << endl;
    }
}
