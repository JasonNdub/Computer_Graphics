#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <math.h>

void DrawCircle(float cx, float cy, float rx, float ry, int num_segments) {
    glBegin(GL_TRIANGLE_FAN);
    for(int ii = 0; ii < num_segments; ii++) {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments); // get the current angle
        float x = rx * cosf(theta); // calculate the x component
        float y = ry * sinf(theta); // calculate the y component

        glVertex2f(x + cx, y + cy); // output vertex
    }
    glEnd();
}

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glOrtho(-500.0, 500.0, -300.0, 300.0, -1.0, 1.0);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0f,0.6f,0.4f);
    glBegin(GL_QUADS); //For Quads
    glVertex3d(60.0,40.0,0.0);
    glVertex3d(-60.0,40.0,0.0);
    glVertex3d(-60.0,-40.0,0.0);
    glVertex3f(60.0,-40.0,0.0);
    glEnd();

    glColor3f(0.0f,0.5f,0.5f);
    glBegin(GL_QUADS); //For Quads Pipe
    glVertex3d(-60.0,40.0,0.0);
    glVertex3d(-65.0,40.0,0.0);
    glVertex3d(-65.0,-130.0,0.0);
    glVertex3f(-60.0,-130.0,0.0);
    glEnd();

    glColor3f(0.0f,0.3f,0.4f);
    glBegin(GL_QUADS); //For Quads Pipe Base
    glVertex3d(-40.0,-130.0,0.0);
    glVertex3d(-85.0,-130.0,0.0);
    glVertex3d(-85.0,-150.0,0.0);
    glVertex3f(-40.0,-150.0,0.0);
    glEnd();


    glColor3f(0.9, 0.1, 0.0);
    DrawCircle(0, 0, 15, 15, 100); //For Circle

    glFlush();
}

int main(int argc, char** argv) {
    // Initialize GLUT
    //Initial GLUT and process command-line arguments....
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Circle");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
