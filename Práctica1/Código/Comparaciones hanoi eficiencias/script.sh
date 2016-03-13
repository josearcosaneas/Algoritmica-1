#!/bin/csh -vx


g++ -o -O1 hanoio1 hanoi.cpp -std=gnu++0x
g++ -o -02 hanoio2 hanoi.cpp -std=gnu++0x
g++ -o -03 hanoio3 hanoi.cpp -std=gnu++0x
g++ -o -0s hanoios hanoi.cpp -std=gnu++0x



printf "" > ./salidas/hanoio1.dat
printf "" > ./salidas/hanoio2.dat
printf "" > ./salidas/hanoio3.dat
printf "" > ./salidas/hanoios.dat
printf "" > ./salidas/hanoipy.dat


@ i = 1
while ( $i < 32 )
  ./hanoio1 $i >> ./salidas/hanoio1.dat
  @ i += 1
end

@ i = 1
while ( $i < 32 )
  ./hanoio2 $i >> ./salidas/hanoio2.dat
  @ i += 1
end

@ i = 1
while ( $i < 32 )
  ./hanoio3 $i >> ./salidas/hanoio3.dat
  @ i += 1
end

@ i = 1
while ( $i < 32 )
  ./hanoios $i >> ./salidas/hanoios.dat
  @ i += 1
end

@ i = 1
while ( $i < 32 )
  ./hanoipy $i >> ./salidas/hanoipy.dat
  @ i += 1
end
