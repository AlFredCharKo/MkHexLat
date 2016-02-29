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
    write_coo(pars->outfile1, crystcoo);
    
    cartcoo=trancoo(crystcoo, Mat);
    write_coo(pars->outfile2, cartcoo);
    write_pdb(pars->outfile2, cartcoo);
    write_gnuplot(pars->outfile2, cartcoo);
    
    hexcoo=cut_hex(cartcoo, pars);
    write_coo(pars->outfile2, hexcoo);
    write_pdb(pars->outfile2, hexcoo);
    write_gnuplot(pars->outfile2, hexcoo);
    
    free(parfile);
    free(pars);
    free(Mat);
    free_coords(crystcoo);
    free_coords(cartcoo);
    
    printf("\n");
    return EXIT_SUCCESS;
}

