//
//  cut_hex.c
//  MkHexLat
//
//  Created by Alexander Kompch on 26.02.16.
//  Copyright (c) 2016 Alexander Kompch. All rights reserved.
//

#include "cut_hex.h"

coords* cut_hex(coords *given, parameters *pars) {
    coords *temp = NULL;
    
    temp = init_coords(temp, given->nat, given->boxL);
    if (temp == NULL) {
        printf("\n***   cut_hex: could not allocate temp");
        return NULL;
    }
    if (cp_coords(given, temp) == EXIT_FAILURE) {
        printf("\n***   cut_hex: could not copy coordinates");
        return NULL;
    }
    
    
    return temp;
}