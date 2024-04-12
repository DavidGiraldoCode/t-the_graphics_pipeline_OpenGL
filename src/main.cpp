//#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

// #include <OpenGL/gl.h>
// #include <OpenGL/glext.h>
// #endif

using namespace std;
#define numVAOs 1

GLuint renderingProgram;
GLuint vao[numVAOs];

GLuint createShaderProgram()
{
    const char *vshaderSource =
        "#version 410 \n"
        "void main(void) \n"
        "{ gl_Position = vec4(0.0, 0.0, 0.0, 1.0); }";
    const char *fshaderSource =
        "#version 410 \n"
        "out vec4 color; \n"
        "void main(void) \n"
        "{ color = vec4(0.0, 0.0, 1.0, 1.0);}";

    GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(vShader, 1, &vshaderSource, NULL);

    glShaderSource(fShader, 1, &fshaderSource, NULL);

    glCompileShader(vShader);
    glCompileShader(fShader);

    GLint status;
    glGetShaderiv(vShader, GL_COMPILE_STATUS, &status);
    if (status != GL_TRUE)
    {
        char buffer[512];
        glGetShaderInfoLog(vShader, 512, NULL, buffer);
        cerr << "Vertex shader compilation failed: " << buffer << std::endl;
        return -1;
    }

    glGetShaderiv(fShader, GL_COMPILE_STATUS, &status);
    if (status != GL_TRUE)
    {
        char buffer[512];
        glGetShaderInfoLog(fShader, 512, NULL, buffer);
        std::cerr << "Fragment shader compilation failed: " << buffer << std::endl;
        exit(EXIT_FAILURE);
    }

    GLuint vfProgram = glCreateProgram();
    glAttachShader(vfProgram, vShader);
    glAttachShader(vfProgram, fShader);

    glLinkProgram(vfProgram);

    glGetProgramiv(vfProgram, GL_LINK_STATUS, &status);
    if (status != GL_TRUE)
    {
        char buffer[512];
        glGetProgramInfoLog(vfProgram, 512, NULL, buffer);
        std::cerr << "Shader program linking failed: " << buffer << std::endl;
        exit(EXIT_FAILURE);
    }

    return vfProgram;
}

void init(GLFWwindow *window)
{
    renderingProgram = createShaderProgram();
    // glGenVertexArraysAPPLE(numVAOs, vao);
    // glBindVertexArrayAPPLE(vao[0]);
    glGenVertexArrays(numVAOs, vao);
    glBindVertexArray(vao[0]);
}

void display(GLFWwindow *window, double currentTime)
{
    /*curentTime ensures that our animations run at the same speed regardless of the computer being used.*/
    /*filled the color buffer with a single color.*/
    // glClearColor(1.0, 0.0, 0.0, 1.0);
    // glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(renderingProgram);
    // std::cout << "Display\n";
    glPointSize(30.0f);
    glDrawArrays(GL_POINTS, 0, 1);
}

int main(int argc, char *argv[])
{
    GLFWwindow *window;

    /* Initialize the library */
    if (!glfwInit())
    {
        return -1;
    }
    /* window hints specify that the machine must be compatible with OpenGL version 4*/
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    // glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    /* Create a windowed mode window and its OpenGL context */
    /*Last two parms allow full screen mode and resource sharing*/
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    const GLubyte *renderer = glGetString(GL_RENDERER);
    const GLubyte *version = glGetString(GL_VERSION);
    std::cout << "Renderer: " << renderer << std::endl;
    std::cout << "OpenGL version supported: " << version << std::endl;

    /*Vertical synchronization (VSync) is enabled*/
    glfwSwapInterval(1);
    init(window);
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        /*glfwGetTime() returns the elapsed time since GLFW was initialized.*/
        display(window, glfwGetTime());

        /* Swap front and back buffers, which paints the screen*/
        glfwSwapBuffers(window);

        /* Poll for and process events, handles other window-related events (such as a key being pressed) */
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}