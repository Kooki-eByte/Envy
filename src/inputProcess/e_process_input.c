#define ENVY_PROCESS_INPUT
#include "../../include/envy_engine.h"

void e_process_input() {
  SDL_Event e;
  SDL_PollEvent(&e);

  switch (e.type) {
  case SDL_QUIT:
    is_game_running = false;
    break;
  default:
    break;
  }
}
