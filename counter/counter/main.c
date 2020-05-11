//
//  main.c
//  counter
//
//  Created by Данил Морозов on 11/05/2020.
//  Copyright © 2020 Данил Морозов. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a[551];
    for (int i = 0; i < 551; ++i) {
        a[i] = 0;
        
    }
    printf("проинициализировал\n");
    int x = 0;
    int k = 0;
    while(x != 1010) {
        scanf("%d", &x);
        if (x<=550) {
        ++k;
        a[x] = 1;
        }
        
    }
    printf("всего %d карточек\n", k);
    printf("Есть такие:\n");
    for (int i = 0; i < 551; ++i) {
       if (a[i] != 0) printf("%d\n", i);
    }
    printf("нет таких:\n");
    for (int i = 0; i < 551; ++i) {
       if (a[i] != 1) printf("%d\n", i);
    }
    return 0;
}
