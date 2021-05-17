//
//  create_random.c
//  last_katka
//
//  Created by Данил Морозов on 21/05/2020.
//  Copyright © 2020 Данил Морозов. All rights reserved.
//

#include "create_random.h"
#define UGOL 800

int node1(Labirint* l, int i) {
    int x = 0, y = 0, name = -1, type = 0;
    name = i;
    x = abs(rand() * rand()) % UGOL;
    y = abs(rand() * rand()) % UGOL;
    type = rand() % 3;
    if (type == 0) {
        type = 3;
    }
    if (type == 1) {
        type = 7;
    }
    if (type == 2) {
        type = 8;
    }
    NodeV *main = NULL;
    main = l->down;
    while (main != NULL) {
        if ((main->x == x) & (main->y == y)) {
  //          printf("запрещаю данное сочетание ключей");
            return 1;
        }
        main = main->down;
    }
    main = (NodeV* )calloc(1, sizeof(NodeV));
    main->name = name;
    main->x = x;
    main->y = y;
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
    return 0;
}

int rebro(Labirint *l) {
//    printf("введите номера тех ячеек, котрые вы хотите соединить\n");
    int a, b;
    a = ((rand() % l->n) + 1);
    b = ((rand() % l->n) + 1);
    if (a == b) {
        printf("ну низя же так\n");
        return 1;
    }
    NodeV *main = NULL;
    NodeG *nemain = NULL;
    NodeV *one = NULL, *two = NULL;
    main = l->down;
    int k = 0;
    while ((main != NULL) & (k != 2)) {
        if (main->name == a) {
            one = main;
            ++k;
        }
        if (main->name == b) {
            two = main;
            ++k;
        }
        main = main->down;
        
    }
    if (k < 2) {
  //      printf("вершины с такими номерами соединить не удалось\n");
        return 1;
    }
    k = 0;
    nemain = one->right;
    while (nemain != NULL) {
        if (nemain->main == two) {
            printf("вершины с такими номерами уже соеденины\n");
            return 1;
        }
        nemain = nemain->right;
    }
  //  printf("все хорошо, соединяю данные вершины\n");
    NodeG* gorizont1 = (NodeG *)calloc(1, sizeof(NodeG));
    NodeG* gorizont2 = (NodeG *)calloc(1, sizeof(NodeG));
    gorizont1->main = one;
    gorizont2->main = two;
    
    
    gorizont2->right = NULL;
    gorizont1->right = NULL;
    gorizont1->left = NULL;
    gorizont2->left = NULL;
    
    
    
    if (one->right == NULL){
        one->right = gorizont2;
    }
    else {
        NodeG *helper = NULL;
        helper = one->right;
        one->right = gorizont2;
        gorizont2->right = helper;
        helper->left = gorizont2;
    }
    if (two->right == NULL){
        two->right = gorizont1;
    }
    else {
        NodeG *helper = NULL;
        helper = two->right;
        two->right = gorizont1;
        gorizont1->right = helper;
        helper->left = gorizont1;
    }
    return 0;
}

int create_random(Labirint* l) {
    printf("вы правда хотите забить граф? '1' - да, '2' -  нет  \n");
    int k;
    scanf("%d", &k);
    if (k == 2) return 1;
    printf("начинаем\n");
    int a, b;
    printf("сколько хотите вершин?\n");
    scanf("%d", &a);
    printf("сколько хотите ребер?\n");
    scanf("%d", &b);
    printf("добавляю вершины\n");
    for (int i = 1; i <= a; ++i) {
        node1(l, i);
    }
    printf("добавляю рёбра\n");
    for (int i = 1; i <= b; ++i) {
        rebro(l);
    }
    return 0;
}

