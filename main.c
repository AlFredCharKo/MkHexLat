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
    char *parfile=NULL;			//pointer to name of parameter file to read in
    coords *crystcoo=NULL;
    coords *cartcoo=NULL;
    int i=0;
    
    printf("\n***   main:argc=%d", argc);
    if (argc < 2) {
        parfile=(char*)malloc(strlen(DEFPARFILE)*sizeof(char));
        if (parfile == NULL) {
            printf("\n***   main: malloc parfile failed");
            return EXIT_FAILURE;
        }
        printf("\n***   main: strlen('DEFPARFILE')*sizeof(char)=%zu",strlen(DEFPARFILE)*sizeof(char));
        strcpy(parfile,DEFPARFILE);
    } else {
        parfile=(char*)malloc(strlen(argv[1])*sizeof(char));
        if (parfile == NULL) {
            printf("\n***   main: malloc parfile failed");
            return EXIT_FAILURE;
        }
        printf("\n***   main: strlen(argv[1])*sizeof(char)=%zu",strlen(argv[1])*sizeof(char));
        strcpy(parfile,argv[1]);
    }
    
    printf("\n***   main: parfile=%s",parfile);
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
    
    free(parfile);
    free(pars);
    free(Mat);
    for (i=0;i<crystcoo->nat;i++) {
        free(crystcoo->atom_ptr[i]);
    }
    for (i=0;i<cartcoo->nat;i++) {
        free(cartcoo->atom_ptr[i]);
    }
    free(crystcoo);
    free(cartcoo);
    
    printf("\n");
    return EXIT_SUCCESS;
}

