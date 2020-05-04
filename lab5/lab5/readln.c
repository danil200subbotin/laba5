//
//  readln.c
//  lab5
//
//  Created by Данил Морозов on 04/05/2020.
//  Copyright © 2020 Данил Морозов. All rights reserved.
//

#include "readln.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *readln(void) {
    //while (scanf("%*c") != 0);
    char *ptr = (char *)malloc(1);
    *ptr = '\0';
    char buf[101];
    int n, len = 0;
    do {
        n = scanf("%100[^\n]", buf);
        //printf("buff = %s\n",buf);
        if(n < 0){
            free(ptr);
            ptr = NULL;
            continue;
        }
        if(n == 0)
            scanf("%*c");
        else {
            len += strlen(buf);
           // printf("len = %d\n",len);
            ptr = (char *) realloc(ptr, len + 1);
            strcat(ptr, buf);
        }
    } while(n > 0);
    return ptr;
}
