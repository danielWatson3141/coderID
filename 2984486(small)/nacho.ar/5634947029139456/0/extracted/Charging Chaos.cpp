using namespace std;
#include <fstream>

int CountONES(unsigned int n, int L){
	int ret = 0;
	for (int i = 0; i < L; i++)
	{
		if (1 << i & n) ret++;

	}
	return ret;
}

int main(int argc, char * argv[])
{
	long icase = 0;
	int T, N, L = 0;

	std::fstream infile;
	infile.open("C:\\Users\\Nacho\\Desktop\\input.in", ios_base::in);
	std::fstream outfile;
	outfile.open("C:\\Users\\Nacho\\Desktop\\output.txt", ios_base::out);

	if (infile >> T){
		while (icase < T){
			if (infile >> N){
				if (infile >> L){
					
					unsigned int * outlets = new unsigned int[N];
					unsigned int * devices = new unsigned int[N];


					//READ OUTLETS
					for (int i = 0; i < N; i++)
					{
						outlets[i] = 0; 

						int base = 1;
						for (int j = 1; j < L; j++)
						{
							base *= 2;
						}

						char aux = 99;
						
						for (int j = 0; j < L; j++)
						{
							infile >> aux;
							if (aux == '1'){
								outlets[i] += base;
							}
							base /= 2;
						}
					}

					//READ DEVICES
					for (int i = 0; i < N; i++)
					{
						devices[i] = 0;

						int base = 1;
						for (int j = 1; j < L; j++)
						{
							base *= 2;
						}

						char aux = 99;

						for (int j = 0; j < L; j++)
						{
							infile >> aux;
							if (aux == '1'){
								devices[i] += base;
							}
							base /= 2;
						}
					}
					

					//ALL 1s
					unsigned int MAXboard = 1;
					int base = 1;
					for (int j = 1; j < L; j++)
					{
						base *= 2;
						MAXboard += base;
					}

					//switchboard configuration
					unsigned int best = MAXboard + base * 2; //bigger than any possibility

					for (int switchboard = 0; switchboard < MAXboard; switchboard++){

						int i = 0;
						for (i = 0; i < N; i++){
							int j = 0;
							for (j = 0; j < N; j++){
								if ( (outlets[i] ^ switchboard) == devices[j])
									//there is a combination that works
									break;
							}
							if (j == N)
								//couldnt find a combination
								break;
						}
						if (i == N)
						{
							//they all had a combination
							if (CountONES(switchboard, L) < CountONES(best, L+1))
							{
								best = switchboard;
							}
						}
					}


					if (icase > 0) outfile << endl;

					if (best == MAXboard + base * 2)
					{
						outfile << "Case #" << icase + 1 << ": NOT POSSIBLE";
					}
					else {
						outfile << "Case #" << icase + 1 << ": " << CountONES(best, L);
					}


					icase++;
					continue;
				}
			}
		}
	}
}