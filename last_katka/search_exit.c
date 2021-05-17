//
//  search_exit.c
//  last_katka
//
//  Created by Данил Морозов on 22/05/2020.
//  Copyright © 2020 Данил Морозов. All rights reserved.
//

#include "search_exit.h"


Q* add_all_child (Q* q, NodeV* root) {
    NodeG* helper = NULL;
    Q* doblicat = q;
    helper = q->node->right;
    int k = 0;
    while (helper != NULL) {
        if ((helper->main != root) & (helper->main->type == 3)) {
            helper->main->colour = 2;
        }
        if (helper->main->colour != 2) {
            Q* q1 = (Q*)calloc(1, sizeof(Q));
            if (k == 0) {
                q1->next = q->next;
            }
            else {
                q1->next = doblicat;
            }
            q1->node = helper->main;
            q1->node->colour = 1;
            q1->node->prev = q->node;
            ++k;
            doblicat = q1;
        }
        helper = helper->right;

    }
    if (k == 0) {
        Q* q2;
        q2 = q->next;
        free(q);
        return q2;
    } else {
        q->node->colour = 2;
        free(q);
        return doblicat;
    }
}


NodeV* search_exit (Labirint* l, int name) {
    NodeV* root = l->down;
    NodeV* cho = l->down;
    while (root != NULL) {
        if (root->name == name) {
           printf("Нашел исходную вершину\n");
            root->prev = NULL;
            break;
        }
        root = root->down;
    }
    if (root == NULL) {
    printf("НЕ Нашел исходную вершину\n");
        return NULL;
    }
    Q* q = (Q*)calloc(1, sizeof(Q));
    q->node = root;
    q->next = NULL;
    q->node->prev = NULL;
    q->node->colour = 1;
    if (q->node->type == 7) {
       printf("вы уже на выходе, поздравляю!\n");
        return NULL;
    }
    while (q != NULL) {
        if (q->node->type == 7) {
        printf("Нашелся выход!!! Поздравляю! Мы добавили выход в графф, если захотите посмотреть - нарисуйте лабиринт\n");
            return q->node;
        }
        q = add_all_child(q, root);
        if (q == NULL) {
           printf("выхода нет, но скоро рассвет!!!\n");
        }
    }
    while (cho->down != NULL) {
        cho->colour = 0;
        cho = cho->down;
    }
        
    
    return 0;
}
