//
//  main.c
//  last_katka
//
//  Created by Данил Морозов on 19/05/2020.
//  Copyright © 2020 Данил Морозов. All rights reserved.
//
#ifndef main_h
#define main_h
#include "stracts.h"
#include <stdio.h>
#include <stdlib.h>
#include "init.h"
#include "Timing.h"
#include "dialog.h"
#include "add_line.h"
#include "add_node.h"
#include "adding.h"
#include "delete_node.h"
#include "draw.h"
#include "create_random.h"
#include "finding_exits.h"
#include "save.h"
#endif /* readln_h */

const char *messages[] = {"0. Exit", "1. Adding node OR мостик","2. Finding EXITS", "3. Delete node", "4. draw this", "5.Read From File OR save to NEW file", "6. Timing", "7.RANDOOOM"};

const int Cmassages = sizeof(messages)/sizeof(messages[0]);



int main() {
    printf("начинааем супер-прогу по лабиринту\n");
    Labirint* labirint = (Labirint*)calloc(1, sizeof(Labirint*));
    init(labirint);
    int k = 0;
    int n = 0;
    int (*func[])(Labirint*) = {NULL, adding, finding_exits, delete_node, draw, save, Timing, create_random};
    while (k == 0) {
        printf("что вы хотите сделать с лабиринтом?\n");
        n = dialog(messages, Cmassages);
               if (n == 0) {
                   return 0;
               }
               printf("вызываю функцию номер:%d\n", n);
               func[n](labirint);
    }
    
    
    
    return 0;
}
