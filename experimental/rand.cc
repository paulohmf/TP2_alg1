#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(int argc, char *argv[]){
	if(argc <= 1){
		printf("necessário mais parametros\n");
		return 0;
	}

	int N = atoi(argv[1]);
	printf("%d\n",N);
	srand(time(NULL));

	for(int i=0;i<N;i++){
		int pulo = 1 + rand()%128;
		printf("%d ", pulo);
	}
}

/* SCRIPT

TIMEFORMAT="%U"
for i in {10..100000..50}; do for j in {1..100..1}; do TIME=`./rand ${i} | { time ./tp1 > /dev/null; }` TIME=${TIME//\\n//}; echo "${i} ${i} ${TIME}"; done; done &> tempos.txt


*/