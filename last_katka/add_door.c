//
//  add_door.c
//  last_katka
//
//  Created by Данил Морозов on 19/05/2020.
//  Copyright © 2020 Данил Морозов. All rights reserved.
//

#include "add_door.h"


int add_door(Labirint* l) {
    printf("введите координаты двери");
    int x = 0, y = 0, name = -1;
    printf("Начинаем вводить новый элемент\n");
    printf("введите ключ 1 (ось X)----->");
    scanf("%d", &x);
    printf("введите ключ 2 (ось Y)----->");
    scanf("%d", &y);
    printf("введите желаемое имя для вершины\n");
    scanf("%d", &name);
    NodeV *main = NULL;
    main = l->down;
    while (main != NULL) {
        if ((main->x = x) & (main->y = y)) {
            printf("запрещаю данное сочетание ключей");
            return 1;
        }
        main = main->down;
    }
    main = (NodeV* )calloc(1, sizeof(NodeV));
    main->name = name;
    main->x = x;
    main->y = y;
    main->type = 3;
    if (l->n == 0) {
        l->down = main;
        main->down = NULL;
        ++(l->n);
        return 0;
    }
    NodeV *helper = NULL;
    helper = l->down;
    l->down = main;
    main->down = helper;
    ++(l->n);
    return 0;
}
