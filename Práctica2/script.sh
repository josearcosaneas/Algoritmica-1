#!/bin/csh -vx

printf "" > ./salidas-algoritmos/salidabrutabuena.dat
printf "" > ./salidas-algoritmos/salidabruta.dat
printf "" > ./salidas-algoritmos/salidadyv.dat

g++ -o fuerzabruta_bueno fuerzabruta_bueno.cpp -std=gnu++0x
g++ -o fuerzabruta fuerzabruta.cpp -std=gnu++0x
g++ -o recursivoV1 recursivoV1.cpp -std=gnu++0x


./fuerzabruta_bueno ./salidas-mezclavectores/salida55.txt 5 >> ./salidas-algoritmos/salidabrutabuena.dat
./fuerzabruta_bueno ./salidas-mezclavectores/salida1010.txt 10 >> ./salidas-algoritmos/salidabrutabuena.dat
./fuerzabruta_bueno ./salidas-mezclavectores/salida1515.txt 15 >> ./salidas-algoritmos/salidabrutabuena.dat
./fuerzabruta_bueno ./salida-mezclavectores/salida2020.txt 20 >> ./salidas-algoritmos/salidabrutabuena.dat
./fuerzabruta_bueno ./salidas-mezclavectores/salida3030.txt 30 >> ./salidas-algoritmos/salidabrutabuena.dat
./fuerzabruta_bueno ./salidas-mezclavectores/salida4040.txt 40 >> ./salidas-algoritmos/salidabrutabuena.dat
./fuerzabruta_bueno ./salidas-mezclavectores/salida5555.txt 55 >> ./salidas-algoritmos/salidabrutabuena.dat
./fuerzabruta_bueno ./salidas-mezclavectores/salida8080.txt 80 >> ./salidas-algoritmos/salidabrutabuena.dat
./fuerzabruta_bueno ./salidas-mezclavectores/salida120120.txt 120 >> ./salidas-algoritmos/salidabrutabuena.dat
./fuerzabruta_bueno ./salidas-mezclavectores/salida160160.txt 160 >> ./salidas-algoritmos/salidabrutabuena.dat
./fuerzabruta_bueno ./salidas-mezclavectores/salida200200.txt 200 >> ./salidas-algoritmos/salidabrutabuena.dat
./fuerzabruta_bueno ./salidas-mezclavectores/salida500500.txt 500 >> ./salidas-algoritmos/salidabrutabuena.dat
./fuerzabruta_bueno ./salidas-mezclavectores/salida700700.txt 700 >> ./salidas-algoritmos/salidabrutabuena.dat
./fuerzabruta_bueno ./salidas-mezclavectores/salida10001000.txt 1000 >> ./salidas-algoritmos/salidabrutabuena.dat
   


./fuerzabruta ./salidas-mezclavectores/salida55.txt 5 >> ./salidas-algoritmos/salidabruta.dat
./fuerzabruta ./salidas-mezclavectores/salida1010.txt 10 >> ./salidas-algoritmos/salidabruta.dat
./fuerzabruta ./salidas-mezclavectores/salida1515.txt 15 >> ./salidas-algoritmos/salidabruta.dat
./fuerzabruta ./salidas-mezclavectores/salida2020.txt 20 >> ./salidas-algoritmos/salidabruta.dat
./fuerzabruta ./salidas-mezclavectores/salida3030.txt 30 >> ./salidas-algoritmos/salidabruta.dat
./fuerzabruta ./salidas-mezclavectores/salida4040.txt 40 >> ./salidas-algoritmos/salidabruta.dat
./fuerzabruta ./salidas-mezclavectores/salida5555.txt 55 >> ./salidas-algoritmos/salidabruta.dat
./fuerzabruta ./salidas-mezclavectores/salida8080.txt 80 >> ./salidas-algoritmos/salidabruta.dat
./fuerzabruta ./salidas-mezclavectores/salida120120.txt 120 >> ./salidas-algoritmos/salidabruta.dat
./fuerzabruta ./salidas-mezclavectores/salida160160.txt 160 >> ./salidas-algoritmos/salidabruta.dat
./fuerzabruta ./salidas-mezclavectores/salida200200.txt 200 >> ./salidas-algoritmos/salidabruta.dat
./fuerzabruta ./salidas-mezclavectores/salida500500.txt 500 >> ./salidas-algoritmos/salidabruta.dat
./fuerzabruta ./salidas-mezclavectores/salida700700.txt 700 >> ./salidas-algoritmos/salidabruta.dat
./fuerzabruta ./salidas-mezclavectores/salida10001000.txt 1000 >> ./salidas-algoritmos/salidabruta.dat

./recursivoV1 ./salidas-mezclavectores/salida55.txt 5 5 >> ./salidas-algoritmos/salidadyv.dat
./recursivoV1 ./salidas-mezclavectores/salida1010.txt 10 10 >> ./salidas-algoritmos/salidadyv.dat
./recursivoV1 ./salidas-mezclavectores/salida1515.txt 15 15 >> ./salidas-algoritmos/salidadyv.dat
./recursivoV1 ./salida-mezclavectores/salida2020.txt 20 20 >> ./salidas-algoritmos/salidadyv.dat
./recursivoV1 ./salidas-mezclavectores/salida3030.txt 30 30 >> ./salidas-algoritmos/salidadyv.dat
./recursivoV1 ./salidas-mezclavectores/salida4040.txt 40 40 >> ./salidas-algoritmos/salidadyv.dat
./recursivoV1 ./salidas-mezclavectores/salida5555.txt 55 55 >> ./salidas-algoritmos/salidadyv.dat
./recursivoV1 ./salidas-mezclavectores/salida8080.txt 80 80 >> ./salidas-algoritmos/salidadyv.dat
./recursivoV1 ./salidas-mezclavectores/salida120120.txt 120 120 >> ./salidas-algoritmos/salidadyv.dat
./recursivoV1 ./salidas-mezclavectores/salida160160.txt 160 160 >> ./salidas-algoritmos/salidadyv.dat
./recursivoV1 ./salidas-mezclavectores/salida200200.txt 200 200 >> ./salidas-algoritmos/salidadyv.dat
./recursivoV1 ./salidas-mezclavectores/salida500500.txt 500 500 >> ./salidas-algoritmos/salidadyv.dat
./recursivoV1 ./salidas-mezclavectores/salida700700.txt 700 700 >> ./salidas-algoritmos/salidadyv.dat
./recursivoV1 ./salidas-mezclavectores/salida10001000.txt 1000 1000 >> ./salidas-algoritmos/salidadyv.dat
   
   



