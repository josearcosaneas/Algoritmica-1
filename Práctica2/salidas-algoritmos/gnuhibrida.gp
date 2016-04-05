f(x) = a0*x*x*x
fit f(x) "Miguesalidabrutabuena.dat" via a0 
set encoding utf8
set terminal png size 1024,768
set title 'Fuerza bruta -Ef.Hibrida'
set output 'fuerzabruta-hibrida.png'
set xlabel 'Tamaño'
set ylabel 'Tiempo'
plot 'Miguesalidabrutabuena.dat', f(x) title 'Fuerza bruta - Hibrida'
