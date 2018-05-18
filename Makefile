BIN = explosion

SRCS = main.cpp Util.cpp Input.cpp Sdl.cpp Sops.cpp Sprite.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)

CFLAGS = -Wshadow -Wall -Wpedantic -Wextra -g
LDFLAGS = -lm -lSDL2

$(BIN): $(OBJS)
	clang++ -std=c++11 $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(BIN)

%.o : %.cpp Makefile
	clang++ -std=c++11 $(CFLAGS) -MMD -MP -MT $@ -MF $*.td -c $<
	mv -f $*.td $*.d

%.d: ;
-include *.d

clean:
	rm -f $(BIN) $(OBJS) $(DEPS)
