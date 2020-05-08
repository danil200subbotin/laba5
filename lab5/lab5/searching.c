//
//  searching.c
//  lab5
//
//  Created by Данил Морозов on 05/05/2020.
//  Copyright © 2020 Данил Морозов. All rights reserved.
//

#include "searching.h"

int searching(Graph *graph) {
    int x, y;
    printf("введите ключ Х------>");
    scanf("%d", &x);
    printf("введите ключ Y------>");
    scanf("%d", &y);
    printf("запустил поиск по ключам х=%d, y=%d\n", x, y);
    Node* ukazka = graph->root;
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
    printf("перешел на листик");
    List *list = ukazka->leaves[0];
    int n = 0;
    while (list != NULL) {
        if ((ukazka->leaves[n]->x == x) & (ukazka->leaves[n]->y == y)) {
            printf("удачный поиск по ключам, информация ----->%s\n", list->info);
            ++n;
            break;
        }
    }
    if (n == 0) printf("неудачный поиск по ключам\n");
return 0;
}
