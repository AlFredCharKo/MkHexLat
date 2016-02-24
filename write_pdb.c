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
    char *filename_ptr = NULL;
    int i=0;
    
    if (coo == NULL) return EXIT_FAILURE;
    
    // make filename from prefix filename
    filename_ptr = malloc((strlen(filename)+4) * sizeof(char));
    strcpy(filename_ptr, filename);
    strcat(filename_ptr, ".pdb");
    
    FP=fopen(filename_ptr, "wt");
    
    if (FP == NULL) {
        printf("\n***   write_coo:Could not open <%s>.", filename_ptr);
        return EXIT_FAILURE;
    }
    
    for(i=0;i<coo->nat;i++) {
        fprintf(FP, "ATOM  %5d %2s   UNK  %4d      %+-8.3f%+-8.3f%+-8.3f%-6.2f%-6.2f         %2s  \n",coo->atom_ptr[i]->n,coo->atom_ptr[i]->esymb,0,coo->atom_ptr[i]->pnt.x, coo->atom_ptr[i]->pnt.y, coo->atom_ptr[i]->pnt.z,1.0,0.0,coo->atom_ptr[i]->esymb);

    }
    
    fclose(FP);
    
    return EXIT_SUCCESS;
}
