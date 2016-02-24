//
//  trancoo.h
//  mklatc
//
//  Created by Alexander Kompch on 09.06.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#ifndef __mklatc__trancoo__
#define __mklatc__trancoo__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gsl/gsl_matrix.h>
#include "structs.h"

coords* trancoo(coords *crystcoo, gsl_matrix *Mat);


#endif /* defined(__mklatc__trancoo__) */
