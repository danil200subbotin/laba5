//
//  stracts.h
//  last_katka
//
//  Created by Данил Морозов on 19/05/2020.
//  Copyright © 2020 Данил Морозов. All rights reserved.
//
#pragma once
#define RAZMER 20 //максимаьная рвзмерность х на y
#define UGOL 800
//#define UGOL 1000000
#define EMPTY 0
#ifndef stracts_h
#define stracts_h


#endif /* stracts_h */
//размерность поля в точках



typedef struct Q Q;

typedef struct NodeV NodeV;
typedef struct NodeG NodeG;
struct NodeG {
    NodeV* main;
    NodeG* right;
    NodeG* left;
};

struct Q {
    NodeV* node;
    Q* next;
};

struct NodeV {
    int x;
    int y;
    int type;
    int name;
    int colour;
    NodeV* prev;
    NodeG* right;
    NodeV* down;
    NodeV* up;
};

typedef struct Labirint Labirint;
struct Labirint {
    int n;
    NodeV* down;
};

