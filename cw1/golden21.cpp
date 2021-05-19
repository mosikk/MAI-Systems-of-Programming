/*  MIP   */
#include "mlisp.h"
extern double a/*2*/;
	 extern double b/*2*/;
	 double fun/*3*/ (double x) ;
	 double golden__section__search/*7*/ (double a, double b) ;
	 double golden__start/*15*/ (double a, double b) ;
	 extern double mphi/*24*/;
	 double __MIP__try/*25*/ (double a, double b
	 , double xa, double ya
	 , double xb, double yb) ;
	 bool close__enough_Q/*46*/ (double x, double y);
	 extern double tolerance/*48*/;
	 extern double total__iterations/*49*/;
	 extern double xmin/*50*/;
	 //________________ 
double a/*2*/ = 2.;
	 double b/*2*/ = 6.;
	 double fun/*3*/ (double x) {
 x = (x - (21. / 22.));
	 return
 (expt((x - 3.)
	 , 4.)
	  - expt(atan(x)
	 , 3.)
	  - 2.);
	 }
double golden__section__search/*7*/ (double a, double b) {
 {
 double xmin( ((a < b)
	? golden__start(a
	 , b)
	 
	: true
	? golden__start(b
	 , a)
	 
	: _infinity) );
	 newline();
	 return xmin;
	 }
}
double golden__start/*15*/ (double a, double b) {
 total__iterations = 0.;
	 {
 double xa( (a + (mphi * (b - a))) ),
	 xb( (b + (- (mphi * (b - a)))) );
	 return __MIP__try(a
	 , b
	 , xa
	 , fun(xa)
	 , xb
	 , fun(xb))
	 ;
	 }
}
double mphi/*24*/ = ((3. - sqrt(5.)) * (1. / 2e+0));
	 double __MIP__try/*25*/ (double a, double b
	 , double xa, double ya
	 , double xb, double yb) {
 return
 (close__enough_Q(a, b)
	 
	? ((a + b) * 5e-1)
	: true
	? display("+"),
	 total__iterations = (total__iterations + 1.),
	 ((ya < yb)
	? b = xb,
	 xb = xa,
	 yb = ya,
	 xa = (a + (mphi * (b - a))),
	 __MIP__try(a
	 , b
	 , xa
	 , fun(xa)
	 , xb
	 , yb)
	 
	: true
	? a = xa,
	 xa = xb,
	 ya = yb,
	 xb = (b - (mphi * (b - a))),
	 __MIP__try(a
	 , b
	 , xa
	 , ya
	 , xb
	 , fun(xb))
	 
	: _infinity)
	: _infinity);
	 }
bool close__enough_Q/*46*/ (double x, double y){
 return
 (abs((x - y)) < tolerance);
	 }
double tolerance/*48*/ = 1e-3;
	 double total__iterations/*49*/ = 0.;
	 double xmin/*50*/ = 0.;
	 int main(){
 xmin = golden__section__search(a
	 , b)
	 ;
	 display("Interval=\t[");
	 display(a);
	 display(" , ");
	 display(b);
	 display("]\n");
	 display("Total number of iteranions=");
	 display(total__iterations);
	 newline();
	 display("xmin=\t\t");
	 display(xmin);
	 newline();
	 display("f(xmin)=\t");
	 display(fun(xmin));
	 newline();
	 std::cin.get();
	 return
 0;
	 }

