//
//  draw.c
//  last_katka
//
//  Created by Данил Морозов on 21/05/2020.
//  Copyright © 2020 Данил Морозов. All rights reserved.
//

#include "draw.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#define DOT 5
#include "stracts.h"
#define UGOL 800


int draw_0 (int x,int y, SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
     SDL_RenderDrawLine(renderer, x,UGOL - y, x + 6,UGOL - y);
    SDL_RenderDrawLine(renderer, x + 6, UGOL - y, x + 6,UGOL - (y-12));
    SDL_RenderDrawLine(renderer,  x + 6,UGOL - (y-12), x,UGOL - (y-12));
    SDL_RenderDrawLine(renderer,  x,UGOL - (y-12), x, UGOL - (y));
    SDL_RenderDrawLine(renderer,  x,UGOL - (y-12), x + 6, UGOL - (y));
    return 0;
}

int draw_1 (int x,int y, SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(renderer, x,UGOL - (y - 6), x + 6,UGOL - y);
    SDL_RenderDrawLine(renderer, x + 6,UGOL - y, x + 6,UGOL - (y - 12));
    return 0;
}

int draw_2 (int x,int y, SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(renderer, x,UGOL - (y - 3), x ,UGOL - y);
    SDL_RenderDrawLine(renderer, x,UGOL - y, x + 6,UGOL - (y));
    SDL_RenderDrawLine(renderer, x + 6,UGOL - (y), x + 6,UGOL - (y - 6));
    SDL_RenderDrawLine(renderer, x + 6,UGOL - (y - 6), x ,UGOL - (y - 12));
    SDL_RenderDrawLine(renderer, x ,UGOL - (y - 12), x + 6 ,UGOL - (y - 12));
    return 0;
}

int draw_3 (int x,int y, SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(renderer, x,UGOL - (y), x + 6 ,UGOL - y);
    SDL_RenderDrawLine(renderer, x + 6,UGOL - y, x,UGOL - (y-6));
    SDL_RenderDrawLine(renderer, x,UGOL - (y-6), x + 6,UGOL - (y - 12));
    SDL_RenderDrawLine(renderer, x + 6,UGOL - (y - 12), x ,UGOL - (y - 12));
    return 0;
}

int draw_4 (int x,int y, SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(renderer, x,UGOL - (y), x ,UGOL - (y-6));
    SDL_RenderDrawLine(renderer, x ,UGOL - (y-6), x + 6,UGOL - (y-6));
    SDL_RenderDrawLine(renderer, x + 6,UGOL - (y), x + 6,UGOL - (y - 12));
    return 0;
}

int draw_5 (int x,int y, SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(renderer, x + 6,UGOL - (y), x ,UGOL - (y));
    SDL_RenderDrawLine(renderer, x ,UGOL - (y), x ,UGOL - (y-6));
    SDL_RenderDrawLine(renderer, x,UGOL - (y - 6), x + 6,UGOL - (y - 6));
    SDL_RenderDrawLine(renderer, x + 6,UGOL - (y - 6), x + 6,UGOL - (y - 12));
    SDL_RenderDrawLine(renderer, x + 6,UGOL - (y - 12), x,UGOL - (y - 12));
    return 0;
}

int draw_6 (int x,int y, SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(renderer, x + 6,UGOL - (y), x ,UGOL - (y));
    SDL_RenderDrawLine(renderer, x ,UGOL - (y), x ,UGOL - (y-12));
    SDL_RenderDrawLine(renderer, x,UGOL - (y - 6), x + 6,UGOL - (y - 6));
    SDL_RenderDrawLine(renderer, x + 6,UGOL - (y - 6), x + 6,UGOL - (y - 12));
    SDL_RenderDrawLine(renderer, x + 6,UGOL - (y - 12), x,UGOL - (y - 12));
    return 0;
}

int draw_7 (int x,int y, SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(renderer, x,UGOL - (y), x + 6 ,UGOL - (y));
    SDL_RenderDrawLine(renderer, x + 6 ,UGOL - (y), x ,UGOL - (y-12));
    return 0;
}

int draw_8 (int x,int y, SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(renderer, x + 6,UGOL - (y), x ,UGOL - (y));
    SDL_RenderDrawLine(renderer, x ,UGOL - (y), x ,UGOL - (y-12));
    SDL_RenderDrawLine(renderer, x,UGOL - (y - 6), x + 6,UGOL - (y - 6));
    SDL_RenderDrawLine(renderer, x + 6,UGOL - (y), x + 6,UGOL - (y - 12));
    SDL_RenderDrawLine(renderer, x + 6,UGOL - (y - 12), x,UGOL - (y - 12));
    return 0;
}

int draw_9 (int x,int y, SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(renderer, x + 6,UGOL - (y), x ,UGOL - (y));
    SDL_RenderDrawLine(renderer, x ,UGOL - (y), x ,UGOL - (y-6));
    SDL_RenderDrawLine(renderer, x,UGOL - (y - 6), x + 6,UGOL - (y - 6));
    SDL_RenderDrawLine(renderer, x + 6,UGOL - (y), x + 6,UGOL - (y - 6));
    SDL_RenderDrawLine(renderer, x + 6,UGOL - (y - 6), x,UGOL - (y - 12));
    return 0;
}

int draw_way(NodeV *ukazka, SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
    while (ukazka->prev != NULL) {
      //  printf("yaaa-----%d\n", ukazka->name);
         SDL_RenderDrawLine(renderer, ukazka->x,UGOL - ukazka->y, ukazka->prev->x,UGOL - ukazka->prev->y);
        ukazka = ukazka->prev;
    }
    
    return 0;
}

int draw_door(NodeV* ukazka, SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(renderer, ukazka->x + 3,UGOL - (ukazka->y + 5), ukazka->x - 3,UGOL - (ukazka->y + 5));
    SDL_RenderDrawLine(renderer,ukazka->x - 3,UGOL - (ukazka->y + 5), ukazka->x - 3,UGOL - (ukazka->y - 5));
    SDL_RenderDrawLine(renderer,ukazka->x - 3,UGOL - (ukazka->y - 5), ukazka->x + 3,UGOL - (ukazka->y - 5));
    SDL_RenderDrawLine(renderer,ukazka->x + 3,UGOL - (ukazka->y - 5), ukazka->x + 3,UGOL - (ukazka->y + 5));
    SDL_RenderDrawLine(renderer,ukazka->x + 1, UGOL - ukazka->y, ukazka->x + 5,UGOL - ukazka->y);
    return 0;
}

int draw_perepere(NodeV* ukazka, SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(renderer, ukazka->x + 6,UGOL - (ukazka->y + 2), ukazka->x + 2,UGOL - (ukazka->y + 2));
    SDL_RenderDrawLine(renderer, ukazka->x + 2,UGOL - (ukazka->y + 2), ukazka->x + 2,UGOL - (ukazka->y + 6));
    SDL_RenderDrawLine(renderer, ukazka->x - 2,UGOL - (ukazka->y + 6), ukazka->x - 2,UGOL - (ukazka->y + 2));
    SDL_RenderDrawLine(renderer, ukazka->x - 2,UGOL - (ukazka->y + 2), ukazka->x - 6,UGOL - (ukazka->y + 2));
    SDL_RenderDrawLine(renderer, ukazka->x - 6,UGOL - (ukazka->y - 2), ukazka->x - 2,UGOL - (ukazka->y - 2));
    SDL_RenderDrawLine(renderer, ukazka->x - 2,UGOL - (ukazka->y - 2), ukazka->x - 2,UGOL - (ukazka->y - 6));
    SDL_RenderDrawLine(renderer, ukazka->x + 2,UGOL - (ukazka->y - 6), ukazka->x + 2,UGOL - (ukazka->y - 2));
    SDL_RenderDrawLine(renderer, ukazka->x + 2,UGOL - (ukazka->y - 2), ukazka->x + 6,UGOL - (ukazka->y - 2));
    return 0;
}

int draw_tupic(NodeV* ukazka, SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(renderer, ukazka->x + 5,UGOL - (ukazka->y + 5), ukazka->x - 5,UGOL - (ukazka->y + 5));
    SDL_RenderDrawLine(renderer, ukazka->x - 5,UGOL - (ukazka->y + 5), ukazka->x - 5,UGOL - (ukazka->y - 5));
    SDL_RenderDrawLine(renderer, ukazka->x - 5,UGOL - (ukazka->y - 5), ukazka->x + 5,UGOL - (ukazka->y - 5));
    SDL_RenderDrawLine(renderer, ukazka->x + 5,UGOL - (ukazka->y - 5), ukazka->x + 5,UGOL - (ukazka->y + 5));
    SDL_RenderDrawLine(renderer, ukazka->x + 5,UGOL - (ukazka->y + 5), ukazka->x - 5,UGOL - (ukazka->y - 5));
    SDL_RenderDrawLine(renderer, ukazka->x + 5,UGOL - (ukazka->y - 5), ukazka->x - 5,UGOL - (ukazka->y + 5));
    return 0;
}

int draw_liniya (SDL_Renderer* renderer, NodeV* ukazka1, NodeV* ukazka2) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    int k;
    if ((ukazka1->x - ukazka2->x) != 0) {
       k = abs(ukazka1->y - ukazka2->y)/abs(ukazka1->x - ukazka2->x);
    }
    else {
        k = 1;
    }
    if (k >= 1) {
        SDL_RenderDrawLine(renderer, ukazka1->x + 3,UGOL - (ukazka1->y), ukazka2->x + 3,UGOL - (ukazka2->y));
        SDL_RenderDrawLine(renderer, ukazka1->x - 3,UGOL - (ukazka1->y), ukazka2->x - 3,UGOL - (ukazka2->y));
    }
    else {
        SDL_RenderDrawLine(renderer, ukazka1->x,UGOL - (ukazka1->y + 3), ukazka2->x,UGOL - (ukazka2->y + 3));
        SDL_RenderDrawLine(renderer, ukazka1->x,UGOL - (ukazka1->y - 3), ukazka2->x,UGOL - (ukazka2->y - 3));
    }
    return 0;
}

int draw_name (int name, int x, int y, SDL_Renderer* renderer) {
    int k = 0;
    int g = 7;
    int v = y - 6;
    while(name != 0) {
        k = name % 10;
        name = name/10;
        switch (k) {
            case 0:
                draw_0(x + g, v, renderer);
                g = g - 8;
            break;
            case 1:
                draw_1(x + g, v, renderer);
                g = g - 8;
            break;
            case 2:
                draw_2(x + g, v, renderer);
                g = g - 8;
            break;
            case 3:
                draw_3(x + g, v, renderer);
                g = g - 8;
            break;
            case 4:
                draw_4(x + g, v, renderer);
                g = g - 8;
            break;
            case 5:
                draw_5(x + g, v, renderer);
                g = g - 8;
            break;
            case 6:
                draw_6(x + g, v, renderer);
                g = g - 8;
            break;
            case 7:
                draw_7(x + g, v, renderer);
                g = g - 8;
            break;
            case 8:
                draw_8(x + g, v, renderer);
                g = g - 8;
            break;
            case 9:
                draw_9(x + g, v, renderer);
                g = g - 8;
            break;
            default:
                printf("Что ты такое???");
        }
    }
    return 0;
}

int sdelai_krasivo(NodeV* ukazka,  SDL_Renderer* renderer) {
    while (ukazka != NULL) {
        if ((ukazka->prev != NULL) & (ukazka->type == 7)) {
            draw_way(ukazka, renderer);
        }
        if (ukazka->type == 7) {
            draw_door(ukazka, renderer);
        }
        if (ukazka->type == 8) {
            draw_perepere(ukazka, renderer);
        }
        if (ukazka->type == 3) {
            draw_tupic(ukazka, renderer);
        }
        draw_name(ukazka->name, ukazka->x, ukazka->y, renderer);
        NodeG* goriz = ukazka->right;
        while (goriz != NULL) {
            draw_liniya(renderer, ukazka, goriz->main);
            goriz = goriz->right;
        }
        ukazka = ukazka->down;
    }
    return 0;
 }


int draw(Labirint* l)
{
    printf("я тут\n");
    if (SDL_Init(SDL_INIT_VIDEO) == 0) {
        SDL_Window* window = NULL;
        SDL_Renderer* renderer = NULL;
        if (SDL_CreateWindowAndRenderer(UGOL, UGOL, 0, &window, &renderer) == 0) {
            SDL_bool done = SDL_FALSE;

            while (!done) {
                SDL_Event event;
                SDL_Delay(500);
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                SDL_RenderClear(renderer);

                SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                NodeV* ukazka = l->down;
             
                sdelai_krasivo(ukazka, renderer);
                
                SDL_RenderPresent(renderer);

                while (SDL_PollEvent(&event)) {
                    if (event.type ==  SDL_QUIT) {
                        done = SDL_TRUE;
                    }
                }
            }
        }

        if (renderer) {
            SDL_DestroyRenderer(renderer);
        }
        if (window) {
            SDL_DestroyWindow(window);
        }
    }
    SDL_Quit();
    return 0;
}
