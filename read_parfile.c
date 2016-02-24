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
        if      (line == 1) sscanf(buffer, "%lf", &(pars->u_latt_a));
        else if (line == 2) sscanf(buffer, "%lf", &(pars->u_latt_b));
        else if (line == 3) sscanf(buffer, "%lf", &(pars->u_latt_c));
        else if (line == 4) sscanf(buffer, "%d", &(pars->nh));
        else if (line == 5) sscanf(buffer, "%d", &(pars->nk));
        else if (line == 6) sscanf(buffer, "%d", &(pars->nl));
        else if (line == 7) sscanf(buffer, "%lf", &(pars->u_angle_a));
        else if (line == 8) sscanf(buffer, "%lf", &(pars->u_angle_b));
        else if (line == 9) sscanf(buffer, "%lf", &(pars->u_angle_g));
        else if (line == 10) sscanf(buffer, "%lf", &(pars->displac));
        else if (line == 11) {
            buffer_ptr=trim(buffer_ptr);
            pars->outfile1 = (char *)malloc(strlen(buffer_ptr)*sizeof(char));
            strcpy(pars->outfile1, buffer_ptr);
        }
        else if (line == 12) {
            buffer_ptr=trim(buffer_ptr);
            pars->outfile2 = (char *)malloc(strlen(buffer_ptr)*sizeof(char));
            strcpy(pars->outfile2, buffer_ptr);
        }
    }
    
    pars->nuatoms=line-12;
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
    
    rewind(FP);
    
    for (line=0; line < 12; line++) {
        buffer_ptr = fgets(buffer, MAX_LEN, FP);
        //		printf("line %d: %s", line, buffer);
    }
    
    for (line=0; line < pars->nuatoms; line++) {
        buffer_ptr = fgets(buffer, MAX_LEN, FP);
        //		printf("line %d: %s", line, buffer);if (fclose(FP)) {
        //		printf("line: %d\n", line);	perror("\n***   read_parfile:fclose(FP) failed");
        sscanf(buffer, "%d" "%s" "%d" "%lf" "%lf" "%lf", &(pars->u_atom[line]->n), pars->u_atom[line]->esymb, &(pars->u_atom[line]->atn), &(pars->u_atom[line]->pnt.x), &(pars->u_atom[line]->pnt.y), &(pars->u_atom[line]->pnt.z));
    }
    
    return pars;
}
