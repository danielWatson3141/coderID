#include <iostream>
#include <fstream>

using namespace std;

bool does_match(int L, int N, char** outlets, char** flows){

	bool* is_used = new bool[N];

	bool output = true;

	for(int i=0; i<N; i++){

		is_used[i] = false;
	}

	for(int i=0; i<N && output ; i++){

		bool found_equal = false;
		for(int j=0; j < N && !found_equal; j++){

			if(!is_used[j]){

				bool is_equal =true;
				for(int k=0; k<L && is_equal; k++){

					is_equal = is_equal && (outlets[i][k] == flows[j][k]);
				}
				if(is_equal){

					is_used[j] = true;
					found_equal = true;
					break;
				}
			}

		}
		output = found_equal;
	}

	delete[] is_used;
	return output;
}

void apply_switch(int i_switch, int N, char** to_switch){

	for(int i=0; i<N; i++){

		if(to_switch[i][i_switch]=='0'){

			to_switch[i][i_switch]='1';
		}
		else{
			to_switch[i][i_switch]='0';
		}
	}
}

int compute_min_switch(int global_L,int L, int N, char** outlets, char** flows){

	if(L==1){

		if(does_match(global_L,N,outlets,flows)){

			return 0;
		}
		else{
			apply_switch(0, N, outlets);
			if(does_match(global_L,N,outlets,flows)){

				apply_switch(0, N, outlets);
				return 1;
			}
			else{
		
				apply_switch(0, N, outlets);
				return -1;
			}
		}
	}

	else{

		if(does_match(global_L,N,outlets,flows)){

			return 0;
		}
		else{
			int m1 = compute_min_switch(global_L, L-1, N,  outlets, flows);
			if(m1==0){
				return 0;
			}
			apply_switch(L-1, N, outlets);
			int m2 = compute_min_switch(global_L, L-1, N,  outlets, flows);
			cout << m1 << " " << m2 <<endl;
			apply_switch(L-1, N,outlets);
			if(m1<0){
				if(m2<0){

					return-1;
				}
				else{
					return m2+1;
				}
			}
			if(m2<0){
				return m1;
			}
			else{
				return min(m1, m2+1);
			}
		}
	}
}
			
					
int main(int argc, char** argv){

	if(argc <2){

		return-1;
	}

	ifstream fichier_input(argv[1], ios::in);
	ofstream fichier_output("output", ios::out);

	if(!fichier_input){

		cout << "ERROR : incorrect input"<<endl;
		return -1;
	}

	int n_test;

	fichier_input >> n_test;

	for(int round=1; round<=n_test; round++){

		int L,N;
		fichier_input >> N >> L;

		cout << "round " << round <<endl;

		char** flows = new char*[N];
		char** outlets = new char*[N];
		for(int i=0; i<N; i++){

			outlets[i] = new char[L];
			fichier_input >> outlets[i];
		}

		for(int i=0; i<N; i++){

			flows[i] = new char[L];
			fichier_input >> flows[i];
		}

		cout << L <<endl;
		int result = compute_min_switch(L,L,  N, outlets, flows);
		if(result <0){

			fichier_output << "Case #" << round << ": " << "NOT POSSIBLE" <<endl;
		}
		else{
		
			fichier_output << "Case #" << round << ": " << result <<endl;
		}

		for(int i=0; i<N; i++){

			delete[] outlets[i];
			delete[] flows[i];
		}
		
		delete[] outlets;
		delete[] flows;

	}

}

		

		
