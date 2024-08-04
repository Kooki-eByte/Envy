#define ENVY_ENGINE
#include "../include/envy_engine.h"

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
    /* Framerate */
    uint32 current_time = SDL_GetTicks();

    e_process_input();
    e_update();
    e_render();

    uint32 end_time = SDL_GetTicks() - current_time;

    if (FRAME_TARGET_TIME > end_time) {
      SDL_Delay(FRAME_TARGET_TIME - end_time);
    }

    printf("FPS: %f\n", ((f32)FRAME_TARGET_TIME - (f32)end_time));
  }

  g_log_debug("Envy closed.");
  return 0;
}
