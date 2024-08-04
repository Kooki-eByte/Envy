#include "../../include/envy_engine.h"

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
  SDL_SetRenderDrawColor(e_renderer, 255, 0, 255, 255);
  SDL_RenderPresent(e_renderer);
}

void e_render_quad(vec2 pos, vec2 size, vec4 color) {
  SDL_RenderClear(e_renderer);
  SDL_SetRenderDrawColor(e_renderer, color.x, color.y, color.z, color.w);

  SDL_Rect rect = {
      pos.x,
      pos.y,
      size.x,
      size.y,
  };

  SDL_RenderFillRect(e_renderer, &rect);
}
