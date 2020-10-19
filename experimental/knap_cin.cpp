#include <iostream>

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

    	int maximo = max (a, b);
    	matrix[n][capacidade] = maximo;

    	return maximo;
    }
    return matrix[n][capacidade];
}

int main(){
	// Recebendo as entradas (CIN)
	int n;
	cin >> n;

	int stones[n];
	int total = 0;

	for(int k=0 ;k < n ; k++){
		cin >> stones[k];
		total += stones[k];
	}

	// Gerar matrix de lookup para a PD da função mochila
	int **matrix;
	matrix = new int *[n+1];
	for(int i=0;i<=n;i++){
		matrix[i] = new int[(total/2)+1];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<=(total/2);j++){
			matrix[i][j] = -1;
		}
	}

	// Chamar problema
	int max = mochila(stones, n - 1, total/2, matrix);
	int result = total - (2*max);
	cout << result << endl;

	return 0;
};
