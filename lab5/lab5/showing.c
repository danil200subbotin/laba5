//
//  showing.c
//  lab5
//
//  Created by Данил Морозов on 08/05/2020.
//  Copyright © 2020 Данил Морозов. All rights reserved.
//

#include "showing.h"


int showing(Graph * graph) {
    Node* ukazka = graph->root;
    showing2(ukazka);
    return 0;
}
