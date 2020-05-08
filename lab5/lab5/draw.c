//
//  draw.c
//  lab5
//
//  Created by Данил Морозов on 09/05/2020.
//  Copyright © 2020 Данил Морозов. All rights reserved.
//
 
#include "draw.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>

  

int main()

{

  

    // возвращает ноль при успехе, иначе не ноль

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {

        printf("error initializing SDL: %s\n", SDL_GetError());

    }

    SDL_Window* win = SDL_CreateWindow("GAME", // создает окно

                                       SDL_WINDOWPOS_CENTERED,

                                       SDL_WINDOWPOS_CENTERED,

                                       1000, 1000, 0);

  

    // запускает программу, которая контролирует

    // ваше графическое оборудование и устанавливает флаги

    Uint32 render_flags = SDL_RENDERER_ACCELERATED;

  

    // создаем рендер для рендеринга наших изображений

    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);

  

    // создаем поверхность для загрузки изображения в основную память

    SDL_Surface* surface;

  

    // укажите путь к вашему изображению

    surface = IMG_Load("path");

  

    // загружает изображение в нашу графическую аппаратную память.

    SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, surface);

  

    // очищает основную память

    SDL_FreeSurface(surface);

  

    // давайте контролировать нашу позицию изображения

    // чтобы мы могли переместить его с помощью клавиатуры.

    SDL_Rect dest;

  

    // соединяет нашу текстуру с dest для контроля положения

    SDL_QueryTexture(tex, NULL, NULL, &dest.w, &dest.h);

  

    // настроить высоту и ширину нашего окна изображения.

    dest.w /= 6;

    dest.h /= 6;

  

    // устанавливает начальную x-позицию объекта

    dest.x = (1000 - dest.w) / 2;

  

    // устанавливает начальную y-позицию объекта

    dest.y = (1000 - dest.h) / 2;

  

    // контролирует цикл анимации

    int close = 0;

  

    // скорость коробки

    int speed = 300;

  

    // цикл анимации

    while (!close) {

        SDL_Event event;

  

        // Управление событиями

        while (SDL_PollEvent(&event)) {

            switch (event.type) {

  

            case SDL_QUIT:

                // обработка кнопки закрытия

                close = 1;

                break;

  

            case SDL_KEYDOWN:

                // клавиатура API для нажатой клавиши

                switch (event.key.keysym.scancode) {

                case SDL_SCANCODE_W:

                case SDL_SCANCODE_UP:

                    dest.y -= speed / 30;

                    break;

                case SDL_SCANCODE_A:

                case SDL_SCANCODE_LEFT:

                    dest.x -= speed / 30;

                    break;

                case SDL_SCANCODE_S:

                case SDL_SCANCODE_DOWN:

                    dest.y += speed / 30;

                    break;

                case SDL_SCANCODE_D:

                case SDL_SCANCODE_RIGHT:

                    dest.x += speed / 30;

                    break;

                }

            }

        }

  

        // правая граница

        if (dest.x + dest.w > 1000)

            dest.x = 1000 - dest.w;

  

        // левая граница

        if (dest.x < 0)

            dest.x = 0;

  

        // нижняя граница

        if (dest.y + dest.h > 1000)

            dest.y = 1000 - dest.h;

  

        // верхняя граница

        if (dest.y < 0)

            dest.y = 0;

  

        // очищает экран

        SDL_RenderClear(rend);

        SDL_RenderCopy(rend, tex, NULL, &dest);

  

        // запускает двойные буферы

        // для многократного рендеринга

        SDL_RenderPresent(rend);

  

        // вычисляет до 60 кадров в секунду

        SDL_Delay(1000 / 60);

    }

  

    // уничтожить текстуру

    SDL_DestroyTexture(tex);

  

    // уничтожаем рендерер

    SDL_DestroyRenderer(rend);

  

    // разрушаем окно

    SDL_DestroyWindow(win);

    return 0;

}
