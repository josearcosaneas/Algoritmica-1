#!/bin/csh -vx


g++ -o ./nlogn/mergesort ./nlogn/mergesort.cpp -std=gnu++0x
g++ -o ./nlogn/heapsort ./nlogn/heapsort.cpp -std=gnu++0x
g++ -o ./nlogn/quicksort ./nlogn/quicksort.cpp -std=gnu++0x

g++ -o ./n^2/seleccion ./n^2/seleccion.cpp -std=gnu++0x
g++ -o ./n^2/burbuja ./n^2/burbuja.cpp -std=gnu++0x
g++ -o ./n^2/insercion ./n^2/insercion.cpp -std=gnu++0x

g++ -o ./otros/hanoi ./otros/hanoi.cpp -std=gnu++0x
g++ -o ./otros/floyd ./otros/floyd.cpp -std=gnu++0x


printf "" > ./salidas-nlogn/salidamerge.dat
printf "" > ./salidas-nlogn/salidaquick.dat
printf "" > ./salidas-nlogn/salidaheap.dat

printf "" > ./salidas-n^2/salidaburbuja.dat
printf "" > ./salidas-n^2/salidaseleccion.dat
printf "" > ./salidas-n^2/salidainsercion.dat

printf "" > ./salidas-otros/salidahanoi.dat
printf "" > ./salidas-otros/salidafloyd.dat
@ i = 1000
while ( $i < 100000 )
  ./nlogn/mergesort $i >> ./salidas-nlogn/salidamerge.dat
  @ i += 1000
end

@ i = 1000
while ( $i < 100000 )
  ./nlogn/quicksort $i >> ./salidas-nlogn/salidaquick.dat
  @ i += 1000
end


@ i = 1000
while ( $i < 100000 )
  ./nlogn/heapsort $i >> ./salidas-nlogn/salidaheap.dat
  @ i += 1000
end


@ i = 100
while ( $i < 10000 )
  ./n^2/seleccion $i >> ./salidas-n^2/salidaseleccion.dat
  @ i += 100
end
@ i = 100
while ( $i < 10000 )
  ./n^2/burbuja $i >> ./salidas-n^2/salidaburbuja.dat
  @ i += 100
end
@ i = 100
while ( $i < 10000 )
  ./n^2/insercion $i >> ./salidas-n^2/salidainsercion.dat
  @ i += 100
end

@ i = 1
while ( $i < 32 )
  ./otros/hanoi $i >> ./salidas-otros/salidahanoi.dat
  @ i += 1
end
@ i = 100
while ( $i < 1200 )
  ./otros/floyd $i >> ./salidas-otros/salidafloyd.dat
  @ i += 100
end
