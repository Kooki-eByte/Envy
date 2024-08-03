#include "../../include/envy.h"

SDL_Renderer *e_renderer = NULL;

struct wall {
  f32 x;
  f32 y;
  f32 width;
  f32 height;
} wall;

bool e_render_init(SDL_Window *window) {
  g_log_debug("Initializing renderer.");

  e_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (!e_renderer) {
    g_log_error("SDL Renderer failed to create render.");
    return false;
  }

  g_log_success("Renderer initialized.");
  return true;
}

void e_render(void) {
  g_log_debug("Rendering on screen.");
  SDL_SetRenderDrawColor(e_renderer, 255, 0, 255, 255);
  SDL_RenderClear(e_renderer);

  wall.x = (WIDTH / 2) + 100;
  wall.y = (HEIGHT / 2) + 50;
  wall.width = 200;
  wall.height = 100;
  /* Start to render game objects */
  /* ----------------------------- */
  SDL_SetRenderDrawColor(e_renderer, 255, 255, 255, 255);
  SDL_Rect wall_rect = {
      wall.x,
      wall.y,
      wall.width,
      wall.height,
  };

  SDL_RenderFillRect(e_renderer, &wall_rect);

  SDL_RenderPresent(e_renderer);
}
