#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct opis
{
	int L;
	bool tab[41];
};

vector <opis> X, Y;

bool operator == (opis A, opis B)
{
	for(int i = 1; i <= A.L; i++)
	{
		if(A.tab[i] != B.tab[i])
			return false;
	}
	return true;
}

int main()
{
	int T;
	cin >> T;
	
	for(int iw = 1; iw <= T; iw++)
	{
		X.clear();
		Y.clear();
		
		int N, L;
		cin >> N >> L;
		
		for(int i = 1; i <= N; i++)
		{
			opis w;
			w.L = L;
			
			string XX;
			cin >> XX;
			
			for(int m = 0; m < L; m++)
			{
				w.tab[m + 1] = XX[m] - 48;
			}
			
			X.push_back(w);
		}
		
		for(int i = 1; i <= N; i++)
		{
			opis w;
			w.L = L;
			
			string XX;
			cin >> XX;
			
			for(int m = 0; m < L; m++)
			{
				w.tab[m + 1] = XX[m] - 48;
			}
			
			Y.push_back(w);
		}
		
		bool prawda = false;
		
		int ile = 0;
		int ILE = 10e9;
		
		vector <int > LM;
		
		for(int i = 1; i <= L; i++)
		{
			LM.push_back(i);
		}
			
		for(unsigned iz=0,n=1<<LM.size();iz<n;++iz) 
		{
			ile = 0;
			vector <opis> roboczy_x = X;
			
			for(unsigned p=0;p<LM.size();++p) 
				if(iz&(1<<p)) 
					{
						ile++;
						for(int ii = 1; ii <= N; ii++)
							{
								roboczy_x[ii - 1].tab[LM[p]] = 1 - roboczy_x[ii - 1].tab[LM[p]];
							}	
					}
			
			bool znaleziono_all = true; 
			
			for(int i = 1; i <= N; i++)
			{
				opis szukany = roboczy_x[i - 1];
				
				bool mamy_szukany = false;
				
				for(int ii = 1; ii <= N; ii++)
				{
					if(Y[ii - 1] == szukany)
					{
						mamy_szukany = true;
					}
				}
				
				if(mamy_szukany == false)
				{
					znaleziono_all = false;
					break;
				}
			}
			
			if(znaleziono_all == true)
			{
				prawda = true;
				ILE = min(ILE, ile);
			}
		}
			
		if(prawda == false)
		{
			cout << "Case #" << iw << ": NOT POSSIBLE" << endl;
		}	
		else
		{
			cout << "Case #" << iw << ": " << ILE << endl;
		}
		
	}

	return 0;
}

