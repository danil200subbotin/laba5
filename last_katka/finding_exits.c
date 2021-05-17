//
//  finding_exits.c
//  last_katka
//
//  Created by Данил Морозов on 24/05/2020.
//  Copyright © 2020 Данил Морозов. All rights reserved.
//

#include "finding_exits.h"


int finding_exits(Labirint * l) {
    printf("напишите имя вершины, от которой вы хотите найти выход!\n");
    int name;
    scanf("%d", &name);
    printf("запускаю поиск\n");
    search_exit(l, name);
    return 0;
}
