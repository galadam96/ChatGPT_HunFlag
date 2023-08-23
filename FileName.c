#include <stdio.h>
#include <SDL.h>

#define WIDTH 1920
#define HEIGHT 1080

void drawFlag(SDL_Renderer* renderer, int x, int y) {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Piros s�v
    SDL_Rect redRect = { x, y, WIDTH, HEIGHT / 3 };
    SDL_RenderFillRect(renderer, &redRect);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Feh�r s�v
    SDL_Rect whiteRect = { x, y + HEIGHT / 3, WIDTH, HEIGHT / 3 };
    SDL_RenderFillRect(renderer, &whiteRect);

    SDL_SetRenderDrawColor(renderer, 0, 128, 0, 255); // K�k s�v
    SDL_Rect blueRect = { x, y + HEIGHT * 2 / 3, WIDTH, HEIGHT / 3 };
    SDL_RenderFillRect(renderer, &blueRect);
}

int main() {
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    window = SDL_CreateWindow("Magyar Z�szl�", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Event event;
    int quit = 0;

    while (!quit) {
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit = 1;
            }
        }

        // Rajzoljuk a z�szl�t az ablak k�zep�n
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        int flagX = (WIDTH - WIDTH) / 2;
        int flagY = (HEIGHT - HEIGHT) / 2;
        drawFlag(renderer, flagX, flagY);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}