set encoding utf8
set terminal png size 1024,768
set title 'Comparacion de ambos programas'
set output './comparacion.png'
set xlabel 'Tamaño de la matriz'
set ylabel 'Tiempo de ejecución (s)'
plot './Miguesalidabrutabuena.dat' using 1:2 title 'Fuerza bruta' with lines, './Miguesalidadyv.dat' using 1:2 title 'Divide y vencerás' with lines




