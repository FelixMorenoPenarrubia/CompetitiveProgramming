#include "shoes.h"

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;


//Funcion que transforma el vector que nos dan
//emparejando los zapatos del mismo tamano y asignando
//un nuevo tamano para cada uno de ellos para que solo haya
//un par de cada tamano.
vi transform(vi s) {
	int n = s.size();

	//v sera el nuevo vector
	vi v(n);

	//Para cada tamano guardamos cuantos izquierdos y cuantos derechos
	//nos hemos encontrado y que nuevos tamanos hemos asignado.
	//Aqui usamos n como cota superior de numero de tamanos.
	vi lc(n);
	vi rc(n);
	vvi transf(n);

	int tam = 1;

	for(int i=0; i < n; ++i) {
		if(s[i] < 0) {
			int x = -s[i];
			//Si este zapato corresponde a una nueva pareja, le asignamos un nuevo
			//tamano. Si no, le asignamos el de su pareja.
			if(lc[x] >= rc[x]) {
				transf[x].push_back(tam);
				v[i] = -tam;
				tam++;
			}
			else {
				v[i] = -transf[x][lc[x]];
			}
			lc[x]++;
		}
		else {
			int x = s[i];
			if(rc[x] >= lc[x]) {
				transf[x].push_back(tam);
				v[i] = tam;
				tam++;
			}
			else {
				v[i] = transf[x][rc[x]];
			}
			rc[x]++;
		}
	}

	return v;
}

//Funciones del segment tree

vi st;

void st_update(int p, int l, int r, int i) {
	if(l > i || r < i) return;
	if(l == i && r == i) {
		st[p] += 1;
	}
	else {
		st_update(2*p, l, (l+r)/2, i);
		st_update(2*p+1, (l+r)/2+1, r, i);
		st[p] = st[2*p]+st[2*p+1];
	}
}

int st_query(int p, int l, int r, int i, int j) {
	if(l > j || r < i) return 0;
	if(l >= i && r <= j) {
		return st[p];
	}
	else {
		return st_query(2*p, l, (l+r)/2, i, j)+st_query(2*p+1, (l+r)/2+1, r, i, j);
	}
}


//Funcion que cuenta la respuesta, asumiendo que ahora solo hay un par de cada tamano
//(tambien se podria haber implementado de forma que no requiriera la funcion transform previa)
ll count(vi s) {

	int n = s.size();

	st = vi(4*n, 0);

	//Calcularemos el doble de la respuesta y al final dividiremos entre dos
	//para no tener que hacer divisiones entre dos por el medio
	ll ans = 0;

	//Aqui guardamos la posicion del primer zapato de la pareja
	vi prev_pos(n, -1);

	for(int i=0; i < n; ++i) {
		int x = s[i];
		if(x < 0) x = -x;
		if(prev_pos[x] == -1) {
			prev_pos[x] = i;
		}
		else {
			//Si estamos en el segundo zapato de la pareja, sumamos a la respuesta d(p) y 2*e(p)
			ans += (i-prev_pos[x]-1)+2*st_query(1, 0, n-1, prev_pos[x], i);
			//Si la pareja esta cambiada de orden hay que sumar un (multiplicado por 2) intercambio extra
			if(s[i] < 0) ans+=2;
			//Actualizamos el segment tree para que se tenga en cuenta esta pareja al calcular el e(p) de parejas posteriores
			st_update(1, 0, n-1, prev_pos[x]);
		}
	}

	ans /= 2;

	return ans;

}

ll count_swaps(vi s) {
	return count(transform(s));
}
