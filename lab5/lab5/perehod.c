//
//  perehod.c
//  lab5
//
//  Created by Данил Морозов on 11/05/2020.
//  Copyright © 2020 Данил Морозов. All rights reserved.
//

#include "perehod.h"


int perehod(int x, int y,char* info, Node* ukazka, Graph* graph) {
    if (graph->n == 0) {
        graph->root->type = 1;
        graph->root->gran_x = UGOL/2;
        graph->root->gran_y= UGOL/2;
        graph->root->max_x = UGOL;
        graph->root->max_y = UGOL;
        graph->root->min_x = 0;
        graph->root->min_y = 0;
        for (int i = 0; i < N; ++i) {
            graph->root->leaves[i] = NULL;
        }
    }
   // printf("вставляю %d, %d\n", x, y);
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
            int chek = vstavka(x, y, info, ukazka);
            if (chek == 0) {
        //        printf("вставка прошла успешно\n");
                ++(graph->n);
                return 1;
            } else {
                return 0;
            }
        }
        
    }
    return 1;
}
