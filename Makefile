src = main.cpp window.cpp
out = -o game
lib = -lSDL2 -lSDL2_image -lSDL2_ttf
flags = -std=c++11

all: $(src)
	g++ $(src) $(out) $(lib) $(flags) 