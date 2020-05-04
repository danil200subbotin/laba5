//
//  strukts.h
//  lab5
//
//  Created by Данил Морозов on 05/05/2020.
//  Copyright © 2020 Данил Морозов. All rights reserved.
//

#ifndef strukts_h
#define strukts_h


#endif /* strukts_h */

typedef struct List List;
struct List {
    int x;
    int y;
    char* info;
};

typedef struct Node Node;
struct Node{
    int type;                   //имеет значенение 0 для разделяющего узла
    int key_x;                  //и 1 для узла с листьями
    int key_y;
    Node* sun[SIZE];
    List* leaves[N];
};

typedef struct Graph Graph;
struct Graph {
    int n;
    Node *root;
};
