#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int num, n, l;
    ifstream fin;
    ofstream fout;
    string input;
    fin.open("chargesmall.in", std::ifstream::in);
    fout.open("chargesmall.out", std::ofstream::out);
    fin>>num;
    for(int k = 0; k < num; k++)
    {
        string device, outlet;
        string tmp;
        fin>>n;
        fin>>l;
        vector<int> model(l, 0);
        cout<<"n:"<<n<<endl;
        cout<<"l:"<<l<<endl;
        getline(fin, tmp);
        getline(fin, outlet);
        getline(fin, device);
        vector<string> d(n);
        vector<string> o(n);
        vector<string> d1(n);
        char x, y;
        int count=0;
        for(int i = 0; i < device.size(); i++)
        {
            if(device[i] == ' ')
            {
                count++;
                continue;
            }
            d[count].push_back(device[i]);
            o[count].push_back(outlet[i]);
        }
        sort(o.begin(), o.end());
        for(int i = 0; i < n; i++)
        {
            cout<<o[i]<<' ';
        }
        cout<<endl;
        for(int i = 0; i < n; i++)
        {
            cout<<d[i]<<' ';
        }
        cout<<endl;
        int min;
        
        bool flag = false;
        min = 100;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                count = 0;
                for(int p = 0; p < n; p++)
                    d1[p].erase(d1[p].begin(), d1[p].end());
                for(int p = 0; p < l; p++)
                {
                    if(d[i][p] == '0' && o[j][p] == '0')
                    {
                        for(int q = 0; q < n; q++)
                        d1[q].push_back(d[q][p]);
                    }
                    if(d[i][p] == '1' && o[j][p] == '1')
                    {
                        for(int q = 0; q < n; q++)
                        d1[q].push_back(d[q][p]);
                    }
                    if(d[i][p] == '0' && o[j][p] == '1')
                    {
                        for(int q = 0; q < n; q++)
                        d1[q].push_back(d[q][p] == '0'?'1':'0');
                        count++;
                    }
                    if(d[i][p] == '1' && o[j][p] == '0')
                    {
                        for(int q = 0; q < n; q++)
                        d1[q].push_back(d[q][p] == '0'?'1':'0');
                        count++;
                    }
                }
                sort(d1.begin(), d1.end());
                if(equal(o.begin(), o.end(),d1.begin()))
                {
                    flag = true;
                    if(count < min)
                        min = count;
                }
            }
        }
        if(flag == true)
        {
            fout<<"Case #"<<k+1<<": "<<min<<endl;
        }
        else
        {
            fout<<"Case #"<<k+1<<": NOT POSSIBLE"<<endl;
        }
    }

    fin.close();
    fout.close();
    return 0;
}
