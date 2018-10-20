#include <string>
//#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

void flip_str(string &str,int index)
{
	str[index]=(str[index]=='0'?'1':'0');
}

void flip_line(vector<string> & line,int index)
{
	for (int i=0;i<line.size();i++)
		flip_str(line[i],index);
}

bool judge_ok(vector<string> line1,const vector<string> &line2)
{
	for (int j=0;j<line2.size();j++)
	{
		vector<string>::iterator it=find(line1.begin(),line1.end(),line2[j]);
		if (it==line1.end())
		{
			return false;
		}
		else
		{
			line1.erase(it);
		}
	}
	return true;
}

int solve_p(vector<string> line1,vector<string> line2,int index)
{

	if (index==line1[0].size()) return -1;
	if(judge_ok(line1,line2)==true) return 0;
	flip_line(line1,index);
	if (judge_ok(line1,line2)==true) return 1;
	int f_time=1;
	int ret_times=solve_p(line1,line2,index+1);
	if (ret_times!=-1)
	{
		f_time+=ret_times;
	}
	else
		f_time=-1;
	flip_line(line1,index);
	ret_times=solve_p(line1,line2,index+1);
	if(ret_times==-1 && f_time==-1)
		return -1;
	else if (ret_times==-1)
	{
		return f_time;
	}
	else if (f_time==-1)
	{
		return ret_times;
	}
	else
		return ret_times<f_time?ret_times:f_time;

}

int main()
{
	char *filename="A-small-attempt2 (1).in";
	char *outfilename="2.txt";
	ifstream infile(filename);
	ofstream outfile(outfilename);
	//stringstream str;
	int case_number;
	infile>>case_number;
	int number_str, str_length;
	vector<string> first_line,second_line;
	for (int i=0;i<case_number;++i)
	{
		first_line.clear();
		second_line.clear();
		infile>>number_str>>str_length;
		string temp_str;
		for(int j=0;j<number_str;j++)
		{
			infile>>temp_str;
			first_line.push_back(temp_str);
		}
		vector<string> first_back_up=first_line;
		int num_dif=0;
		for (int j=0;j<number_str;j++)
		{
			infile>>temp_str;
			second_line.push_back(temp_str);
		}
		int filip_time=solve_p(first_line,second_line,0);
		
		outfile<<"Case #"<<i+1<<": ";
		if (filip_time!=-1)
		{
			outfile<<filip_time;
		}
		else
		{
			outfile<<"NOT POSSIBLE";
		}
		outfile<<endl;
	}
	outfile.close();
	infile.close();
	return 0;
}