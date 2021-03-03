#include "grader.h"
#include "memory.h"

void play() {
   int i;
   char a, b;
   vector<char> v(51);
   for (i=1; i<=50; ++i) {
     v[i] = faceup(i);
   }
   for(i=1; i <= 50; ++i) {
   	for(int j=i+1; j <= 50; ++j) {
   		if(v[i]==v[j]) {
   			faceup(i);
   			faceup(j);
   		}
   	}
   }
}
