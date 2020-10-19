#!/bin/bash
TIMEFORMAT="%U"
for i in {1..256..1}; do
	for j in {1..10..1}; do
		TIME=`./rand ${i} | { time ./tp2 > /dev/null; }`
		TIME=${TIME//\\n//};		
		echo "${i} ${i} ${TIME}";  
	done;
done &> tempos.txt


TIMEFORMAT="%U"
for i in {1..256..1}; do for j in {1..10..1}; do TIME=`./rand ${i} | { time ./tp2 > /dev/null; }` TIME=${TIME//\\n//}; echo "${i} ${i} ${TIME}"; done; done &> temposPD.txt