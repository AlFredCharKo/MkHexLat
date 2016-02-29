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
    int i=0;
    
    if (coo == NULL) return EXIT_FAILURE;

    
    FP=fopen(filename, "wt");
    
    if (FP == NULL) {
        printf("\n***   write_gnuplot:Could not open <%s>.", filename);
        return EXIT_FAILURE;
    }
    
    printf("\n***write_gnuplot: coo->nat=%d",coo->nat);
    
    for(i=0;i<coo->nat;i++) {
        fprintf(FP, "%+-8.6f %+-8.6f %+-8.6f\n",coo->atom_ptr[i]->pnt.x, coo->atom_ptr[i]->pnt.y, coo->atom_ptr[i]->pnt.z);
    }
    
    printf("\n***write_gnuplot: here!!!");
    
    fclose(FP);
    
    return EXIT_SUCCESS;
}