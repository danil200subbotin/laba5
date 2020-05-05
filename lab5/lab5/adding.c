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
    if (graph->n == 0) {
        graph->root->type = 1;
        graph->root->gran_x = UGOL/2;
        graph->root->gran_y= UGOL/2;
        graph->root->max_x = UGOL;
        graph->root->max_y = UGOL;
        graph->root->min_x = 0;
        graph->root->min_y = 0;
        for (int i = 0; i < N; ++i) {
            graph->root->leaves[i] = NULL;
        }
    }
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
            if (( x <= ukazka->gran_x) & (y <= ukazka->gran_y) & !((x == ukazka->gran_x) & (y == ukazka->gran_y))) {
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
            if (chek == 0) printf("вставка прошла успешно");
        }
        
    }
    return 0;
};
