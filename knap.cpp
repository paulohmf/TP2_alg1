#include <iostream>
#include <fstream>

using namespace std;

int mochila(int stones[], int n, int capacidade,int **matrix) {
    if (capacidade < 0){
    	return -999999;
    }
    if (n <= 0 || capacidade == 0){
    	return 0;
    }
    if(matrix[n][capacidade] == -1){
    	int a = stones[n] + mochila(stones, n - 1, capacidade - stones[n], matrix);
    	int b = mochila(stones, n - 1, capacidade, matrix);

    	matrix[n][capacidade] = max (a, b);
    }
    return matrix[n][capacidade];
}

int main(int argc, char *argv[]){
	// Recebendo as entradas 
	if(argc > 2){
		cout << "Insira o caminho para o arquivo de entrada" << endl;
		return 0;
	}
	string filename = "";
	filename = argv[1];

	string line = "";
	ifstream file(filename);
	if(!file.is_open()){
		cout << "Não foi possivel abrir o arquivo de entrada" << endl;
		return 0;
	}

	int n;
	file >> n;

	int stones[n];
	int total = 0;
	for(int k=0 ;k < n ; k++){
		file >> stones[k];
		total += stones[k];
	}
	file.close();

	// Gerar matrix de lookup para a PD da função mochila
	int **matrix;
	matrix = new int *[n+1];
	for(int i=0;i<=n;i++){
		matrix[i] = new int[(total/2)+1];
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=(total/2);j++){
			matrix[i][j] = -1;
		}
	}

	// Chamar problema
	int max = mochila(stones, n - 1, total/2, matrix);
	int result = total - (2*max);
	cout << result << endl;

	// Free da memoria 
	for(int i=0;i<=n;i++){
		delete matrix[i];
	}
	delete matrix;

	return 0;
};
