#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main() {
    // Initialize GLFW (creates windows and contexts)
    glfwInit();
    
    // Create a window (800x600)
    GLFWwindow* window = glfwCreateWindow(800, 600, "My OpenGL Window", NULL, NULL);
    glfwMakeContextCurrent(window);

    // Initialize GLEW (loads OpenGL function pointers)
    glewInit();

    // Render loop
    while(!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        // Draw your triangles here...
        glfwSwapBuffers(window);  // display the rendered frame
        glfwPollEvents();         // handle input/events
    }

    glfwTerminate();
    return 0;
}