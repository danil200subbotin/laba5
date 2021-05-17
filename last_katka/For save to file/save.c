//
//  save.c
//  last_katka
//
//  Created by Данил Морозов on 24/05/2020.
//  Copyright © 2020 Данил Морозов. All rights reserved.
//

#include "save.h"


int save_to_file (NodeV *ukazka, FILE* file) {
    NodeV *dobler = ukazka;
    while (dobler != NULL) {
        fprintf(file, "%d\n",-1);
        fprintf(file, "%d\n",dobler->x);
        fprintf(file, "%d\n",dobler->y);
        fprintf(file, "%d\n",dobler->type);
        fprintf(file, "%d\n",dobler->name);
       // if (dobler->down != NULL) fprintf(file, "%d\n",-1);
        dobler = dobler->down;
    }
    fprintf(file, "%d\n",-2);
    dobler = ukazka;
    while (dobler != NULL) {
        NodeG* helper = dobler->right;
        while (helper != NULL) {
            fprintf(file, "%d\n",-3);
            fprintf(file, "%d\n",dobler->name);
            fprintf(file, "%d\n",helper->main->name);
            helper = helper->right;
        }
        dobler = dobler->down;
    }
    fprintf(file, "%d\n",-10);
    return 0;
}

int save(Labirint* l) {
    FILE *file = NULL;
    printf("Напишите имя желаемого файла, с которого считать граф, или в который захотите сохранить, автоматически будут предприняты соответствующие решения\n");
    fseek (stdin, 0, SEEK_END);
    char *fname = readln();
    file = fopen(fname, "r");
    if (file == NULL) {        //создаем новый файл, если нету такаго
        file = fopen(fname, "w");
        if (file) {
            printf("создан новый файл \n произвожу сохранение в него %s\n", fname);
            save_to_file(l->down, file);
            fclose(file);
        }
        else {
            printf("Ошибка создания файла");
            return 1;
        }
    }
    else {
        printf("Такой файл нашелся, приступаю к его считыванию (если у вас были какие-либо узлы, то узлы из файла просто добавятся)\n");
        int x,y, type, name;
        int k;
 //   while(!feof(file)) {
        fscanf(file,"%d\n", &k);
        while (k == -1) {
            fscanf(file, "%d\n", &x);
            fscanf(file, "%d\n", &y);
            fscanf(file, "%d\n", &type);
            fscanf(file, "%d\n", &name);
            node(l, x, y, type, name);
            fscanf(file, "%d\n", &k);
        }
        printf("ya  tut\n");
        int a, b;
        fscanf(file,"%d\n", &k);
        while (k == -3)  {
            fscanf(file,"%d\n", &a);
            fscanf(file,"%d\n", &b);
            fscanf(file,"%d\n", &k);
            line(l, a, b);
        }
        if (k == -10) printf("Успешно считал файлик\n");
        fclose(file);
    }
    return 0;
}

