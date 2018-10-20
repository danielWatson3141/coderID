//
//  main.cpp
//
//  Created by Fazekas Miklos on 03/03/14.
//  Copyright (c) 2014 Fazekas Miklos. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>

#include <stdlib.h>
#include <dirent.h>

using namespace std;

class Solver
{
public:
    typedef bitset<160> BS;
    BS tobs(string in)
    {
        BS ret;
        for (int i = 0; i < in.size(); ++i) {
            if (in[i] == '1')
                ret.set(i,true);
        }
        return ret;
    }
    vector<BS> tobs(vector<string> in)
    {
        vector<BS> ret;
        for (auto i : in) {
            ret.push_back(tobs(i));
        }
        return ret;
    }
    
    long solve(const vector<BS>& req, const vector<BS>&has)
    {
        unordered_set<BS> reqs;
        for (auto i:req) {
            reqs.insert(i);
        }
        
        long best = INT_MAX;
        for (int ri = 0; ri < req.size(); ++ri) {
            for (int hi = 0; hi <= ri; ++hi) {
                BS diff = req[ri]^has[hi];
                int act = (int)diff.count();
                bool good=true;
                for (int i = 0; good && (i < has.size()); ++i) {
                    if (!reqs.count(has[i]^diff)) {
                        good=false;
                    }
                }
                if (good && (act < best))
                    best = act;
            }
        }
        return best;
    }
    
    /*
     The first line of the input gives the number of test cases, <b>T</b>. <b>T</b> test cases follow. Each test case consists of three lines. The first line contains two space-separated integers <b>N</b> and <b>L</b>. The second line contains <b>N</b> space-separated strings of length <b>L</b>, representing the initial electric flow from the outlets. The third line also contains <b>N</b> space-separated strings of length <b>L</b>, representing the electric flow required by Shota's devices. */

    void solve_stream(istream& in, ostream& out)
    {
        int T;
        in >> T;
        for (int t=0;t < T; ++t) {
            int N,L;
            
            in >> N >> L;
            vector<string> req,has;
            for (int n =0; n < N;++n) {
                string seqn;
                in >> seqn;
                has.push_back(seqn);
            }
            for (int n =0; n < N;++n) {
                string seqn;
                in >> seqn;
                req.push_back(seqn);
            }
            out << "Case #" << t+1 << ": ";
            long s =solve(tobs(req),tobs(has));
            if (s == INT_MAX) {
                out << "NOT POSSIBLE";
            } else {
                out << s;
            }
            out << std::endl;
        }
    }
};

void do_solve(std::string input,std::string output)
{
    Solver solver;
    ifstream inf(input);
    ofstream outf(output);
    solver.solve_stream(inf,outf);
}

string path_join(string base,string file)
{
    return base + "/" + file;
}

bool do_compare(std::string output, std::string good_output,int precision=-1)
{
    //precision=6;
    string diff_cmd=string("diff -du \"")+output+"\" \""+good_output+"\"";
    if (precision > 0) {
        diff_cmd=string("python ")+getenv("DATADIR")+string("/../scripts/diff.py --precision ")+to_string(precision)+" \""+output+"\" \""+good_output+"\"";
    }
    int ret = system(diff_cmd.c_str());
    if (WIFEXITED(ret)) {
        return (WEXITSTATUS(ret)==0);
    } else {
        throw logic_error("Diff failed:"+diff_cmd);
    }
}

template <typename T>
void list_dir(string dir, T t)
{
    DIR* dirp = opendir(dir.c_str());
    if (dirp == NULL)
    throw logic_error("opendir failed!");
    
    struct dirent *dp;
    while ((dp = readdir(dirp)) != NULL) {
        t(string(dp->d_name,dp->d_namlen));
    }
    (void)closedir(dirp);
}


int main(int argc, const char * argv[])
{
    char* datadir= getenv("DATADIR");
    if (datadir == 0) {
        throw logic_error("DATADIR env should be set!");
    }
    struct Desc {
        bool has_good_solution=false;
        bool has_input=false;
    };
    map<string,Desc> inputs;

    string good_suffix=".out-good.txt";
    list_dir(datadir,[&](string item) {
        if (good_suffix.size() < item.size() && equal(good_suffix.rbegin(),good_suffix.rend(),item.rbegin())) {
            string base(item.begin(),item.begin()+item.size()-good_suffix.size());
            inputs[base].has_good_solution=true;
        }
        string in_suffix=".in.txt";
        if (in_suffix.size() < item.size() && equal(in_suffix.rbegin(),in_suffix.rend(),item.rbegin())) {
            string base(item.begin(),item.begin()+item.size()-in_suffix.size());
            inputs[base].has_input=true;
        }
    });
    
    for (auto& input: inputs) {
        if (input.second.has_input) {
            string inname=input.first+".in.txt";
            string outname=input.first+".out.txt";
            string in=path_join(datadir,inname);
            string out=path_join(datadir,outname);
            std::cerr << "solving: " << inname << " to: " << outname <<std::endl;
            do_solve(in,out);
            if (input.second.has_good_solution) {
                string out_good=path_join(datadir,input.first+good_suffix);
                bool same = do_compare(out,out_good);
                if (same) {
                    std::cerr << "  => OK: same as " <<input.first+good_suffix << std::endl;
                } else {
                    std::cerr << "  => BAD: different from " << input.first+good_suffix << std::endl;
                }
            }
        }
    }
    
    return 0;
}

