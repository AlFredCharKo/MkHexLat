//
//  handle_cmdlargs.c
//  MkHexLat
//
//  Created by Alexander Kompch on 26.02.16.
//  Copyright (c) 2016 Alexander Kompch. All rights reserved.
//

#include "handle_cmdlargs.h"


char* handle_cmdlargs(int argc, const char *argv[]) {
    
    char *parfile=NULL;			//pointer to name of parameter file to read in

    if (argc < 2) {
        parfile=(char*)malloc((strlen(DEFPARFILE)+1)*sizeof(char));
        if (parfile == NULL) {
            printf("\n***   handle_cmdlargs: malloc parfile failed");
            return NULL;
        }
        printf("\n***   handle_cmdlargs: strlen('DEFPARFILE')*sizeof(char)=%zu",strlen(DEFPARFILE)*sizeof(char));
        strcpy(parfile,DEFPARFILE);
    } else {
        parfile=(char*)malloc((strlen(argv[1])+1)*sizeof(char));
        if (parfile == NULL) {
            printf("\n***   handle_cmdlargs: malloc parfile failed");
            return NULL;
        }
        printf("\n***   handle_cmdlargs: strlen(argv[1])*sizeof(char)=%zu",strlen(argv[1])*sizeof(char));
        strcpy(parfile,argv[1]);
    }
    
    printf("\n***   handle_cmdlargs: parfile=%s",parfile);
    return parfile;
}
