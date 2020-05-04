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
#define SIZE 4
#define N 2
#include "strukts.h"

const char *messages[] = {"0. Exit", "1. Adding element", "2. Finding element", "3. Delete element", "4. Show Al Table"};

const int Cmassages = sizeof(messages)/sizeof(messages[0]);

int main() {
    Graph *graph = (Graph *)calloc(1, sizeof(Graph));
    graph->root = (Node *)calloc(1, sizeof(Node));
    graph->n = 0;
    printf("Добро пожаловать в идеальную табличку на Q-дереве\n");
    int n = 0;
    int (*func[])(Graph *) = {NULL, adding, searching, deleting, showing};
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
