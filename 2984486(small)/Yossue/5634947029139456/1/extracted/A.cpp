#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
#include <map>

using namespace std;

int main()
{
	ifstream ifs("C:/yoshiko/programming/gcj/2014/1A/A/A/A-large.in");
	ofstream ofs("C:/yoshiko/programming/gcj/2014/1A/A/A/A-large.out");
	string line;


	int nCases = 0;
	ifs >> nCases;

	for(int i=0; i<nCases; ++i)
	{
		int N = 0;
		ifs >> N;
		int L = 0;
		ifs >> L;

		vector<string> vecNum1InOutlet;
		for(int j=0; j<N; ++j)
		{
			string tmp;
			ifs >> tmp;
			vecNum1InOutlet.push_back(tmp);
		}
		sort(vecNum1InOutlet.begin(), vecNum1InOutlet.end());

		vector<string> vecNum1Required;
		for(int j=0; j<N; ++j)
		{
			string tmp;
			ifs >> tmp;
			vecNum1Required.push_back(tmp);
		}
		sort(vecNum1Required.begin(), vecNum1Required.end());

		int answer = 0;
		set<vector<string>> setCandidates;
		setCandidates.insert(vecNum1InOutlet);
		map<vector<string>, int> mapFlippedCount;
		mapFlippedCount[vecNum1InOutlet] = 0;


		bool isImpossible = false;
		for(int j=0; j<L; ++j)
		{
			set<vector<string>> setCandidatesTmp;

			set<vector<string>>::iterator it = setCandidates.begin();
			for(; it!=setCandidates.end(); ++it)
			{
				vector<string> vecCandidate = *it;

				vector<string> vecFlipped;
				int vecLen = vecCandidate.size();
				for(int k=0; k<vecLen; ++k)
				{
					string tmp = vecCandidate[k];
					tmp[j] = (tmp[j] == '1') ? '0' : '1';
					vecFlipped.push_back(tmp);
				}
				sort(vecFlipped.begin(), vecFlipped.end());

				bool isExist = false;
				if(setCandidates.find(vecFlipped) != setCandidates.end())
				{
					isExist = true;
				}
		
				bool isCandidateCorrect = true;
				bool isFlippedCorrect = !isExist;
				for(int k=0; k<vecLen; ++k)
				{
					if(isCandidateCorrect &&
						vecCandidate[k].substr(0, j+1) != vecNum1Required[k].substr(0, j+1))
					{
						isCandidateCorrect = false;
					}
					if(isFlippedCorrect && 
						vecFlipped[k].substr(0, j+1) != vecNum1Required[k].substr(0, j+1))
					{
						isFlippedCorrect = false;
					}

					if(!isCandidateCorrect && !isFlippedCorrect)
					{
						break;
					}
				}

				if(isCandidateCorrect)
				{
					setCandidatesTmp.insert(vecCandidate);
				}

				if(isFlippedCorrect)
				{
					setCandidatesTmp.insert(vecFlipped);
					mapFlippedCount[vecFlipped] = mapFlippedCount[vecCandidate] + 1;
				}
			}

			setCandidates = setCandidatesTmp;
			if(setCandidates.size() == 0)
			{
				isImpossible = true;
				break;
			}
		}

		int minAns = -1;
		if(!isImpossible)
		{
			set<vector<string>>::iterator it = setCandidates.begin();
			for(; it!=setCandidates.end(); ++it)
			{
				int count = mapFlippedCount[*it];
				if(minAns < 0 || count < minAns)
				{
					minAns = count;
				}
			}
		}

		if(isImpossible)
		{
			ofs << "Case #" << i+1 << ": NOT POSSIBLE" << endl;
		}
		else
		{
			ofs << "Case #" << i+1 << ": " << minAns << endl;
		}
	}
}