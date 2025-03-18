all: engine.c
	@gcc engine.c -o engine -O2 -lpthread -lGL -lGLU -lglut -lm
