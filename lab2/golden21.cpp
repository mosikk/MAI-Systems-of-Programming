#include "mlisp.h"

extern double a;
extern double b;
double fun(double x);
double golden__section__search(double a, double b);
double golden__start(double a, double b);
extern double mphi;
double __mip__try(double a, double b, double xa, double ya, double xb, double yb);
bool close__enough_Q(double x, double y);
extern double tolerance;
extern double total__iterations;
extern double xmin;

double a = 2., b = 6.;

//(define (fun x)
// (set! x (- x (/ 21 22)))
// (-(expt(- x 3) 4) (expt(atan x) 3) 2)
//)

double fun(double x) {
    x = x - 21. / 22.;
    return expt(x - 3., 4.) - expt(atan(x), 3.) - 2.;
}

//(define (golden-section-search a b)
// (let(
//      (xmin(if(< a b)(golden-start a b)(golden-start b a )))
//     )
//     (newline)
//     xmin
// )
//)

double golden__section__search(double a, double b) {
    {
        double
            xmin = a < b ? golden__start(a, b) : golden__start(b, a);
        newline();
        return xmin;
    }
}

//(define (golden-start a b)
// (set! total-iterations 0)
// (let(
//      (xa (+ a (* mphi(- b a))))
//      (xb (+ b (-(* mphi(- b a)))))
//     )
//     (try a b xa (fun xa) xb (fun xb))
// )
//)

double golden__start(double a, double b) {
    total__iterations = 0.;
    {
        double
            xa = a + (mphi * (b - a)),
            xb = b + (-(mphi * (b - a)));
        return __mip__try(a, b, xa, fun(xa), xb, fun(xb));
    }
}

//(define mphi (* (- 3(sqrt 5))(/ 2.0)))
double mphi = (3. - sqrt(5.)) / 2.0;

//(define (try a b xa ya xb yb)
// (if(close-enough? a b)
//      (* (+ a b)0.5)
//      (let() (display "+")
//             (set! total-iterations (+ total-iterations 1))
//             (cond((< ya yb)(set! b xb)
//                         (set! xb xa)
//                         (set! yb ya)
//                         (set! xa (+ a (* mphi(- b a))))
//                         (try a b xa (fun xa) xb yb)
//                  )
//                  (else    (set! a xa)
//                         (set! xa xb)
//                         (set! ya yb)
//                         (set! xb (- b (* mphi(- b a))))
//                         (try a b xa ya xb (fun xb))
//                   )
//             );cond...
//      );let...
// );if...
//)

double __mip__try(double a, double b, double xa, double ya, double xb, double yb) {
    return close__enough_Q(a, b) ?
        (a + b) * 0.5 :
        (display("+"),
            total__iterations = total__iterations + 1,
            ya < yb ? (b = xb,
                xb = xa,
                yb = ya,
                xa = a + (mphi * (b - a)),
                __mip__try(a, b, xa, fun(xa), xb, yb))
            : (a = xa,
                xa = xb,
                ya = yb,
                xb = b - (mphi * (b - a)),
                __mip__try(a, b, xa, ya, xb, fun(xb))));
}

//(define (close-enough? x y)
//  (<(abs (- x y))tolerance))

bool close__enough_Q(double x, double y) {
    return (abs(x - y) < tolerance);
}

double tolerance = 0.001;
double total__iterations = 0.;
double xmin = 0.;

//(set! xmin(golden-section-search a b))
//  (display"Interval=\t[")
//  (display a)
//  (display" , ")
//  (display b)
//  (display"]\n")
//  (display"Total number of iteranions=")
//total-iterations
//  (display"xmin=\t\t")
//xmin
//  (display"f(xmin)=\t")
//(fun xmin)

int main() {
    xmin = golden__section__search(a, b);
    display("Interval=\t[");
    display(a);
    display(" , ");
    display(b);
    display("]\n");
    display("Total number of iterations=");
    display(total__iterations); newline();
    display("xmin=\t\t");
    display(xmin); newline();
    display("f(xmin)=\t");
    display(fun(xmin)); newline();

    std::cin.get();
    return 0;
}