
#define GLEW_STATIC
#define GL_LOG_FILE "gl.log"

#include <GL/glew.h>
#include <GLFW/glfw3.h> 
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
	GLFWwindow *window = NULL;
	const GLubyte *renderer;
	const GLubyte *version;
	GLuint cat_vao;
	GLuint laser_vao;
	GLuint c_points_vbo;
	GLuint c_colors_vbo;
	GLuint l_points_vbo;
	GLuint l_colors_vbo;
	static int frameCount;

	// All the points that make up the cat geometry 
	GLfloat c_points[] = {
					-0.35f, 0.18f, 0.0f,
					-0.13f, -0.01f, 0.0f,
					-0.28f, -0.1f, 0.0f,

					-0.05f, 0.03f, 0.0f,
					-0.09f, -0.09f, 0.0f,
					-0.31f, -0.12f, 0.0f,

					0.01f, 0.23f, 0.0f,
					-0.05f, -0.24f, 0.0f,
					-0.09f, -0.09f, 0.0f,

					0.01f, 0.23f, 0.0f,
					0.08f, -0.03f, 0.0f,
					-0.05f, -0.24f, 0.0f,

					0.08f, -0.03f, 0.0f,
					0.13f, -0.21f, 0.0f,
					-0.05f, -0.24f, 0.0f,

					0.01f, 0.23f, 0.0f,
					0.24f, -0.05f, 0.0f,
					0.13f, -0.21f, 0.0f,

					0.24f, -0.05f, 0.0f,
					0.37f, -0.11f, 0.0f,
					0.21f, -0.09f, 0.0f,

					0.21f, -0.09f, 0.0f,
					0.37f, -0.11f, 0.0f,
					0.46f, -0.37f, 0.0f,

					0.46f, -0.37f, 0.0f,
					0.52f, -0.52f, 0.0f,
					0.4f, -0.44f, 0.0f,

					0.4f, -0.44f, 0.0f,
					0.52f, -0.52f, 0.0f,
					0.44f, -0.56f, 0.0f,

					0.4f, -0.44f, 0.0f,
					0.44f, -0.56f, 0.0f,
					0.31f, -0.54f, 0.0f,

					0.21f, -0.09f, 0.0f,
					0.46f, -0.37f, 0.0f,
					0.31f, -0.54f, 0.0f,

					0.21f, -0.09f, 0.0f,
					0.31f, -0.54f, 0.0f,
					0.13f, -0.21f, 0.0f,

					0.31f, -0.54f, 0.0f,
					0.44f, -0.56f, 0.0f,
					0.42f, -0.72f, 0.0f,

					0.31f, -0.54f, 0.0f,
					0.42f, -0.72f, 0.0f,
					0.32f, -0.7f, 0.0f,

					0.31f, -0.54f, 0.0f,
					0.32f, -0.7f, 0.0f,
					0.18f, -0.62f, 0.0f,

					0.13f, -0.21f, 0.0f,
					0.31f, -0.54f, 0.0f,
					0.18f, -0.62f, 0.0f,

					0.13f, -0.21f, 0.0f,
					0.18f, -0.62f, 0.0f,
					-0.01f, -0.37f, 0.0f,

					0.13f, -0.21f, 0.0f,
					-0.01f, -0.37f, 0.0f,
					-0.05f, -0.24f, 0.0f,

					0.18f, -0.62f, 0.0f,
					0.32f, -0.7f, 0.0f,
					0.23f, -0.8f, 0.0f,

					0.18f, -0.62f, 0.0f,
					0.23f, -0.8f, 0.0f,
					0.06f, -0.78f, 0.0f,


					-0.01f, -0.37f, 0.0f,
					0.18f, -0.62f, 0.0f,
					0.06f, -0.67f, 0.0f,


					-0.01f, -0.37f, 0.0f,
					0.06f, -0.67f, 0.0f,
					-0.1f, -0.73f, 0.0f,


					0.18f, -0.62f, 0.0f,
					0.06f, -0.78f, 0.0f,
					0.02f, -0.69f, 0.0f,


					0.02f, -0.69f, 0.0f,
					0.06f, -0.78f, 0.0f,
					-0.1f, -0.73f, 0.0f,

					-0.09f, -0.09f, 0.0f,
					-0.05f, -0.24f, 0.0f,
					-0.31f, -0.12f, 0.0f,

					-0.31f, -0.12, 0.0f,
					-0.05f, -0.24f, 0.0f,
					-0.17f, -0.29f, 0.0f,

					-0.05f, -0.24f, 0.0f,
					-0.01f, -0.37f, 0.0f,
					-0.17f, -0.29f, 0.0f,

					-0.31f, -0.12f, 0.0f,
					-0.17f, -0.29f, 0.0f,
					-0.33f, -0.25f, 0.0f,

					-0.33f, -0.25f, 0.0f,
					-0.17f, -0.29f, 0.0f,
					-0.28f, -0.41f, 0.0f,

					-0.17f, -0.29f, 0.0f,
					-0.2f, -0.4f, 0.0f,
					-0.28f, -0.41f, 0.0f,

					-0.17f, -0.29f, 0.0f,
					-0.01f, -0.37f, 0.0f,
					-0.2f, -0.4f, 0.0f,

					-0.01f, -0.37f, 0.0f,
					-0.1f, -0.73f, 0.0f,
					-0.28f, -0.41f, 0.0f,

					-0.31f, -0.12f, 0.0f,
					-0.33f, -0.25f, 0.0f,
					-0.48f, -0.41f, 0.0f,

					-0.33f, -0.25f, 0.0f,
					-0.28f, -0.41f, 0.0f,
					-0.48f, -0.41f, 0.0f,

					-0.48f, -0.41f, 0.0f,
					-0.28f, -0.41f, 0.0f,
					-0.49f, -0.54f, 0.0f,

					-0.28f, -0.41f, 0.0f,
					-0.34f, -0.67f, 0.0f,
					-0.49f, -0.54f, 0.0f,

					-0.28f, -0.41f, 0.0f,
					-0.1f, -0.73f, 0.0f,
					-0.34f, -0.67f, 0.0f,

					-0.48f, -0.41f, 0.0f,
					-0.49f, -0.54f, 0.0f,
					-0.61f, -0.55f, 0.0f,

					-0.49f, -0.54f, 0.0f,
					-0.57f, -0.62f, 0.0f,
					-0.61f, -0.55f, 0.0f,

					-0.49f, -0.54f, 0.0f,
					-0.4f, -0.72f, 0.0f,
					-0.57f, -0.62f, 0.0f,

					-0.49f, -0.54f, 0.0f,
					-0.34f, -0.67f, 0.0f,
					-0.4f, -0.72f, 0.0f,

					-0.57f, -0.62f, 0.0f,
					-0.5f, -0.74f, 0.0f,
					-0.57f, -0.71f, 0.0f,

					-0.57f, -0.62f, 0.0f,
					-0.4f, -0.72f, 0.0f,
					-0.5f, -0.74f, 0.0f,

					-0.4f, -0.72f, 0.0f,
					-0.36f, -0.83f, 0.0f,
					-0.45f, -0.73f, 0.0f,

					-0.34f, -0.67f, 0.0f,
					-0.36f, -0.83f, 0.0f,
					-0.4f, -0.72f, 0.0f,

					-0.34f, -0.67f, 0.0f,
					-0.1f, -0.73f, 0.0f,
					-0.36f, -0.83f, 0.0f

					};

	// This adjusts the width so that it is the correct size for the window
	for (int i = 0; i < 423; i = i+3) {
		c_points[i] = c_points[i] / 2;
	}

	// The color values for the cat
	GLfloat c_colors[] = {
				0.31f, 0.12f, 0.03f,
				0.18f, 0.03f, 0.01f,
				0.22f, 0.03f, 0.01f, 

				0.76f, 0.51f, 0.18f,
				0.75f, 0.41f, 0.11f,
				0.76f, 0.51f, 0.18f, 

				0.93f, 0.69f, 0.6f,
				0.84f, 0.54f, 0.43f,
				0.93f, 0.69f, 0.6f, 

				0.84f, 0.54f, 0.43f,
				0.82f, 0.5f, 0.37f,
				0.82f, 0.5f, 0.37f, 

				0.78f, 0.39f, 0.29f,
				0.75f, 0.32f, 0.25f,
				0.78f, 0.39f, 0.29f, 

				0.52f, 0.19f, 0.04f,
				0.38f, 0.11f, 0.03f,
				0.38f, 0.11f, 0.03f, 

				0.75f, 0.41f, 0.11f, 
				0.76f, 0.51f, 0.18f, 
				0.75f, 0.41f, 0.11f, 
	
				0.18f, 0.03f, 0.01f, 
				0.52f, 0.19f, 0.04f, 
				0.52f, 0.19f, 0.04f, 

				0.52f, 0.19f, 0.04f, 
				0.38f, 0.11f, 0.03f, 
				0.31f, 0.12f, 0.03f, 

				0.76f, 0.51f, 0.18f, 
				0.85f, 0.61f, 0.29f, 
				0.85f, 0.61f, 0.29f, 

				0.64f, 0.33f, 0.05f, 
				0.75f, 0.41f, 0.11f, 
				0.64f, 0.33f, 0.05f, 
				
				0.51f, 0.25f, 0.03f, 
				0.75f, 0.41f, 0.11f, 
				0.64f, 0.33f, 0.05f, 

				0.75f, 0.41f, 0.11f, 
				0.85f, 0.61f, 0.29f, 
				0.75f, 0.41f, 0.11f, 

				0.38f, 0.11f, 0.03f, 
				0.52f, 0.19f, 0.04f, 
				0.52f, 0.19f, 0.04f, 

				0.76f, 0.51f, 0.18f, 
				0.85f, 0.61f, 0.29f, 
				0.85f, 0.61f, 0.29f, 

				0.51f, 0.25f, 0.03f, 
				0.64f, 0.33f, 0.05f, 
				0.64f, 0.33f, 0.05f, 

				0.64f, 0.33f, 0.05f, 
				0.64f, 0.33f, 0.05f, 
				0.75f, 0.41f, 0.11f, 

				0.64f, 0.33f, 0.05f, 
				0.75f, 0.41f, 0.11f, 
				0.64f, 0.33f, 0.05f, 

				0.89f, 0.74f, 0.5f, 
				0.89f, 0.74f, 0.5f, 
				0.85f, 0.61f, 0.29f, 

				0.38f, 0.11f, 0.03f, 
				0.52f, 0.19f, 0.04f, 
				0.38f, 0.11f, 0.03f, 

				0.31f, 0.12f, 0.03f, 
				0.76f, 0.51f, 0.18f, 
				0.85f, 0.61f, 0.29f, 

				0.31f, 0.12f, 0.03f, 
				0.38f, 0.11f, 0.03f, 
				0.64f, 0.33f, 0.05f, 

				0.64f, 0.33f, 0.05f, 
				0.75f, 0.41f, 0.11f, 
				0.64f, 0.33f, 0.05f, 

				0.31f, 0.12f, 0.03f, 
				0.76f, 0.51f, 0.18f, 
				0.76f, 0.51f, 0.18f, 

				0.51f, 0.25f, 0.03f, 
				0.51f, 0.25f, 0.03f, 
				0.64f, 0.33f, 0.05f, 

				0.76f, 0.51f, 0.18f, 
				0.76f, 0.51f, 0.18f, 
				0.85f, 0.61f, 0.29f, 
				
				0.76f, 0.51f, 0.18f, 
				0.75f, 0.41f, 0.11f, 
				0.75f, 0.41f, 0.11f, 

				0.85f, 0.61f, 0.29f, 
				0.76f, 0.51f, 0.18f, 
				0.85f, 0.61f, 0.29f, 

				0.76f, 0.51f, 0.18f, 
				0.75f, 0.41f, 0.11f, 
				0.85f, 0.61f, 0.29f, 

				0.61f, 0.8f, 0.29f, 
				0.21f, 0.66f, 0.29f, 
				0.61f, 0.8f, 0.29f, 

				0.85f, 0.83f, 0.79f, 
				0.81f, 0.76f, 0.71f, 
				0.85f, 0.83f, 0.79f, 

				0.52f, 0.19f, 0.04f, 
				0.38f, 0.11f, 0.03f, 
				0.38f, 0.11f, 0.03f, 

				0.85f, 0.61f, 0.29f, 
				0.75f, 0.41f, 0.11f, 
				0.75f, 0.41f, 0.11f, 

				0.85f, 0.61f, 0.29f, 
				0.85f, 0.61f, 0.29f, 
				0.89f, 0.74f, 0.5f, 

				0.89f, 0.74f, 0.5f, 
				0.89f, 0.74f, 0.5f, 
				0.85f, 0.61f, 0.29f, 

				0.64f, 0.33f, 0.05f, 
				0.85f, 0.61f, 0.29f,
				0.64f, 0.33f, 0.05f, 
				
				0.76f, 0.51f, 0.18f, 
				0.64f, 0.33f, 0.05f, 
				0.64f, 0.33f, 0.05f, 

				0.76f, 0.51f, 0.18f, 
				0.85f, 0.61f, 0.29f, 
				0.76f, 0.51f, 0.18f, 

				0.85f, 0.61f, 0.29f,
				0.76f, 0.51f, 0.18f, 
				0.75f, 0.41f, 0.11f, 

				0.84f, 0.54f, 0.43f, 
				0.78f, 0.39f, 0.29f,
				0.84f, 0.54f, 0.43f, 

				0.81f, 0.76f, 0.71f, 
				0.81f, 0.76f, 0.71f, 
				0.85f, 0.83f, 0.79f, 

				0.81f, 0.76f, 0.71f, 
				0.68f, 0.6f, 0.52f, 
				0.81f, 0.76f, 0.71f, 

				0.97f, 0.94f, 0.91f, 
				0.85f, 0.83f, 0.79f, 
				0.97f, 0.94f, 0.91f, 

				0.85f, 0.83f, 0.79f, 
				0.81f, 0.76f, 0.71f, 
				0.85f, 0.83f, 0.79f, 

				0.97f, 0.94f, 0.91f, 
				0.85f, 0.83f, 0.79f, 
				0.97f, 0.94f, 0.91f, 

				0.81f, 0.76f, 0.71f, 
				0.85f, 0.83f, 0.79f, 
				0.85f, 0.83f, 0.79f, 

				0.81f, 0.76f, 0.71f, 
				0.85f, 0.83f, 0.97f, 
				0.81f, 0.76f, 0.71f 	 

				};

	// The points for the laser
	GLfloat l_points[] = {
				-0.8f, -0.76f, 0.0f,
				-0.8f, -0.8f, 0.0f,
				-0.84f, -0.78f, 0.0f,

				-0.8f, -0.76f, 0.0f,
				-0.76f, -0.78f, 0.0f,
				-0.8f, -0.8f, 0.0f,

				-0.76f, -0.78f, 0.0f,
				-0.76f, -0.82f, 0.0f,
				-0.8f, -0.8f, 0.0f,

				-0.8f, -0.8f, 0.0f,
				-0.76f, -0.82f, 0.0f,
				-0.8f, -0.84f, 0.0f,

				-0.8f, -0.8f, 0.0f,
				-0.8f, -0.84f, 0.0f,
				-0.8f, -0.82f, 0.0f,

				-0.84f, -0.78f, 0.0f,
				-0.8f, -0.8f, 0.0f,
				-0.84f, -0.82f, 0.0f
				
				};

	// Adjusts laser width for window
	for (int i = 0; i < 54; i = i + 3) {
		l_points[i] = l_points[i] / 2;
	}

	// Laser color values
	GLfloat l_colors[] = {
				0.89f, 0.0f, 0.0f,
				0.89f, 0.0f, 0.0f,
				0.9f, 0.0f, 0.0f,

				0.89f, 0.0f, 0.0f,
				0.88f, 0.0f, 0.0f,
				0.89f, 0.0f, 0.0f,

				0.88f, 0.0f, 0.0f,
				0.88f, 0.0f, 0.0f,
				0.89f, 0.0f, 0.0f,

				0.89f, 0.0f, 0.0f,
				0.88f, 0.0f, 0.0f,
				0.89f, 0.0f, 0.0f,

				0.89f, 0.0f, 0.0f,
				0.89f, 0.0f, 0.0f,
				0.9f, 0.0f, 0.0f,

				0.9f, 0.0f, 0.0f,
				0.89f, 0.0f, 0.0f,
				0.9f, 0.0f, 0.0f
				
				};

	// these are the strings of code for the shaders the vertex shader positions each vertex point
	const char *vertex_shader = "#version 410\n"

		"layout(location = 0) in vec3 vertex_position;"
		"layout(location = 1) in vec3 vertex_colour;"

		"uniform mat4 matrix;"

		"out vec3 colour;"
		"void main () {"
		"	colour = vertex_colour;"
		"	gl_Position = matrix * vec4(vertex_position, 1.0);"
		"}";

	// the fragment shader colours each fragment (pixel-sized area of the triangle) 
	const char *fragment_shader = "#version 410\n"
		"in vec3 colour;"
		"out vec4 frag_colour;"
		"void main () {"
		"  frag_colour = vec4(colour, 1.0);"
		"}";

	// GL shader objects for vertex and fragment shader [components]
	GLuint vert_shader, frag_shader;
	// GL shader programme object [combined, to link] 
	GLuint shader_programme;

	// start GL context and O/S window using the GLFW helper library 
	if (!glfwInit()) {
		fprintf(stderr, "ERROR: could not start GLFW3\n");
		return 1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(1280, 480, "Laser Chase", NULL, NULL);
	if (!window) {
		fprintf(stderr, "ERROR: could not open window with GLFW3\n");
		glfwTerminate();
		
		return 1;
	}


	glfwMakeContextCurrent(window);

	// start GLEW extension handler 
	glewExperimental = GL_TRUE;
	glewInit();

	renderer = glGetString(GL_RENDERER); // get renderer string 
	version = glGetString(GL_VERSION);	 // version as a string 
	printf("Renderer: %s\n", renderer);
	printf("OpenGL version supported %s\n", version);

	/* tell GL to only draw onto a pixel if the shape is closer to the viewer than
		anything already drawn at that pixel*/
	glEnable(GL_DEPTH_TEST); // enable depth-testing 
	// with LESS depth-testing interprets a smaller depth value as meaning "closer" 
	glDepthFunc(GL_LESS);

	/* a vertex buffer object (VBO) is created here. this stores an array of data on the
		graphics adapter's memory. in our case - the vertex points */
	glGenBuffers(1, &c_points_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, c_points_vbo);
	glBufferData(GL_ARRAY_BUFFER, 423 * sizeof(GLfloat), c_points, GL_STATIC_DRAW);

	glGenBuffers(1, &c_colors_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, c_colors_vbo);
	glBufferData(GL_ARRAY_BUFFER, 423 * sizeof(GLfloat), c_colors, GL_STATIC_DRAW);

	/* the vertex array object (vao) is a little descriptor that defines which data from
		vertex buffer objects should be used as input variables to vertex shaders. in our
		case - use our only VBO, and say 'every three floats is a variable' */
	glGenVertexArrays(1, &cat_vao);
	glBindVertexArray(cat_vao);

	glBindBuffer(GL_ARRAY_BUFFER, c_points_vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	/* this VBO is already bound, but it's a good habit to explicitly specify which VBO's
		data the following vertex attribute pointer refers to */

		/* "attribute #0 is created from every 3 variables in the above buffer, of type float
			(i.e. make me vec3s)" */
	glBindBuffer(GL_ARRAY_BUFFER, c_colors_vbo);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, NULL);


	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	//						Second One

	glGenBuffers(1, &l_points_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, l_points_vbo);
	glBufferData(GL_ARRAY_BUFFER, 54 * sizeof(GLfloat), l_points, GL_STATIC_DRAW);

	glGenBuffers(1, &l_colors_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, l_colors_vbo);
	glBufferData(GL_ARRAY_BUFFER, 54 * sizeof(GLfloat), l_colors, GL_STATIC_DRAW);


	glGenVertexArrays(1, &laser_vao);
	glBindVertexArray(laser_vao);
	glBindBuffer(GL_ARRAY_BUFFER, l_points_vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glBindBuffer(GL_ARRAY_BUFFER, l_colors_vbo);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	/* here we copy the shader strings into GL shaders, and compile them. we then create an
		executable shader 'program' and attach both of the compiled shaders. we link this,
		which matches the outputs of the vertex shader to the inputs of the fragment shader,
		etc. and it is then ready to use */

		//						Shaders

	vert_shader = glCreateShader(GL_VERTEX_SHADER);
	const GLchar *p = (const GLchar *)vertex_shader;
	glShaderSource(vert_shader, 1, &p, NULL);
	glCompileShader(vert_shader);

	int params = -1;
	glGetShaderiv(vert_shader, GL_COMPILE_STATUS, &params);
	if (GL_TRUE != params) {
		fprintf(stderr, "ERROR: GL shader index %i did not compile\n", vert_shader);
		return 1;
	}

	frag_shader = glCreateShader(GL_FRAGMENT_SHADER);
	p = (const GLchar *)fragment_shader;
	glShaderSource(frag_shader, 1, &p, NULL);
	glCompileShader(frag_shader);

	glGetShaderiv(frag_shader, GL_COMPILE_STATUS, &params);
	if (GL_TRUE != params) {
		fprintf(stderr, "ERROR: GL shader index %i did not compile\n", frag_shader);
		return 1; // or exit
	}

	shader_programme = glCreateProgram();
	glAttachShader(shader_programme, frag_shader);
	glAttachShader(shader_programme, vert_shader);
	glLinkProgram(shader_programme);

	glGetProgramiv(shader_programme, GL_LINK_STATUS, &params);
	if (GL_TRUE != params) {
		fprintf(stderr, "ERROR: could not link shader programme GL index %i\n",
			shader_programme);
		return false;
	}


	//							Final Stuff

	GLfloat matrix[] = {
		1.0f, 0.0f, 0.0f, 0.0f, 
		0.0f, 1.0f, 0.0f, 0.0f, 
		0.0f, 0.0f, 1.0f, 0.0f, 
		0.5f, 0.0f, 0.0f, 1.0f
	};

	int matrix_location = glGetUniformLocation(shader_programme, "matrix");
	glUseProgram(shader_programme);
	glUniformMatrix4fv(matrix_location, 7, GL_FALSE, matrix);


	float speed = -0.5f; // move at 1 unit per second
	float lastPos = 0.0f;
	
	glClearColor(0.05f, 0.0f, 0.1f, 1.0f);
		

	/* this loop clears the drawing surface, then draws the geometry described by the VAO onto the
		drawing surface. we 'poll events' to see if the window was closed, etc. finally, we 'swap the
		buffers' which displays our drawing surface onto the view area. we use a double-buffering
		system which means that we have a 'currently displayed' surface, and 'currently being drawn'
		surface. hence the 'swap' idea. in a single-buffering system we would see stuff being drawn
		one-after-the-other */
	while (!glfwWindowShouldClose(window)) {
		
		static double lastSec = glfwGetTime();
		double currSec = glfwGetTime();
		double timePassed = currSec - lastSec;
		lastSec = currSec;

		if (timePassed > 0.25) {
			lastSec = currSec;
			double fps = (double)frameCount / timePassed;
			timePassed = 0;
		}
		frameCount++;
		

		// wipe the drawing surface clear 
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(shader_programme);

		matrix[12] = timePassed * speed + lastPos;
		lastPos = matrix[12];
		if (fabs(lastPos) > 1.0) {

			matrix[0] = matrix[0] * (-1);
			speed = -speed;
					
		}
		glUniformMatrix4fv(matrix_location, 1, GL_FALSE, matrix);

		glBindVertexArray(cat_vao);
		glDrawArrays(GL_TRIANGLES, 0, 141);

		glBindVertexArray(laser_vao);
		glDrawArrays(GL_TRIANGLES, 0, 6);

		// update other events like input handling 
		glfwPollEvents();
		// put the stuff we've been drawing onto the display 
		glfwSwapBuffers(window);
	}
 
	glfwTerminate();
	return 0;
}