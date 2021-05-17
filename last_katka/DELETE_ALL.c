//
//  DELETE_ALL.c
//  last_katka
//
//  Created by Данил Морозов on 26/05/2020.
//  Copyright © 2020 Данил Морозов. All rights reserved.
//

#include "DELETE_ALL.h"


int DELETE_ALL (Labirint* l) {
    NodeV* helper1 = l->down;
    if (helper1 != NULL) {
        NodeV* helper2 = helper1->down;
        while (helper2 != NULL) {
            free(helper1);
            helper1 = helper2;
            helper2 = helper2->down;
        }
    }
    return 0;
}
