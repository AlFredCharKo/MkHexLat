//
//  write_gnuplot.c
//  mklatc
//
//  Created by Alexander Kompch on 09.06.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#include "write_gnuplot.h"

int write_gnuplot(char *filename, coords *coo) {
    FILE *FP;
    char *filename_ptr = NULL;
    int i=0;
    
    if (coo == NULL) return EXIT_FAILURE;
    
    // make filename from prefix filename
    filename_ptr = malloc((strlen(filename)+4) * sizeof(char));
    strcpy(filename_ptr, filename);
    strcat(filename_ptr, ".gnu");
    
    FP=fopen(filename_ptr, "wt");
    
    if (FP == NULL) {
        printf("\n***   write_coo:Could not open <%s>.", filename_ptr);
        return EXIT_FAILURE;
    }
    
    printf("\n***write_coo: coo->nat=%d",coo->nat);
    
    for(i=0;i<coo->nat;i++) {
        fprintf(FP, "%+-8.6f %+-8.6f %+-8.6f\n",coo->atom_ptr[i]->pnt.x, coo->atom_ptr[i]->pnt.y, coo->atom_ptr[i]->pnt.z);
    }
    
    printf("\n***write_coo: here!!!");
    
    fclose(FP);
    free(filename_ptr);
    
    return EXIT_SUCCESS;
}