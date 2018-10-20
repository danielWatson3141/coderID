#include<iostream>
#include<sstream>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>
#include<stack>

using std::cin;using std::cout;using std::endl;
using std::string;using std::stringstream;
using std::replace;
using std::map;using std::make_pair;
using std::vector;
using std::queue;
using std::stack;

#define FOR(i,s,e) for (int i = int(s); i != int(e); ++i)
#define FORIT(i,c) for (auto i = (c).begin(); i != (c).end(); ++i)
stringstream ssin;
void cin2line(char eliminator = 0)
{
  string line;ssin.clear();
  getline(cin,line);
  if (eliminator != 0) 
    replace(line.begin(),line.end(),eliminator,' ');
  ssin.str(line);
}

int g_step;

void walk(vector<string> ivstr,const vector<string>& ovstr, int bit, int L, int step)
{
  if (bit == L) {
    if (g_step < 0 || g_step > step) g_step = step;
  } else {
    map<string,int> omstr;
    map<string,int> imstr1,imstr2;
    FORIT(it,ovstr) {
      string str = it->substr(0,bit+1);
      if (omstr.find(str) == omstr.end()) omstr.insert(make_pair(str,1));
      else ++omstr.find(str)->second;
    }
    FORIT(it,ivstr) {
      string str = it->substr(0,bit+1);
      if (imstr1.find(str) == imstr1.end()) imstr1.insert(make_pair(str,1));
      else ++imstr1.find(str)->second;
    }
    if (imstr1 == omstr) walk(ivstr,ovstr,bit+1,L,step);
    FORIT(it,ivstr) {
      (*it)[bit] = ((*it)[bit] == '0')?'1':'0';
      string str = it->substr(0,bit+1);
      if (imstr2.find(str) == imstr2.end()) imstr2.insert(make_pair(str,1));
      else ++imstr2.find(str)->second;
    }
    if (imstr2 == omstr) walk(ivstr,ovstr,bit+1,L,step+1);
  }
}

int main()
{
  int T;
  cin2line();
  ssin >> T;
  FOR(i,0,T) {
    int N,L;
    g_step = -1;
    string str;
    vector<string> ivstr;
    vector<string> ovstr;
    cin2line();
    ssin >> N >> L;
    cin2line();
    FOR(j,0,N) {
      ssin >> str;
      ivstr.push_back(str);
    }
    cin2line();
    FOR(j,0,N) {
      ssin >> str;
      ovstr.push_back(str);
    }
    walk(ivstr,ovstr,0,L,0);
    if (g_step < 0) cout << "Case #" << i+1 << ": NOT POSSIBLE" << endl;
    else cout << "Case #" << i+1 << ": " << g_step << endl;
  }
}
