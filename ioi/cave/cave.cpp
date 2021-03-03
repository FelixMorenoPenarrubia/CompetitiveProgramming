#include "cave.h"


//position: guarda la posicion correcta de cada interruptor
int position[5000];
//S: array que usamos para las preguntas
int S[5000];
//door: guarda la puerta asociada a cada interruptor
int door[5000];
//Tenemos n como variable global por comodidad
int n;

//Usamos esta funcion para preguntar y asi siempre que preguntemos
//ponemos los interruptores ya conocidos en la posicion correcta
int ask() {
	for(int i=0; i < n; ++i) {
		if(position[i] != -1) S[i] = position[i];
	}
	return tryCombination(S);
}

void exploreCave(int N) {
   	n = N;

   	//Inicialmente no conocemos ninguna posicion
    for(int i=0; i < n; ++i) position[i] = -1;

    for(int i=0; i < n; ++i) {
    	//Determinamos el interruptor de la i-esima puerta
    	for(int j=0; j < n; ++j) S[j] = 0;

    	//Hacemos la primera pregunta para determinar la posicion
    	//cur_pos guarda la posicion correcta
    	int cur_pos;
    	int res = ask();
    	//recordemos que si da -1 es que todas las puertas estan abiertas
    	if(res > i or res == -1) {
    		cur_pos = 0;
    	}
    	else {
    		cur_pos = 1;
    	}

    	//busqueda binaria: buscamos en el intervalo [low, high)
    	int low = 0;
    	int high = n;
    	while(high > low+1) {
    		int mid = (low+high)/2;
    		//ponemos [low, mid) en posicion incorrecta y
    		//[mid, high) en correcta
    		for(int j=low; j < high; ++j) {
    			if(j < mid) S[j] = 1-cur_pos;
    			else S[j] = cur_pos;
    		}
    		res = ask();
    		if(res > i or res == -1) {
    			low = mid;
    		}
    		else {
    			high = mid;
    		}
    	} 

    	position[low] = cur_pos;
    	door[low] = i;
    }
    answer(position, door);
}
