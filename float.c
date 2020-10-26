#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "float.h"
//make problem2

int is_special ( float f ) {
    if (f == INFINITY || f == -INFINITY || isnan(f))
    {
        return 1 ;
    }
    return 0 ;
}


float get_M  ( float f ) {
    if (f == INFINITY || f == -INFINITY)
    {
        return 00000000000000000000 ;
    }
    else if (isnan(f))
    {
        return 0.5000000000000000000 ;
    }
    int e ;
    float mantissa = frexpf(f, &e) ;
    mantissa = fabs(mantissa*2) ;
    return mantissa ;
    
}


int get_s ( float f ) { //check if float
	
    if (!signbit(f))
    {
        return 1 ;
    }
    else{
        return -1 ;
    }
}

int get_E ( float f ) {
    if (is_special(f) == 1)
    {
        return 255 ;
    }
    else if (f< pow(2,-126))
    {
        return -126 ;
    }
    int e ;
    float mantissa = frexpf(f, &e) ;
    return e - 1 ;
	
}













      



    
    
