set encoding utf8
set terminal png size 1024,768
set title 'Suma Vectores PC-Local'
set output 'sumavectoresLocal.png'
set xlabel 'Bytes'
set ylabel 'Execution time'
plot 'datos_local.dat' using 1:2 title 'Local' with lines 





