//
//  read_parfile.c
//  mklatc
//
//  Created by Alexander Kompch on 09.06.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#include "read_parfile.h"

parameters* read_parfile(char* parfile)
{
    int i=0, line=0;
    char buffer[MAX_LEN], *buffer_ptr=NULL;
    parameters* pars = (parameters *)malloc(sizeof(parameters));
    FILE *FP;
    
    FP=fopen(parfile, "rt");
    if (FP == NULL) {
        printf("\n***   read_parfile:Could not open <%s>.", parfile);
        return NULL;
    }
    
    pars->parfile = (char *)malloc(strlen(parfile)*sizeof(char));
    strcpy(pars->parfile, parfile);
    
    while ((buffer_ptr = fgets(buffer, MAX_LEN, FP)) != NULL) {
        line ++;
        if      (line == 1) sscanf(buffer, "%lf %lf %lf", &(pars->u_latt.x), &(pars->u_latt.y), &(pars->u_latt.z));
        else if (line == 2) sscanf(buffer, "%d %d %d", &(pars->nh), &(pars->nk), &(pars->nl));
        else if (line == 3) sscanf(buffer, "%lf %lf %lf", &(pars->u_angle.x), &(pars->u_angle.y), &(pars->u_angle.z));
        else if (line == 4) sscanf(buffer, "%lf", &(pars->displac));
        else if (line == 5) sscanf(buffer, "%lf %lf %lf", &(pars->hex_origin.x), &(pars->hex_origin.y), &(pars->hex_origin.z));
        else if (line == 6) sscanf(buffer, "%lf", &(pars->hex_side));
        else if (line == 7) {
            buffer_ptr=trim(buffer_ptr);
            pars->outfile1 = (char *)malloc(strlen(buffer_ptr)*sizeof(char));
            strcpy(pars->outfile1, buffer_ptr);
        }
    }
    
        //first read of all lines in file, table with unit cell composition after line 7
    pars->nuatoms=line-7;
    rewind(FP);
    
    if ((pars->u_atom = (atom **)malloc(pars->nuatoms*sizeof(atom*))) == NULL) {
        perror("\n***   read_parfie:malloc pars.u_atom failed");
        EXIT_FAILURE;
    }
    for (i=0; i<pars->nuatoms; i++) {
        if ((pars->u_atom[i] = (atom *)malloc(sizeof(atom))) == NULL) {
            perror("\n***   read_parfie:malloc pars.u_atom failed");
            EXIT_FAILURE;
        }
        
    }
    

        //second read of all lines in file, read only after line 7
    for (line=0; line < 7; line++) {
        buffer_ptr = fgets(buffer, MAX_LEN, FP);
        //		printf("line %d: %s", line, buffer);
    }
    
    for (line=0; line < pars->nuatoms; line++) {
        buffer_ptr = fgets(buffer, MAX_LEN, FP);
        sscanf(buffer, "%d" "%s" "%d" "%lf" "%lf" "%lf", &(pars->u_atom[line]->n), pars->u_atom[line]->esymb, &(pars->u_atom[line]->atn), &(pars->u_atom[line]->pnt.x), &(pars->u_atom[line]->pnt.y), &(pars->u_atom[line]->pnt.z));
    }
    
    return pars;
}
