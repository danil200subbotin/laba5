//
//  perehod.c
//  lab5
//
//  Created by Данил Морозов on 11/05/2020.
//  Copyright © 2020 Данил Морозов. All rights reserved.
//

#include "perehod.h"


int perehod(int x, int y,char* info, Node* ukazka) {
    int n = 0;
    while (n == 0) {
        if (ukazka->type == 0) {
            if (( x >= ukazka->gran_x) & (y >= ukazka->gran_y)) {
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
        else {
            n = 1;
            int chek = vstavka(x, y, info, ukazka);
            if (chek == 0) {
                printf("вставка прошла успешно\n");
            }
        }
        
    }
    vstavka(x, y, info, ukazka);
    return 0;
}
