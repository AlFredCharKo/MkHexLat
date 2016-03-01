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
    vec u_latt;
    int nh;
    int nk;
    int nl;
    vec u_angle;
    double displac;
    vec hex_origin;
    double hex_side;
    double hex_height;
    char *parfile;
    char *outfile1;
    int nuatoms;
    atom **u_atom;
} parameters;

#endif
