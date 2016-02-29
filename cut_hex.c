//
//  cut_hex.c
//  MkHexLat
//
//  Created by Alexander Kompch on 26.02.16.
//  Copyright (c) 2016 Alexander Kompch. All rights reserved.
//

#include "cut_hex.h"

coords* cut_hex(coords *given, parameters *pars) {
    coords *temp = NULL;
    coords *hex = NULL;
    int i = 0, counter = 0;
    double ic = 0.0, oc = 0.0;
    
        //coords given will be copied to coord temp
    temp = init_coords(temp, given->nat, given->boxL);
    if (temp == NULL) {
        printf("\n***   cut_hex: could not allocate temp");
        return NULL;
    }
        //coord hex is same size as given and temp and will hold only atoms found to in hexagon (coord hex is actually over allocated)
    hex = init_coords(temp, given->nat, given->boxL);
    if (hex == NULL) {
        printf("\n***   cut_hex: could not allocate temp");
        return NULL;
    }
    
    if (cp_coords(given, temp) == EXIT_FAILURE) {
        printf("\n***   cut_hex: could not copy coordinates");
        return NULL;
    }
    
    if (move2center(temp, pars->hex_origin) != EXIT_SUCCESS) {
        printf("\n***   cut_hex: move2center failed");
        return NULL;
    }
    
    
    ic = pars->hex_side * M_SQRT3 * 0.5;
    oc = pars->hex_side;
    counter = 0;
    for (i=0; i<temp->nat; i++) {
        if (lvec(temp->atom_ptr[i]->pnt) <= ic) {
            counter++;
            cp_atom(temp->atom_ptr[i], hex->atom_ptr[counter], counter);
            continue;
        } else if (lvec(temp->atom_ptr[i]->pnt) > oc) {
            continue;
        } else if ((-1.0 * oc / 2.0) <= temp->atom_ptr[i]->pnt.x && temp->atom_ptr[i]->pnt.x <= (oc / 2.0) && temp->atom_ptr[i]->pnt.y <= ic) {
            counter++;
            cp_atom(temp->atom_ptr[i], hex->atom_ptr[counter], counter);
            continue;
        } else if (temp->atom_ptr[i]->pnt.y >= 0.0 && temp->atom_ptr[i]->pnt.x > 0.0 && hex_f1(temp->atom_ptr[i]->pnt.x, oc) >= temp->atom_ptr[i]->pnt.y) {
                counter++;
                cp_atom(temp->atom_ptr[i], hex->atom_ptr[counter], counter);
                continue;
        } else if (temp->atom_ptr[i]->pnt.y >= 0.0 && temp->atom_ptr[i]->pnt.x < 0.0 && hex_f2(temp->atom_ptr[i]->pnt.x, oc) >= temp->atom_ptr[i]->pnt.y) {
            counter++;
            cp_atom(temp->atom_ptr[i], hex->atom_ptr[counter], counter);
            continue;
        } else if (temp->atom_ptr[i]->pnt.y < 0.0 && temp->atom_ptr[i]->pnt.x > 0.0 && hex_f3(temp->atom_ptr[i]->pnt.x, oc) <= temp->atom_ptr[i]->pnt.y) {
            counter++;
            cp_atom(temp->atom_ptr[i], hex->atom_ptr[counter], counter);
            continue;
        } else if (temp->atom_ptr[i]->pnt.y < 0.0 && temp->atom_ptr[i]->pnt.x < 0.0 && hex_f4(temp->atom_ptr[i]->pnt.x, oc) <= temp->atom_ptr[i]->pnt.y) {
            counter++;
            cp_atom(temp->atom_ptr[i], hex->atom_ptr[counter], counter);
            continue;
        }
    }
    
    free_coords(temp);
    
        //allocate new temp for just as many atoms as were found to be in hexagon
    temp = init_coords(temp, counter, given->boxL);
    if (temp == NULL) {
        printf("\n***   cut_hex: could not allocate temp");
        return NULL;
    }
        //copy from hex to temp only the number of atoms that were found in hexagon and skip the remainder
    if (cp_ncoords(hex, temp, counter) == EXIT_FAILURE) {
        printf("\n***   cut_hex: could not copy coordinates");
        return NULL;
    }
    
    free_coords(hex);
    return temp;
}


    // the following functions hex_f1 to hex_f4 return the y-values of line 1, 2, 3, 4 of a hexagon's sides
    // which are not parallel to the x-axis.
    // f1 and f3 are the sides for x > 0
    // f2 and f4 are the sides for x < 0


double hex_f1(double x, double a) {
    double y = 0.0;
    
    y = M_SQRT3 * (a - x);
    
    return y;
}

double hex_f2(double x, double a) {
    double y = 0.0;
    
    y = M_SQRT3 * (x + a);
    
    return y;
}

double hex_f3(double x, double a) {
    double y = 0.0;
    
    y = M_SQRT3 * (x - a);
    
    return y;
}

double hex_f4(double x, double a) {
    double y = 0.0;
    
    y = -1.0 * M_SQRT3 * (x + a);
    
    return y;
}