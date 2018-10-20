// Round1A.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void change_i(string& s, int i){
	if(s[i]=='0') s[i]='1';
	else s[i]='0';
	return;
}

bool check(vector<string> outlet, vector<string> device, int& counter, int i, int m){
		if(i==m){
			sort(outlet.begin(),outlet.end());
			sort(device.begin(),device.end());
			return equal(outlet.begin(),outlet.end(),device.begin());
		}
		else{
			int counter1=0, counter2=0;
			for(int k=0; k<outlet.size(); k++){
					if(outlet[k][i]=='1') counter1++;
					if(device[k][i]=='1') counter2++;
			}
			if(counter1!=counter2 && outlet.size()-counter1 != counter2) return false;
			else{
				counter1=counter;
				counter2=counter+1;
				if(check(outlet,device,counter1,i+1,m)){ 
					counter=counter1;
					return true;
				}
				for(int k=0; k<outlet.size(); k++) change_i(outlet[k],i);
				if(check(outlet,device,counter2,i+1,m)){
					counter=counter2;
					return true;
				}
				else return false;
			}
		}
}

int main()
{
    freopen("D://Practice//A-small-attempt1.in", "r", stdin);
    freopen("D://Practice//A-small-attempt1.out", "w", stdout);

	int numCase;
	cin >> numCase;

	for(int i=0; i<numCase; i++) {
		int m, n;
		cin>>m>>n;
		vector<string> outlet, device;
		string tmp;
		for(int j=0; j<m; j++){
			cin>>tmp;
			outlet.push_back(tmp);
		}

		for(int j=0; j<m; j++){
			cin>>tmp;
			device.push_back(tmp);
		}
		int counter=0;
		bool flag;
		flag= check(outlet, device, counter, 0, n);


		if(flag==true) cout << "Case #" << (i+1) << ": " << counter << endl;
		else cout << "Case #" << (i+1) << ": " << "NOT POSSIBLE" << endl;
	}
	return 0;
}

