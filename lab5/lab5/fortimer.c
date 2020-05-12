//
//  fortimer.c
//  lab5
//
//  Created by Данил Морозов on 12/05/2020.
//  Copyright © 2020 Данил Морозов. All rights reserved.
//

#include "fortimer.h"


int fortimer (int x, int y, Node *ukazka) {
    while (ukazka->type == 0) {
        if (( x >= ukazka->gran_x) & (y >= ukazka->gran_y)) {
            ukazka = ukazka->sun[0];
            continue;
        }
        if (( x < ukazka->gran_x) & (y > ukazka->gran_y)) {
            ukazka = ukazka->sun[1];
            continue;
        }
        if (( x <= ukazka->gran_x) & (y <= ukazka->gran_y) & !((x == ukazka->gran_x) & (y == ukazka->gran_y))) {
            ukazka = ukazka->sun[2];
            continue;
        }
        if (( x > ukazka->gran_x) & (y < ukazka->gran_y)) {
            ukazka = ukazka->sun[3];
            continue;
        }
    }
    //printf("перешел на листик\n");
    
    
    
//    for (int i = 0; ukazka->leaves[i] != NULL; ++i) {
//        printf("ukazka-x%d-y%d.", ukazka->leaves[i]->x , ukazka->leaves[i]->y);
//
//    }
    int n = 0;
    for (int i = 0; ukazka->leaves[i] != NULL; ++i) {
     //   printf("последняя надежда ======%d======\n",i);
        if ((ukazka->leaves[i] != NULL) & (ukazka->leaves[i]->x == x) & (ukazka->leaves[i]->y == y)) {
        printf("удачный поиск по ключам, информация ----->%s\n", ukazka->leaves[i]->info);
            ++n;
            return 0;
        }
    }
//   if (n == 0) printf("неудачный поиск по ключам\n");
    return 1;
}
