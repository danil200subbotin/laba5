//
//  adding.c
//  lab5
//
//  Created by Данил Морозов on 05/05/2020.
//  Copyright © 2020 Данил Морозов. All rights reserved.
//

#include "adding.h"


int adding(Graph *graph) {
    printf("сейчас в графе %d узлов\n", graph->n);
    int x = 0, y = 0;
    printf("Начинаем вводить новый элемент\n");
    printf("введите ключ 1 (ось X)----->");
    scanf("%d", &x);
    printf("введите ключ 2 (ось Y)----->");
    scanf("%d", &y);
    //printf("введите информацию");
    char* info = readln();
    Node* ukazka = graph->root;
    perehod(x, y, info, ukazka, graph);
    return 0;
};
