//
//  anint.c
//  mklatc
//
//  Created by Alexander Kompch on 09.06.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#include "anint.h"

double anint(double x) {
    int a;
    double y;
    
    a = (int)x; //a=9
    
    if (10 * x - 10 * (double)a >= 5)
    {
        a = a + 1;
    }
    
    y = (double)a;
    
    return y;
}