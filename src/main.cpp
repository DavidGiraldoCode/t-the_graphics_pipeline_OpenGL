/*
David Giraldo 2024 May, Stockholm.
Tutorial: https://learnopengl.com/Getting-started/Hello-Window
Original source code: https://learnopengl.com/code_viewer_gh.php?code=src/1.getting_started/1.2.hello_window_clear/hello_window_clear.cpp

Status 2024 05 05 - 14:10:
- Reading about Vertex Shader the VBO and the binding process.
https://learnopengl.com/Getting-started/Hello-Triangle

*/
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

//Thirdparty open source library
#include<stb/stb_image.h>
#include"Texture.h"

#include "shaderClass.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"

//GLM
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main(int argc, char* argv[])
{
    // glfw: initialize and configure------------------------------
    glfwInit();
	/*
	glfwWindowHint allow the configuration of the GLFW window, the enum with prefix GLFW_ 
	states what is being configured
	https://www.glfw.org/docs/latest/window.html#window_hints
	*/
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //explicitly use the core-profile.

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", nullptr, nullptr);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    

    // glad: load all OpenGL function pointers ---------------------------------------
	/*
	The address of the OpenGL function pointers is OS-specific.
	glfwGetProcAddress defines the function based on the target OS.
	*/
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }    
	
	// Registering Callback everytime the framebuffer is resized
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // RENDER loop ---------------------------------------------------------------------
    while (!glfwWindowShouldClose(window)) //Check if the window has been closed
    {
        // Input
        /*
		In interactive Computer Graphics, the program checks at every start of a new frame
		what (data, states) has change, and proccede accordingly. This is resonsiveness.
		*/
        processInput(window);

        // Render -----------------------------------------------------------------------
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f); //State-setting function
        glClear(GL_COLOR_BUFFER_BIT); //State-using function

		// Swap Frame Buffer ------------------------------------------------------------
        /* 
		glfw Double Buffer:
		- Front Buffer: Holds the final pixels tha the user can see
		- Back Buffer: Is where the rendering process happens(setting a color to each pixel left-rigth, top-bottom)
		Once the back buffers finishes, the program swaps the two buffers.
		*/
        glfwSwapBuffers(window);
		
		// glfw: poll IO events (keys pressed/released, mouse moved etc.)
        glfwPollEvents(); // Check for events
    }

    // glfw: terminate, clearing all previously allocated GLFW resources. -----------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
	/*
	Some commun keys:
	GLFW_KEY_A W S D
	GLFW_KEY_ENTER
	GLFW_KEY_RIGHT LEFT, UP, DOWN
	*/
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

	if(glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
		std::cout << "Space pressed" << std::endl;
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}
