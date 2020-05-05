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
#include "vstavka.h"

int adding(Graph *graph) {
    printf("сейчас в графе %d узлов\n", graph->n);
    int x = 0, y = 0;
    switch (graph->n) {
    case 0:
            printf("Поздравляем, вы намереваетесь ввести свой первый элемент!\n");
            printf("введите ключ 1 (ось X)----->");
            scanf("%d", &(graph->root->leaves[0]->x));
            printf("введите ключ 2 (ось Y)----->");
            scanf("%d", &(graph->root->leaves[0]->y));
            printf("введите информацию для элемента----->");
            graph->root->leaves[0]->info = readln();
            graph->n = 1;
            graph->root->type = 1;
            graph->root->gran_x = -13;
            graph->root->gran_y= -13;
            for (int i = 1; i < N; ++i) {
                graph->root->leaves[i] = NULL;
            }
      break;
    default:
            printf("Начинаем вводить новый элемент\n");
            printf("введите ключ 1 (ось X)----->");
            scanf("%d", &x);
            printf("введите ключ 2 (ось Y)----->");
            scanf("%d", &y);
            int n = 0;
            Node* ukazka = graph->root;
            while (n == 0) {
                if (ukazka->type == 0) {
                    if (( x >= ukazka->gran_x) & (y >= ukazka->gran_y)) {
                        ukazka = ukazka->sun[0];
                        continue;
                    }
                    if (( x < ukazka->gran_x) & (y > ukazka->gran_y)) {
                        ukazka = ukazka->sun[1];
                        continue;
                    }
                    if (( x <= ukazka->gran_x) & (y <= ukazka->gran_y) & (x != ukazka->gran_x) & (y != ukazka->gran_y)) {
                        ukazka = ukazka->sun[2];
                        continue;
                    }
                    if (( x > ukazka->gran_x) & (y < ukazka->gran_y)) {
                        ukazka = ukazka->sun[3];
                        continue;
                    }
                }
                else {
                    n = 1;
                    int chek = vstavka(x, y, ukazka);
                }
                
            }
      break;
    }
};
