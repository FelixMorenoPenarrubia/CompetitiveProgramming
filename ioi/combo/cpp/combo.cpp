#include "combo.h"
#include<vector>
#include<string>

using namespace std;

std::string guess_sequence(int N) {
  vector<string> btn = {"A", "B", "X", "Y"};
  int r;
  int startbtn;

  r = press("AB");
  if(r) {
  	r = press("A");
  	if(r) {
  		startbtn = 0;
  	}
  	else {
  		startbtn = 1;
  	}
  }
  else {
  	r = press("X");
  	if(r) {
  		startbtn = 2;
  	}
  	else {
  		startbtn = 3;
  	}
  }

  swap(btn[0], btn[startbtn]);

  string s = btn[0];
  if(N == 1) return s;
  for(int i=1; i < N-1; ++i) {
  	r = press(s+btn[1]+s+btn[2]+btn[1]+s+btn[2]+btn[2]+s+btn[2]+btn[3]);
  	if(r == i) {
  		s += btn[3];
  	}
  	else if(r == i+1) {
  		s += btn[1];
  	}
  	else if(r == i+2) {
  		s += btn[2];
  	}
  }
  r = press(s+btn[1]+s+btn[2]);
  if(r == N) {
  	r = press(s+btn[1]);
  	if(r == N) {
  		s += btn[1];
  	}
  	else {
  		s += btn[2];
  	}
  }
  else {
  	s += btn[3];
  }
  return s;
}
