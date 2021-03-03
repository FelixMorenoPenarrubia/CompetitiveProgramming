#include <vector>
#include <iostream>
#include "messy.h"

using namespace std;

int[128] p;
int N;


void read(int a, int b, string s) {

	cerr << "read(" << a << ", " << b << ", " << s << ")" << endl;

	if(a == b) {
		for(int i=0; i < N; ++i) {
			if(s[i] == '0') p[i] = a;
		}
	}
	else {
		string ns = string(N, '1');

		for(int i=0; i < N; ++i) {
			if(s[i] == '0') {
				s[i] = '1';
				if(check_element(s)) ns[i] = '0';
				s[i] = '0';
			}
		}

		int c = (a+b)/2;

		read(a, c, ns);

		for(int i=0; i < N; ++i) {
			if(ns[i] == '0') ns[i] = '1';
			else {
				if(s[i] == '0') ns[i] = '0';
			}
		}

		read(c+1, b, ns);
	}
}

void write(int a, int b, string s) {
	if(a == b) return;
	
	int c = (a+b)/2;
	for(int i=a; i <= c; ++i) {
		s[i] = '1';
		add_element(s);
		s[i] = '0';
	}

	string ns = string(N, '1');
	for(int i=a; i <= c; ++i) {
		ns[i] = '0';
	}
	write(a, c, ns);

	ns = string(N, '1');

	for(int i=c+1; i <= b; ++i) {
		ns[i] = '0';
	}
	write(c+1, b, ns);
	
}

int[] restore_permutation(int n, int w, int r) {
	N = n;
	//p = vector<int>(N);
    	
    write(0, N-1, string(N, '0'));
    compile_set();
    read(0, N-1, string(N, '0'));


    return p;
}
