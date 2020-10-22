#include <stdio.h>
#include <GLUT/GLUT.h>

#define GL_SILENCE_DEPRECATION

// FUNCTIONS
void display();
void init();
void resize(int width, int height);

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    
    glutInitWindowSize(1000, 720);
    glutInitWindowPosition(100, 100);
    
    glutCreateWindow("Hello");
    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    init();
    
    glutMainLoop();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    // rendering triangle
    glPointSize(10.0);
    glBegin(GL_TRIANGLES);
    
    glColor3f(1.0,0,0);
    glVertex2f( 0,  5);
    
    glColor3f(0,1.0,0);
    glVertex2f(-5, -5);
    
    glColor3f(0,0,1.0);
    glVertex2f( 5, -5);
    
    glEnd();
    glFlush();
}

void init() {
    glClearColor(0,0,0,1.0);
}

void resize(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    gluOrtho2D(-10, 10, -10, 10);
    glMatrixMode(GL_MODELVIEW);
    glEnd();
}
