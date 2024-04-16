
/* Vertices coordinates of a Triangle
GLfloat vertices[] =
    {
        //               COORDINATES                  /     COLORS           //
        -0.5f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f, 0.8f, 0.3f, 0.02f,	 // Lower left corner
        0.5f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f, 0.8f, 0.3f, 0.02f,	 // Lower right corner
        0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f, 1.0f, 0.6f, 0.32f,	 // Upper corner
        -0.25f, 0.5f * float(sqrt(3)) * 1 / 6, 0.0f, 0.9f, 0.45f, 0.17f, // Inner left
        0.25f, 0.5f * float(sqrt(3)) * 1 / 6, 0.0f, 0.9f, 0.45f, 0.17f,	 // Inner right
        0.0f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f, 0.8f, 0.3f, 0.02f	 // Inner down
};

// Indices for vertices order
GLuint indices[] =
    {
        0, 3, 5, // Lower left triangle
        3, 2, 4, // Lower right triangle
        5, 4, 1	 // Upper triangle
};

// Vertices coordinates OF A COLORED RECTANGLE
GLfloat vertices[] =
    {
        //     COORDINATES     /        COLORS      /   TexCoord  //
        -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, // Lower left corner
        -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,  // Upper left corner
        0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,   // Upper right corner
        0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f   // Lower right corner
};

// Indices for vertices order
GLuint indices[] =
    {
        0, 2, 1, // Upper triangle
        0, 3, 2  // Lower triangle
};

*/