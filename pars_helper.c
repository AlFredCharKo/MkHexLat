//
//  pars_helper.c
//  MkHexLat
//
//  Created by Alexander Kompch on 01.03.16.
//  Copyright (c) 2016 Alexander Kompch. All rights reserved.
//

#include "pars_helper.h"

int pars_free(parameters *given) {
    int i=0;
    
    for (i=0; i < given->nuatoms; i++) {
        free(given->u_atom[i]);
    }
    free(given->u_atom);
    free(given->outfile1);
    free(given->parfile);
    free(given);
    
    return EXIT_SUCCESS;
}