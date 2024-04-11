SRC_DIR = src
BUILD_DIR = build/debug
CC = g++
SRC_FILES = ${wildcard ${SRC_DIR}/*.cpp}
OBJ_NAME = game
INCLUDE_PATHS = -Iinclude -I/opt/homebrew/Cellar/glfw/3.4/include
LIBRARY_PATHS = -Llib -L/opt/homebrew/Cellar/glfw/3.4/lib
COMPILER_FLAGS = -std=c++20 -Wall -O0 -g
LINKER_FLAGS = -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit

all:
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(SRC_FILES) -o $(BUILD_DIR)/$(OBJ_NAME) && ./$(BUILD_DIR)/$(OBJ_NAME)