#include <windows.h>
#include <stdio.h>
#include <math.h>
#include <gl/glut.h>

GLint ch;
GLint p1[] = {350, 400};
GLint p2[] = {500, 400};
GLint p3[] = {425, 500};
GLint tx = 100;
GLint ty = 100;
GLint rp1[2], rp2[2], rp3[3];
GLint theta = 90, t;
GLint sx = 2; 
int sy = 1;

void drawTri() {
    glBegin(GL_TRIANGLES);
    glVertex2iv(p1);
    glVertex2iv(p2);
    glVertex2iv(p3);
    glEnd();
    glFlush();
}

void transTri() {
    p1[0] = p1[0] + tx;
    p1[1] = p1[1] + ty;
    p2[0] = p2[0] + tx;
    p2[1] = p2[1] + ty;
    p3[0] = p3[0] + tx;
    p3[1] = p3[1] + ty;
}

void rotateTri() {
    float rad = 3.14 * theta / 180;
    rp1[0] = abs(p1[0] * cos(rad) - p1[1] * sin(rad));
    rp1[1] = abs(p1[0] * sin(rad) + p1[1] * cos(rad));
    rp2[0] = abs(p2[0] * cos(rad) - p2[1] * sin(rad));
    rp2[1] = abs(p2[0] * sin(rad) + p2[1] * cos(rad));
    rp3[0] = abs(p3[0] * cos(rad) - p3[1] * sin(rad));
    rp3[1] = abs(p3[0] * sin(rad) + p3[1] * cos(rad));

    glColor3f(1.0, 0.0, 1.0);
    glBegin(GL_TRIANGLES);
    glVertex2iv(rp1);
    glVertex2iv(rp2);
    glVertex2iv(rp3);
    glEnd();
    glFlush();
}

void scaleTri() {
    p1[0] = p1[0] * sx;
    p1[1] = p1[1] * sy;
    p2[0] = p2[0] * sx;
    p2[1] = p2[1] * sy;
    p3[0] = p3[0] * sx;
    p3[1] = p3[1] * sy;
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0, 1.0, 1.0, 0.0);

    if (ch == 1) {
        glColor3f(0.0, 0.0, 1.0); // Blue Input Triangle
        drawTri();
        transTri();
        glColor3f(1.0, 0.0, 0.0); // Red Output Triangle
        drawTri();
        glFlush();
    }
    if (ch == 2) {
        glColor3f(0.0, 0.0, 1.0); // Blue Input Triangle
        drawTri();
        rotateTri();
        glFlush();
    }
    if (ch == 3) {
        glColor3f(0.0, 0.0, 1.0); // Blue Input Triangle
        drawTri();
        scaleTri();
        glFlush();
        glColor3f(1.0, 0.0, 0.0);
        drawTri();
        glFlush();
    }
}

void myinit() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 1000, 0, 1000);
}

int main(int argc, char** argv) {
    printf("***Geometric Operations ***\n1.Translation \n2.Rotation \n 3.Scaling \n");
    printf("Enter choice\n");
    scanf("%d", &ch);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 1000);
    glutCreateWindow("Geometric Operations on 2D Objects");
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();
    return 0;
}
