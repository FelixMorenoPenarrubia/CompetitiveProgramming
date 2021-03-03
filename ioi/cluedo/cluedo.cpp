#include "grader.h"
#include "cluedo.h"

void Solve(){
   for(int i=1; i <= 6; ++i) {
   	for(int j=1; j <= 10; ++j) {
   		for(int k=1; k <= 6; ++k) {
   			Theory(i, j, k);
   		}
   	}
   }
   
}
