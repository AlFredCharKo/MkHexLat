//
//  main.c
//  mklatc
//
//  Created by Alexander Kompch on 03.06.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#include "main.h"

int main(int argc, const char * argv[]) {
    
    printf("\n***   main:argc=%d", argc);
    
    char *parfile = handle_cmdlargs(argc, argv);
    parameters *pars=read_parfile(parfile);
    if (pars == NULL) {
        printf("\n***   main: read_parfile failed! Will exit!");
        exit(EXIT_FAILURE);
    }
    
    print_pars(pars);
    
    gsl_matrix *Mat=MakeMat(pars);
    print_matrix(Mat);
    
    coords *crystcoo=gencoo(pars);
    char *filename = append_filename(pars->outfile1, ".cryst", ".coo");
    write_coo(filename, crystcoo);
    
    coords *cartcoo=trancoo(crystcoo, Mat);
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
    
    coords *hexcoo=cut_hex(cartcoo, pars);
    filename = append_filename(pars->outfile1, ".hex", ".coo");
    write_coo(filename, hexcoo);
    free(filename);
    filename = append_filename(pars->outfile1, ".hex", ".pdb");
    write_pdb(filename, hexcoo);
    free(filename);
    filename = append_filename(pars->outfile1, ".hex", ".gnu");
    write_gnuplot(filename, hexcoo);
    
    free(filename);
    gsl_matrix_free (Mat);
    free(parfile);

    pars_free(pars);
    coords_free(crystcoo);
    coords_free(cartcoo);
    coords_free(hexcoo);
    
    printf("\n");
    return EXIT_SUCCESS;
}

