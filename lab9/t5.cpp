/*  MIP   */
#include "mlisp.h"
double __MIP__try/*2*/ (double x);
//________________ 
double __MIP__try/*2*/ (double x){
 	x = sin(x);
return
 x;
	 }
int main(){
 display(__MIP__try(2));
	 newline();
	  std::cin.get();
	 return 0;
	 }

