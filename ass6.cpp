#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

GLfloat xRot,yRot,zRot;
void init()
{
	glEnable(GL_TEXTURE_2D);
	glShadeModel(GL_SMOOTH);
	glClearColor(0.0f,0.0f,0.0f,0.5f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);
	glOrtho(-6.0, 6.0, -6.0, 6.0, -6.0, 6.0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	SDL_Surface* img;

	glTranslatef(0.0f,0.0f,-5.0f);
	glRotatef(xRot,1.0f,0.0f,0.0f);
	glRotatef(yRot,0.0f,1.0f,0.0f);
	glRotatef(zRot,0.0f,0.0f,1.0f);

	glPushMatrix();
	glTranslatef(1.5,0,0);

	img = SDL_LoadBMP("_1.bmp");
	gluBuild2DMipmaps(GL_TEXTURE_2D,3,img->w,img->h,GL_RGB,GL_UNSIGNED_BYTE,img->pixels);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
	glEnd();

	img = SDL_LoadBMP("2.bmp");
	gluBuild2DMipmaps(GL_TEXTURE_2D,3,img->w,img->h,GL_RGB,GL_UNSIGNED_BYTE,img->pixels);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
	glEnd();

	img = SDL_LoadBMP("3.bmp");
	gluBuild2DMipmaps(GL_TEXTURE_2D,3,img->w,img->h,GL_RGB,GL_UNSIGNED_BYTE,img->pixels);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
	glEnd();

	img = SDL_LoadBMP("4.bmp");
	gluBuild2DMipmaps(GL_TEXTURE_2D,3,img->w,img->h,GL_RGB,GL_UNSIGNED_BYTE,img->pixels);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
	glEnd();

	img = SDL_LoadBMP("5.bmp");
	gluBuild2DMipmaps(GL_TEXTURE_2D,3,img->w,img->h,GL_RGB,GL_UNSIGNED_BYTE,img->pixels);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
	glEnd();

	img = SDL_LoadBMP("6.bmp");
	gluBuild2DMipmaps(GL_TEXTURE_2D,3,img->w,img->h,GL_RGB,GL_UNSIGNED_BYTE,img->pixels);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
	glEnd();

	// glBegin(GL_POLYGON);
    // glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 0.0f, 1.0f);
	// glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
	// glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
	// glEnd();
	glPopMatrix();
	glutSwapBuffers();
}

void reshape(int w,int h)
{
	if (0 == h)
		h = 1;

	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0f,(GLfloat)w / (GLfloat)h,1,100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void keyboard(unsigned char key,int x,int y)
{
	switch(key){
    case 'x':
        xRot += 1.0f;
        glutPostRedisplay();
        break;
    case 'y':
        yRot += 1.0f;
        glutPostRedisplay();
        break;
    case 'z':
        zRot += 1.0f;
        glutPostRedisplay();
        break;
    default:
        break;
	}
}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(400,400);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Texture Map");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
