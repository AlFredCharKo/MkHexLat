//
//  cut_hex.h
//  MkHexLat
//
//  Created by Alexander Kompch on 26.02.16.
//  Copyright (c) 2016 Alexander Kompch. All rights reserved.
//

#ifndef __MkHexLat__cut_hex__
#define __MkHexLat__cut_hex__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gsl/gsl_math.h>
#include "structs.h"
#include "coords_helper.h"
#include "lvec.h"

coords* cut_hex(coords *given, parameters *pars);
double hex_f1(double x, double a);
double hex_f2(double x, double a);
double hex_f3(double x, double a);
double hex_f4(double x, double a);

#endif /* defined(__MkHexLat__cut_hex__) */
