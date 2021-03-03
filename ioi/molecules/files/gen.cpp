int tn = 0;

#include "gen_include.cpp"

int main() {
	readAll("samples.in");
	
	readAll("tests.1");
	genGroup1();
	
	readAll("tests.2");
	genGroup2();
	
	readAll("tests.3");
	genGroup3();
	
	genGroup4();
	genGroup5();
	
	readAll("tests.6");
	genGroup6();
}
