//
//  lvec.c
//  MkHexLat
//
//  Created by Alexander Kompch on 29.02.16.
//  Copyright (c) 2016 Alexander Kompch. All rights reserved.
//

#include "lvec.h"

double lvecxyz(vec a) {
    double length = 0.0;
    
    length = sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
    
    return length;
}

double lvecxy(vec a) {
    double length = 0.0;
    
    length = sqrt(a.x * a.x + a.y * a.y);
    
    return length;
}