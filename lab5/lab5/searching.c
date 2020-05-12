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
    fortimer(x, y, ukazka);
return 0;
}
