//
//  adding.c
//  last_katka
//
//  Created by Данил Морозов on 19/05/2020.
//  Copyright © 2020 Данил Морозов. All rights reserved.
//

#include "adding.h"


int adding(Labirint* l) {
    printf("какой тип элемента вы хотите добавить?\nType - 1 - коридорчик\nType - 7 – дверь\nType – 8 – перекресток\nType – 3 - тупик\n");
    int type;
    scanf("%d", &type);
    int i = 1;
    while (i-- > 0) {
        if (type == 1) {
            if (l->n < 2) {
                printf("малова-то вершин(нечего соединять)\n");
                return (1);
            }
            add_line(l);
            return 0;
        }
        if ((type == 7) || (type == 8) || (type == 3)) {
            add_node(l, type);
            return 0;
        }
    }
    printf("введена неизвестная команда\n");
    return 1;
}
