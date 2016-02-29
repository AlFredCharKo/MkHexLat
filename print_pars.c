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
    printf("\n%9.6f %9.6f %9.6f %10.6f %10.6f %10.6f",pars->u_latt.x, pars->u_latt.y, pars->u_latt.z, pars->u_angle.x, pars->u_angle.y, pars->u_angle.z);
    printf("\ndisplacement factor: %10.6f", pars->displac);
    printf("\nbox dimensions: %d x %d x %d", pars->nh, pars->nk, pars->nl);
    printf("cut hexagon with side a = %9.6f around %9.6f %9.6f %9.6f", pars->hex_side, pars->hex_origin.x, pars->hex_origin.y, pars->hex_origin.z);
    printf("\noutput filename1: <%s>", pars->outfile1);

    
    for (i=0; i<pars->nuatoms; i++) {
        printf("\n%d %2s %2d %8.6f %8.6f %8.6f", pars->u_atom[i]->n, pars->u_atom[i]->esymb, pars->u_atom[i]->atn, pars->u_atom[i]->pnt.x, pars->u_atom[i]->pnt.y, pars->u_atom[i]->pnt.z);
    }
    printf("\n");
    return EXIT_SUCCESS;
}