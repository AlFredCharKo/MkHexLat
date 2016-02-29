//
//  main.c
//  mklatc
//
//  Created by Alexander Kompch on 03.06.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#include "main.h"

int main(int argc, const char * argv[]) {
    parameters *pars=NULL;      //pointer to be malloced to point to struct parameters holding all paramteres read from parfile
    gsl_matrix *Mat=NULL;		//pointer to gsl_matrix to be malloced to hold conversion Matrix elements calculated from unit cell parameters
    char *parfile;
    char *filename;
    coords *crystcoo=NULL;
    coords *cartcoo=NULL;
    coords *hexcoo=NULL;
    int i=0;
    
    printf("\n***   main:argc=%d", argc);
    
    parfile = handle_cmdlargs(argc, argv);
    pars=read_parfile(parfile);
    if (pars == NULL) {
        printf("\n***   main: read_parfile failed! Will exit!");
        exit(EXIT_FAILURE);
    }
    
    print_pars(pars);
    
    Mat=MakeMat(pars);
    print_matrix(Mat);
    
    crystcoo=gencoo(pars);
    filename = append_filename(pars->outfile1, ".cryst", ".coo");
    write_coo(filename, crystcoo);
    
    cartcoo=trancoo(crystcoo, Mat);
    free(filename);
    filename = append_filename(pars->outfile1, ".cart", ".coo");
    write_coo(filename, cartcoo);
    free(filename);
    filename = append_filename(pars->outfile1, ".cart", ".pdb");
    write_pdb(filename, cartcoo);
    free(filename);
    filename = append_filename(pars->outfile1, ".cart", ".gnu");
    write_gnuplot(filename, cartcoo);
    free(filename);
    
    hexcoo=cut_hex(cartcoo, pars);
    filename = append_filename(pars->outfile1, ".hex", ".coo");
    write_coo(filename, hexcoo);
    free(filename);
    filename = append_filename(pars->outfile1, ".hex", ".pdb");
    write_pdb(filename, hexcoo);
    free(filename);
    filename = append_filename(pars->outfile1, ".hex", ".gnu");
    write_gnuplot(filename, hexcoo);
    
    free(parfile);
    for (i=0; i<pars->nuatoms; i++) {
        free(pars->u_atom[i]);
    }
    free(pars->u_atom);
    free(pars);
    free(Mat);
    free_coords(crystcoo);
    free_coords(cartcoo);
    
    printf("\n");
    return EXIT_SUCCESS;
}

