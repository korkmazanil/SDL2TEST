//
//  main.cpp
//  SDL2TEST
//
//  Created by ANIL KORKMAZ on 4.12.2023.
//

#include <SDL2/SDL.h>
#include <math.h>

using namespace std;

int main() {

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("SDL başlatılamadı: %s", SDL_GetError());
        return 1;
    }

    int screenWidth = 800;
    int screenHeight = 600;

    SDL_Window* window = SDL_CreateWindow("SDL2 Şekil Örneği", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_FULLSCREEN);
    if (!window) {
        SDL_Log("Pencere oluşturulamadı: %s", SDL_GetError());
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        SDL_Log("Renderer oluşturulamadı: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    bool quit = false;
    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
                quit = true;
            }
        }

        // Ekranı temizleme
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        
        // Çizgi çizme
               SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
               SDL_RenderDrawLine(renderer, 100, 100, 700, 500);

        // Kare çizme
        SDL_Rect squareRect = {200, 200, 100, 100};
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &squareRect);

        // Yuvarlak çizme
        int circleX = 500;
        int circleY = 400;
        int circleRadius = 50;
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        for (int i = 0; i < 360; ++i) {
            float angle = i * (M_PI / 180.0f);
            int x = static_cast<int>(circleX + circleRadius * cos(angle));
            int y = static_cast<int>(circleY + circleRadius * sin(angle));
            SDL_RenderDrawPoint(renderer, x, y);
        }

        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}


