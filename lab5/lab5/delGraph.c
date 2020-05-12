//
//  delGraph.c
//  lab5
//
//  Created by Данил Морозов on 12/05/2020.
//  Copyright © 2020 Данил Морозов. All rights reserved.
//

#include "delGraph.h"

int delGraph(Node *ukazka) {
    if (ukazka->type == 1) {
        for (int i = 0; ukazka->leaves[i] != NULL; ++i) {
            free(ukazka->leaves[i]);
        }
        return 1;
    }
    for (int i = 0; i < SIZE; ++i) {
        if (ukazka->sun[i] != NULL) {
           // printf("-");
            delGraph(ukazka->sun[i]);
            
        }
    }
    free(ukazka);
    return 0;
}
