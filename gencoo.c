//
//  gencoo.c
//  mklatc
//
//  Created by Alexander Kompch on 09.06.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#include "gencoo.h"

coords* gencoo(parameters *pars) {
    coords *crystcoo=NULL;
    int nuatoms=0;
    int h=0, k=0, l=0, i=0;
    double boxh=0.0, boxk=0.0, boxl=0.0, displac;
    vec rand, boxL;
    gsl_rng *T;
    
    //initialize rnd generator
    T = gsl_rng_alloc (gsl_rng_taus);
    
    
    //initialize crystcoo to hold coordinates, atomic numbers and element symbols for crystal in crystal's native coordinates
    nuatoms = pars->nuatoms * pars->nh * pars->nk * pars->nl;
    boxL.x = (double)pars->nh * pars->u_latt.x;
    boxL.y = (double)pars->nk * pars->u_latt.y;
    boxL.z = (double)pars->nl * pars->u_latt.z;
    crystcoo = init_coords(crystcoo, nuatoms, boxL);
    

    displac = pars->displac;
    i=0;
    for (h=0;h<pars->nh;h++) {
        for (k=0;k<pars->nk;k++) {
            for (l=0;l<pars->nl;l++) {
                for (nuatoms=0;nuatoms<pars->nuatoms;nuatoms++) {
                    //make 3 random double ]0;1[
                    rand.x = gsl_rng_uniform_pos(T);
                    rand.y = gsl_rng_uniform_pos(T);
                    rand.y = gsl_rng_uniform_pos(T);
                    crystcoo->atom_ptr[i]->n = i+1;
                    strcpy(crystcoo->atom_ptr[i]->esymb ,pars->u_atom[nuatoms]->esymb);
                    crystcoo->atom_ptr[i]->atn = pars->u_atom[nuatoms]->atn;
                    crystcoo->atom_ptr[i]->pnt.x = pars->u_atom[nuatoms]->pnt.x + (double)h + 2.0 * displac * (rand.x - 0.5);
                    crystcoo->atom_ptr[i]->pnt.y = pars->u_atom[nuatoms]->pnt.y + (double)k + 2.0 * displac * (rand.y - 0.5);
                    crystcoo->atom_ptr[i]->pnt.z = pars->u_atom[nuatoms]->pnt.z + (double)l + 2.0 * displac * (rand.z - 0.5);
                    //					printf("\n***in gencoo: i=%d",i);
                    i++;
                }
            }
        }
    }
    
    //	canonical coordinates [-0.5,+0.5[
    boxh=(double)pars->nh;
    boxk=(double)pars->nk;
    boxl=(double)pars->nl;
    for (i=0;i<crystcoo->nat; i++) {
        crystcoo->atom_ptr[i]->pnt.x = crystcoo->atom_ptr[i]->pnt.x/boxh;
        crystcoo->atom_ptr[i]->pnt.y = crystcoo->atom_ptr[i]->pnt.y/boxk;
        crystcoo->atom_ptr[i]->pnt.z = crystcoo->atom_ptr[i]->pnt.z/boxl;
        crystcoo->atom_ptr[i]->pnt.x = crystcoo->atom_ptr[i]->pnt.x - anint(crystcoo->atom_ptr[i]->pnt.x);
        crystcoo->atom_ptr[i]->pnt.y = crystcoo->atom_ptr[i]->pnt.y - anint(crystcoo->atom_ptr[i]->pnt.y);
        crystcoo->atom_ptr[i]->pnt.z = crystcoo->atom_ptr[i]->pnt.z - anint(crystcoo->atom_ptr[i]->pnt.z);
    }
    return crystcoo;
}
