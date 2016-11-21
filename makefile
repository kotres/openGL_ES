#SRCS specifies which source files to compile as part of the project
SRCS= $(wildcard sources/*cpp)
#wildcard function is to get a list of all the CPP source files in sources

OBJS_WRONG_DIR := $(patsubst %cpp,%o,$(SRCS))
#patsubst finds and replaces all the cpp with o
#wrong_dir car ils ne sont pas localises dans sources

#OBJS_WRONG_DIR = $(SRCS:.cpp=.o)
OBJS = $(foreach file,$(OBJS_WRONG_DIR),objetsCompilation/$(notdir $(file)))
#on change "sources/objet.o" par "objetsCompilation/objet.o"

#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
COMPILER_FLAGS = -g -Wall -Wextra -std=c++11

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2 -lGL -lGLEW

#TARGET specifies the name of our exectuable
#TARGET = executable

#This is the target that compiles our executable
executable: ${OBJS}
	g++ $^ -o $@ $(LINKER_FLAGS)

#compilation des .o
objetsCompilation/%.o: sources/%.cpp
	g++ $< -o $@ -c $(COMPILER_FLAGS) -MD
# $@ and $^ are the left and right sides of the :

clean: 
	$(RM) executable count *~ objetsCompilation/* source/*~ shaders/*~
