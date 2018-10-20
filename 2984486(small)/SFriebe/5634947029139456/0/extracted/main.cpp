#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <vector>
#include <math.h>

using namespace std;

ifstream in;
stringstream out;


// Data
int nOutlets;
int nBits;
vector<string> outlets;
vector<string> devices;



void switch_bit(int n)
{
    for (string& str : outlets)
    {
        if (str[n] == '0')
            str[n] = '1';
        else
            str[n] = '0';
    }
}

bool matches()
{
    vector<string> searched = devices;
    vector<string> there = outlets;
    //while (!(searched.empty() || there.empty()))
    //for (auto iterS = searched.begin(); iterS != searched.end(); iterS++)
    for (unsigned int i = 0; i < searched.size(); i++)
    {
        for (auto iter = there.begin(); iter != there.end(); iter++)
        {
            if (searched[i].compare(*iter) == 0)
            {
//            cout << "found" << *iter << "\n";
                there.erase(iter);
                break;
            }
        }
    }
    if (there.empty())
        return true;
    return false;
}

int iterate(int n, int c)
{
    if (n > nBits)
        return 999999999;






    if (matches())
    {
/*cout << "\n" << n << " " << c<< " ";
    cout << "Outlets: ";
    for (int i = 0; i < nOutlets; i++)
    {
        cout << "'" << outlets[i] << "' ";
    }//*/
        return c;
    }

    int min = 999999999;
    for (int i = n + 1; i < nBits; i++)
    {
        int it = iterate(i, c);
        if (it < min)
            min = it;
    }

    switch_bit(n);
    if (matches())
    {
/*
cout << "\n" << n << " " << c<< " ";
    cout << "Outlets: ";
    for (int i = 0; i < nOutlets; i++)
    {
        cout << "'" << outlets[i] << "' ";
    }//*/
    switch_bit(n);
        return c + 1;
    }
    for (int i = n + 1; i < nBits; i++)
    {
        int it = iterate(i, c + 1);
        if (it < min)
            min = it;
    }
    switch_bit(n);
    return min;
/*
cout << n<<"\n";

    if (matches())
        return c;
    else
    {
        switch_bit(n);
        int min = 999999999;
        for (int i = n + 1; i < nBits; i++)
        {
            int it = iterate(i, c + 1);
            if (it >= 0 && it < min)
                min = it;
        }
        switch_bit(n);
        return min;
    }*/
    return -1;
}

void run_case()
{
    // Load data
    in >> nOutlets;
    in >> nBits; // Don't care for length of numbers
    string tmp;

    for (int i = 0; i < nOutlets; i++)
    {
        in >> tmp;
        outlets.push_back(tmp);
    }

    for (int i = 0; i < nOutlets; i++)
    {
        in >> tmp;
        devices.push_back(tmp);
    }

    cout << "Outlets: ";
    for (int i = 0; i < nOutlets; i++)
    {
        cout << "'" << outlets[i] << "' ";
    }

    cout << "\nDevices: ";
    for (int i = 0; i < nOutlets; i++)
    {
        cout << "'" << devices[i] << "' ";
    }
    cout << "\n";

    int iter = iterate(0, 0);
    if (iter <= nBits)
        out << iter << "\n";
    else
        out << "NOT POSSIBLE\n";
}

int main(int argc, char **argv)
{
    int n_cases = 0;
    int n_case  = 0;


    //string input_file = "sample.in";
    string input_file = "A-small-attempt4.in";
    //string input_file = "a.in";
    string output_file;

    if (argc > 1)
        input_file = argv[1];

    if (argc > 2)
        output_file = argv[2];
    else
    {
        output_file = input_file;
        string::size_type pos = output_file.rfind('.');

        if (pos != string::npos)
        {
            output_file.replace(pos + 1, string::npos, "out");
        }
        else
        {
            output_file += ".out";
        }
    }

    in.open(input_file);

    if (!in.is_open() || !in.good())
    {
        cerr << "Could not open input file '" << input_file << "'!\n";
        return 1;
    }

    ofstream outfile(output_file, ofstream::trunc);

    if (!outfile.is_open() || !outfile.good())
    {
        cerr << "Could not open output file '" << output_file << "'!\n";
        return 2;
    }

    // Set precision
    out.precision(12);

    in >> n_cases;
    cout << n_cases << " testcases in file.\n";

    for (n_case = 1; n_case <= n_cases; n_case++)
    {
        cout << "\nCase #" << n_case << ":\n";
        out << "Case #" << n_case << ": ";
        outlets.clear();
        devices.clear();
        run_case();
    }

    // Write contents to file
    outfile << out.str();

    // Output file-data
    cout << "\nWritten to file:\n================\n" << out.str() << "\n================\n";

    if (!outfile.good())
        cerr << "Error writing output file!\n";

    in.close();
    outfile.close();

    if (input_file.compare("sample.in") == 0)
    {
        cout << "Comparing:";
        system("cmp sample.out sample.lst");
        cout << "\n";
    }

    return 0;
}
