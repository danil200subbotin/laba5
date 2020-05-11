//
//  main.c
//  lab5
//
//  Created by Данил Морозов on 04/05/2020.
//  Copyright © 2020 Данил Морозов. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "readln.h"
#include "dialog.h"
#include "strukts.h"
#include "adding.h"
#include "searching.h"
#include "deleting.h"
#include "showing.h"
#include "draw.h"
#include "read_from_file.h"
//#include "drawcpp.hpp"


const char *messages[] = {"0. Exit", "1. Adding element", "2. Finding element", "3. Delete element", "4. Show Al Table", "5. DrawCoolImage", "6.Read From File OR save to NEW file"};

const int Cmassages = sizeof(messages)/sizeof(messages[0]);

int main() {
    Graph *graph = (Graph *)calloc(1, sizeof(Graph));
    graph->root = (Node *)calloc(1, sizeof(Node));
    graph->n = 0;
    for (int i = 0; i < N; ++i) {
        graph->root->leaves[i] = NULL;
    };
    printf("Добро пожаловать в идеальную табличку на Q-дереве\n");
    int n = 0;
    //int (*func[])(Graph *) = {NULL, adding, searching, deleting, showing};
    int (*func[])(Graph *) = {NULL, adding, searching, deleting, showing, draw, read_from_file};
    while(n != -1) {
        printf("you should have to choose one of the alternatives bellow\n");
        n = dialog(messages, Cmassages);
        if (n == 0) {
            return 0;
        }
        //printf("вызываю функцию номер:%d\n", n);
        func[n](graph);
    }
    return 0;
}
