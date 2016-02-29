//
//  write_coo.c
//  mklatc
//
//  Created by Alexander Kompch on 09.06.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#include "write_coo.h"

int write_coo(char *filename, coords *coo) {
    FILE *FP;
    int i=0;
    
    printf("write_coo: filename = %s",filename);
    
    if (coo == NULL) return EXIT_FAILURE;
       
    FP=fopen(filename, "wt");
    if (FP == NULL) {
        printf("\n***   write_coo:Could not open <%s>.", filename);
        return EXIT_FAILURE;
    }
    
    printf("\n***write_coo: coo->nat=%d",coo->nat);
    fprintf(FP, "%5d %+-8.6f %+-8.6f %+-8.6f %3s\n", coo->nat, coo->boxL.x, coo->boxL.y, coo->boxL.z, "coo");

    for(i=0;i<coo->nat;i++) {
        fprintf(FP, "%5d %2s %2d %+-8.6f %+-8.6f %+-8.6f\n", coo->atom_ptr[i]->n, coo->atom_ptr[i]->esymb, coo->atom_ptr[i]->atn, coo->atom_ptr[i]->pnt.x, coo->atom_ptr[i]->pnt.y, coo->atom_ptr[i]->pnt.z);
    }
    
    printf("\n***write_coo: here!!!");
    fclose(FP);
    
    return EXIT_SUCCESS;
}