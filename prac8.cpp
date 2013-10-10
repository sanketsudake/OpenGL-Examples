#include <cstdio>
#include <cmath>
#include <GL/gl.h>
#include <GL/glut.h>
#include <cstdio>
#define MAX 50
int V = 0, E = 0;
int vertex[MAX][3], edges[MAX][2];


void init();

void display();


void keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
	case 'r':
		glRotatef(10,0, 0, 1);

		break;
	}
	glutPostRedisplay();
}


int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Prac 7");
	init();
	freopen("graph.txt", "r", stdin);
	scanf("%d", &V);
	for(int i = 0; i < V; i++)
	{
		scanf("%d", &vertex[i][0]);
		scanf("%d", &vertex[i][1]);
		scanf("%d", &vertex[i][2]);
	}
	scanf("%d", &E);
	for(int j = 0; j < E; j++)
	{
		scanf("%d", &edges[j][0]);
		scanf("%d", &edges[j][1]);
	}
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);

	glutMainLoop();
    return 0;
}

void init()
{
	glClearColor (1.0, 1.0, 1.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);

	/* Set background in window to white
	 */

	/* Set window co-ordinate system
	 */
	glOrtho(-1.0, 10.0, -1.0, 10.0, -1.0, 10.0);

	glEnable(GL_DEPTH);
	glTranslatef(1, 1, 0);
}


void display()
{
	/* Clear all pixels
	 */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3f(1, 0, 0);
	for(int i = 0; i < V; i++)
	{
		glRasterPos3f(vertex[i][0], vertex[i][1], vertex[i][2]);
		//glutSolidCube(0.2);

		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 65 + i);

	}

	for(int j = 0; j < E; j++)
	{
		int a, b;
		a = edges[j][0];
		b = edges[j][1];
		// GLfloat mid_x = (vertex[a][0] + vertex[a][0] )/2;
		// GLfloat mid_y = (vertex[a][1] + vertex[b][1] )/ 2;
		// GLfloat mid_z = (vertex[a][2] + vertex[b][2] )/ 2;
		// printf("Edge : %d %d %d\n", mid_x, mid_y, mid_z);
		// glColor3f(1, 1, 1);
		// glRasterPos3f(mid_x, mid_y, mid_z);
		// glutBitmapCharacter(GLUT_BITMAP_8_BY_13, '*');
		glColor3f(0, 0, 1);
		glBegin(GL_LINES);
		glVertex3f(vertex[a][0], vertex[a][1], vertex[a][2]);
		glVertex3f(vertex[b][0], vertex[b][1], vertex[b][2]);
		glEnd();
	}
	glutSwapBuffers();
}
