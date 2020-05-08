//
//  showing.c
//  lab5
//
//  Created by Данил Морозов on 05/05/2020.
//  Copyright © 2020 Данил Морозов. All rights reserved.
//

#include "showing2.h"

int showing2(Node* ukazka) {
    if (ukazka->type == 1) {
        for (int i = 0; ukazka->leaves[i] != NULL; ++i) {
            printf("вот такой №%d:x=%d, y=%d, info=%s\n",i, ukazka->leaves[i]->x, ukazka->leaves[i]->y, ukazka->leaves[i]->info);
        }
        return 1;
    }
    for (int i = 0; i < SIZE; ++i) {
        if (ukazka->sun[i] != NULL) {
            printf("-");
            showing2(ukazka->sun[i]);
            
        }
        
    }
    
    
    return 0;
}
