#define POLYGON

int tn = 3;

#include "gen_include.cpp"
#include "gen_polygon_str.cpp"

int main() {
	//newTest();
	
	//readAll("samples.in");
	//readFromString(strSample);
	
	//readAll("tests.1");
	readFromString(str1);
	genGroup1();
	
	//readAll("tests.2");
	readFromString(str2);
	genGroup2();
	
	//readAll("tests.3");
	readFromString(str3);
	genGroup3();
	
	genGroup4();
	genGroup5();
	
	readFromString(str6);
	genGroup6();
}
