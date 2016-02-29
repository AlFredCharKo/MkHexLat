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
#include <gsl/gsl_rng.h>
#include "structs.h"
#include "anint.h"

coords* cut_hex(coords *given, parameters *pars);

#endif /* defined(__MkHexLat__cut_hex__) */
