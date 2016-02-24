//
//  print_matrix.c
//  mklatc
//
//  Created by Alexander Kompch on 09.06.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#include "print_matrix.h"

int print_matrix(gsl_matrix *Mat) {
    printf("\n***MATRIX***");
    printf("\n%11.6f %11.6f %11.6f", gsl_matrix_get (Mat, 0, 0), gsl_matrix_get (Mat, 0, 1) ,gsl_matrix_get (Mat, 0, 2));
    printf("\n%11.6f %11.6f %11.6f", gsl_matrix_get (Mat, 1, 0), gsl_matrix_get (Mat, 1, 1) ,gsl_matrix_get (Mat, 1, 2));
    printf("\n%11.6f %11.6f %11.6f", gsl_matrix_get (Mat, 2, 0), gsl_matrix_get (Mat, 2, 1) ,gsl_matrix_get (Mat, 2, 2));
    return EXIT_SUCCESS;
}
