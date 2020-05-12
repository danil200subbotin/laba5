//
//  Timing.c
//  lab5
//
//  Created by Данил Морозов on 12/05/2020.
//  Copyright © 2020 Данил Морозов. All rights reserved.
//

#include "Timing.h"

int Timing (Graph * g) {
    Graph *graph = (Graph *)calloc(1, sizeof(Graph));
    graph->root = (Node *)calloc(1, sizeof(Node));
    graph->n = 0;
    for (int i = 0; i < N; ++i) {
        graph->root->leaves[i] = NULL;
    };
    printf("запускаем таймирование\nинициализирую новый граф\n");
    int n = 10, key_x[10000], key_y[10000], x, y, cnt = 1000000, i, m;
    clock_t first, last;
    srand((int)time(NULL));
    while (n-- > 0){
        for (i = 0; i < 10000; ++i)
            key_x[i] = abs(rand() * rand()) % UGOL;
            key_y[i] = abs(rand() * rand()) % UGOL;
        for (i = 0; i < cnt; ){
            x = abs(rand() * rand()) % UGOL;
            y = abs(rand() * rand()) % UGOL;//int perehod(int x, int y,char* info, Node* ukazka, Graph* graph);
            if (perehod(x, y, "1", graph->root, graph))
            ++i;
        }
        printf("забил дерево\n");
        m = 0;
        first = clock();
        for (i = 0; i < 10000; ++i)
        if (!(fortimer(key_y[i], key_x[i], graph->root)))
        ++m;
        last = clock();
        printf("%d items was found\n", m);
        printf("test #%d, number of nodes = %d, time = %d\n", 10 - n, (10 -
        n)*cnt, (int)(last - first));
        }
    delGraph(graph->root);
    printf("удалил граф\n");
    return 1;
    }
