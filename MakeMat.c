//
//  MakeMat.c
//  mklatc
//
//  Created by Alexander Kompch on 09.06.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#include "MakeMat.h"

gsl_matrix *MakeMat(parameters *pars) {
    gsl_matrix *Mat = gsl_matrix_calloc (3,3);
    double caxes[3], cosvals[3], sinvals[3], cstars[3], cosvalas[3];
    double volume;
    
    //	real space length of lattice to be produced
    caxes[0]=pars->nh * pars->u_latt.x;
    caxes[1]=pars->nk * pars->u_latt.y;
    caxes[2]=pars->nl * pars->u_latt.z;
    //  real space cosine values of unit cell angles
    cosvals[0]=cos(pars->u_angle.x / 180.0 * M_PI);
    cosvals[1]=cos(pars->u_angle.y / 180.0 * M_PI);
    cosvals[2]=cos(pars->u_angle.z / 180.0 * M_PI);
    //  real space sine values of unit cell angles
    sinvals[0]=sin(pars->u_angle.x / 180.0 * M_PI);
    sinvals[1]=sin(pars->u_angle.y / 180.0 * M_PI);
    sinvals[2]=sin(pars->u_angle.z / 180.0 * M_PI);
    
    //	real space volume of unit cell
    volume = caxes[0] * caxes[1] * caxes[2];
    volume = volume * sqrt(1.0 - cosvals[0] * cosvals[0] - cosvals[1] * cosvals[1] - cosvals[2] * cosvals[2] + 2.0 * cosvals[0] * cosvals[1] * cosvals[2]);
    //  reciprocal length of lattice axes (a*,b*,c*)
    cstars[0] = caxes[1] * caxes[2] * sinvals[0] / volume;
    cstars[1] = caxes[0] * caxes[2] * sinvals[1] / volume;
    cstars[2] = caxes[0] * caxes[1] * sinvals[2] / volume;
    //	reciprocal space cosine values of unit cell angles cos(alpha*), cos(beta*), cos(gamma*))
    cosvalas[0] = (cosvals[1] * cosvals[2] - cosvals[0]) / (sinvals[1] * sinvals[2]);
    cosvalas[1] = (cosvals[0] * cosvals[2] - cosvals[1]) / (sinvals[0] * sinvals[2]);
    cosvalas[2] = (cosvals[0] * cosvals[1] - cosvals[2]) / (sinvals[0] * sinvals[1]);
    
    
    //	Matrix elements for M-1 to use in A=M-1*E (gia92a p.68)
    gsl_matrix_set (Mat, 0, 0, caxes[0]);
    gsl_matrix_set (Mat, 0, 1, 0.0);
    gsl_matrix_set (Mat, 0, 2, 0.0);
    gsl_matrix_set (Mat, 1, 0, caxes[1] * cosvals[2]);
    gsl_matrix_set (Mat, 1, 1, caxes[1] * sinvals[2]);
    gsl_matrix_set (Mat, 1, 2, 0.0);
    gsl_matrix_set (Mat, 2, 0, caxes[2] * cosvals[1]);
    gsl_matrix_set (Mat, 2, 1, -caxes[2] * sinvals[1] * cosvalas[0]);
    gsl_matrix_set (Mat, 2, 2, 1/cstars[2]);
    
    //	Matrix elements for M to use in E=M*A (gia92a p.68)
    //	gsl_matrix_set (Mat, 0, 0, 1/caxes[0]);
    //	gsl_matrix_set (Mat, 0, 1, 0.0);
    //	gsl_matrix_set (Mat, 0, 2, 0.0);
    //  gsl_matrix_set (Mat, 1, 0, -cosvals[2]/(caxes[0] * sinvals[2]));
    //	gsl_matrix_set (Mat, 1, 1, 1/(caxes[1] * sinvals[2]));
    //	gsl_matrix_set (Mat, 1, 2, 0.0);
    //	gsl_matrix_set (Mat, 2, 0, cstars[0] * cosvalas[1]);
    //	gsl_matrix_set (Mat, 2, 1, cstars[1] * cosvalas[0]);
    //	gsl_matrix_set (Mat, 2, 2, cstars[2]);
    
    
    return Mat;
    
}
