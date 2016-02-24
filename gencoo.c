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
    atom **at=NULL;
    int nuatoms=0;
    int h=0, k=0, l=0, i=0;
    double boxh=0.0, boxk=0.0, boxl=0.0, displac;
    vec rand;
    gsl_rng *T;
    
    //initialize rnd generator
    T = gsl_rng_alloc (gsl_rng_taus);
    
    nuatoms = pars->nuatoms * pars->nh * pars->nk * pars->nl;
    printf("\n***in gencoo*** nuatoms=%d", nuatoms);
    crystcoo = (coords*)malloc(sizeof(coords));
    if (crystcoo == NULL) {
        printf("\n***   gencoo: malloc crystcoo failed");
        return NULL;
    }
    crystcoo->nat=nuatoms;
    crystcoo->atom_ptr = (atom**)malloc(crystcoo->nat*sizeof(atom*));
    if (crystcoo->atom_ptr == NULL) {
        printf("\n***   gencoo: malloc crystcoo->atom_ptr failed");
        return NULL;
    }
    at = (atom**)malloc(crystcoo->nat*sizeof(atom*));
    if (at == NULL) {
        printf("\n***   gencoo: malloc at failed");
        return NULL;
    }
    for (i=0;i<crystcoo->nat;i++) {
        at[i]=(atom*)malloc(sizeof(atom));
        if (at[i] == NULL) {
            printf("\n***   gencoo: malloc at[%d] failed",i);
            return NULL;
        }
        crystcoo->atom_ptr[i]=at[i];
    }
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
                    at[i]->n = i+1;
                    strcpy(at[i]->esymb ,pars->u_atom[nuatoms]->esymb);
                    at[i]->atn = pars->u_atom[nuatoms]->atn;
                    at[i]->pnt.x = pars->u_atom[nuatoms]->pnt.x + (double)h + 2.0 * displac * (rand.x - 0.5);
                    at[i]->pnt.y = pars->u_atom[nuatoms]->pnt.y + (double)k + 2.0 * displac * (rand.y - 0.5);
                    at[i]->pnt.z = pars->u_atom[nuatoms]->pnt.z + (double)l + 2.0 * displac * (rand.z - 0.5);
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
        at[i]->pnt.x = at[i]->pnt.x/boxh;
        at[i]->pnt.y = at[i]->pnt.y/boxk;
        at[i]->pnt.z = at[i]->pnt.z/boxl;
        at[i]->pnt.x = at[i]->pnt.x - anint(at[i]->pnt.x);
        at[i]->pnt.y = at[i]->pnt.y - anint(at[i]->pnt.y);
        at[i]->pnt.z = at[i]->pnt.z - anint(at[i]->pnt.z);
    }
    crystcoo->boxL.x = (double)pars->nh * pars->u_latt_a;
    crystcoo->boxL.y = (double)pars->nk * pars->u_latt_b;
    crystcoo->boxL.z = (double)pars->nl * pars->u_latt_c;
    return crystcoo;
}
