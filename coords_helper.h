//
//  coords_helper.h
//  MkHexLat
//
//  Created by Alexander Kompch on 29.02.16.
//  Copyright (c) 2016 Alexander Kompch. All rights reserved.
//

#ifndef __MkHexLat__coords_helper__
#define __MkHexLat__coords_helper__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defs.h"
#include "structs.h"


coords *init_coords(int nat, vec boxL);
int cp_coords(const coords *source, coords *dest);
int cp_ncoords(const coords *source, coords *dest, int n);
int move2center(coords *given, vec new_origin);
int cp_atom(const atom *source, atom *dest, int v);
int coords_free(coords *given);

#endif /* defined(__MkHexLat__coords_helper__) */
