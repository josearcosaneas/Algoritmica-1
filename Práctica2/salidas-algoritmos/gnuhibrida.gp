f(x) = a0*x*log(x)
fit f(x) "Miguesalidadyv.dat" via a0 
set encoding utf8
set terminal png size 1024,768
set title 'Fuerza bruta -Ef.Hibrida'
set output 'divideyvenseras-hibrida.png'
set xlabel 'Tamaño'
set ylabel 'Tiempo'
plot 'Miguesalidadyv.dat', f(x) title 'Fuerza bruta - Hibrida'
