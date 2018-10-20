#include<iostream>
#include<cstdio>
#include<fstream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<sstream>
#include<string>
#include<iterator>
#include<functional>
#include<time.h>
#include<iomanip>
using namespace std;
typedef unsigned long long int ll;
typedef long double ld;
#define INF 100000000000000000LL

ll diff(ll a,ll b)
{
    return a>b ? a-b : b-a;
}

/*#define COMB_NUM 10001L
ll comb[COMB_NUM][COMB_NUM];
//need init_comb();
void init_comb()
{
    comb[0][0]=1;
    ll i,j;
    for(i=1;i<COMB_NUM;i++)
    {
        comb[i][0]=comb[i][i]=1;
        for(j=1;j<i;j++)
            comb[i][j]=comb[i-1][j]+comb[i-1][j-1];
    }
}
*/

#define print(a)      for(int i=0;i<a.size();i++) cout<<a[i]<<" "; cout<<endl;
#define print2n(a,n)      for(int i=0;i<=n;i++) cout<<a[i]<<" "; cout<<endl;

void llFromString(const string &s,ll &a,ll &b)
{
    string replacedString = s;
    replace_if(replacedString.begin(),
               replacedString.end(),
               bind2nd(equal_to<char>(),'.'),
               ' ');
               
    istringstream buffer(replacedString);
    buffer>>a;
    if(buffer.good())
    {
        buffer>>b;
    }
    else
    {
        b=0;
    }
}


template<class T>
vector<T> split(const std::string &s) {
    
    string replacedString = s;
    replace_if(replacedString.begin(),
               replacedString.end(),
               bind2nd(equal_to<char>(),'.'),
               ' ');
    
    vector<T> ret;
    istringstream buffer(replacedString);
    copy(istream_iterator<T>(buffer),
         istream_iterator<T>(), back_inserter(ret));
    return ret;    
}// vector<ll> k = split<ll>(s);

const ll IMPO = 999;

ll N,L;
vector<ll> outlet(200,0),dev(200,0);

ll s2b(string &s)
{
    //cout<<s<<" ";
    ll ret=0;
    for(int i =0;i<s.length();i++)
    {
        ret =  ret*2 + s[i]-'0';
    }
    //cout<<ret<<endl;
    return ret;
    
}

int main()
{
	fstream in,out;
	//in.open("test.in.txt",ios::in); out.open("test.out.txt",ios::out);
	in.open("A-small-attempt2.in",ios::in); out.open("A-small-0.out",ios::out);
    //in.open("A-large.in",ios::in); out.open("A-large-0.out",ios::out);

	istream& input = in;
	ostream& output = out;

	ll case_id,total_case,temp,ans;

	input>>total_case; 
	int I,H,K,k;     
	ll dif;
	string s;
	for(case_id=1;case_id<=total_case;case_id++)
	{
        ans = IMPO;
        input>>N>>L;
        for(I=0;I<N;I++) {
            input>>s;
            
            outlet[I] = s2b(s);
    //        cout<<outlet[I];
        }
        for(I=0;I<N;I++) {
            input>>s;
            dev[I] = s2b(s);
        }        
        sort(outlet.begin(),outlet.begin()+N);
        
        for(I=0;I<N;I++)
        {
            dif = dev[0]^outlet[I];
            //cout<<dif<<endl;
            vector<ll> app(200,0);
            for(H=0;H<N;H++)
            {
                app[H] = dev[H] ^ dif;
            }
            sort(app.begin(),app.begin()+N);
            
            for(H=0;H<N;H++) if(app[H]!=outlet[H]) break;
            
            
                
            if(H==N)
            {
                temp = 0;
                for(H=0;H<L;H++)
                {
                    temp+=dif%2;
                    dif=dif>>1;
                }
                
                ans=min(ans,temp);
            }
            
        }

        output<<"Case #"<<case_id<<": ";
        
        ans==IMPO ? output<<"NOT POSSIBLE" : output<<ans;
		output<<endl;
	}
    system("PAUSE");
    return EXIT_SUCCESS;
}
