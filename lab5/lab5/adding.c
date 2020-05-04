//
//  adding.c
//  lab5
//
//  Created by Данил Морозов on 05/05/2020.
//  Copyright © 2020 Данил Морозов. All rights reserved.
//

#include "adding.h"
#include "strukts.h"
#include "readln.h"

int adding(Graph *graph) {
    printf("сейчас в графе %d узлов\n", graph->n);
    switch (graph->n) {
    case 0:
            printf("Поздравляем, вы намереваетесь ввести свой первый элемент!\n");
            printf("введите ключ 1 (ось X)----->");
            scanf("%d", graph->root->leaves[0]->x);
            printf("введите ключ 2 (ось Y)----->");
            scanf("%d", graph->root->leaves[0]->y);
            printf("введите информацию для элемента----->");
            graph->root->leaves[0]->info = readln();
      break;
    default:
      /*Код, который выполнится, если ниодно из константых значению не соответствует значение в переменной variable*/
      break;
    }
};
