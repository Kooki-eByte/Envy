#define SDL_MAIN_HANDLED
#include "../include/envy.h"
#include "greed.h"
#include <SDL2/SDL.h>

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
bool is_game_running = false;

struct wall {
  float x;
  float y;
  float width;
  float height;
} wall;

bool init_window() {
  g_log_debug("initializing window.");
  window = SDL_CreateWindow("Envy", SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
  if (!window) {
    g_log_error("SDL Window failed to create.");
    return false;
  }

  g_log_debug("initializing renderer");
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (!renderer) {
    g_log_error("SDL Renderer failed to create render.");
    return false;
  }

  g_log_success("Window and Renderers were initialized.");
  return true;
}

void setup() {
  wall.x = WIDTH / 2;
  wall.y = HEIGHT / 2;
  wall.width = 100;
  wall.height = 50;
}

void process_input() {
  SDL_Event event;
  SDL_PollEvent(&event);

  switch (event.type) {
  case SDL_QUIT:
    is_game_running = false;
    break;
  default:
    break;
  }
};

void update() {};

void render() {
  g_log_debug("Rendering on screen.");
  SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
  SDL_RenderClear(renderer);

  /* Start to render game objects */
  /* ----------------------------- */
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_Rect wall_rect = {
      wall.x,
      wall.y,
      wall.width,
      wall.height,
  };

  SDL_RenderFillRect(renderer, &wall_rect);

  SDL_RenderPresent(renderer);
};

void destroy_window() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

int main(int argc, char *argv[]) {
  if (SDL_Init(SDL_INIT_EVERYTHING != 0)) {
    g_log_error("SDL failed to initialize!");
    return 1;
  }

  is_game_running = init_window();

  setup();

  while (is_game_running) {
    process_input();
    update();
    render();
  }

  g_log_debug("Envy closed.");
  return 0;
}
