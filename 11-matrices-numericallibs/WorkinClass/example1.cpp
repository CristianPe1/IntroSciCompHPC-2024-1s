#include <cstdio>
#include <cmath>
#include <gsl/gsl_sf_bessel.h>

int main(void){
    double x = 5.0; 
    double expected = std::sin(x);
    double fromcmath = std::cyl_bessel_j(0, x);
    double result = gsl_sf_bessel_J0(x);

    printf("J0(%g) = %.18e\n", x, result);
    printf("sin(%g) = %.18e\n", x, expected);
    printf("cyl_bessel_j(0, %g) = %.18e\n", x, fromcmath);
    
    return 0;
}