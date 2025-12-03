from OpenGL.GL import *
from OpenGL.GLUT import *
from OpenGL.GLU import *
import sys

angle = 0.0

WIN_W, WIN_H = 600, 600

def init():
    glClearColor(0.9, 0.95, 1.0, 1.0) 
    glShadeModel(GL_FLAT)
    glMatrixMode(GL_PROJECTION)
    glLoadIdentity()
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0)
    glMatrixMode(GL_MODELVIEW)

def display():
    global angle
    glClear(GL_COLOR_BUFFER_BIT)
    glLoadIdentity()
    
    glPushMatrix()
    glRotatef(angle, 0.0, 0.0, 1.0)
    
    side = 0.6
    half = side / 2.0
    
    glColor3f(0.2, 0.6, 0.86) 
    glBegin(GL_QUADS)
    glVertex2f(-half, -half)
    glVertex2f(half, -half)
    glVertex2f(half, half)
    glVertex2f(-half, half)
    glEnd()
    
    glColor3f(0.05, 0.2, 0.3)
    glLineWidth(2.0)
    glBegin(GL_LINE_LOOP)
    glVertex2f(-half, -half)
    glVertex2f(half, -half)
    glVertex2f(half, half)
    glVertex2f(-half, half)
    glEnd()
    
    glPopMatrix()
    glutSwapBuffers()

def idle():
    global angle
    angle += 0.6
    if angle >= 360.0:
        angle -= 360.0
    glutPostRedisplay()

def reshape(w, h):
    side = min(w, h)
    glViewport((w - side) // 2, (h - side) // 2, side, side)

def keyboard(key, x, y):
    if key == b'\x1b' or key == b'q':
        glutLeaveMainLoop()
        sys.exit(0)

def main():
    glutInit(sys.argv)
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB)
    glutInitWindowSize(WIN_W, WIN_H)
    glutInitWindowPosition(100, 100)
    glutCreateWindow(b"Rotating Square - PyOpenGL")
    
    init()
    glutDisplayFunc(display)
    glutReshapeFunc(reshape)
    glutKeyboardFunc(keyboard)
    glutIdleFunc(idle)
    glutMainLoop()

if __name__ == "__main__":
    main()