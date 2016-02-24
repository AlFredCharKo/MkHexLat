//
//  print_pars.c
//  mklatc
//
//  Created by Alexander Kompch on 09.06.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#include "print_pars.h"

int print_pars(parameters *pars)
{
    int i=0;
    
    printf("\n***   IN print_pars   ***\n");
    
    printf("\nparameters read from <%s>", pars->parfile);
    printf("\nlattice parameters:");
    printf("\na \t b \t c \t alpha \t beta \t gamma");
    printf("\n%9.6f %9.6f %9.6f %10.6f %10.6f %10.6f",pars->u_latt_a, pars->u_latt_b, pars->u_latt_c, pars->u_angle_a, pars->u_angle_b, pars->u_angle_g);
    printf("\ndisplacement factor: %10.6f", pars->displac);
    printf("\nbox dimensions: %d x %d x %d", pars->nh, pars->nk, pars->nl);
    printf("\noutput filename1: <%s>", pars->outfile1);
    printf("\noutput filename2: <%s>", pars->outfile2);
    
    for (i=0; i<pars->nuatoms; i++) {
        printf("\n%d %2s %2d %8.6f %8.6f %8.6f", pars->u_atom[i]->n, pars->u_atom[i]->esymb, pars->u_atom[i]->atn, pars->u_atom[i]->pnt.x, pars->u_atom[i]->pnt.y, pars->u_atom[i]->pnt.z);
    }
    printf("\n");
    return EXIT_SUCCESS;
}