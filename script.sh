#!/bin/csh -vx
echo "" >> salida.dat
@ i = 1000
while ( $i < 100000 ){
  ./mergeSort $i >> salida.dat
  @ i += 1000
}
end
