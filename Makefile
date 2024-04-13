SRC_DIR = src
BUILD_DIR = build/debug
CC = clang++
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(SRC_DIR)/*.c)
OBJ_NAME = game
INCLUDE_PATHS = -Iinclude -I/opt/homebrew/Cellar/glfw/3.4/include -I/opt/homebrew/Cellar/glm/1.0.1/include
LIBRARY_PATHS = -Llib -L/opt/homebrew/Cellar/glfw/3.4/lib -L/opt/homebrew/Cellar/glm/1.0.1/lib
COMPILER_FLAGS = -std=c++20 -Wall -Wno-deprecated -O0 -g
LINKER_FLAGS = -lglfw3 -lglm -framework Cocoa -framework OpenGL -framework IOKit

all:
	$(CC) $(COMPILER_FLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(SRC_FILES) -o $(BUILD_DIR)/$(OBJ_NAME) $(LINKER_FLAGS) && ./$(BUILD_DIR)/$(OBJ_NAME)