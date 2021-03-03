#include "molecules.h"
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int find_subset(int l, int u, int* w, int n, int* result) {

	//Almacenamos pares {valor, indice} y luego ordenamos el vector
	//Este truco nos permite recuperar los indices originales
	//del vector w para cuando necesitemos devolver el subconjunto
	vii v(n);
	for(int i=0; i < n; ++i) {
		v[i] = {w[i], i};
	}
	sort(v.begin(), v.end());

	//Calculamos el valor de m
	int m = 0;
	ll suma_min = 0;
	ll suma_max = 0;
	while(m < n && suma_max < l) {
		//vamos acumulando en suma_min la suma de las m moleculas
		//mas ligeras y en suma_max la de las m mas pesadas
		//paramos cuando la suma_max >= l (o ya hayamos cogido todas)
		suma_min += v[m].first;
		suma_max += v[n-1-m].first;
		m++;
	}

	//Si no se satisfacen las condiciones, retornamos que no hay subconjunto
	if(suma_max < l || suma_min > u) {
		return 0;
	}

	//Si se satisfacen, sabemos que se podra. Buscamos el indice idx
	//donde la suma de las m siguientes moleculas pasa a ser >= l
	ll suma = suma_min;
	int idx = -1;
	if(suma >= l) {
		idx = 0;
	}
	for(int i=0; idx == -1 && i+m < n; ++i) {
		suma -= v[i].first;
		suma += v[i+m].first;
		if(suma >= l) {
			idx = i+1;
		}
	}

	//Ponemos el resultado, recuperando los indices originales
	//que estaban en las segundas posiciones de los pares
	for(int i=0; i < m; ++i) {
		result[i] = v[i+idx].second;
	}

    return m;
}

