//
//  strukts.h
//  lab5
//
//  Created by Данил Морозов on 05/05/2020.
//  Copyright © 2020 Данил Морозов. All rights reserved.
//
#pragma once
#ifndef strukts_h
#define strukts_h
#include <stdlib.h>
#include <stdio.h>
#endif /* strukts_h */
#include <Limits.h>
#define SIZE 4
#define N 3
#define UGOL 10000000
//#define UGOL 864

typedef struct List List;
struct List {
    int x;
    int y;
    char* info;
};

typedef struct Node Node;
struct Node{
    int type;                   //имеет значенение 0 для разделяющего узла
    int gran_x;                  //и 1 для узла с листьями
    int gran_y;
    int max_x;        //да, я использую много границ, но это для того, чтобы можно было в любое время изменить размер "игрового" поля и можно удобно рисовать)
    int max_y;
    int min_x;
    int min_y;
    Node* sun[SIZE];
    List* leaves[N];
};

typedef struct Graph Graph;
struct Graph {
    FILE* fd;                   //нужен, чтобы подсасывать информацию из файла;
    char* fname;
    int n;
    Node *root;
};
