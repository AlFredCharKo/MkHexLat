//
//  MakeMat.h
//  mklatc
//
//  Created by Alexander Kompch on 09.06.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#ifndef __mklatc__MakeMat__
#define __mklatc__MakeMat__

#include <stdio.h>
#include <math.h>
#include <gsl/gsl_matrix.h>
#include "structs.h"


gsl_matrix *MakeMat(parameters *pars);

#endif /* defined(__mklatc__MakeMat__) */
