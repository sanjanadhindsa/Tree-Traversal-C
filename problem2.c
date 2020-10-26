/* Author: JoannaKl
 * 
 * This program performs basic operations on floating 
 * point numbers to illustrate how they are encoded 
 * using the IEEE754 standard. It reads a sequence of 
 * floating point numbers from the standard input stream
 * and outputs the results to the standard output stream.
 * The input is terminated by a zero.
 * 
 * DO NOT MODIFY THIS FILE
 * 
 */
 
 #include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "float.h"

int main() {
    
    
    float value;
    int E;
    float M;
    int sign; 
    
    //continue reading values until failure or zero
    while ( scanf("%f", &value) > 0 && value != 0 ) {
        
        //disassemble the number into the three parts 
        M = get_M  ( value ); 

        sign = get_s ( value );

        E = get_E ( value ) ;
        
        //print each of the three parts 
        printf("%d %d %22.20f\n", sign, E, M); 
        
        //display recalculated value based on the three parts 
        if (! is_special(value) ) {
            //use pow() not shifts since E may be larger than 32
            printf("%.50f\n\n", sign * M * pow(2,E)  ) ; 
        }
        else if (M==0.0){ //these values are infinity
            
            printf("%.50f\n\n", sign*INFINITY  ) ; 
        }
        else { //these values are not numbers 
            printf("%.50f\n\n", sign*NAN  ) ; 
        }
    }
	

	return 0;
}




