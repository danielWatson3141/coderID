#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

ifstream in;
stringstream out;

/// Comparator with delta to avoid problems when checking for equality
bool compareDelta(const double& lhs, const double& rhs)
{
    static const double DELTA = 0.00000001;
    bool res = lhs - DELTA < rhs && lhs + DELTA < rhs;
//    cout << "cmp "<< lhs << " " << rhs << " " << res << "\n";
    return res;
}

enum Type
{
    GOOD,
    BAD
};

/// Reads a line from the input and calculates the results
Type run_case()
{
    // Load data
    unsigned int nNumbers;
    in >> nNumbers;
    vector<unsigned int> numbers;
    unsigned int tmp;
    for (unsigned int i = 0; i < nNumbers; i++)
    {
        in >> tmp;
        numbers.push_back(tmp);
    }

    /*for (int i : numbers)
        cout << "_" << i << "_";
    cout << "\n";*/


    // If the first position is 0, it is (hopefully) a bad algo
    if (numbers[0] == 0)
        return BAD;

    // Calculate the median offset of the numbers. Should be N/2   BROKEN
    /*double offset = 0;
    for (unsigned int i = 0; i < numbers.size(); i++)
        offset += (numbers[i] - (nNumbers - i));
    cout << offset;*/

    // The propability for having the 0 at the first position is 1/N, same for 1 on second position (1/(N-1))
    // Calculate the propability for the given number
    double prob = 0;
    for (unsigned int i = 0; i < numbers.size() - 1; i++)
    {
        if (numbers[i] == i)
            prob += ((double)1/(nNumbers-i));
        else
            prob += 1-((double)1/(nNumbers-i));
    //cout << prob << "\n";
    }

    double minprob = 0;
    for (unsigned int i = 0; i < numbers.size() - 1; i++)
        minprob += ((double)1/(nNumbers-i));

    double maxprob = 0;
    for (unsigned int i = 0; i < numbers.size() - 1; i++)
        maxprob += 1-((double)1/(nNumbers-i));
    double medprob = (maxprob + minprob) / 2;
    cout << minprob << "/" << prob << "/" << maxprob << "/" << medprob;

    if (prob < maxprob - 0.9)
        return BAD;

    return GOOD;
}

int main(int argc, char **argv)
{
    int n_cases = 0;
    int n_case  = 0;


    //string input_file = "sample.in";
    string input_file = "C-small-attempt9.in";
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

    int good = 0;
    int bad = 0;

    for (n_case = 1; n_case <= n_cases; n_case++)
    {
        cout << "\nCase #" << n_case << ":\n";
        out << "Case #" << n_case << ": ";
        if(run_case() == GOOD)
        {
            good++;
            out << "GOOD\n";
        }
        else
        {
            bad++;
            out << "BAD\n";
        }
    }

    // Write contents to file
    outfile << out.str();

    // Output file-data
    cout << "\nWritten to file:\n================\n" << out.str() << "\n================\n";

    cout << "Good: " << good << " Bad: " << bad << "\n";

    if (!outfile.good())
        cerr << "Error writing output file!\n";

    in.close();
    outfile.close();

    return 0;
}
