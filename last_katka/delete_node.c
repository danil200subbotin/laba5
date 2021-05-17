//
//  delete_node.c
//  last_katka
//
//  Created by Данил Морозов on 20/05/2020.
//  Copyright © 2020 Данил Морозов. All rights reserved.
//-

#include "delete_node.h"


NodeV* finder (int name, Labirint* l) {
    NodeV* node = l->down;
    while (node != NULL) {
        if (node->name == name) {
            return node;
        }
        node = node->down;
        
    }
    printf("не нашел такого элемента\n");
    return NULL;
}

int delete_node(Labirint * l) {
    printf("ввидите имя счастливчика\n");
    int name;
    scanf("%d", &name);
    NodeV* helper = NULL;
    NodeG* helperg = NULL;
    NodeV* node = finder(name, l);
    if (node == NULL) return 100500;
    printf("уже за бриком\n");
    NodeG* goriz = NULL;
    goriz = node->right;
    while (goriz != NULL) {
        helper = goriz->main;
        helperg = helper->right;
        if (helperg == NULL) {
           goriz = goriz->right;
 //           free(goriz->left);
            continue;
        }
        int k = 0;
        while (k == 0) {
            if (helperg->main->name == name) {
                ++k;
                if (helperg->left == NULL) {
                    helper->right = helperg->right;
                }
                else {
                    helperg->left->right = helperg->right;
                }
                free(helperg);
            }
            if (helperg->right != NULL) {
                helperg = helperg->right;
            }
            else k++;
        }
        if (goriz->right == NULL) {
 //           free(goriz);
            goriz = NULL;
        }
        else {
        goriz = goriz->right;
            free(goriz->left);
        }
    }
    if (node->up == NULL) {
        l->down = node->down;
    }
    else {
        node->up->down = node->down;
    }
    if (node->down != NULL) node->down->up = node->up;
    free(node);
    --(l->n);
    return 0;
}
