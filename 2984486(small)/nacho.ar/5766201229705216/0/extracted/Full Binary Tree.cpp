using namespace std;
#include <fstream>

struct node {
	int * connected;
	int connections;
};

int numberOfChilds(node * G, int index, int parent, int N){
	int ret = 0;
	for (int i = 0; i < N; i++)
	{
		if (i != parent){
			if (G[index].connected[i]){
				ret++;
			}
		}
	}
	return ret;
}

int deletesToBeBinary(node * G, int index, int parent, int N){
	
	int nchilds = numberOfChilds(G, index, parent, N);
	int ret = 0;

	int visited = 1;

	if (nchilds == 2){
		//CONTINUE DOWN
		for (int j = 0; j < N; j++)
		{
			if (j != parent){
				if (G[index].connected[j]){
					visited += deletesToBeBinary(G, j, index, N);
				}
			}
		}
	}
	//else if (nchilds == 1) {
	//	//ERASE THE CHILD
	//	for (int j = 0; j < N; j++)
	//	{
	//		if (j != parent){
	//			if (G[index].connected[j]){
	//				ret = 1 + numberOfChilds(G, j, index, N);
	//			}
	//		}
	//	}
	//}
	else if (nchilds > 2){
		//CHOOSE WHICH CHILDS TO KEEP
		int maxvisits[2]; maxvisits[0] = 0; maxvisits[1] = 0;
		int maxindex[2]; maxindex[0] = 20; maxindex[1] = 20;

		for (int j = 0; j < N; j++)
		{
			if (j != parent){
				if (G[index].connected[j]){
					int visits = deletesToBeBinary(G, j, index, N);

					if (visits > maxvisits[0]){
						if (visits > maxvisits[1])
						{
							//bigger than both
							if (maxvisits[0] > maxvisits[1]){
								//1 is smaller. leave 1
								maxvisits[1] = visits;
								maxindex[1] = j;
							}
							else {
								//0 is bigger
								maxvisits[0] = visits;
								maxindex[0] = j;
							}
						}
						else {
							// smaller than 0, bigger than 1
							maxvisits[0] = visits;
							maxindex[0] = j;
						}
					}
					else if (visits > maxvisits[1]){
						//bigger than 0, smaller than 1
						maxvisits[1] = visits;
						maxindex[1] = j;
					}

				}
			}
		}

		//for (int j = 0; j < N; j++)
		//{
		//	if (j != parent && j != maxindex[0] && j != minindex[1]){
		//		if (G[index].connected[j]){
		//			ret += 1 + numberOfChilds(G, j, index, N);
		//		}
		//	}
		//}

		visited += maxvisits[0] + maxvisits[1];

	}
	return visited;
}

int main(int argc, char * argv[])
{
	long icase = 0;
	int T, N = 0;

	std::fstream infile;
	infile.open("C:\\Users\\Nacho\\Desktop\\input.in", ios_base::in);
	std::fstream outfile;
	outfile.open("C:\\Users\\Nacho\\Desktop\\output.txt", ios_base::out);

	if (infile >> T){
		while (icase < T){
			if (infile >> N){
	

				//INITIALIZE STRUCTURE

				node * G = new node[N];

				for (int i = 0; i < N; i++)
				{
					G[i].connections = 0;
					G[i].connected = new int[N];
					for (int j = 0; j < N; j++)
					{
						G[i].connected[j] = 0;
					}
				}

				// LOAD EDGES

				for (int i = 0; i < N - 1; i++){
					int X;
					int Y;
					infile >> X;
					X -= 1;
					infile >> Y;
					Y -= 1;

					G[X].connected[Y] = 1;
					G[X].connections++;
					G[Y].connected[X] = 1;
					G[Y].connections++;
				}

				
				int mindeletes = N;

				for (int i = 0; i < N; i++)
				{
					int visited = deletesToBeBinary(G, i, 22, N);
					int deletes = N - visited;
					if (deletes < mindeletes) mindeletes = deletes;
					//if (G[i].connections == 2){
					//	// THIS COULD BE A ROOT
					//	int deletes = 0;
					//	for (int j = 0; j < N; j++)
					//	{
					//		if (G[i].connected[j]){
					//			deletes += deletesToBeBinary(G, j, i, N);
					//		}
					//	}
					//	if (deletes < mindeletes) mindeletes = deletes;
					//}
					
				}

				if (icase > 0) outfile << endl;

				outfile << "Case #" << icase + 1 << ": " << mindeletes;

				icase++;
				continue;
			}
		}
	}
}