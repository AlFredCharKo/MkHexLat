//
//  write_pdb.c
//  mklatc
//
//  Created by Alexander Kompch on 09.06.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#include "write_pdb.h"

int write_pdb(char *filename, coords*coo) {
    FILE *FP;
    int i=0;
    
    if (coo == NULL) return EXIT_FAILURE;
    
    FP=fopen(filename, "wt");
    
    if (FP == NULL) {
        printf("\n***   write_pdb:Could not open <%s>.", filename);
        return EXIT_FAILURE;
    }
    
    for(i=0;i<coo->nat;i++) {
        fprintf(FP, "ATOM  %5d %2s   UNK  %4d      %+-8.3f%+-8.3f%+-8.3f%-6.2f%-6.2f         %2s  \n",coo->atom_ptr[i]->n,coo->atom_ptr[i]->esymb,0,coo->atom_ptr[i]->pnt.x, coo->atom_ptr[i]->pnt.y, coo->atom_ptr[i]->pnt.z,1.0,0.0,coo->atom_ptr[i]->esymb);
    }
    
    fclose(FP);
    
    return EXIT_SUCCESS;
}
