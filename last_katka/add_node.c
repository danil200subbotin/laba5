//
//  add_node.c
//  last_katka
//
//  Created by Данил Морозов on 20/05/2020.
//  Copyright © 2020 Данил Морозов. All rights reserved.
//

#include "add_node.h"
int add_node(Labirint* l, int type) {
  //  printf("введите координаты будущей вершины");
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
        if ((main->x == x) & (main->y == y)) {
            printf("запрещаю данное сочетание ключей");
            return 1;
        }
        main = main->down;
    }
    main = (NodeV* )calloc(1, sizeof(NodeV));
    main->name = name;
    main->x = x;
    main->y = y;
    main->prev = NULL;
    main->colour = 0;
    main->prev = NULL;
    main->type = type;
    main->up = NULL;
    if (l->n == 0) {
        l->down = main;
        main->down = NULL;
        ++(l->n);
        return 0;
    }
    NodeV *helper = NULL;
    helper = l->down;
    helper->up = main;
    l->down = main;
    main->down = helper;
    ++(l->n);
    return 0;
}
