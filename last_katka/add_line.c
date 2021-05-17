//
//  add_line.c
//  last_katka
//
//  Created by Данил Морозов on 19/05/2020.
//  Copyright © 2020 Данил Морозов. All rights reserved.
//

#include "add_line.h"



int add_line (Labirint *l) {
    printf("введите номера тех ячеек, котрые вы хотите соединить\n");
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
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
        printf("вершины с такими номерами соединить не удалось\n");
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
    printf("все хорошо, соединяю данные вершины\n");
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
