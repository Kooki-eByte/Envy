#ifndef ENVY_MAIN
#define ENVY_MAIN
#define WIDTH 1280
#define HEIGHT 720
#define FPS 60
#define FRAME_TARGET_TIME (1000 / FPS)
#define SDL_MAIN_HANDLED

#include "greed.h"
#include "sloth.h"
#include <SDL2/SDL.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#ifndef ENVY_ENGINE
#define ENVY_ENGINE
extern bool is_game_running;
extern bool e_init_window(void);
extern void e_setup(void);
/* Envy Gameloop */
/* ------------- */

/* Envy Update */
/* ----------- */
extern void e_update(void);
extern void e_destroy_window(void);
#endif

/* Envy User Input Process */
/* ----------------------- */
#ifndef ENVY_PROCESS_INPUT
#define ENVY_PROCESS_INPUT
extern void e_process_input(void);
#endif

/* Envy Renderer */
/* ------------- */
#ifndef ENVY_RENDER
#define ENVY_RENDER
extern SDL_Renderer *e_renderer;
extern bool e_render_init(SDL_Window *window);
extern void e_render(void);
extern void e_render_quad(vec2, vec2, vec4);
/* ------------- */
#endif
#endif
