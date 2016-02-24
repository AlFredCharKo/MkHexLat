//
//  read_parfile.h
//  mklatc
//
//  Created by Alexander Kompch on 09.06.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#ifndef __mklatc__read_parfile__
#define __mklatc__read_parfile__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "defs.h"
#include "trim.h"


parameters* read_parfile(char* parfile);

#endif /* defined(__mklatc__read_parfile__) */
