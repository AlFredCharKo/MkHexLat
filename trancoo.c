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
    vec boxL;
    int i=0;

    //get boxlengths in cartesian x,y,z directions from Mat main diagonal (0,0), (1,1), (2,2)
    boxL.x = gsl_matrix_get(Mat,0,0);
    boxL.y = gsl_matrix_get(Mat,1,1);
    boxL.z = gsl_matrix_get(Mat,2,2);
    
    trancoo = init_coords(trancoo, crystcoo->nat, boxL);
    
    for(i=0;i<trancoo->nat;i++) {
        trancoo->atom_ptr[i]->n = i+1;
        strcpy(trancoo->atom_ptr[i]->esymb ,crystcoo->atom_ptr[i]->esymb);
        trancoo->atom_ptr[i]->atn = crystcoo->atom_ptr[i]->atn;
        trancoo->atom_ptr[i]->pnt.x = crystcoo->atom_ptr[i]->pnt.x * gsl_matrix_get(Mat,0,0) + crystcoo->atom_ptr[i]->pnt.y * gsl_matrix_get(Mat,1,0) + crystcoo->atom_ptr[i]->pnt.z * gsl_matrix_get(Mat,2,0);
        trancoo->atom_ptr[i]->pnt.y = crystcoo->atom_ptr[i]->pnt.y * gsl_matrix_get(Mat,1,1) + crystcoo->atom_ptr[i]->pnt.z * gsl_matrix_get(Mat,2,1);
        trancoo->atom_ptr[i]->pnt.z = crystcoo->atom_ptr[i]->pnt.z * gsl_matrix_get(Mat,2,2);						
    }

    return trancoo;
}
