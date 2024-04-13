#define STB_IMAGE_IMPLEMENTATION
#include<stb/stb_image.h>
/*
This specifies only the thing we need from the library
This library should be compile once, but in the current Makefile implementation, its being compiled at every build

Current Warnings:
include/stb/stb_image.h:6778:11: warning: variable 'out_size' set but not used [-Wunused-but-set-variable]
      int out_size = 0;
          ^
include/stb/stb_image.h:6779:11: warning: variable 'delays_size' set but not used [-Wunused-but-set-variable]
      int delays_size = 0;
*/