//
//  Timing.c
//  last_katka
//
//  Created by Данил Морозов on 26/05/2020.
//  Copyright © 2020 Данил Морозов. All rights reserved.
//

#include "Timing.h"

int Timing (Labirint * q) {
    Labirint *l = (Labirint*)calloc(1, sizeof(Labirint));
    l->n = 0;
    l->down = NULL;
    printf("запускаем таймирование\nинициализирую новый лабиринт\n");
    int n = 50, key_x[10000], key_y[10000], x, type, y, cnt = 100, i, m;
    clock_t first, last, a, b;
    srand((int)time(NULL));
    while (n-- > 0){
        for (i = 0; i < 10000; ++i) {
            key_x[i] = abs(rand() * rand()) % UGOL;
            key_y[i] = abs(rand() * rand()) % UGOL;
        }
        //printf("1");
        a = clock();
        for (i = 0; i < cnt; ){
            x = abs(rand() * rand()) % UGOL;
            y = abs(rand() * rand()) % UGOL;
            type = abs(rand() * rand() % 3);
            if (type == 1) type = 7;
            if (type == 0) type = 3;
            if (type == 2) type = 8;//int perehod(int x, int y,char* info, Node* ukazka, Graph* graph);
            if (node(l, x, y, type, i)) ++i;
        }
        b = clock();
        //printf("забил дерево\n");
        m = 0;
        first = clock();
        for (i = 0; i < 10000; ++i)
            search_exit(l, i);
        last = clock();
     //   printf("%d items was found\n", m);
//      printf("test #%d, number of nodes = %d, time = %d\n", 30 - n, (30 - n)*cnt, (int)(last - first));
        printf("%d\t%d\n",(50 - n)*cnt, (int)(last - first));
  //      printf("время вставки %d\n", (int)(b-a));
        }
    DELETE_ALL(l);
    printf("удалил граф\n");
    return 1;
    }
