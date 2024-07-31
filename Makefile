CC = gcc
VERSION = c89
CFLAGS = -Wall -Werror

SDL_CFLAGS = -I../SDL2/include
SDL_LDFLAGS = -L../SDL2/lib/
SDL_LIBS = -lSDL2 -lSDL2main

LDFLAGS = -L../Greed/lib $(SDL_LDFLAGS)
LDLIBS = -lgreed $(SDL_LIBS)
INCFLAGS = -I./include -I../Greed/include $(SDL_CFLAGS)
TARGET = envy

all: $(TARGET)

$(TARGET): main.o
	$(CC) -std=$(VERSION) $(LDFLAGS) -o $@ $^ $(LDLIBS)

main.o: src/main.c
	$(CC) -std=$(VERSION) $(CFLAGS) $(INCFLAGS) -c $^

clean:
	rm -f *.o
