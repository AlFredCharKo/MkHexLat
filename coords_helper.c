//
//  coords_helper.c
//  MkHexLat
//
//  Created by Alexander Kompch on 29.02.16.
//  Copyright (c) 2016 Alexander Kompch. All rights reserved.
//

#include "coords_helper.h"

coords *init_coords(coords *given, int nat, vec boxL) {
    int i = 0;
    
    if  (given == NULL) {
        given = (coords*)malloc(sizeof(coords));
        if (given == NULL) {
            printf("\n***   init_coords: malloc failed");
            return NULL;
        }
        given->atom_ptr = (atom**)malloc(nat * sizeof(atom*));
        if (given->atom_ptr == NULL) {
            printf("\n***   init_coords: malloc failed");
            return NULL;
        }
        for (i=0; i<nat; i++) {
            given->atom_ptr[i] = (atom*)malloc(sizeof(atom));
            if (given->atom_ptr[i] == NULL) {
                printf("\n***   init_coords: malloc failed");
                return NULL;
            }
            given->atom_ptr[i]->n = i+1;
            strncpy(given->atom_ptr[i]->esymb, "XX", 2);
            given->atom_ptr[i]->atn = -1;
            given->atom_ptr[i]->pnt.x = 0.0;
            given->atom_ptr[i]->pnt.y = 0.0;
            given->atom_ptr[i]->pnt.z = 0.0;
        }
        given->nat = nat;
        given->boxL.x = boxL.x;
        given->boxL.y = boxL.y;
        given->boxL.z = boxL.z;
        
    } else {
        free_coords(given);
        given = init_coords(given, nat, boxL);
    }
    return given;
}

int cp_coords(const coords *source, coords *dest) {
    int i = 0;
    
        // check that source is allocated, else exit function with error
    if (source == NULL) {
        return (EXIT_FAILURE);
    }
        // check that destination is allocated, else exit function with error
    if (dest == NULL) {
        return (EXIT_FAILURE);
    }
        // check that destination has been allocated for at least as many atoms as in source, else exit with error
    if (dest->nat < source->nat) {
        return (EXIT_FAILURE);
    }
    
    for (i=i; i<source->nat; i++) {
        dest->atom_ptr[i]->n = source->atom_ptr[i]->n;
        strncpy(dest->atom_ptr[i]->esymb, source->atom_ptr[i]->esymb, 2);
        dest->atom_ptr[i]->atn = source->atom_ptr[i]->atn;
        dest->atom_ptr[i]->pnt.x = source->atom_ptr[i]->pnt.x;
        dest->atom_ptr[i]->pnt.y = source->atom_ptr[i]->pnt.y;
        dest->atom_ptr[i]->pnt.z = source->atom_ptr[i]->pnt.z;
    }
    
    dest->boxL.x = source->boxL.x;
    dest->boxL.y = source->boxL.y;
    dest->boxL.z = source->boxL.z;
    
    
    return (EXIT_SUCCESS);
}


int free_coords(coords *given) {
    int i = 0;
    
    for (i=0;i<given->nat;i++) {
        free(given->atom_ptr[i]);
    }
    free(given->atom_ptr);
    free(given);
    return (EXIT_SUCCESS);
}