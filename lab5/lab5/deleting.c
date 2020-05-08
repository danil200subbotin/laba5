//
//  deleting.c
//  lab5
//
//  Created by Данил Морозов on 05/05/2020.
//  Copyright © 2020 Данил Морозов. All rights reserved.
//

#include "deleting.h"
#include <stdlib.h>

int deleting(Graph * graph) {
    int x, y;
    Node *ukazka = graph->root;
    printf("добро пожаловать в функцию удаления\n");
    printf("введите ключ X\n");
    scanf("%d", &x);
    printf("введите ключ Y\n");
    scanf("%d", &y);
    int n = 0;
    while (n == 0) {
    if (ukazka->type == 0) {
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
    else {
        n = 1;
        for (int h = 0; (ukazka->leaves[h] != NULL) & (h < N); ++h) {
            if ((ukazka->leaves[h]->x == x) & (ukazka->leaves[h]->y == y)) {
                printf("нашелся такой элементик, удаляю\n");
                free(ukazka->leaves[h]->info);
                ukazka->leaves[h] = NULL;
                }
            }
        }
    }
    
    return 0;
}
