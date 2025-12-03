#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>

static int flag = 0;
float ball_x = 0.5, ball_y = 0.0, ball_z = 0.0;

void glutInitRendering() {
    glEnable(GL_DEPTH_TEST);
}

void reshaped(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, 0, 1, 200);
}

void updateBall() {
    if (!flag) {
        ball_y += 0.0005; 
        if (ball_y > 1.0)
            flag = 1;
    }
    if (flag) {
        ball_y -= 0.0005;
        if (ball_y < -1)
            flag = 0;
    }
    glutPostRedisplay(); 
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0, 1, 0, 0); 

    glPushMatrix();
    glColor3f(1, 1, 0); 
    glTranslatef(ball_x, ball_y, ball_z);
    glutSolidSphere(0.1, 23, 23);
    glPopMatrix();

    updateBall();
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(700, 800);
    glutCreateWindow("OpenGL Animation- Bouncing Ball");
    glutInitRendering();
    glutDisplayFunc(display);
    glutReshapeFunc(reshaped);
    glutMainLoop();
    return 0;
}