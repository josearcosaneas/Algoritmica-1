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

-Ahora veremos como se ajuste la funcion a nuestros datos 
dibujando las dos.

Vamos a usar 8 algoritmo , los 3 primeros son lentos , luego 3 
algoritmos de ordenacion rapida, el algoritmo de floyd para 
calcular los caminos de un grafo y el algoritmo de hanoi con una 
eficiencia mala. 

De cada problema se genere al menos 25 datos, que la grafica 
aporte informacion

Hacemos una tabal para los de ordenacion lenta, para observar 
las pequeñas diferencias entre unos y otros, porque las 
constante ocultas asociadas son mas pequeñas, se puede ver en 
las tablas y en las representaciones

-Analizar un algoritmo con opciones de optimizacion y sin 
optimizacion, a ver 
como cambian los tiempos de ejecucion reales
