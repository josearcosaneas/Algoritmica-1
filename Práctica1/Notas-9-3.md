Ajuste minimos cuadrados entre curva teorica y curva empirica.
Sacamos la ecuacion que seria algo asi:
	T(n) = a0 * n^2 +a1*n + a2 , aunque podriamos usar la 
que mas "impacto" tiene y usar directamente T(n)=a0*n²

El ajuste se hace con gnuplot:
-En gnuplot le ponemos la funcion que queremos representar: 
a0*x*x+a1*x+a2 
-Lueog hay que indicarle a gnuplot que haga la regresión usando 
 el comando fit:
da una serie de cosas, l oimportante para nosotros es que nos 
dice los parametros de los valores que ha ajustado (a0 a1 y a2) 
y nos da informacion sobre la calidad del ajuste (nos dice el 
error, el porcentaje)
