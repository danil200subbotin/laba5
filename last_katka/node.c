//
//  node.c
//  last_katka
//
//  Created by Данил Морозов on 25/05/2020.
//  Copyright © 2020 Данил Морозов. All rights reserved.
//

#include "node.h"



int node(Labirint* l, int x,int y,int type, int name) {
  //  printf("введите координаты будущей вершины");
    NodeV *main = NULL;
    main = l->down;
//    while (main != NULL) {
//        if ((main->x == x) & (main->y == y)) {
//            printf("запрещаю данное сочетание ключей");
//            return 1;
//        }
//        main = main->down;
//    }
    main = (NodeV* )calloc(1, sizeof(NodeV));
    main->name = name;
    main->colour = 0;
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
    return 1;
}
