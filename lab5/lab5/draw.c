//
//  draw.c
//  lab5
//
//  Created by Данил Морозов on 09/05/2020.
//  Copyright © 2020 Данил Морозов. All rights reserved.
//SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
#ifndef LEVEL_H_
#define LEVEL_H_
#endif
#include "draw.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#define DOT 5
#include "strukts.h"
#include <SDL2/SDL_ttf.h>

int SCREEN_WIDTH = 1000;
int SCREEN_HEIGHT = 1000;

int draw_this_shit(Node* ukazka, SDL_Renderer* renderer) {
    
    if (ukazka->type == 1) {
        for (int i = 0; ukazka->leaves[i] != NULL; ++i) {
            SDL_SetRenderDrawColor(renderer, 0, 0, 139, SDL_ALPHA_OPAQUE);
            //SDL_RenderDrawPoint (renderer, ukazka->leaves[i]->x, ukazka->leaves[i]->y);
            SDL_RenderDrawLine(renderer, ukazka->leaves[i]->x+DOT, UGOL - (ukazka->leaves[i]->y+DOT), ukazka->leaves[i]->x-DOT, UGOL - (ukazka->leaves[i]->y-DOT));
            SDL_RenderDrawLine(renderer, ukazka->leaves[i]->x-DOT, UGOL - (ukazka->leaves[i]->y+DOT), ukazka->leaves[i]->x+DOT, UGOL - (ukazka->leaves[i]->y-DOT));
        }
        return 1;
    }
    for (int i = 0; i < SIZE; ++i) {
        if (ukazka->sun[i] != NULL) {
            printf("-");
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
            SDL_RenderDrawLine(renderer, ukazka->min_x,UGOL - ukazka->gran_y, ukazka->max_x, UGOL - ukazka->gran_y);
            SDL_RenderDrawLine(renderer, ukazka->gran_x, UGOL - ukazka->max_y, ukazka->gran_x, UGOL - ukazka->min_y);
            draw_this_shit(ukazka->sun[i], renderer);
            
        }
        
    }
    return 0;
}




int draw(Graph* graph)
{
    printf("я тут\n");
    if (SDL_Init(SDL_INIT_VIDEO) == 0) {
        SDL_Window* window = NULL;
        SDL_Renderer* renderer = NULL;
        if (SDL_CreateWindowAndRenderer(UGOL, UGOL, 0, &window, &renderer) == 0) {
            SDL_bool done = SDL_FALSE;
            
            
            
            TTF_Init();

            TTF_Font *verdanaFont = TTF_OpenFont("/Users/danilmorozov/Desktop/GIT HUB/laba5/Metroplex Shadow.ttf", 25);
            SDL_Color textColor = { 0, 0, 0, 255 };
            SDL_Surface *textSurface = TTF_RenderText_Solid(verdanaFont, "Hello World", textColor);
            SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
            SDL_Rect textRect;
            textRect.x = UGOL - textSurface->w * 0.5;
            textRect.y = UGOL - textSurface->h * 0.5;
            textRect.w = textSurface->w;
            textRect.h = textSurface->h;

            SDL_FreeSurface(textSurface);
            TTF_Quit();
            
            
            
            while (!done) {
                SDL_Event event;
                SDL_Delay(500);
                SDL_SetRenderDrawColor(renderer, 216, 191, 216, SDL_ALPHA_OPAQUE);
                SDL_RenderClear(renderer);
                
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                Node* ukazka = graph->root;
                draw_this_shit(ukazka, renderer);
                //SDL_RenderDrawLine(renderer, 320, 200, 300, 240);
               SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
                //SDL_RenderDrawLine(renderer, 340, 240, 320, 200);
                SDL_RenderPresent(renderer);

                while (SDL_PollEvent(&event)) {
                    if (event.type ==  SDL_QUIT) {
                        done = SDL_TRUE;
                    }
                }
            }
            SDL_DestroyTexture(textTexture);
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


//#define POINTS_COUNT 4
//
//static SDL_Point points[POINTS_COUNT] = {
//    {320, 200},
//    {300, 240},
//    {340, 240},
//    {320, 200}
//};
//
//int draw(Graph * graph)
//{
//    if (SDL_Init(SDL_INIT_VIDEO) == 0) {
//        SDL_Window* window = NULL;
//        SDL_Renderer* renderer = NULL;
//
//        if (SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer) == 0) {
//            SDL_bool done = SDL_FALSE;
//
//            while (!done) {
//                SDL_Event event;
//
//                SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
//                SDL_RenderClear(renderer);
//
//                SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
//                SDL_RenderDrawLines(renderer, points, POINTS_COUNT);
//                SDL_RenderPresent(renderer);
//
//                while (SDL_PollEvent(&event)) {
//                    if (event.type == SDL_QUIT) {
//                        done = SDL_TRUE;
//                    }
//                }
//            }
//        }
//
//        if (renderer) {
//            SDL_DestroyRenderer(renderer);
//        }
//        if (window) {
//            SDL_DestroyWindow(window);
//        }
//    }
//    SDL_Quit();
//    return 0;
//}




//int draw(Graph * graph) {
//    SDL_Window *win = NULL;
//    SDL_Renderer *renderer = NULL;
//    SDL_Texture *bitmapTex = NULL;
//    SDL_Surface *bitmapSurface = NULL;
//    int posX = 100, posY = 100, width = 320, height = 240;
//
//    SDL_Init(SDL_INIT_VIDEO);
//
//    win = SDL_CreateWindow("Hello World", posX, posY, width, height, 0);
//
//    renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
//
//    bitmapSurface = SDL_LoadBMP("img/hello.bmp");
//    bitmapTex =  SDL_CreateTextureFromSurface( renderer,  bitmapSurface);
//    SDL_FreeSurface( bitmapSurface);
//
//    while ( 1)  {
//        SDL_Event e;
//        if ( SDL_PollEvent( & e))  {
//            if ( e.type ==  SDL_QUIT)  {
//                break;
//            }
//        }
//
//        SDL_RenderClear( renderer);
//        SDL_RenderCopy( renderer, bitmapTex, NULL, NULL);
//        SDL_RenderPresent(renderer);
//    }
//
//    SDL_DestroyTexture(bitmapTex);
//    SDL_DestroyRenderer(renderer);
//    SDL_DestroyWindow(win);
//
//    SDL_Quit();
//
//    return 0;
//}
