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


#endif /* strukts_h */

#define SIZE 4
#define N 2
#define UGOL 4096

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
    int max_x;        //да, я использую много границ, но это для того, чтобы можно было в любое время изменить размер "игрового" поля
    int max_y;
    int min_x;
    int min_y;
    Node* sun[SIZE];
    List* leaves[N];
};

typedef struct Graph Graph;
struct Graph {
    int n;
    Node *root;
};
