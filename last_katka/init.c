//
//  init.c
//  last_katka
//
//  Created by Данил Морозов on 19/05/2020.
//  Copyright © 2020 Данил Морозов. All rights reserved.
//

#include "init.h"

int init (Labirint* labirint) {
    printf("начинаю инициализацию лабиринта\n");
    labirint->n = 0;
    labirint->down = NULL;
    return 0;
}
