#define ENVY_ENGINE
#include "../include/envy.h"

SDL_Window *window = NULL;
bool is_game_running = false;

bool e_init_window(void) {
  g_log_debug("initializing window.");
  window = SDL_CreateWindow("Envy", SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
  if (!window) {
    g_log_error("SDL Window failed to create.");
    return false;
  }

  bool render = e_render_init(window);
  if (!render) {
    return false;
  }

  g_log_success("Window and Renderers were initialized.");
  return true;
}

void e_setup(void) {}

void e_process_input(void) {
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

void e_update(void) {};

void e_destroy_window(void) {
  SDL_DestroyRenderer(e_renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

int main(int argc, char *argv[]) {
  if (SDL_Init(SDL_INIT_EVERYTHING != 0)) {
    g_log_error("SDL failed to initialize!");
    return 1;
  }

  is_game_running = e_init_window();

  e_setup();

  while (is_game_running) {
    e_process_input();
    e_update();
    e_render();
  }

  g_log_debug("Envy closed.");
  return 0;
}
