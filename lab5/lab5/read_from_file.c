//
//  read_from_file.c
//  lab5
//
//  Created by Данил Морозов on 11/05/2020.
//  Copyright © 2020 Данил Морозов. All rights reserved.
//
#include "read_from_file.h"


int save_to_file (Node *ukazka, FILE* file) {
    if (ukazka->type == 1) {
        for (int i = 0; ukazka->leaves[i] != NULL; ++i) {
            fprintf(file, "%d\n",ukazka->leaves[i]->x);
            fprintf(file, "%d\n",ukazka->leaves[i]->y);
            fprintf(file, "%s\n",ukazka->leaves[i]->info);
        }
        return 1;
    }
    for (int i = 0; i < SIZE; ++i) {
        if (ukazka->sun[i] != NULL) {
            //printf("-");
            save_to_file(ukazka->sun[i], file);
            
        }
        
    }
    
    
    return 0;
}

int read_from_file (Graph * graph) {                           //считывание таблицы из файла
    FILE *file = NULL;
    printf("Напишите имя желаемого файла, с которого считать граф, или в который захотите сохранить, автоматически будут предприняты соответствующие решения\n");
    fseek (stdin, 0, SEEK_END);
    char *fname = readln();
    file = fopen(fname, "r");
    if (file == NULL) {                                 //создаем новый файл, если нету такаго
        file = fopen(fname, "w");
        if (file) {
            printf("создан новый файл \n произвожу сохранение в него %s\n", fname);
            save_to_file(graph->root, file);
            fclose(file);
        }
        else {
            printf("Ошибка создания файла");
            return 1;
        }
    }
    else {
        printf("Такой файл нашелся, приступаю к его считыванию (если у вас были какие-либо узлы, то узлы из файла просто добавятся)\n");
        int x,y;
        char *buf;
    while(!feof(file))
    {
        fscanf(file, "%d\n", &x);
        fscanf(file, "%d\n", &y);
        buf = (char*)malloc(100);
        fscanf(file, "%s\n", buf);
        printf("Считал из файла %d,%d,%s!!!\n",x ,y ,buf);
        perehod(x, y, buf, graph->root, graph);
        
    }
        fclose(file);
    }
    return 0;
}
