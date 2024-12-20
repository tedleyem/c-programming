#include <stdio.h>
/* Temperature conversion script */
/* print Fahrenheit-Celsius table 
for fahr = 0, 20, ..., 300 */

main (){
    /* using float instead of int for better accuracy.
     * using int doesnt give a decimal */
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;      /* lower limit of temperature scale */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    fahr = lower;
    while (fahr <= upper){
            /* celsius = 5 * (fahr-32) / 9; --old */ 
            celsius = (5.0/9.0) * (fahr-32.0);
            printf("%3.0f %5.1f\n", fahr, celsius);
            printf("fahr -- celsius\n");
            fahr = fahr + step;
            }
}
