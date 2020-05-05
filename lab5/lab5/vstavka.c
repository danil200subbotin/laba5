//
//  vstavka.c
//  lab5
//
//  Created by Данил Морозов on 05/05/2020.
//  Copyright © 2020 Данил Морозов. All rights reserved.
//

#include "vstavka.h"
#include "strukts.h"
#include <stdlib.h>

int vstavka(int x, int y, Node* ukazka) {
    if (ukazka->leaves[N-1] != NULL) {
        List* list = NULL;
        List* new = (List *)calloc(1, sizeof(List));
        new->x = x;
        new->y = y;
        for (int i = 0; i < N; ++i) {
            if ((x == ukazka->leaves[i]->x) & (y == ukazka->leaves[i]->y)) {
                printf("Запрещаю данное сочетание ключей!!!!!!\n");
                free(new);
                return -1;
            }
            if (x < ukazka->leaves[i]->x) {
                list = ukazka->leaves[i];
                ukazka->leaves[i] = new;
                
            }
        }
     }
    
    
}
