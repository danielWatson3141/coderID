#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <cmath>
#include <windows.h>
#include <cstdio>
#include "BigIntegerLibrary.hh"
#include "BigIntegerUtils.hh"
using namespace std;
#define FILE
int isprime(int num);
int palindrome(string a);
int main()
{
    int t;

    #ifndef FILE
    cin >> t;
    #endif
    #ifdef FILE
    freopen("ab.txt","r+",stdin);
    freopen("oute.txt","w+",stdout);
    cin >> t;
    #endif // FILE

    for (int c(0);c<t;c++){
int devices,length;
cin >> devices >> length;
vector<string> arrke;
vector<string> arr1k;
for (int c1(0);c1<devices;c1++){
    string a;
    cin >> a;
arrke.push_back(a);
}
for (int c1(0);c1<devices;c1++){string a;cin >> a;arr1k.push_back(a);}
int mini(1000000);
for (int c2(0);c2<devices;c2++){
                    vector<string>arrk;
arrk=arrke;
            vector<int>index;
        for (int c3(0);c3<arrk[0].size();c3++){
            if (arrk[0][c3]!=arr1k[c2][c3]){index.push_back(c3);arrk[0][c3]=arr1k[c2][c3];}
        }
         int done[200];
    int don1[200];
    for (int jjjj(0);jjjj<200;jjjj++){done[jjjj]=0;don1[jjjj]=0;}
        don1[c2]=1;
        done[0]=1;
        for (int c5(1);c5<devices;c5++){for (int c6(0);c6<index.size();c6++)if (arrk[c5][index[c6]]=='0')arrk[c5][index[c6]]='1'; else arrk[c5][index[c6]]='0';}


    for (int c4(0);c4<devices;c4++){
     for (int c9(1);c9<devices;c9++){
        if (arr1k[c4]==arrk[c9]&&done[c9]==0){done[c9]=1;don1[c4]=1;break;}
     }
    }
   //cout << arr1k[0] << " " << arr1k[1] << " " << arr1k[2] << endl << arrk[0] << " " << arrk[1] << " " << arrk[2] << endl;
    int flag(0);
    for (int joker(0);joker<devices;joker++)if (don1[joker]==1)flag++;
    if (flag==devices)if (mini>index.size())mini=index.size();
// cout << flag << endl;
}
if (mini==1000000){cout << "Case #" << c+1 << ": NOT POSSIBLE" <<  endl;}
else
cout << "Case #" << c+1 << ": " << mini << endl;
        }
        return 0;
    }





/*for (int c2(0);c2<pow(2,length);c2++){
        vector<string> arr;
        arr=arrk;
vector<string> arr1;arr1=arr1k;
    int compare(1);
    vector<int>index;
    int c22(0);
    for (;compare<=c2;c22++)
    {
        if ((c2&compare)==compare)index.push_back(c22);
        compare=compare*2;
    }
    for (int c4(0);c4<index.size();c4++){
        for (int j(0);j<devices;j++){
            if (arr[j][index[c4]]=='0')arr[j][index[c4]]='1'; else arr[j][index[c4]]='0';

        }
    }

     int done[100];
    int don1[100];
    for (int jjjj(0);jjjj<100;jjjj++){done[jjjj]=0;don1[jjjj]=0;}
    for (int c4(0);c4<devices;c4++){
     for (int c9(0);c9<devices;c9++){
        if (arr1[c4]==arr[c9]&&done[c9]==0){done[c9]=1;don1[c4]=1;break;}
     }
    }
   //  cout << arr1[0] << " " << arr1[1] << " " << arr1[2] << endl << arr[0] << " " << arr[1] << " " << arr[2] << endl;
    int flag(0);
    for (int joker(0);joker<devices;joker++)if (don1[joker]==1)flag++;
    if (flag==devices)if (mini>index.size())mini=index.size();
// cout << flag << endl;
}
if (mini==1000000){cout << "Case #" << c+1 << ": NOT POSSIBLE" <<  endl;}
else
cout << "Case #" << c+1 << ": " << mini << endl;

    }
    */

int palindrome(string a){
string b(a);
reverse(a.begin(),a.end());
if (a==b)return 1; else return 0;






}

int isprime(int num){

	if(num<=1)
		return false;
	if(num==2)
		return true;
	if(num%2==0)
		return false;
	int sRoot = sqrt(num*1.0);
	for(int i=3; i<=sRoot; i+=2)
	{
		if(num%i==0)
			return 1;
	}
	return 1;






}
