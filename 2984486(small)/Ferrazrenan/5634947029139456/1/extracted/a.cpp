#include "stdafx.h"


std::fstream instream;
std::fstream outstream;

int N,L;
int test_cases;
string iniciais[222];
string finais[222];
long long swts;
long long inis[222];
long long fins[222];

long long mask_reached;

map<long long, long long> mascara_indice_fim_dela;

int go(int mask_i, int mask_f, int indice_bit){
	if (indice_bit == L) return 0;
	else{
		if (iniciais[mask_i][indice_bit] != finais[mask_f][indice_bit])	swts |= (1LL << indice_bit);
		return go(mask_i, mask_f, indice_bit + 1) + (iniciais[mask_i][indice_bit] != finais[mask_f][indice_bit]);
	}
}

void process(int t){
	int resp = 999999999;
	for (int mask_inicial_indice = 0; mask_inicial_indice < N; mask_inicial_indice++){
		for (int mask_final_indice = 0; mask_final_indice < N; mask_final_indice++){
			swts = 0;
			int numSwts = go(mask_inicial_indice, mask_final_indice, 0);
			mask_reached = 0;
			for (int indice = 0; indice < N; indice++){
				long long found = inis[indice] ^ swts;
				if (mascara_indice_fim_dela.find(found) == mascara_indice_fim_dela.end()) break;
				mask_reached |= (1LL << mascara_indice_fim_dela[found]);
			}
			if (mask_reached + 1 == (1LL << N)){
				resp = min(resp, numSwts);
			}
		}
	}

	outstream << "Case #" << t << ": ";
	if (resp == 999999999) outstream << "NOT POSSIBLE" << endl;
	else outstream << resp << endl;
}

void lerTeste(){
	instream.open("A-large.in", std::fstream::in);
	outstream.open("saida.txt", std::fstream::out);
	
	instream >> test_cases;
	
	for (int i = 0; i < test_cases; i++){
		instream >> N >> L;
		mascara_indice_fim_dela.clear();

		for (int j = 0; j < N; j++){
			inis[j] = 0;
			instream >> iniciais[j];
			for (int k = 0; k < L; k++) if (iniciais[j][k] == '1') inis[j] |= (1LL << k);

		}
		for (int j = 0; j < N; j++){
			fins[j] = 0;
			instream >> finais[j];
			for (int k = 0; k < L; k++) if (finais[j][k] == '1') fins[j] |= (1LL << k);
			mascara_indice_fim_dela[fins[j]] = j;
		}
		process(i + 1);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	lerTeste();

	//go(my_tree->root);


	return 0;
}