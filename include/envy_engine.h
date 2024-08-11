#ifndef ENVY_MAIN
#define ENVY_MAIN
#include <vcruntime.h>
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

typedef struct Triangle {
  Vec3 p[3];
} Triangle;

typedef struct Mesh {
  Triangle *tris; // Dynamic Array for amount of triangles.
  size_t numTris;
} Mesh;

extern SDL_Renderer *e_renderer;
extern bool e_render_init(SDL_Window *window);
extern void e_render(void);
extern void e_render_quad(Vec2 *pos, Vec2 *size, Vec4 *color);
/* ------------- */
#endif
#endif
