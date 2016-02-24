//
//  structs.h
//  mklatc
//
//  Created by Alexander Kompch on 03.06.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#ifndef mklatc_structs_h
#define mklatc_structs_h

//typedefstructs
typedef struct {
    double x;
    double y;
    double z;
} vec;

typedef struct {
    int n;
    char esymb[2];
    int atn;
    vec pnt;
} atom;

typedef struct {
    int nat;
    vec boxL;
    atom **atom_ptr;
} coords;

typedef struct {
    double u_latt_a;
    double u_latt_b;
    double u_latt_c;
    int nh;
    int nk;
    int nl;
    double u_angle_a;
    double u_angle_b;
    double u_angle_g;
    double displac;
    char *parfile;
    char *outfile1;
    char *outfile2;
    int nuatoms;
    atom **u_atom;
} parameters;

#endif
