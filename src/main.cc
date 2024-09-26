#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main(void)
{
    if( glfwInit() != GLFW_TRUE )
    {
        std::cout << "Failed to initialize GLFW\n";		
        return -1;
    }
	
    auto window = glfwCreateWindow(800, 600, "DEMO", NULL, NULL);
    glfwMakeContextCurrent(window);

    if( !gladLoadGLLoader((GLADloadproc)(glfwGetProcAddress)) )
    {
        std::cout << "Failed to initialize GLAD\n";
        return -2;
    }

    glfwShowWindow(window);
	
    glClearColor( 0.25f, 0.65f, 0.25f, 1.0f );

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
}
