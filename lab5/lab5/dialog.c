//
//  dialog.c
//  lab5
//
//  Created by Данил Морозов on 04/05/2020.
//  Copyright © 2020 Данил Морозов. All rights reserved.
//

#include "dialog.h"



int dialog(const char *messages[], int n) {
    char *errormessage = "";
    int realchoose = 0;
    int i, k;
    printf("******************************\n");
    do {
        printf("%s",errormessage);
        errormessage = "********************************\nError of enter, pleace try again";
        for (i = 0; i < n; ++i) {
            printf("%s\n",messages[i]);
        }
        printf("Choose from alternatives --------->");
        k = scanf("%d", &realchoose);
        if (k == 0) fseek (stdin, 0, SEEK_END);
    } while (realchoose < 0 || realchoose >= n || k == 0);
    return realchoose;
}
