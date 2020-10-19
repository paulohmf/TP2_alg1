#include <iostream>
#include <chrono>
#include <ctime>  

using namespace std;

auto start = std::chrono::system_clock::now();

void brute_force(int stones[], int tam, int *minimo){
	//Time limit
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end-start;
	cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
	if( elapsed_seconds.count() > 600){
		cout << "TLE" << endl;
		throw -1;
	}
	//Condição de parada

	int new_minimo;
	if(tam <= 2){
		if(tam == 2){
			new_minimo = abs(stones[0]-stones[1]);
		}
		else{
			new_minimo = stones[0];
		}
		if(new_minimo < *minimo){
			*minimo = new_minimo;
		}
		return;
	}

	for(int i=0; i< tam; i++){
		for(int j=i+1; j <tam; j++){
			int dif = abs(stones[i]-stones[j]);

			int new_tam = tam - 2;
			if( dif != 0 ){
				new_tam = tam - 1;
			}

			int new_stones[new_tam];
			int pos = 0;

			if(dif != 0 ){
				pos = 1;
				new_stones[0] = dif;
			}

			for(int k=0; k< tam; k++){
				if(k != i && k != j){
					new_stones[pos] = stones[k];
					pos++;
				}
			}
			brute_force(new_stones,new_tam,minimo);
		}
	}
}

int main(){
	// Recebendo as entradas (CIN)
	int n;
	cin >> n;

	int stones[n];

	for(int k=0 ;k < n ; k++){
		cin >> stones[k];
	}
	cout << endl;

	// Problema
	int *minimo = new int;
	*minimo = 999999;

	//Time limit
	start = std::chrono::system_clock::now();
	brute_force(stones,n,minimo);

	cout << *minimo << endl;
	return 0;
};
