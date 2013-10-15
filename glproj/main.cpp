using namespace std;
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <GL/gl.h>
#include <GL/glut.h>

void init();

void display();
void reshape(int w, int h);
/* Get single random number
 * in given range
 */
int getnos(int range){
	return ( rand() % range );
}
float getnosf(int range){
	return (rand() % range + (rand() % 10 * 0.1));
}
float getcolf(){
	return (rand() % 11 * 0.1);
}
/*
 *Config
 *Config for each droplet
 */

class Config{
	public:
	int speed;
	int angle;
	int intensity ;
	float color[3];
	int size;

	Config(){
		speed = 0;
		angle = 0;
		intensity = 0;
		color[1] = 0, color[2] = 0, color[3] = 0 ;
		size = 0;
	}
};
class Drop{
	public:

};
class Area{
	public:
	int width;
	int height;
};
void keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
	case 'r':
		//glRotatef(10,0, 0, 1);

		break;
	}
	glutPostRedisplay();
}


int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(800, 700);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("RainGL");
	init();
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
    return 0;
}

void init()
{
	glClearColor (0.1, 0.1, 0.1, 0.1);
	glColor4f(1.0, 1.0, 1.0, 0.9);

	/* Set background in window to white
	 */

	/* Set window co-ordinate system
	 */
	glOrtho(0.0, 10.0, 0.0, 10.0, 0.0, 10.0);

}


void display()
{

	/* Clear all pixels
	 */

	glEnable(GL_DEPTH);
	glEnable(GL_BLEND);
    glBlendFunc(GL_SRC1_ALPHA, GL_ONE_MINUS_SRC1_COLOR);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_FOG);
	GLfloat fogColor[4] = {1.0, 0.8, 0.8, 0.5};
	GLfloat density = 0.9;
	int fogMode = GL_EXP2;
	glFogi (GL_FOG_MODE, fogMode);
	glFogfv (GL_FOG_COLOR, fogColor);
	glFogf (GL_FOG_DENSITY, density);
	glHint (GL_FOG_HINT, GL_DONT_CARE);
	glFogf (GL_FOG_START, 1.0);
	glFogf (GL_FOG_END, 9.0);

	glColor3f(0, 0, 0);

    GLfloat mat_shininess[] = {  0.0 };
    GLfloat light_position1[] = { 1.0, 1.0, 0.0, 0.0 };
	GLfloat light_position2[] = { 9.0, 9.0, 0.0, 0.0 };

	for(int i = 0; i < 1000; i++){
		glPushMatrix();
		glLightf(GL_LIGHT0, GL_DIFFUSE, 0.9);
		glLightfv(GL_LIGHT0, GL_POSITION, light_position1);


		glLightf(GL_LIGHT1, GL_DIFFUSE, 1.0);
		glLightfv(GL_LIGHT1, GL_POSITION, light_position2);

		glLightfv(GL_LIGHT0, GL_SHININESS, mat_shininess);
		glLightfv(GL_LIGHT1, GL_SHININESS, mat_shininess);

		glTranslatef(0, 0, 0);
		glTranslatef(getnosf(10), getnosf(10), 0);
		glColor4f(0.5, 0.5, 0.5, 0.4);
		//glColor3f(getcolf(), getcolf(), getcolf());
		glutSolidSphere(0.05*getcolf(), 100, 10 );
		glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
		glEnable(GL_LIGHT1);
        glEnable(GL_DEPTH_TEST);
		glPopMatrix();
	}
	///glutSolidSphere(GLdouble radius, GLint slices, GLint stacks)
	glutSwapBuffers();

}

void reshape(int w, int h) {
	glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	glOrtho(0.0, 10.0, 0.0, 10.0, 0.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}
