#include "shaderClass.h"
/*
fragmentCode = get_file_contents(fragmentFile);
// Reads a text file and outputs a string with everything in the text file
std::string get_file_contents(const char *filename)
{
	std::ifstream in(filename, std::ios::binary);
	if (in)
	{
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return (contents);
	}
	throw(errno);
}
*/
// Vertex Shader source code
const char *vertexSource = "#version 330 core\n"
						   "layout (location = 0) in vec3 aPos;\n"
						   "void main()\n"
						   "{\n"
						   "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
						   "}\0";
// Fragment Shader source code
const char *fragmentSource = "#version 330 core\n"
							 "out vec4 FragColor;\n"
							 "void main()\n"
							 "{\n"
							 "   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
							 "}\n\0";

// Constructor that build the Shader Program from 2 different shaders
Shader::Shader(const char *vertexFile, const char *fragmentFile)
{

	/*
	std::cout << "Shader Constructor " << vertexFile << std::endl;

	std::string vertexCode;
	std::string fragmentCode;

	// Read vertexFile and fragmentFile and store the strings
	try
	{
		// vertexCode = get_file_contents(vertexFile);
		std::cout << vertexCode << std::endl;
		// fragmentCode = get_file_contents(fragmentFile);
	}
	catch (const std::exception &e)
	{
		// Handle the exception here
		std::cerr << "Exception occurred: " << e.what() << std::endl;
		// You can choose to log the error, display a message to the user, or take any other appropriate action
	}
	// const char *vertexSource = vertexCode.c_str();
	// Convert the shader source strings into character arrays
	const char *vertexSource = vertexCode.c_str();
	const char *fragmentSource = fragmentCode.c_str();
	*/

	// Create Vertex Shader Object and get its reference
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	// Attach Vertex Shader source to the Vertex Shader Object
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	// Compile the Vertex Shader into machine code
	glCompileShader(vertexShader);

	// Create Fragment Shader Object and get its reference
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	// Attach Fragment Shader source to the Fragment Shader Object
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	// Compile the Vertex Shader into machine code
	glCompileShader(fragmentShader);

	// Create Shader Program Object and get its reference
	ID = glCreateProgram();
	// Attach the Vertex and Fragment Shaders to the Shader Program
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);
	// Wrap-up/Link all the shaders together into the Shader Program
	glLinkProgram(ID);

	// Delete the now useless Vertex and Fragment Shader objects
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

// Activates the Shader Program
void Shader::Activate()
{
	glUseProgram(ID);
}

// Deletes the Shader Program
void Shader::Delete()
{
	glDeleteProgram(ID);
}