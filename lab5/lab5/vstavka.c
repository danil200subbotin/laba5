//
//  vstavka.c
//  lab5
//
//  Created by Данил Морозов on 05/05/2020.
//  Copyright © 2020 Данил Морозов. All rights reserved.
//

#include "vstavka.h"
#include "strukts.h"
#include <stdlib.h>
#include "readln.h"

int vstavka(int x, int y, Node* ukazka) {
    if (ukazka->leaves[N-1] != NULL) {
        List* list = NULL;
        List* new = (List *)calloc(1, sizeof(List));
        new->x = x;
        new->y = y;
        new->info = readln();
        int i = 0;
        for (i = 0; ukazka->leaves[i] != NULL; ++i) {
            if ((x == ukazka->leaves[i]->x) & (y == ukazka->leaves[i]->y)) {
                printf("Запрещаю данное сочитание ключей!!!!!!\n");
                free(new);
                return -1;
            }
            if (x < ukazka->leaves[i]->x) {
                break;
            }
        }
        list = ukazka->leaves[i];
        ukazka->leaves[i] = new;
        ++i;
        for (; ukazka->leaves[i] != NULL; ++i) {
            new = ukazka->leaves[i];
            ukazka->leaves[i] = list;
        }
        ukazka->leaves[i] = new;
        return 0;
    }
    else {
        printf("нужная честь дерева переполнена, придется разделить ее на 4 части\n");
        ukazka->type = 0;
        Node *node1 = (Node *)calloc(1, sizeof(Node));
        Node *node2 = (Node *)calloc(1, sizeof(Node));
        Node *node3 = (Node *)calloc(1, sizeof(Node));
        Node *node4 = (Node *)calloc(1, sizeof(Node));
        
        node1->gran_x = (ukazka->gran_x + ukazka->max_x)/2;
        node1->gran_y = (ukazka->gran_y + ukazka->max_y)/2;
        node1->max_x = ukazka->max_x;
        node1->max_y = ukazka->max_y;
        node1->min_x = ukazka->gran_x;
        node1->min_y = ukazka->gran_y;
        
        node2->gran_x = (ukazka->gran_x + ukazka->min_x)/2;
        node2->gran_y = node1->gran_y;
        node2->max_x = ukazka->gran_x;
        node2->max_y = node1->max_y;
        node2->min_x = ukazka->min_x;
        node2->min_y = node1->min_y;
        
        node3->gran_x = node2->gran_x;
        node3->gran_y = (ukazka->gran_y + ukazka->min_y)/2;
        node3->max_x = node2->max_x;
        node3->max_y = ukazka->gran_y;
        node3->min_x = node2->min_x;
        node3->min_y = ukazka->max_y;
        
        node4->gran_x = node1->gran_x;
        node4->gran_y = node3->gran_y;
        node4->max_x = node1->max_x;
        node4->max_y = node3->max_y;
        node4->min_x = node1->min_x;
        node4->min_y = node3->min_y;
        
        ukazka->sun[0] = node1;
        ukazka->sun[1] = node2;
        ukazka->sun[2] = node3;
        ukazka->sun[3] = node4;
        
        node1->type = 1;
        node2->type = 1;
        node3->type = 1;
        node4->type = 1;
        
        printf("фух, создал, устал\n");
        int n1, n2, n3, n4;
        n1 = n2 = n3 = n4 = 0;
        for (int i = 0; ukazka->leaves[i] != NULL; ++i) {
                if ((ukazka->leaves[i]->x >= ukazka->gran_x) & (ukazka->leaves[i]->y >= ukazka->gran_y)) {
                    node1->leaves[n1] = ukazka->leaves[i];
                    ukazka->leaves[i] = NULL;
                    ++n1;
                    continue;
                }
                if ((ukazka->leaves[i]->x < ukazka->gran_x) & (ukazka->leaves[i]->y > ukazka->gran_y)) {
                    node2->leaves[n1] = ukazka->leaves[i];
                    ukazka->leaves[i] = NULL;
                    ++n2;
                    continue;
                }
                if ((ukazka->leaves[i]->x <= ukazka->gran_x) & (ukazka->leaves[i]->y <= ukazka->gran_y) & !((ukazka->leaves[i]->x == ukazka->gran_x) & (ukazka->leaves[i]->y == ukazka->gran_y))) {
                    ukazka = ukazka->sun[2];
                    node3->leaves[n1] = ukazka->leaves[i];
                    ukazka->leaves[i] = NULL;
                    ++n3;
                    continue;
                }
                if ((ukazka->leaves[i]->x > ukazka->gran_x) & (ukazka->leaves[i]->y < ukazka->gran_y)) {
                    node4->leaves[n1] = ukazka->leaves[i];
                    ukazka->leaves[i] = NULL;
                    ++n4;
                    continue;
                }
            }
        if ((n1 == N) || (n2 == N) || (n3 == N) || (n4 == N)) {
            printf("вхожу в рекурсию резальщика");
        };
        for (int g = 0; g < 1; ++g) {
            if ((x >= ukazka->gran_x) & (y >= ukazka->gran_y)) {
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
        vstavka(x, y, ukazka);
    }
    return +100500;
}
    

