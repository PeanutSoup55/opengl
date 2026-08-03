#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "ogldev_math_3d.h"

using namespace std;

GLuint VBO;

static void RenderSceneCB(){
    glClear(GL_COLOR_BUFFER_BIT);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDisableVertexAttribArray(0);
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

    int width = 1920;
    int height = 1080;
    glutInitWindowSize(width, height);

    int x = 200;
    int y = 100;
    glutInitWindowPosition(x, y);

    // 1. CREATE WINDOW FIRST (Creates OpenGL Context)
    int win = glutCreateWindow("Tutorial 02 - First Point");
    printf("Window ID: %d\n", win);

    // 2. INITIALIZE GLEW SECOND (Loads OpenGL Function Pointers)
    GLenum res = glewInit();
    if (res != GLEW_OK) {
        cerr << "Error initializing GLEW: " << glewGetErrorString(res) << endl;
        return 1;
    }

    // 3. SET BACKGROUND COLOR & INITIALIZE BUFFERS
    GLclampf Red = 0.0f, Green = 0.0f, Blue = 0.0f, Alpha = 0.0f;
    glClearColor(Red, Green, Blue, Alpha);

    Vector3f Vertices[3];
    Vertices[0] = Vector3f(-1.0f, -1.0f, 0.0f);
    Vertices[1] = Vector3f(1.0f, -1.0f, 0.0f);
    Vertices[2] = Vector3f(0.0f, 1.0f, 0.0f);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);

    // 4. SET CALLBACK & START MAIN LOOP
    glutDisplayFunc(RenderSceneCB);
    glutMainLoop();

    return 0;
}