#define SDL_MAIN_HANDLED
#include "../include/envy.h"
#include "greed.h"
#include <SDL2/SDL.h>

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

int init_window() {
  g_log_debug("initializing window.");
  window = SDL_CreateWindow("Envy", SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
  if (!window) {
    g_log_error("SDL Window failed to create.");
    return 1;
  }

  g_log_debug("initializing renderer");
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (!renderer) {
    g_log_error("SDL Renderer failed to create render.");
    return 1;
  }

  bool running = true;
  while (running) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_QUIT:
        g_log_debug("Attempted to close Envy Engine.");
        running = false;
        break;
      default:
        break;
      }
    }

    SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);
  }

  return 0;
}

int main(int argc, char *argv[]) {
  if (SDL_Init(SDL_INIT_EVERYTHING != 0)) {
    g_log_error("SDL failed to initialize!");
    return 1;
  }

  init_window();
  g_log_success("Envy closed.");
  return 0;
}
