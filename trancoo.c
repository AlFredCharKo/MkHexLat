//
//  trancoo.c
//  mklatc
//
//  Created by Alexander Kompch on 09.06.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#include "trancoo.h"

coords* trancoo(coords *crystcoo, gsl_matrix *Mat) {
    coords *trancoo=NULL;
    atom **at=NULL;
    int i=0;
    //	int h=0, k=0, l=0, i=0;
    //	double boxh=0.0, boxk=0.0, boxl=0.0;
    
    //	nuatoms = pars->nuatoms * pars->nh * pars->nk * pars->nl;
    printf("\n***in trancoo*** nuatoms=%d", crystcoo->nat);
    trancoo = (coords*)malloc(sizeof(coords));
    if (trancoo == NULL) {
        printf("\n***   trancoo: malloc trancoo failed");
        return NULL;
    }
    trancoo->nat=crystcoo->nat;
    trancoo->atom_ptr = (atom**)malloc(trancoo->nat*sizeof(atom*));
    if (trancoo->atom_ptr == NULL) {
        printf("\n***   tranoo: malloc trancoo->atom_ptr failed");
        return NULL;
    }
    at = (atom**)malloc(trancoo->nat*sizeof(atom*));
    if (at == NULL) {
        printf("\n***   trancoo: malloc at failed");
        return NULL;
    }
    for (i=0;i<trancoo->nat;i++) {
        at[i]=(atom*)malloc(sizeof(atom));
        if (at[i] == NULL) {
            printf("\n***   trancoo: malloc at[%d] failed",i);
            return NULL;
        }
        trancoo->atom_ptr[i]=at[i];
    }
    
    for(i=0;i<trancoo->nat;i++) {
        at[i]->n = i+1;
        strcpy(at[i]->esymb ,crystcoo->atom_ptr[i]->esymb);
        at[i]->atn = crystcoo->atom_ptr[i]->atn;
        at[i]->pnt.x = crystcoo->atom_ptr[i]->pnt.x * gsl_matrix_get(Mat,0,0) + crystcoo->atom_ptr[i]->pnt.y * gsl_matrix_get(Mat,1,0) + crystcoo->atom_ptr[i]->pnt.z * gsl_matrix_get(Mat,2,0);
        at[i]->pnt.y = crystcoo->atom_ptr[i]->pnt.y * gsl_matrix_get(Mat,1,1) + crystcoo->atom_ptr[i]->pnt.z * gsl_matrix_get(Mat,2,1);
        at[i]->pnt.z = crystcoo->atom_ptr[i]->pnt.z * gsl_matrix_get(Mat,2,2);						
    }
    //include boxlength into coords struct and use Mat main diagonal (0,0), (1,1), (2,2)
    trancoo->boxL.x = gsl_matrix_get(Mat,0,0);
    trancoo->boxL.y = gsl_matrix_get(Mat,1,1);
    trancoo->boxL.z = gsl_matrix_get(Mat,2,2);
    return trancoo;
}
