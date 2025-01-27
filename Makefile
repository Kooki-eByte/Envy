CC = gcc
VERSION = c89
CFLAGS = -Wall -Werror

SDL_CFLAGS = -I../SDL2/include
SDL_LDFLAGS = -L../SDL2/lib/
SDL_LIBS = -lSDL2 -lSDL2main

LDFLAGS = -L../Greed/lib -L../Sloth/lib $(SDL_LDFLAGS)
LDLIBS = -lgreed -lsloth $(SDL_LIBS)
INCFLAGS = -I./include -I../Greed/include -I../Sloth/include $(SDL_CFLAGS)
TARGET = envy

SRC = ./src/main.c ./src/render/e_render.c ./src/inputProcess/e_process_input.c
OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -std=$(VERSION) $(LDFLAGS) -o $@ $^ $(LDLIBS)

%.o: %.c
	$(CC) -std=$(VERSION) $(CFLAGS) $(INCFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET)
