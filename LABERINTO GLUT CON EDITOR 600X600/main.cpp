#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
#include <fstream>

using namespace std;

GLdouble ADELANTE=0.0;
GLdouble ATRAS=0.0;
GLdouble IZQUIERDA=0.0;
GLdouble DERECHA=0.0;

GLdouble angle = 0,angle2 = 0;
int moving, startx, starty;

GLdouble LejaniaCamara=400.0;

GLfloat xi = 0.0;
GLfloat yi = -2.0;
GLint escala = 1;
GLdouble angulo = 0;

int MATRIZ1=600,MATRIZ2=600;
char MAPA[600][600];

void CUBO(double, double, int);

void init(void){
    string valor;
    ofstream salida;
    ifstream leer("Salida.txt");
    int N_FILAS=0,N_COL=0;

    while(!leer.eof()){
        leer >> valor;
        if(leer){
            for(N_COL=0;valor[N_COL];N_COL++){
                MAPA[N_FILAS][N_COL]=valor[N_COL];
            }
        }N_FILAS++;
    }
    leer.close();

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_DEPTH_TEST);
}

static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :
        case 's':
            for(int i=0, S=1;i<MATRIZ1&&S;i++){
                for(int j=0;j<MATRIZ2&&S;j++){
                    if(MAPA[i][j]=='I'){
                        if(MAPA[i][j-1]&&MAPA[i][j-1]!='X'){
                            if(MAPA[i][j-1]=='F'){
                                MAPA[i][j-1]='N';
                            }else{
                                MAPA[i][j-1]='I';
                            }MAPA[i][j]='E';
                            S=0;


                        }
                    }
                }
            }
            break;
        case 'S':
            for(int i=0, S=1;i<MATRIZ1&&S;i++){
                for(int j=0;j<MATRIZ2&&S;j++){
                    if(MAPA[i][j]=='I'){
                        if(MAPA[i][j-1]&&MAPA[i][j-1]!='X'){
                            if(MAPA[i][j-1]=='F'){
                                MAPA[i][j-1]='N';
                            }else{
                                MAPA[i][j-1]='I';
                            }MAPA[i][j]='E';
                            S=0;


                        }
                    }
                }
            }
            break;

        case 'w':
            for(int i=0, S=1;i<MATRIZ1&&S;i++){
                for(int j=0;j<MATRIZ2&&S;j++){
                    if(MAPA[i][j]=='I'){
                        if(MAPA[i][j+1]&&MAPA[i][j+1]!='X'){
                            if(MAPA[i][j+1]=='F'){
                                MAPA[i][j+1]='N';
                            }else{
                                MAPA[i][j+1]='I';
                            }
                            MAPA[i][j]='E';
                            S=0;
                        }
                    }
                }
            }
            break;
        case 'W':
            for(int i=0, S=1;i<MATRIZ1&&S;i++){
                for(int j=0;j<MATRIZ2&&S;j++){
                    if(MAPA[i][j]=='I'){
                        if(MAPA[i][j+1]&&MAPA[i][j+1]!='X'){
                            if(MAPA[i][j+1]=='F'){
                                MAPA[i][j+1]='N';
                            }else{
                                MAPA[i][j+1]='I';
                            }
                            MAPA[i][j]='E';
                            S=0;
                        }
                    }
                }
            }
            break;

        case 'a':
            for(int i=0, S=1;i<MATRIZ1&&S;i++){
                for(int j=0;j<MATRIZ2&&S;j++){
                    if(MAPA[i][j]=='I'){
                        if(MAPA[i-1][j]&&MAPA[i-1][j]!='X'){
                            if(MAPA[i-1][j]=='F'){
                                MAPA[i-1][j]='N';
                            }else{
                                MAPA[i-1][j]='I';
                            }
                            MAPA[i][j]='E';
                            S=0;
                        }
                    }
                }
            }
            break;
        case 'A':
            for(int i=0, S=1;i<MATRIZ1&&S;i++){
                for(int j=0;j<MATRIZ2&&S;j++){
                    if(MAPA[i][j]=='I'){
                        if(MAPA[i-1][j]&&MAPA[i-1][j]!='X'){
                            if(MAPA[i-1][j]=='F'){
                                MAPA[i-1][j]='N';
                            }else{
                                MAPA[i-1][j]='I';
                            }
                            MAPA[i][j]='E';
                            S=0;
                        }
                    }
                }
            }
            break;

        case 'd':
            for(int i=0, S=1;i<MATRIZ1&&S;i++){
                for(int j=0;j<MATRIZ2&&S;j++){
                    if(MAPA[i][j]=='I'){
                        if(MAPA[i+1][j]&&MAPA[i+1][j]!='X'){
                            if(MAPA[i+1][j]=='F'){
                                MAPA[i+1][j]='N';
                            }else{
                                MAPA[i+1][j]='I';
                            }
                            MAPA[i][j]='E';
                            S=0;
                        }
                    }
                }
            }
            break;
        case 'D':
            for(int i=0, S=1;i<MATRIZ1&&S;i++){
                for(int j=0;j<MATRIZ2&&S;j++){
                    if(MAPA[i][j]=='I'){
                        if(MAPA[i+1][j]&&MAPA[i+1][j]!='X'){
                            if(MAPA[i+1][j]=='F'){
                                MAPA[i+1][j]='N';
                            }else{
                                MAPA[i+1][j]='I';
                            }
                            MAPA[i][j]='E';
                            S=0;
                        }
                    }
                }
            }
            break;

        case 'q':
            exit(0);
            break;
    }

    glutPostRedisplay();
}

static void idle(void)
{
    glutPostRedisplay();
}

void ArrowKey(int key, int x, int y){
	switch (key)
	{

	case GLUT_KEY_RIGHT:
		if (xi < 3000)
			xi += 5.5;
		break;

	case GLUT_KEY_LEFT:
		if (xi > -3000)
			xi -= 5.5;
		break;

	case GLUT_KEY_UP:
		if (yi < 3000)
			yi += 5.5;
		break;

	case GLUT_KEY_DOWN:
		if (yi > -3000)
			yi -= 5.5;
		break;

	case GLUT_KEY_HOME:
		escala = escala + 1;
		break;
	case GLUT_KEY_PAGE_UP:
		if (escala <=1){
            escala = 1;
		}else{
            escala = escala - 1;
		}

		break;

	case GLUT_KEY_PAGE_DOWN:
		angulo +=5;
		break;

	case GLUT_KEY_END:
		angulo -=5;
		break;
    }
}

void drawText(const char *text,int lengh,int x,int y){
    glMatrixMode(GL_PROJECTION);
    double *matrix=new double[16];
    glGetDoublev(GL_PROJECTION_MATRIX, matrix);
    glLoadIdentity();
    glOrtho(0,800,0,600,-5,5);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glLoadIdentity();
    glRasterPos2d(x,y);
    for(int i=0;i<lengh;i++){
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15,(int)text[i]);
    }
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glLoadMatrixd(matrix);
    glMatrixMode(GL_MODELVIEW);
}

void MapaLAB(){
    int XI,YI;
    for(int i=0;i<MATRIZ1;i++){
        for(int j=0;j<MATRIZ2;j++){
            XI=i*1;
            YI=j*1;
            if(MAPA[i][j]=='X'){
                CUBO(XI,YI,0);
            }else if(MAPA[i][j]=='I'){
                CUBO(XI,YI,1);
            }else if(MAPA[i][j]=='N'){
                CUBO(XI,YI,2);
            }
        }
    }
}

void CUBO(double PXI, double PYI, int COLOR){
    double PX=PXI+1-280,PY=PYI+1-280,PZ=0.5d,PZI=0.0d;PXI-=280;PYI-=280;
    if(COLOR==1){
        glColor3d(1.0f,0.0f,0.0f);
    }else if(COLOR==2){
        glColor3d(1.0f,1.0f,1.0f);
    }else{
        glColor3d(0.2f,0.46f,0.8f);
    }

    glBegin(GL_QUADS);
        glVertex3f(PXI, PYI, PZI);
        glVertex3f(PX,  PYI, PZI);
        glVertex3f(PX,  PY,  PZI);
        glVertex3f(PXI, PY,  PZI);
        glVertex3f(PXI, PYI, PZI);
    glEnd();
/*
    glBegin(GL_QUADS);
        glVertex3f(PXI, PYI, PZ);
        glVertex3f(PX,  PYI, PZ);
        glVertex3f(PX,  PY,  PZ);
        glVertex3f(PXI, PY,  PZ);
        glVertex3f(PXI, PYI, PZ);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(PXI, PYI, PZI);
        glVertex3f(PX,  PYI, PZI);
        glVertex3f(PX,  PYI, PZ);
        glVertex3f(PXI, PYI, PZ);
        glVertex3f(PXI, PYI, PZI);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(PXI, PY, PZI);
        glVertex3f(PX,  PY, PZI);
        glVertex3f(PX,  PY, PZ);
        glVertex3f(PXI, PY, PZ);
        glVertex3f(PXI, PY, PZI);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(PXI, PYI, PZI);
        glVertex3f(PXI, PY,  PZI);
        glVertex3f(PXI, PY,  PZ);
        glVertex3f(PXI, PYI, PZ);
        glVertex3f(PXI, PYI, PZI);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(PX, PYI, PZI);
        glVertex3f(PX, PY,  PZI);
        glVertex3f(PX, PY,  PZ);
        glVertex3f(PX, PYI, PZ);
        glVertex3f(PX, PYI, PZI);
    glEnd();

    glColor3d(1.0f,1.0f,1.0f);
    glBegin(GL_LINE_STRIP);
        glVertex3f(PXI, PYI, PZI);
        glVertex3f(PX,  PYI, PZI);
        glVertex3f(PX,  PY,  PZI);
        glVertex3f(PXI, PY,  PZI);
        glVertex3f(PXI, PYI, PZI);

        glVertex3f(PXI, PYI, PZ);
        glVertex3f(PX,  PYI, PZ);
        glVertex3f(PX,  PY,  PZ);
        glVertex3f(PXI, PY,  PZ);
        glVertex3f(PXI, PYI, PZ);

        glVertex3f(PXI, PYI, PZI);
        glVertex3f(PX,  PYI, PZI);
        glVertex3f(PX,  PYI, PZ);
        glVertex3f(PXI, PYI, PZ);
        glVertex3f(PXI, PYI, PZI);

        glVertex3f(PXI, PY, PZI);
        glVertex3f(PX,  PY, PZI);
        glVertex3f(PX,  PY, PZ);
        glVertex3f(PXI, PY, PZ);
        glVertex3f(PXI, PY, PZI);

        glVertex3f(PXI, PYI, PZI);
        glVertex3f(PXI, PY,  PZI);
        glVertex3f(PXI, PY,  PZ);
        glVertex3f(PXI, PYI, PZ);
        glVertex3f(PXI, PYI, PZI);

        glVertex3f(PX, PYI, PZI);
        glVertex3f(PX, PY,  PZI);
        glVertex3f(PX, PY,  PZ);
        glVertex3f(PX, PYI, PZ);
        glVertex3f(PX, PYI, PZI);
    glEnd();*/
}

void display(void){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 0.1, 0.0, 0.0, 0.0, 0.0, 0.1, 0.0);

	glPushMatrix();
        glTranslatef(xi, yi, 0);
        glScaled(escala, escala, 1.0);
        glRotated(angulo, 0.0, 0.0, 1.0);

        glPushMatrix();
            glTranslatef(-9.5, -4, 0);
            //glRotated(-1, 1.0, 1.0, 0.0);
            glRotatef(angle2, 1.0, 0.0, 0.0);/* mover mouse */
            glRotatef(angle, 0.0, 1.0, 0.0);
            MapaLAB();
        glPopMatrix();
    glPopMatrix();


    glColor3f(1,1,1);
    std::string text;
    text= "LABERINTO ROMPE CRANEOS";
    drawText(text.data(),text.size(),5,5);

	glFlush();
	glutSwapBuffers();
}
void reshape(int w, int h){
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();//Inicializa la matriz de proyeccion
	glOrtho(-LejaniaCamara, LejaniaCamara, -LejaniaCamara, LejaniaCamara, -1000.0, 1000.0); // WorkSpace
	glMatrixMode(GL_MODELVIEW); // cambiamos la matrix :D
}
void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            moving = 1;
            startx = x;
            starty = y;
        }
        if (state == GLUT_UP) {
            moving = 0;
        }
    }
}

void mover(int x, int y)
{
    if (moving) {
        angle = angle + (x - startx);
        angle2 = angle2 + (y - starty);
        startx = x;
        starty = y;
        glutPostRedisplay();
    }
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(900, 900);
	glutInitWindowPosition(1, 1);
	glutCreateWindow("Movimiento");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutMotionFunc(mover);
	glutIdleFunc(idle);
	glutKeyboardFunc(key);
	glutSpecialFunc(ArrowKey);
	glutMainLoop();

	return 0;
}
