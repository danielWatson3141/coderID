#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
int count(string str[],string r[],string str1[],int n,int l,int k)
{
	int x=0;
	string st="";
	string s1=str1[k];
	string s2=str[0];
	for(int i=0;i<l;i++)
	{
		if(s1[i]!=s2[i])
		{
			x++;
			st=st+"1";
		}
		else
		{
			st=st+"0";
		}
	}
	for(int i=1;i<n;i++)
	{
			int flag=0;
		string temp="";
		s2=str[i];
		for(int j=0;j<l;j++)
		{
			if(st[j]=='1')
			{
				if(s2[j]=='1')
				{
					temp=temp+"0";
				}
				else
				{
					temp=temp+"1";
				}
			}
			else
			{
				temp=temp+s2[j];
			}
		
		}
		for(int j=0;j<n;j++)
		{
			if(temp==str1[j] && k!=j )
			{
				flag=1;
				str1[j]="a";
				break;
			}
		}
		if(flag==0)
		{
	
		for(int i=0;i<n;i++)
		{
			str1[i]=r[i];
		}
			return -1;
		}
	}
		for(int i=0;i<n;i++)
		{
			str1[i]=r[i];
		}
	return x;
}
int main()
{
	ifstream inp;
	ofstream out;
	inp.open("input.in");
	if(!inp)
		{
			return 100;
		}
	out.open("output.txt");
	if(!out)
		{
			return 100;
		}
	int cases;
	inp>>cases;
	//define variables
	int n,l,c=0,cp=-1;
	
	//defined variables
	for(int z=1;z<=cases;z++)
	{
		cp=-1;
		inp>>n;
		inp>>l;
		string str[n];
		string str1[n];
		string r[n];
		for(int i=0;i<n;i++)
		{
			inp>>str[i];
		}
		for(int i=0;i<n;i++)
		{
			inp>>str1[i];
			r[i]=str1[i];
		}
		//start loop
		for(int i=0;i<n;i++)
		{
			c=count(str,r,str1,n,l,i);
			
			if((c<cp && cp!=-1 && c!=-1)||(cp==-1))
			{
		
				cp=c;
			}
			
		}
		out<<"Case #"<<z<<": "; 
		if(cp==-1)
		{
			out<<"NOT POSSIBLE"<<endl;
		}
		else
		{
			out<<cp<<endl;
		}
	
		//end loop
	}
	inp.close();
	out.close();
	return 0;
}
